## Purpose
Definir el cálculo de telemetría en tiempo real en el Arduino Nano, su transmisión serial en formato JSON y la API del ESP32 que expone los datos para el panel web.
## Requirements
### Requirement: Cómputo del Estado en Tiempo Real
El Arduino Nano SHALL estimar las posiciones y estados de los componentes de la grúa en tiempo real basándose en los tiempos de ejecución de los motores y sus límites físicos.

#### Scenario: Dynamic trolley position computation
- **WHEN** El motor del carro (trolley) está en funcionamiento en dirección hacia adelante o hacia atrás
- **THEN** La posición del carro se actualiza a una tasa de 5.0 cm/s entre los límites de 0.0 y 30.0 cm de recorrido.

### Requirement: Transmisión Serial JSON
El Arduino Nano SHALL empaquetar todas las lecturas de los sensores, los estados de los motores y las posiciones calculadas en un objeto JSON y transmitirlo por el puerto serial cada 200 ms.

#### Scenario: Telemetry transmission containing active mode
- **WHEN** Se alcanza el intervalo de telemetría de 200 ms
- **THEN** Se imprime una cadena JSON donde `"cx"` contiene la lectura del joystick del carro, `"cy"` contiene la lectura del joystick de la elevación y `"cz"` contiene la lectura del joystick de giro.

### Requirement: API Web de Consulta de Telemetría
El ESP32 SHALL escuchar el puerto UART, almacenar en caché el último JSON de telemetría válido y servirlo a través de HTTP al panel de control web.

#### Scenario: Servir telemetría al cliente web
- **WHEN** Se recibe una solicitud HTTP GET en el endpoint `/telemetry`
- **THEN** El ESP32 responde con los últimos datos de telemetría JSON almacenados en caché e incluye las cabeceras CORS.

### Requirement: Registro de Movimientos de Joystick en Depuración Serie
El Arduino Nano SHALL registrar los cambios en los estados de movimiento (carro, elevación, giro) controlados por los joysticks físicos y transmitirlos al puerto `debugSerial` (SoftwareSerial) de manera eficiente.

#### Scenario: Event logging on joystick movement state changes
- **WHEN** El control web no está activo (modo joystick) y ocurre una transición en el estado de movimiento del carro, de la elevación o del giro
- **THEN** El Arduino Nano transmite un mensaje descriptivo al puerto SoftwareSerial (ej. `[JOYSTICK] Carro: ADELANTE`, `[JOYSTICK] Elevacion: DETENIDO`, etc.), evitando el envío continuo en cada iteración de bucle.

