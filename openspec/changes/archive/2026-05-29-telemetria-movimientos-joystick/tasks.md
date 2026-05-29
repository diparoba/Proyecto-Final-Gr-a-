## 1. Modificaciones de Firmware en Arduino Nano

- [x] 1.1 Declarar variables de control para rastrear los estados anteriores de movimiento (carro, elevación, giro) en `arduino/grua_arduino/grua_arduino.ino`.
- [x] 1.2 Programar la lógica de detección de cambios de estado para cada movimiento.
- [x] 1.3 Transmitir al puerto `debugSerial` los logs de cambios de estado en modo Joystick (`[JOYSTICK] Carro: ...`, `[JOYSTICK] Elevacion: ...`, `[JOYSTICK] Giro: ...`).

## 2. Pruebas y Verificación

- [x] 2.1 Compilar y verificar el código de `arduino/grua_arduino/grua_arduino.ino` para asegurar que no hay errores de sintaxis o de compilación.
- [x] 2.2 Validar que las trazas de depuración de joysticks se emiten correctamente por SoftwareSerial y no interfieren con la telemetría JSON principal del puerto USB.
