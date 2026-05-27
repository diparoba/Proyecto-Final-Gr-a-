## Why

El usuario indica que los joysticks analógicos físicos son dos módulos separados y que sus conexiones a tierra (GND) no se conectan a ninguna parte en el esquema actual. Asimismo, el comportamiento de hover en el SVG hace que la página salte (scroll) constantemente hacia abajo debido a la longitud de la tabla, lo cual resulta molesto. Se requiere separar los joysticks en el diagrama, conectar correctamente todas las líneas GND y configurar el desplazamiento (scroll) automático únicamente al hacer clic en los cables del SVG.

## What Changes

- Rediseñar el diagrama SVG en `schema.html` para separar el componente del joystick en dos módulos distintos (Joystick 1 y Joystick 2).
- Completar las líneas vectoriales de conexión de GND en el SVG para que todos los GNDs (incluidos el Joystick 2 y el Puente H #2) se unan al bus común de tierra.
- Modificar el comportamiento interactivo de la interfaz: el hover sobre los cables SVG o filas de la tabla solo las resaltará visualmente en su lugar, mientras que el desplazamiento suave (scroll) a la posición de la tabla se activará exclusivamente al hacer clic sobre un cable en el SVG.

## Capabilities

### New Capabilities
<!-- Ninguna -->

### Modified Capabilities
- `wiring-guide`: Modificación de las especificaciones del diagrama SVG (componentes de joystick separados y cableado GND correcto) e interactividad de desplazamiento en la tabla (activación de scroll solo por clic).

## Impact

- **Interfaz de Guía (`schema.html`)**: Cambios en el diseño del SVG y en los manejadores de eventos JavaScript.
