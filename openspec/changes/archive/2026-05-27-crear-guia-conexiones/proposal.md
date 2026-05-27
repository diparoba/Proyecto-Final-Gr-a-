## Why

Los estudiantes y programadores del proyecto TorreGrúa necesitan una guía clara, visual y detallada de todas las conexiones electrónicas entre el Arduino Nano, el ESP32, los puentes H TB6612FNG, los joysticks analógicos y la alimentación externa de 9V. Esto evitará cortocircuitos y errores de cableado durante el armado físico del prototipo.

## What Changes

- Crear un archivo independiente `schema.html` en la raíz del proyecto.
- Diseñar un esquema de conexiones SVG interactivo en `schema.html` que permita ver de forma individual y conjunta los circuitos eléctricos.
- Integrar una tabla interactiva con filtros rápidos de categorización de conexiones y resaltado en vivo.

## Capabilities

### New Capabilities
- `wiring-guide`: Nueva sección/guía interactiva del cableado electrónico del prototipo de la grúa.

### Modified Capabilities
<!-- Ninguna -->

## Impact

- **Estructura del Proyecto**: Se añade el archivo `schema.html` en la raíz del proyecto.
