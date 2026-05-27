## Why
Habilitar las capacidades de control inalámbrico. Los usuarios y estudiantes necesitan una interfaz web responsiva, atractiva e intuitiva para mover la grúa y observar las lecturas de los sensores remotamente desde cualquier dispositivo móvil o tablet.

## What Changes
- Crear el módulo `boot.py` para conectar el ESP32 a la red local.
- Crear el módulo `main.py` con el código para alojar el servidor web asíncrono en MicroPython.
- Programar el archivo `index.html` con mandos de control, animaciones SVG en tiempo real (Vista Lateral y Vista Superior) y visualización del depurador analógico.
- Configurar la UART2 en el ESP32 para intercomunicarse con el Arduino Nano.

## Capabilities
### New Capabilities
- `web-interface`: Entrega el panel de control web (`index.html`) y dispone de la API de telemetría y ejecución de movimientos.

## Impact
- **Software**: Incorpora los scripts `boot.py`, `main.py` e `index.html` al ESP32. Actualiza `grua_arduino.ino` para interpretar la entrada UART ('F', 'B', etc.) y frenar los motores ante inactividad.
