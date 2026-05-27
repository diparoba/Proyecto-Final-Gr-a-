## ADDED Requirements

### Requirement: Control Mode Selection UI
La página web SHALL proveer un control interactivo (switch) que refleje y permita conmutar el modo de control actual.

#### Scenario: Switch changes mode
- **WHEN** El usuario interactúa con el switch de control en la página web
- **THEN** Se envía una petición HTTP al endpoint `/toggle-mode` para alternar el modo de control.

#### Scenario: Telemetry updates switch state
- **WHEN** Se recibe una actualización de telemetría indicando `"mode": "JOYSTICK"`
- **THEN** El switch de la página web se sitúa en la posición de Joystick, y los controles web quedan inhabilitados en la pantalla.
