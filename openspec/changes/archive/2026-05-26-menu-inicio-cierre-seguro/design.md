## Context
Al encenderse, MicroPython ejecuta secuencialmente `boot.py` y `main.py`. Si `main.py` contiene un bucle asíncrono infinito, Thonny IDE no logra recuperar el control del puerto REPL para programar o modificar archivos. Es indispensable contar con un temporizador de interrupción.

## Goals / Non-Goals
**Goals:**
- Presentar una ventana de espera de 5 segundos donde pulsar '2' aborte la carga de `main.py` y libere la terminal.
- Continuar automáticamente al modo normal de operación si transcurren los 5 segundos sin entrada.
- Cerrar los sockets TCP del servidor de forma limpia al pulsar Ctrl+C.

**Non-Goals:**
- Ofrecer un asistente de configuración de parámetros de red completo.

## Decisions
- **Decisión 1: Monitoreo no bloqueante de teclado**: Usar el objeto `uselect.poll()` en `sys.stdin` para escuchar la entrada del usuario sin detener la cuenta regresiva en pantalla.
- **Decisión 2: Punto de Acceso fallback**: Si tras 5 intentos no hay conexión Wi-Fi, arrancar en modo AP con IP fija `192.168.4.1` para que los estudiantes se conecten de forma directa sin router.

## Risks / Trade-offs
- **Riesgo**: La lectura del teclado serial por MicroPython podría verse afectada por interferencias del cable serial en ciertos sistemas operativos.
- **Mitigación**: Capturar cualquier excepción de lectura de entrada analógica y forzar el arranque normal para evitar colgar el microcontrolador.
