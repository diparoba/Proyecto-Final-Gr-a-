/*
 * grua_arduino.ino
 * Controlador principal de la Grúa Torre basado en Arduino Nano.
 * 
 * Funciones:
 * 1. Lee comandos vía Serial (UART) enviados desde el ESP32 (interfaz web).
 * 2. Lee entradas analógicas de joysticks físicos para control manual.
 * 3. Controla motores DC (carro y elevación) usando el driver TB6612FNG.
 * 4. Controla un motor a pasos Nema 17 (rotación) usando un driver DRV8825.
 * 5. Implementa lógica de prioridad (joystick sobre web) y timeout de seguridad.
 */
// grua_arduino.ino
#include <AccelStepper.h>

// ==== PINES DEL JOYSTICK (Entradas Analógicas) ====
const int JOY_X_CARRO = A0;   // Controla el movimiento del carro
const int JOY_Y_ELEVACION = A1; // Controla el gancho (subir/bajar)
const int JOY_GIRO = A2;      // Controla la rotación de la grúa

// ==== PINES DRIVER TB6612FNG (Motores DC N20) ====
// Motor A: Carro
const int AIN1 = 2;
const int AIN2 = 4;
const int PWMA = 3;
// Motor B: Elevación
const int BIN1 = 7;
const int BIN2 = 8;
const int PWMB = 5;

// ==== CONFIGURACIÓN DE LÍMITES FÍSICOS Y VELOCIDADES DE TELEMETRÍA ====
// Modifica estos valores según las dimensiones reales de tu prototipo físico:
const float CARRO_LIMITE_MAX = 30.0;       // Límite máximo del carro en cm
const float CARRO_VELOCIDAD_CMS = 5.0;     // Velocidad estimada del carro (cm por segundo)
const float ELEV_LIMITE_MAX = 50.0;        // Límite máximo de elevación (gancho) en cm
const float ELEV_VELOCIDAD_CMS = 8.0;      // Velocidad estimada de elevación (cm por segundo)
const float GIRO_PASOS_POR_VUELTA = 200.0; // Pasos por vuelta del motor Nema 17 (e.g. 200 si es paso completo, 3200 para 1/16 paso)

// ==== PINES DRIVER DRV8825 (Motor Nema 17 - Giro) ====
const int STEP_PIN = 9;
const int DIR_PIN = 10;

// Instancia del motor a pasos (1 = modo driver)
AccelStepper motorGiro(1, STEP_PIN, DIR_PIN);

// ==== VARIABLES DE ESTADO Y SEGURIDAD ====
char comandoWeb = 'S'; 
unsigned long ultimoComandoWeb = 0;
const unsigned long TIMEOUT_WEB = 500; // Si pasan 500ms sin recibir comando, se detiene

// Zona muerta para los joysticks (0-1023, centro ~512)
const int ZONA_MUERTA_MIN = 400;
const int ZONA_MUERTA_MAX = 600;
const int VELOCIDAD_DC = 255; // Velocidad PWM (0-255)

// ==== VARIABLES DE TELEMETRÍA (INTEGRACIÓN VIRTUAL) ====
float posCarro = 0.0;     // Posición estimada actual del carro (0 a CARRO_LIMITE_MAX)
float posElev = 0.0;      // Altura estimada actual del gancho (0 a ELEV_LIMITE_MAX)
unsigned long ultimaActualizacionFisica = 0;
unsigned long ultimoReporteTelemetria = 0;
const unsigned long INTERVALO_TELEMETRIA = 200; // Enviar datos cada 200 ms

void setup() {
  // Comunicación Serial con el ESP32
  Serial.begin(9600);

  // Configuración de pines de salida Motores DC
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  // Motores DC detenidos al iniciar
  detenerCarro();
  detenerElevacion();

  // Configuración Motor a Pasos (Movimiento suave)
  motorGiro.setMaxSpeed(1000.0);
  motorGiro.setAcceleration(300.0);

  // Inicializar tiempo de telemetría física
  ultimaActualizacionFisica = millis();
}

// === FUNCIONES DE CONTROL: MOTOR DC ===
void moverCarro(bool adelante) {
  digitalWrite(AIN1, adelante ? HIGH : LOW);
  digitalWrite(AIN2, adelante ? LOW : HIGH);
  analogWrite(PWMA, VELOCIDAD_DC);
}

void detenerCarro() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);
}

void moverElevacion(bool subir) {
  digitalWrite(BIN1, subir ? HIGH : LOW);
  digitalWrite(BIN2, subir ? LOW : HIGH);
  analogWrite(PWMB, VELOCIDAD_DC);
}

void detenerElevacion() {
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 0);
}

void loop() {
  // 1. LEER COMANDOS DEL ESP32 (SERVIDOR WEB)
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == 'F' || c == 'B' || c == 'U' || c == 'D' || c == 'L' || c == 'R' || c == 'S') {
      comandoWeb = c;
      ultimoComandoWeb = millis(); // Reiniciar el contador de timeout de seguridad
    }
  }

  // 2. TIMEOUT DE SEGURIDAD (Si el WiFi falla o el usuario suelta el botón web)
  if (millis() - ultimoComandoWeb > TIMEOUT_WEB) {
    comandoWeb = 'S'; // Forzar parada
  }

  // 3. LEER JOYSTICKS FÍSICOS
  int valCarro = analogRead(JOY_X_CARRO);
  int valElev = analogRead(JOY_Y_ELEVACION);
  int valGiro = analogRead(JOY_GIRO);

  // 4. LÓGICA DE CONTROL MIXTO (El Joystick tiene prioridad sobre la Web)
  
  // ---> Control del Carro (Motor A)
  if (valCarro > ZONA_MUERTA_MAX) moverCarro(true);       // Joystick: Adelante
  else if (valCarro < ZONA_MUERTA_MIN) moverCarro(false); // Joystick: Atrás
  else {
    // Si no se usa el Joystick, usamos la Web
    if (comandoWeb == 'F') moverCarro(true);
    else if (comandoWeb == 'B') moverCarro(false);
    else if (comandoWeb == 'S' || (comandoWeb != 'F' && comandoWeb != 'B')) detenerCarro();
  }

  // ---> Control de Elevación (Motor B)
  if (valElev > ZONA_MUERTA_MAX) moverElevacion(true);       // Joystick: Subir
  else if (valElev < ZONA_MUERTA_MIN) moverElevacion(false); // Joystick: Bajar
  else {
    // Si no se usa el Joystick, usamos la Web
    if (comandoWeb == 'U') moverElevacion(true);
    else if (comandoWeb == 'D') moverElevacion(false);
    else if (comandoWeb == 'S' || (comandoWeb != 'U' && comandoWeb != 'D')) detenerElevacion();
  }

  // ---> Control de Giro (Nema 17)
  if (valGiro < ZONA_MUERTA_MIN) {
    motorGiro.moveTo(motorGiro.currentPosition() - 10000); // Joystick: Izquierda
  } 
  else if (valGiro > ZONA_MUERTA_MAX) {
    motorGiro.moveTo(motorGiro.currentPosition() + 10000); // Joystick: Derecha
  } 
  else {
    // Si no se usa el Joystick, usamos la Web
    if (comandoWeb == 'L') motorGiro.moveTo(motorGiro.currentPosition() - 10000);
    else if (comandoWeb == 'R') motorGiro.moveTo(motorGiro.currentPosition() + 10000);
    else motorGiro.stop(); // Freno suave
  }

  // 5. EJECUTAR PASO DEL MOTOR A PASOS
  // Esta función debe ejecutarse sin bloqueos (sin delays) para garantizar la suavidad
  motorGiro.run();

  // 6. ACTUALIZAR FÍSICA VIRTUAL (TELEMETRÍA)
  unsigned long ahora = millis();
  float dt = (ahora - ultimaActualizacionFisica) / 1000.0;
  if (dt < 0.0) dt = 0.0; // Manejar desbordamiento de millis() cada 50 días (por seguridad)
  ultimaActualizacionFisica = ahora;

  // Analizar estados del movimiento del carro
  String estadoCarro = "DETENIDO";
  if (digitalRead(AIN1) == HIGH && digitalRead(AIN2) == LOW) {
    posCarro = posCarro + (CARRO_VELOCIDAD_CMS * dt);
    if (posCarro > CARRO_LIMITE_MAX) posCarro = CARRO_LIMITE_MAX;
    estadoCarro = "ADELANTE";
  } else if (digitalRead(AIN1) == LOW && digitalRead(AIN2) == HIGH) {
    posCarro = posCarro - (CARRO_VELOCIDAD_CMS * dt);
    if (posCarro < 0.0) posCarro = 0.0;
    estadoCarro = "ATRÁS";
  }

  // Analizar estados del movimiento de elevación (gancho)
  String estadoElev = "DETENIDO";
  if (digitalRead(BIN1) == HIGH && digitalRead(BIN2) == LOW) {
    posElev = posElev + (ELEV_VELOCIDAD_CMS * dt);
    if (posElev > ELEV_LIMITE_MAX) posElev = ELEV_LIMITE_MAX;
    estadoElev = "SUBIENDO";
  } else if (digitalRead(BIN1) == LOW && digitalRead(BIN2) == HIGH) {
    posElev = posElev - (ELEV_VELOCIDAD_CMS * dt);
    if (posElev < 0.0) posElev = 0.0;
    estadoElev = "BAJANDO";
  }

  // Analizar estados del movimiento de giro
  String estadoGiro = "DETENIDO";
  long distToGo = motorGiro.distanceToGo();
  if (distToGo > 0) {
    estadoGiro = "DERECHA";
  } else if (distToGo < 0) {
    estadoGiro = "IZQUIERDA";
  }

  // Calcular ángulo de giro en grados (0 a 360)
  long pasosActuales = motorGiro.currentPosition();
  float anguloGiro = (float)(pasosActuales % (long)GIRO_PASOS_POR_VUELTA) * (360.0 / GIRO_PASOS_POR_VUELTA);
  if (anguloGiro < 0.0) anguloGiro += 360.0;

  // Determinar el modo de control activo
  bool joystickActivo = (valCarro > ZONA_MUERTA_MAX || valCarro < ZONA_MUERTA_MIN ||
                         valElev > ZONA_MUERTA_MAX || valElev < ZONA_MUERTA_MIN ||
                         valGiro > ZONA_MUERTA_MAX || valGiro < ZONA_MUERTA_MIN);
  String modoControl = "INACTIVO";
  if (joystickActivo) {
    modoControl = "JOYSTICK";
  } else if (comandoWeb != 'S') {
    modoControl = "WEB";
  }

  // 7. ENVIAR REPORTE SERIAL CADA 200MS
  if (ahora - ultimoReporteTelemetria >= INTERVALO_TELEMETRIA) {
    ultimoReporteTelemetria = ahora;

    // Crear JSON manual para evitar librerías externas y sobrecarga
    Serial.print("{\"mode\":\""); Serial.print(modoControl);
    Serial.print("\",\"cx\":"); Serial.print(valCarro);
    Serial.print(",\"cy\":"); Serial.print(valElev);
    Serial.print(",\"cz\":"); Serial.print(valGiro);
    Serial.print(",\"pCarro\":"); Serial.print(posCarro, 1);
    Serial.print(",\"pElev\":"); Serial.print(posElev, 1);
    Serial.print(",\"pGiro\":"); Serial.print(anguloGiro, 1);
    Serial.print(",\"mCarro\":\""); Serial.print(estadoCarro);
    Serial.print("\",\"mElev\":\""); Serial.print(estadoElev);
    Serial.print("\",\"mGiro\":\""); Serial.print(estadoGiro);
    Serial.println("\"}");
  }
}
