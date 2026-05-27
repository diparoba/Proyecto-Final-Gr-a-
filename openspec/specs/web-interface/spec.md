## Purpose
Definir el panel de control del cliente web, incluyendo las interacciones del usuario, las animaciones SVG en vivo, los indicadores de depuración de los joysticks analógicos y la comprobación de conectividad.
## Requirements
### Requirement: Panel de Control Responsivo
La página web servida por el ESP32 SHALL proporcionar una interfaz de usuario interactiva para controlar la grúa y supervisar la telemetría.

#### Scenario: Estilo visual y tema
- **WHEN** La página principal `/` se carga en un navegador web
- **THEN** El panel muestra una interfaz con tema oscuro, tarjetas de tipo glassmorphism, tipografía de Google Fonts y un diseño de rejilla adaptativo.

#### Scenario: Eventos de los botones de movimiento
- **WHEN** Se presiona un botón de movimiento (`onpointerdown`)
- **THEN** El cliente inicia un ciclo que envía la petición HTTP correspondiente al ESP32 (por ejemplo, `/forward`) cada 250 ms hasta que se suelta el botón o el cursor sale de él (`onpointerup`, `onpointerleave`), en cuyo momento envía la petición `/stop`.

### Requirement: Animación SVG en Tiempo Real
El panel web SHALL animar el estado de la grúa física en tiempo real utilizando gráficos vectoriales (SVG).

#### Scenario: Side View movement animation containing dynamic trolley
- **WHEN** Se reciben actualizaciones de telemetría indicando el cambio en la posición de carro y gancho
- **THEN** El SVG de la vista lateral desplaza dinámicamente el carro rojo a lo largo de la pluma y altera el cable y el gancho según los datos reales computados.

#### Scenario: Top View slew animation representing cab rotation
- **WHEN** Se reciben actualizaciones de telemetría indicando la rotación de la cabina y la posición del carro
- **THEN** El SVG de vista superior rota la pluma según el ángulo de giro (`pGiro`) y desplaza el carro rojo a lo largo de la pluma.

### Requirement: Depurador de Joysticks en Pantalla
La página web SHALL incluir un visor de depuración que muestre los valores analógicos de los joysticks físicos.

#### Scenario: Mostrar desviación del joystick
- **WHEN** La telemetría reporta los valores analógicos (`"cx"`, `"cy"`, `"cz"`) de los joysticks
- **THEN** El depurador dibuja barras indicadoras bidireccionales centradas en 512, que se extienden a la izquierda o derecha de acuerdo con la desviación física del mando.

### Requirement: Heartbeat y Estado de Conexión
El panel de control SHALL rastrear y mostrar el estado de la conexión de red con el ESP32.

#### Scenario: Ping de telemetría exitoso
- **WHEN** Una petición Fetch al endpoint `/telemetry` se completa correctamente
- **THEN** La etiqueta de conexión cambia a verde ("Conectado") y muestra el tiempo de latencia en milisegundos.

#### Scenario: Pérdida de conexión y recuperación
- **WHEN** Tres peticiones Fetch consecutivas al endpoint `/telemetry` fallan
- **THEN** El indicador de estado cambia a rojo ("Desconectado") y la etiqueta del modo de control cambia a "SIN CONEXIÓN".

### Requirement: Control Mode Selection UI
La página web SHALL proveer un control interactivo (switch) que refleje y permita conmutar el modo de control actual. Debe presentarse con una etiqueta de texto legible que indique claramente "Control Web" o "Modo Manual/Joystick".

#### Scenario: Switch changes mode
- **WHEN** El usuario desliza el interruptor (checkbox) del modo de control en la cabecera del panel web
- **THEN** Se envía una petición HTTP al endpoint `/toggle-mode` para alternar el modo y deshabilitar/habilitar los botones de mando.

#### Scenario: Web buttons disabled when joystick mode is active
- **WHEN** La telemetría recibida indica que el modo actual es "JOYSTICK" o "INACTIVO"
- **THEN** Los botones de mando manual en la página web cambian su opacidad, muestran un cursor no permitido y se deshabilitan para evitar clics accidentales.

