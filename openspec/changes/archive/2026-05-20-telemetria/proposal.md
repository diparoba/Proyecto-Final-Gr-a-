## Why
Proporcionar visibilidad del estado físico de la grúa en tiempo real. Los operadores deben poder conocer la distancia del carro y la altura del gancho en centímetros, además del ángulo de rotación exacto sin requerir herramientas de medición físicas adicionales.

## What Changes
- Implementar la integración virtual de estados en el Arduino Nano, estimando la posición actual de los componentes basándose en el tiempo de ejecución y velocidad de los motores.
- Programar una rutina de reporte serial en el Nano para emitir los valores de estado estructurados en formato JSON.

## Capabilities
### New Capabilities
- `telemetry`: Calcula la geometría de la grúa (posición del carro, altura del gancho y ángulo de giro) y la envía como JSON por la interfaz serial UART.

## Impact
- **Software**: Modifica `grua_arduino.ino` para medir el diferencial de tiempo (`dt`), actualizar las posiciones calculadas, construir el formato JSON y transmitirlo periódicamente a intervalos de 200 ms.
