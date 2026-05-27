## Purpose
Definir los comportamientos de seguridad y apagado del sistema de control, incluyendo la pérdida de conexión web y los apagados controlados del servidor.

## Requirements
### Requirement: Temporizador de Seguridad de Control Web
Para evitar movimientos descontrolados si se pierde la conexión, los comandos web SHALL expirar automáticamente.

#### Scenario: Detener motores por inactividad web
- **WHEN** No se recibe ningún carácter de comando desde el ESP32 durante más de 500 ms
- **THEN** El comando web activo se restablece a 'S' (Parar) y todos los motores controlados por la web se detienen.

### Requirement: Apagado Controlado del Servidor Asíncrono
El servidor web del ESP32 SHALL cerrarse limpiamente cuando se interrumpa a través de la consola REPL.

#### Scenario: Manejo de KeyboardInterrupt
- **WHEN** Se activa una interrupción por teclado KeyboardInterrupt (Ctrl+C) en el REPL del ESP32
- **THEN** El bucle de eventos asíncronos se detiene y el servidor se apaga de forma segura mostrando un mensaje limpio en la terminal.
