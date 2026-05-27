## 1. Mejoras en el Cargador de Arranque

- [x] 1.1 Programar la cuenta atrás e impresión de menú interactivo en `boot.py`.
- [x] 1.2 Implementar el monitoreo no bloqueante del canal de entrada serial con `uselect.poll`.
- [x] 1.3 Implementar el contador de reintentos Wi-Fi y configuración de AP local fallback.

## 2. Parada Controlada del Servidor

- [x] 2.1 Envolver la inicialización de la tarea en un bloque `try-except KeyboardInterrupt`.
- [x] 2.2 Imprimir un mensaje confirmando el apagado limpio en la terminal al interceptar la señal de parada.
