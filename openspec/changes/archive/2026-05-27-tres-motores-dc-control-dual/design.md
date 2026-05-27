## Context

Se reconfirma que la maqueta física de la grúa torre cuenta con la funcionalidad del carro horizontal (trolley) y utiliza exactamente 3 motores DC:
1. Motor Carro: 1 motor DC.
2. Motor Elevación (Grúa): 1 motor DC de 300 RPM.
3. Motor Giro: 1 motorreductor DC de 30 RPM.

Esto requiere restablecer las variables de telemetría y control para el carro en el firmware de Arduino y volver a habilitar las animaciones del carro en la interfaz web de manera dinámica.

## Goals / Non-Goals

**Goals:**
- Configurar el control de los 3 motores DC en la placa Arduino Nano usando 3 canales de puente H.
- Asignar pines analógicos en el Nano para los 3 ejes del joystick (A0, A1, A2) y el pulsador de modo (A3).
- Reactivar el cálculo dinámico de `posCarro` (0.0 a 30.0 cm) basado en el tiempo de funcionamiento del motor a una tasa de velocidad supuesta de 5.0 cm/s.
- Habilitar telemetría bidireccional completa para los 3 movimientos y la conmutación de modo.

**Non-Goals:**
- Modificar la estructura visual o el diseño CSS de `index.html`.

## Decisions

- **Decisión 1: Mapeo de Pines**:
  *   **Carro**: Dirección D2/D4, PWM D3.
  *   **Giro**: Dirección D7/D8, PWM D5.
  *   **Elevación**: Dirección D10/D11, PWM D6.
  *   **Joysticks**: A0 (Carro), A1 (Elevación), A2 (Giro), A3 (Pulsador).
- **Decisión 2: Sincronización Bidireccional de Modo**: Mantener el uso del pin `A3` (pulsador físico) y del endpoint `/toggle-mode` (comando serial `'M'`) para alternar el control exclusivo entre web y joystick.
- **Decisión 3: Telemetría Dinámica**: El cálculo físico virtual volverá a actualizar las variables `posCarro`, `posElev` y `posGiro` en tiempo real basándose en el estado de los motores, reflejándose inmediatamente en los gráficos vectoriales SVG del navegador.

## Risks / Trade-offs

- **Riesgo**: El reestablecimiento de la lógica analógica de 3 ejes del joystick podría introducir latencia si las lecturas de los puertos analógicos bloquean el loop.
- **Mitigación**: Pollear y procesar lecturas analógicas únicamente en modo joystick (`controlWebActivo == false`) y de forma secuencial, garantizando fluidez en el resto de tareas de telemetría y comunicación serial.
