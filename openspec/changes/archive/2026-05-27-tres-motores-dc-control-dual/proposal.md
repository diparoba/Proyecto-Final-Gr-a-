## Why

Corregir la arquitectura del prototipo tras reconfirmar la presencia física del carro horizontal (trolley). El sistema utilizará 3 motores DC en total: 1 para el carro, 1 para la elevación (grúa) y 1 para el giro de la cabina. Se conservará la conmutación de modo exclusiva bidireccional y se reactivará la telemetría dinámica del carro tanto física como digitalmente.

## What Changes

- Reestablecer el soporte lógico y la estimación física del movimiento del carro (trolley) en el firmware de Arduino Nano y de la página web.
- Configurar 3 motores DC reales usando 3 canales independientes de los 2 puentes H disponibles.
- Reorganizar la distribución de los pines del Nano para dar soporte a: Joystick Carro (A0), Joystick Elevación (A1), Joystick Giro (A2) y Pulsador de Modo (A3).
- Reactivar el cálculo dinámico de `posCarro` (0 a 30 cm) basado en el tiempo de funcionamiento del motor del carro.

## Capabilities

### New Capabilities
*Ninguna.*

### Modified Capabilities
- `dual-control`: Manejo exclusivo alternado de 3 ejes de control (Carro, Elevación, Giro) y el pulsador de alternancia de modo (A3).
- `telemetry`: Restablecimiento de la telemetría dinámica del carro y cómputo de posiciones virtuales para los 3 ejes de movimiento.
- `web-interface`: Visualización de telemetría dinámica para el carro y la grúa.

## Impact

- **Firmware Arduino (`grua_arduino.ino`)**: Configuración de pines para el motor del carro (D2, D3, D4), motor de giro (D7, D5, D8) y motor de elevación (D10, D6, D11). Lógica de control analógico para 3 ejes de joystick.
- **Hojas de Especificaciones**: Modificaciones en `requirements.md` y `roadmap.md` para reflejar la existencia de los 3 motores reales y el carro.
