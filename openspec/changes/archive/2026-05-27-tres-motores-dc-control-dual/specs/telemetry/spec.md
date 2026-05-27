## MODIFIED Requirements

### Requirement: Cómputo del Estado en Tiempo Real
El Arduino Nano SHALL estimar las posiciones y estados de los componentes de la grúa en tiempo real basándose en los tiempos de ejecución de los motores y sus límites físicos.

#### Scenario: Dynamic trolley position computation
- **WHEN** El motor del carro (trolley) está en funcionamiento en dirección hacia adelante o hacia atrás
- **THEN** La posición del carro se actualiza a una tasa de 5.0 cm/s entre los límites de 0.0 y 30.0 cm de recorrido.
