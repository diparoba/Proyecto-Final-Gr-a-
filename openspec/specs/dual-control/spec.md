## Purpose
Definir el mecanismo de control dual de la grúa, estableciendo las prioridades de anulación por joystick y los comportamientos de respaldo del control web.
## Requirements
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

### Requirement: Conmutación de Modo de Control Bidireccional
El sistema SHALL permitir alternar de forma exclusiva entre el modo de control web y el modo de control por joystick mediante comandos seriales y entradas físicas.

#### Scenario: Cambio de modo por botón físico
- **WHEN** El usuario presiona el pulsador físico del joystick (Pin A3)
- **THEN** El modo de control del Arduino Nano se alterna y se transmite el nuevo estado en la telemetría.

#### Scenario: Cambio de modo por petición web
- **WHEN** Se recibe una solicitud HTTP en `/toggle-mode`
- **THEN** El ESP32 envía la orden serial `'M'` al Arduino Nano, el cual alterna su modo de control y lo refleja en la telemetría.

