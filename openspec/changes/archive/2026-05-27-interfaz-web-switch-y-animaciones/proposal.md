## Why

Añadir un interruptor deslizante visual (toggle switch) en la cabecera de la interfaz web para alternar entre el modo Web y el modo Joystick. Además, corregir la telemetría bidireccional en el Arduino Nano re-mapeando las claves del JSON (`cx`, `cy`, `cz`) para que correspondan exactamente a los ejes analógicos del carro, la elevación y el giro en el depurador visual de la página web.

## What Changes

- Incorporar estilos CSS y estructura HTML para un switch deslizante de modo de control en `index.html`.
- Añadir lógica JavaScript en `index.html` para sincronizar el estado del switch con las actualizaciones de la telemetría y enviar la petición `/toggle-mode` al accionarlo.
- Modificar el orden de los campos seriales impresos por el Arduino Nano en `grua_arduino.ino` para alinear `"cx"`, `"cy"`, `"cz"` con el orden esperado por la página web (Carro, Elevación, Giro) y añadir el estado del botón físico.

## Capabilities

### New Capabilities
*Ninguna.*

### Modified Capabilities
- `telemetry`: Corrección del mapeo de variables de entrada del joystick en el JSON serial.
- `web-interface`: Integración del interruptor deslizante interactivo y vinculación de eventos de control de modo.

## Impact

- **Firmware Arduino (`grua_arduino.ino`)**: Cambios menores en la construcción del string JSON en `Serial.print`.
- **Interfaz Web (`index.html`)**: Inclusión de estilos CSS para el slider y el elemento HTML de tipo checkbox, así como la actualización asíncrona de su estado.
