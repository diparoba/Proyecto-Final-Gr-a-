## MODIFIED Requirements

### Requirement: Control Mode Selection UI
La página web SHALL proveer un control interactivo (switch) que refleje y permita conmutar el modo de control actual.

#### Scenario: Switch changes mode
- **WHEN** El usuario desliza el interruptor (checkbox) del modo de control en la cabecera del panel web
- **THEN** Se envía una petición HTTP al endpoint `/toggle-mode` para alternar el modo y deshabilitar/habilitar los botones de mando.
