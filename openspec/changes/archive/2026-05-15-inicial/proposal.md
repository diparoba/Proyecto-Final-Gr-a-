## Why
Establecer el marco de trabajo inicial y la configuración electrónica básica para una maqueta de grúa torre con control dual. El objetivo es configurar el control de versiones y asentar las bases de hardware y software para el control manual directo.

## What Changes
- Configurar la estructura básica del repositorio.
- Inicializar el firmware principal `grua_arduino.ino` para el actuador (Arduino Nano).
- Inicializar las conexiones de pines para los joysticks analógicos y los drivers de motores.

## Capabilities
### New Capabilities
- `dual-control`: Permite que los joysticks físicos analógicos controlen los tres motores (carro, elevación y giro).

## Impact
- **Hardware**: Establece el esquema de pines para los controladores TB6612FNG y DRV8825 en el Arduino Nano.
- **Software**: Inicializa el bucle básico de Arduino para leer los puertos A0, A1, A2 y accionar los motores.
