## 1. Actualización de Documentación

- [x] 1.1 Modificar el archivo principal `requirements.md` para adaptarlo a la nueva arquitectura (reemplazo de motor a pasos por motorreductor de 30 RPM, 2 motores de 300 RPM independientes, segundo puente H, pulsador A3 de cambio de modo, y eliminación del carro).
- [x] 1.2 Actualizar el archivo `roadmap.md` agregando un nuevo hito de desarrollo (Hito 6: Control de 3 Motores DC y Conmutación Exclusiva) para mantenerlo en sintonía con las especificaciones actuales.

## 2. Modificaciones del Firmware Arduino (`grua_arduino.ino`)

- [x] 2.1 Eliminar la biblioteca `AccelStepper.h` y todas las referencias lógicas y físicas del motor a pasos.
- [x] 2.2 Reorganizar los pines de los motores de acuerdo al Enfoque 1 (Carro eliminado, Giro en D2/D3/D4, Elevación 1 en D5/D7/D8, Elevación 2 en D6/D10/D11).
- [x] 2.3 Definir constantes de velocidad máxima (`VEL_MAX_GIRO`, `VEL_MAX_ELEV1`, `VEL_MAX_ELEV2`) y configurar el pin `A3` como `INPUT_PULLUP` para el pulsador.
- [x] 2.4 Implementar la lectura analógica de joysticks escalada a las velocidades máximas y la lectura con debounce para el pulsador de alternancia de modo.
- [x] 2.5 Programar la lógica de exclusión de control: ignorar joysticks cuando `controlWebActivo` es verdadero, e ignorar peticiones seriales cuando es falso.
- [x] 2.6 Actualizar el cálculo de telemetría física en Arduino Nano (giro basado en la velocidad teórica del motorreductor de 30 RPM, carro fijo en 15.0 cm) y reportarlo cada 200 ms.
- [x] 2.7 Añadir el parser para el comando `'M'` en el lector serial de Arduino para alternar el modo.

## 3. Modificaciones del Firmware ESP32 (`main.py`)

- [x] 3.1 Añadir el endpoint `/toggle-mode` en el servidor web asíncrono para enviar el carácter `'M'` al Arduino Nano.
