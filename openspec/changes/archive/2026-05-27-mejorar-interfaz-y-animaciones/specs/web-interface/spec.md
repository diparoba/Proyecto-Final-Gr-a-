## MODIFIED Requirements

### Requirement: Control Mode Selection UI
La página web SHALL proveer un control interactivo (switch) que refleje y permita conmutar el modo de control actual. Debe presentarse con una etiqueta de texto legible que indique claramente "Control Web" o "Modo Manual/Joystick".

#### Scenario: Switch changes mode
- **WHEN** El usuario desliza el interruptor (checkbox) del modo de control en la cabecera del panel web
- **THEN** Se envía una petición HTTP al endpoint `/toggle-mode` para alternar el modo y deshabilitar/habilitar los botones de mando.

#### Scenario: Web buttons disabled when joystick mode is active
- **WHEN** La telemetría recibida indica que el modo actual es "JOYSTICK" o "INACTIVO"
- **THEN** Los botones de mando manual en la página web cambian su opacidad, muestran un cursor no permitido y se deshabilitan para evitar clics accidentales.

### Requirement: Animación SVG en Tiempo Real
El panel web SHALL animar el estado de la grúa física en tiempo real utilizando gráficos vectoriales (SVG).

#### Scenario: Side View movement animation containing dynamic trolley
- **WHEN** Se reciben actualizaciones de telemetría indicando el cambio en la posición de carro y gancho
- **THEN** El SVG de la vista lateral desplaza dinámicamente el carro rojo a lo largo de la pluma y altera el cable y el gancho según los datos reales computados.

#### Scenario: Top View slew animation representing cab rotation
- **WHEN** Se reciben actualizaciones de telemetría indicando la rotación de la cabina y la posición del carro
- **THEN** El SVG de vista superior rota la pluma según el ángulo de giro (`pGiro`) y desplaza el carro rojo a lo largo de la pluma.
