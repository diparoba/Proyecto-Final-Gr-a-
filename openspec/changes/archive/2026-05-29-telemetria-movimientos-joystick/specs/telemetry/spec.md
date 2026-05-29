## ADDED Requirements

### Requirement: Registro de Movimientos de Joystick en Depuración Serie
El Arduino Nano SHALL registrar los cambios en los estados de movimiento (carro, elevación, giro) controlados por los joysticks físicos y transmitirlos al puerto `debugSerial` (SoftwareSerial) de manera eficiente.

#### Scenario: Event logging on joystick movement state changes
- **WHEN** El control web no está activo (modo joystick) y ocurre una transición en el estado de movimiento del carro, de la elevación o del giro
- **THEN** El Arduino Nano transmite un mensaje descriptivo al puerto SoftwareSerial (ej. `[JOYSTICK] Carro: ADELANTE`, `[JOYSTICK] Elevacion: DETENIDO`, etc.), evitando el envío continuo en cada iteración de bucle.
