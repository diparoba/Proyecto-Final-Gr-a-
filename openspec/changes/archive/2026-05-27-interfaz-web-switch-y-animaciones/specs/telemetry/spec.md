## MODIFIED Requirements

### Requirement: Transmisión Serial JSON
El Arduino Nano SHALL empaquetar todas las lecturas de los sensores, los estados de los motores y las posiciones calculadas en un objeto JSON y transmitirlo por el puerto serial cada 200 ms.

#### Scenario: Telemetry transmission containing active mode
- **WHEN** Se alcanza el intervalo de telemetría de 200 ms
- **THEN** Se imprime una cadena JSON donde `"cx"` contiene la lectura del joystick del carro, `"cy"` contiene la lectura del joystick de la elevación y `"cz"` contiene la lectura del joystick de giro.
