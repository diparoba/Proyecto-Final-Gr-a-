## MODIFIED Requirements

### Requirement: Cómputo del Estado en Tiempo Real
El Arduino Nano SHALL estimar las posiciones y estados de los componentes de la grúa en tiempo real basándose en los tiempos de ejecución de los motores y sus límites físicos.

#### Scenario: Giro position computation
- **WHEN** El motor de rotación de 30 RPM está girando a la derecha (CW)
- **THEN** El ángulo de giro estimado se incrementa a una tasa de 180.0 grados por segundo (basado en 30 RPM) y se normaliza en el rango [0.0, 360.0].

#### Scenario: Static trolley position
- **WHEN** Se computa el estado de telemetría del carro (trolley)
- **THEN** El valor devuelto de la distancia del carro es un valor constante de 15.0 cm, manteniendo el carro estático en la interfaz.

### Requirement: Transmisión Serial JSON
El Arduino Nano SHALL empaquetar todas las lecturas de los sensores, los estados de los motores y las posiciones calculadas en un objeto JSON y transmitirlo por el puerto serial cada 200 ms.

#### Scenario: Telemetry transmission containing active mode
- **WHEN** Se alcanza el intervalo de telemetría de 200 ms
- **THEN** Se imprime una cadena JSON que incluye el estado actual de `"mode"` (siendo `"WEB"` o `"JOYSTICK"`), los valores de joystick, las posiciones estimadas y los estados de dirección de los motores.
