## MODIFIED Requirements

### Requirement: Documentación de Conexiones Electrónicas
El sistema SHALL proveer una guía de conexiones electrónica interactiva a través del archivo `schema.html` ubicado en la raíz.

#### Scenario: Visualización del diagrama y componentes
- **WHEN** El usuario abre `schema.html`
- **THEN** Se presenta un diagrama SVG que representa físicamente las placas del Arduino Nano, ESP32, los dos puentes H, los dos módulos de joystick analógicos separados y la batería, etiquetando claramente sus pines de E/S.

#### Scenario: Filtrado interactivo de conexiones
- **WHEN** El usuario selecciona una categoría de conexiones (ej. "Alimentación", "Comunicación Serial")
- **THEN** Los cables correspondientes en el SVG se iluminan mientras que las demás conexiones reducen su opacidad para mejorar la visibilidad.

#### Scenario: Hover cruzado interactivo
- **WHEN** El usuario posiciona el cursor sobre una fila de la tabla o sobre un componente del SVG
- **THEN** El cable asociado en el SVG se ilumina con brillo neón y la fila de la tabla de conexiones correspondiente se resalta visualmente en su lugar sin desplazar la página (no scroll).

#### Scenario: Desplazamiento por clic en SVG
- **WHEN** El usuario hace clic sobre un cable de conexión en el SVG
- **THEN** La tabla de conexiones se desplaza suavemente (scroll) para mostrar la fila de conexión correspondiente y la resalta.
