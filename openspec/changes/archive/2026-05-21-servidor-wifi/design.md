## Context
Se requiere asociar el ESP32 a la red local, servir un sitio web de control e intercambiar telemetría y comandos con el Arduino Nano a través del canal serial. El cliente web debe responder de forma fluida y ligera.

## Goals / Non-Goals
**Goals:**
- Servir peticiones asíncronas concurrentes usando MicroPython con `uasyncio`.
- Alojar la interfaz web en un único archivo integrado con hojas de estilo CSS y lógica Fetch de JavaScript.
- Crear gráficos vectoriales (SVG) dinámicos que se muevan según los valores recibidos de los sensores.
- Generar códigos de comandos a través del bus serial según las acciones de botones táctiles en pantalla.

**Non-Goals:**
- Implementar registros históricos de telemetría en bases de datos locales.

## Decisions
- **Decisión 1: Servidor asíncrono**: Usar la biblioteca `uasyncio` para atender simultáneamente peticiones web, lectura del puerto serie y cambio de estado del LED sin bloqueos.
- **Decisión 2: Eventos de puntero**: Utilizar `onpointerdown` y `onpointerup`/`onpointerleave` para garantizar el soporte de pulsación tanto en dispositivos táctiles como en ratón clásico.
- **Decisión 3: Envíos repetitivos**: El cliente web repite el comando cada 250 ms mientras se mantiene pulsado. El Arduino detiene el motor si no recibe señales en un margen de 500 ms por seguridad.

## Risks / Trade-offs
- **Riesgo**: Peticiones de refresco excesivamente frecuentes por parte de múltiples clientes web podrían sobrecargar el procesador del ESP32.
- **Mitigación**: Establecer una tasa máxima de consulta de telemetría a 300 ms por cliente y liberar sockets inmediatamente después del envío.
