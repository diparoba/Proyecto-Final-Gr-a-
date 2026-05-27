## Why

El usuario reporta que no visualiza claramente el switch toggle en la interfaz web de la grúa. Además, se requiere asegurar que la animación de la vista lateral (carro y gancho) y el giro de orientación (slew) reaccionen dinámicamente y de manera bidireccional basándose en la telemetría enviada en tiempo real.

## What Changes

- Añadir etiquetas de texto explícitas al switch de modo en la cabecera para que sea visible y comprensible.
- Asegurar que los botones de control manual por web se deshabiliten o habiliten visual y funcionalmente cuando se cambia de modo (Web vs. Joystick).
- Verificar e implementar que la animación de la vista lateral y la vista superior de giro funcionen fluidamente con los datos de telemetría bidireccional (`pCarro`, `pElev`, `pGiro`) provistos por el Arduino Nano.

## Capabilities

### New Capabilities
<!-- Ninguna -->

### Modified Capabilities
- `web-interface`: Se añaden requisitos visuales de visibilidad y etiquetado para el selector de modo (switch toggle), deshabilitación de controles web cuando no está activo el modo Web, y la correcta reacción animada de los SVGs a la telemetría en tiempo real.

## Impact

- **Interfaz Web (`index.html`)**: Modificaciones de diseño en la cabecera para incluir la etiqueta del switch, CSS para los estados deshabilitados de los botones y lógica JS mejorada.
