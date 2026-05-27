## Context
El Arduino Nano no dispone de codificadores rotativos (encoders) o sensores lineales físicos para medir las posiciones del carro y la altura del gancho. Implementaremos un modelo físico estimado por software basado en la velocidad y el tiempo de activación.

## Goals / Non-Goals
**Goals:**
- Estimar la posición del carro de 0 a 30 cm con una velocidad promedio supuesta de 5.0 cm/s.
- Estimar la altura de elevación de 0 a 50 cm con una velocidad promedio de 8.0 cm/s.
- Traducir los pasos del motor Nema 17 a un ángulo de rotación de 0 a 360 grados.
- Emitir los paquetes JSON por el puerto UART a un intervalo regular de 200 ms.

**Non-Goals:**
- Control por lazo cerrado (ya que no se cuenta con sensores físicos de posición).
- Análisis y renderizado web (que se delegarán al ESP32 en fases posteriores).

## Decisions
- **Decisión 1: Integración temporal**: Usar la función `millis()` para medir el delta de tiempo (`dt`) entre ejecuciones consecutivas del bucle e incrementar/decrementar la posición teórica cuando los motores estén encendidos.
- **Decisión 2: Construcción manual de JSON**: Ensamblar el string JSON de forma directa con impresiones `Serial.print` sucesivas para evitar el consumo excesivo de memoria dinámica del Arduino.

## Risks / Trade-offs
- **Riesgo**: La estimación en lazo abierto acumula error si el motor desliza o encuentra un obstáculo mecánico.
- **Mitigación**: Acotar estrictamente los valores dentro de los límites [0, máximo] y sincronizar cada vez que el carro o gancho alcancen los topes físicos teóricos.
