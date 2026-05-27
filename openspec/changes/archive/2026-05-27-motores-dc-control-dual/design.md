## Context

El sistema de la grúa torre de control dual se basaba originalmente en un motor a pasos para la rotación (giro) y soporte para un carro horizontal (trolley). La necesidad de adaptación física del prototipo requiere:
1. Eliminar el motor a pasos y sustituirlo por un motorreductor DC de 30 RPM.
2. Eliminar por completo el carro horizontal (trolley), dejando su representación visual web estática en la mitad del brazo.
3. Controlar la elevación mediante 2 motores independientes de 300 RPM con calibración individual de velocidad máxima en Arduino Nano.
4. Implementar un selector de modo de control (Web vs. Joystick) bidireccional y exclusivo (Opción 3 elegida).

## Goals / Non-Goals

**Goals:**
- Configurar 3 canales de control de motor DC usando los pines digitales de Arduino Nano.
- Implementar constantes configurables para velocidad máxima (`VEL_MAX_xxx`) para cada motor.
- Programar el cambio de modo de control exclusivo utilizando el pulsador físico (pin A3) y peticiones web (`/toggle-mode`).
- Asegurar que la telemetría se envíe en ambos modos, permitiendo que la web se mueva al interactuar con los joysticks físicos.

**Non-Goals:**
- Modificar el diseño visual de la interfaz web `index.html` (debe permanecer intacto a nivel de maquetación y hojas de estilo).

## Decisions

- **Decisión 1: Mapeo de Pines del Nano (Enfoque 1)**: Asignar D2, D3(PWM), D4 para Giro; D7, D5(PWM), D8 para Elevación 1; y D10, D6(PWM), D11 para Elevación 2. Esto permite el control independiente de cada motor y deja libres pines analógicos y digitales para futuras expansiones.
- **Decisión 2: Sincronización Bidireccional de Modo**: Utilizar el comando UART `'M'` enviado desde el ESP32 para cambiar el estado en el Nano, y el pin `A3` con pull-up interno en el Nano. Ambos alternan la variable `controlWebActivo`. La telemetría en formato JSON reporta constantemente el modo actual (`"WEB"` o `"JOYSTICK"`) para mantener sincronizada la interfaz web.
- **Decisión 3: Telemetría Estática del Carro**: Seguir enviando `"pCarro": 15.0` en el JSON para evitar que la página web muestre errores de consola o fallos por datos faltantes, manteniendo el diseño intacto.

## Risks / Trade-offs

- **Riesgo 1**: La desincronización de velocidad entre los dos motores de 300 RPM de elevación podría inclinar la carga.
  - *Mitigación*: Se definen constantes separadas (`VEL_MAX_ELEV1` y `VEL_MAX_ELEV2`) para calibrar finamente el comportamiento y balancear mecánicamente la elevación.
- **Riesgo 2**: Ruido eléctrico y rebote en el pulsador del joystick (A3) al alternar el modo.
  - *Mitigación*: Implementar un control de rebotes (*software debounce*) con un retardo no bloqueante de 50 ms antes de conmutar el estado.
