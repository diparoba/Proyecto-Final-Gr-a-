## MODIFIED Requirements

### Requirement: Prioridad de Anulación del Joystick
El sistema SHALL priorizar las entradas de los joysticks físicos locales únicamente cuando el modo de control activo esté establecido en modo joystick (controlWebActivo == false).

#### Scenario: Joystick execution of 3 motors
- **WHEN** El modo de control está configurado en modo joystick y los mandos analógicos para Carro, Elevación y Giro se mueven fuera de la zona muerta
- **THEN** Los motores correspondientes responden de manera proporcional a las entradas de los joysticks.

### Requirement: Respaldo de Control de Interfaz Web
El sistema SHALL ejecutar los comandos de la interfaz web únicamente cuando el modo de control activo esté establecido en modo web (controlWebActivo == true).

#### Scenario: Web control execution of 3 motors
- **WHEN** El modo de control está configurado en modo web y se recibe una petición de movimiento válida para Carro, Elevación o Giro (por ejemplo, `/forward`)
- **THEN** El motor correspondiente ejecuta el movimiento a su velocidad máxima configurada.
