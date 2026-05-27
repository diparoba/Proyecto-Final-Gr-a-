## Why

Reemplazar el motor a pasos de rotación por un motorreductor DC de 30 RPM y configurar un sistema de elevación con 2 motores de 300 RPM controlados de forma independiente. Asimismo, se simplifica el sistema eliminando la funcionalidad del carro (trolley) y se implementa una conmutación explícita bidireccional (física y digital) para habilitar/deshabilitar el control web.

## What Changes

- **BREAKING**: Eliminación del motor a pasos y su driver DRV8825.
- **BREAKING**: Eliminación del soporte físico y lógico del carro (trolley).
- Incorporación de un motorreductor de 30 RPM para el giro de la grúa y 2 motores de 300 RPM para la elevación, requiriendo 3 canales activos a través de 2 puentes H TB6612FNG.
- Permisión de calibración independiente de la velocidad máxima por software en Arduino para cada motor.
- Implementación de conmutación de modo de control (Web vs. Joystick) mediante el pulsador físico del joystick (Pin A3) y un botón interactivo en la web (endpoint `/toggle-mode`).
- Habilitación de telemetría bidireccional continua: el movimiento de los joysticks físicos actualiza en tiempo real las posiciones calculadas en Arduino, reflejándose inmediatamente en los gráficos SVG de la web.

## Capabilities

### New Capabilities
*Ninguna.*

### Modified Capabilities
- `dual-control`: Incorporación del interruptor alternado (físico y digital) para conmutar entre los modos exclusivo Web y exclusivo Joystick.
- `telemetry`: Eliminación del cálculo del carro (ahora fijo), rediseño de la estimación de giro para el motorreductor de 30 RPM, y envío de datos del joystick hacia la web.
- `web-interface`: Visualización de telemetría actualizada a partir de comandos de joystick y envío de conmutación de modo.

## Impact

- **Firmware Arduino (`grua_arduino.ino`)**: Eliminación del código de `AccelStepper`. Configuración de pines de control para 3 motores DC. Nuevas variables de límite de velocidad (`VEL_MAX_xxx`). Lógica de lectura analógica del pulsador de modo.
- **Firmware ESP32 (`main.py`)**: Añadido del endpoint `/toggle-mode` para enviar el carácter `'M'` al Nano.
- **Interfaz Web (`index.html`)**: El código se mantiene sin cambios visuales, pero procesa las actualizaciones de telemetría originadas por joystick y envía eventos de cambio de modo al endpoint `/toggle-mode`.
- **Roadmap (`roadmap.md`)**: El mapa de ruta del proyecto debe ser actualizado.
