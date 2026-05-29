## Context

La grúa torre tiene un sistema de control dual (Web y Joystick). Cuando está en modo Joystick, el Arduino Nano lee los potenciómetros analógicos (A0, A1, A2) y el conmutador (A3) para mover físicamente los motores de carro, elevación y giro. Sin embargo, no se genera ninguna traza de depuración serie hacia el ESP32 para reflejar estos movimientos manuales en tiempo real. Esto limita el diagnóstico visual inalámbrico de la grúa.

## Goals / Non-Goals

**Goals:**
- Implementar la detección de transiciones de estado para los 3 movimientos de la grúa (Carro, Elevación y Giro) en el firmware del Arduino Nano.
- Transmitir eventos de inicio, cambio de dirección y parada de movimientos en modo Joystick al puerto de depuración inalámbrico (SoftwareSerial `debugSerial`).
- Minimizar el tráfico serie enviando trazas únicamente ante cambios en el estado lógico del movimiento.

**Non-Goals:**
- No se transmitirá telemetría de depuración serie de forma periódica incondicional por SoftwareSerial para evitar saturación de la CPU o del búfer UART (9600 bps).
- No se altera la interfaz web ni la lógica del ESP32.

## Decisions

- **Decisión 1: Registro basado en transiciones de estado**: Guardar los últimos estados de movimiento y comparar en cada ciclo.
  - *Razón*: El puerto SoftwareSerial corre a 9600 baudios. Enviar mensajes en cada iteración del `loop` saturaría por completo la transmisión serial, causando retrasos en el control del motor y congelamiento del microcontrolador.
- **Decisión 2: Mensajes estructurados**: Usar la cabecera `[JOYSTICK] <Componente>: <Estado>` para mantener consistencia con las trazas de depuración del sistema.

## Risks / Trade-offs

- **[Riesgo]**: Ruido en las lecturas analógicas del joystick podría provocar oscilaciones en la zona muerta, generando excesivos mensajes de log.
  - *Mitigación*: Se utiliza la zona muerta definida (`ZONA_MUERTA_MIN = 400`, `ZONA_MUERTA_MAX = 600`) para discriminar el estado lógico ("ADELANTE", "ATRÁS", "DETENIDO"). Al basar el log en cambios del estado lógico consolidado (`estadoCarro`, `estadoElev`, `estadoGiro`), se previene la inestabilidad por ruido analógico.
