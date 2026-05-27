## Why
Mejorar la fiabilidad y la experiencia de programación. Los estudiantes necesitan un mecanismo sencillo para pausar la ejecución automática y liberar la consola REPL de MicroPython sin tener que reinstalar firmware. Además, el servidor web debe cerrarse de manera ordenada al cancelar el script para evitar el bloqueo del puerto 80.

## What Changes
- Incorporar un menú de terminal interactivo y no bloqueante en `boot.py` con una cuenta regresiva de 5 segundos.
- Añadir el inicio automático de un Access Point (`ESP32-Grua-Setup`) si la red local Wi-Fi falla tras reintentos.
- Implementar el manejo de la excepción `KeyboardInterrupt` en `main.py` para detener el servidor de forma segura.

## Capabilities
### New Capabilities
- `startup-menu`: Permite interrumpir la inicialización automática para programar y habilita el AP de respaldo.
- `safety-mechanisms`: Controla la interrupción del bucle asíncrono para liberar recursos del procesador.

## Impact
- **Software**: Modifica `boot.py` incorporando el módulo `uselect` para monitorear `sys.stdin`. Edita `main.py` para interceptar `KeyboardInterrupt`.
