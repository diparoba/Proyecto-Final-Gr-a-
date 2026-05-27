## Purpose
Definir el proceso de inicialización de arranque, las opciones de menú en la terminal y el comportamiento de respaldo ante fallos de conexión Wi-Fi configurando el modo Access Point.

## Requirements
### Requirement: Menú de Inicio Interactivo
El ESP32 SHALL mostrar un menú de arranque en el inicio para permitir a los desarrolladores interrumpir la ejecución automática y reprogramar la placa.

#### Scenario: Mostrar cuenta regresiva del menú
- **WHEN** El ESP32 se enciende o se reinicia
- **THEN** Se imprime un menú en la consola de terminal serial con una cuenta regresiva de 5 segundos.

#### Scenario: Iniciar modo de ejecución por timeout o elección
- **WHEN** La cuenta regresiva expira sin entrada del usuario, o el usuario presiona '1'
- **THEN** El ESP32 procede a conectarse a la red Wi-Fi e inicia la ejecución del script principal (`main.py`).

#### Scenario: Detener la ejecución para programación
- **WHEN** El usuario presiona '2' durante la cuenta regresiva
- **THEN** El script de arranque llama a `sys.exit()`, deteniendo la ejecución antes de cargar `main.py` y dejando libre la consola REPL para subir código.

### Requirement: Respaldo de Conexión Wi-Fi Robustecido
El ESP32 SHALL gestionar los fallos de conexión Wi-Fi activando un punto de acceso (Access Point) local como respaldo.

#### Scenario: Cambiar a modo Access Point por fallo de conexión
- **WHEN** El ESP32 no logra conectarse al SSID de la red Wi-Fi configurada (modo STA) después de 5 intentos
- **THEN** Inicializa un punto de acceso local (AP) llamado `ESP32-Grua-Setup` para hospedar la interfaz web en la dirección `http://192.168.4.1`.
