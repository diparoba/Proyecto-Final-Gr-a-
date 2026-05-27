## Context
Diseño de una maqueta a escala de una grúa torre que requiere dos modos de control: control directo por hardware (joysticks físicos) y control remoto (vía web). El sistema actuador está controlado por un Arduino Nano.

## Goals / Non-Goals
**Goals:**
- Conectar 2 motores DC N20 y 1 motor a pasos Nema 17 al Arduino Nano.
- Acoplar un driver TB6612FNG para motores DC y un driver DRV8825 para el motor a pasos.
- Programar rutinas básicas de lectura analógica para tres ejes de joystick.

**Non-Goals:**
- Comunicación con el ESP32 o configuración de red Wi-Fi.
- Cálculos avanzados de telemetría o límites virtuales.

## Decisions
- **Decisión 1: Selección de Driver de Motor**: Usar TB6612FNG para los motores DC gracias a su mayor eficiencia y menor generación de calor frente al L298N.
- **Decisión 2: Control del Motor a Pasos**: Utilizar la biblioteca `AccelStepper` para manejar rampas suaves de aceleración y desaceleración en el giro de la grúa.

## Risks / Trade-offs
- **Riesgo**: La ejecución directa del bucle principal podría bloquear el paso del motor si se introducen demasiadas lecturas analógicas lentas o retardos.
- **Mitigación**: Asegurar una lógica no bloqueante en el `loop()` principal de Arduino y evitar el uso de funciones de retardo `delay()`.
