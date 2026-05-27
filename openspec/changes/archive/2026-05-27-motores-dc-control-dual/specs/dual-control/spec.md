## MODIFIED Requirements

### Requirement: Prioridad de Anulación del Joystick
El sistema SHALL priorizar las entradas de los joysticks físicos locales únicamente cuando el modo de control activo esté establecido en modo joystick (controlWebActivo == false).

#### Scenario: Joystick execution in joystick mode
- **WHEN** El modo de control está configurado en manual/joystick y los mandos físicos se mueven fuera de la zona muerta (< 400 o > 600)
- **THEN** Los motores correspondientes responden directamente al joystick.

#### Scenario: Joystick ignored in web mode
- **WHEN** El modo de control está configurado en modo web (controlWebActivo == true) y los joysticks físicos son desplazados fuera de la zona muerta
- **THEN** Los motores ignoran las entradas de los joysticks y siguen el estado web.

### Requirement: Respaldo de Control de Interfaz Web
El sistema SHALL ejecutar los comandos de la interfaz web únicamente cuando el modo de control activo esté establecido en modo web (controlWebActivo == true).

#### Scenario: Web control execution in web mode
- **WHEN** El modo de control está configurado en modo web y se recibe una petición de movimiento válida (por ejemplo, `/up`)
- **THEN** El motor correspondiente ejecuta el movimiento a su velocidad máxima.

#### Scenario: Web control ignored in joystick mode
- **WHEN** El modo de control está configurado en modo joystick y se recibe una petición de movimiento desde la web
- **THEN** Los motores ignoran las órdenes de la web y siguen detenidos o controlados por el joystick.

## ADDED Requirements

### Requirement: Conmutación de Modo de Control Bidireccional
El sistema SHALL permitir alternar de forma exclusiva entre el modo de control web y el modo de control por joystick mediante comandos seriales y entradas físicas.

#### Scenario: Cambio de modo por botón físico
- **WHEN** El usuario presiona el pulsador físico del joystick (Pin A3)
- **THEN** El modo de control del Arduino Nano se alterna y se transmite el nuevo estado en la telemetría.

#### Scenario: Cambio de modo por petición web
- **WHEN** Se recibe una solicitud HTTP en `/toggle-mode`
- **THEN** El ESP32 envía la orden serial `'M'` al Arduino Nano, el cual alterna su modo de control y lo refleja en la telemetría.
