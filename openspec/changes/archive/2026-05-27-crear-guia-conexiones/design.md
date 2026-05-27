## Context

Para facilitar el ensamblado físico y la programación del prototipo de la grúa, se requiere una documentación gráfica e interactiva detallada de todo el conexionado eléctrico. El Enfoque 1 seleccionado es un diseño web autónomo (`schema.html`) con un diagrama SVG inline que resalta conexiones en tiempo real de manera bidireccional con una tabla de referencia.

## Goals / Non-Goals

**Goals:**
- Crear el archivo `schema.html` autónomo en la raíz del proyecto.
- Incluir un SVG inline detallado que dibuje los componentes físicos (Arduino Nano, ESP32, dos puentes H TB6612FNG, Joysticks, Batería y conexiones).
- Proveer botones de filtros para aislar circuitos (Alimentación, Comunicación UART, Puentes H, Joystick).
- Implementar hover bidireccional entre la tabla y el SVG para resaltar los cables con brillo neón.

**Non-Goals:**
- Modificar el hardware real del prototipo o re-mapear los pines que ya están configurados en el firmware.
- Depender de librerías JS externas cargadas vía CDN para permitir su funcionamiento offline.

## Decisions

### 1. Paleta de Colores de los Cables (Brillo Neón)
Para diferenciar rápidamente las funciones del circuito en el diagrama, utilizaremos los siguientes colores:
- **Alimentación (VCC 5V y VM 9V)**: Rojo brillante (`#ff1744`)
- **Tierra (GND común)**: Verde brillante (`#00e676`)
- **Comunicación UART (Serial TX/RX)**: Violeta brillante (`#d500f9`)
- **Señales Joystick (Entradas analógicas/digitales)**: Amarillo/Naranja (`#ffd600`)
- **Control de Motores (Puentes H e hilos de motor)**: Celeste/Cyan (`#00e5ff`)

### 2. Mapeo Completo de Conexiones
El circuito implementado se estructurará de la siguiente forma:

- **Alimentación y Tierra**:
  * Batería 9V (+) -> VM de Puente H #1 y Puente H #2
  * Batería 9V (-) -> GND Común (Bus de Tierra)
  * Arduino Nano GND -> GND Común
  * ESP32 GND -> GND Común
  * Puentes H GND -> GND Común
  * Arduino Nano 5V -> VCC de Puente H #1, Puente H #2 y Joystick VCC

- **UART Serial**:
  * Arduino D0 (RX) -> ESP32 GPIO 17 (TX)
  * Arduino D1 (TX) -> ESP32 GPIO 16 (RX)

- **Mando Joystick**:
  * Joystick Eje X1 (Giro) -> Arduino A0
  * Joystick Eje Y1 (Elevación) -> Arduino A1
  * Joystick Eje X2 (Carro) -> Arduino A2
  * Joystick Pulsador (Cambio de Modo) -> Arduino A3

- **Puente H #1 (Carro y Giro)**:
  * Arduino D2 -> AIN1 (Dirección Carro)
  * Arduino D4 -> AIN2 (Dirección Carro)
  * Arduino D3 (PWM) -> PWMA (Velocidad Carro)
  * Arduino D7 -> BIN1 (Dirección Giro)
  * Arduino D8 -> BIN2 (Dirección Giro)
  * Arduino D5 (PWM) -> PWMB (Velocidad Giro)
  * Puente H STBY -> VCC (5V)
  * Salidas AO1/AO2 -> Bornes Motor Carro
  * Salidas BO1/BO2 -> Bornes Motor Giro

- **Puente H #2 (Elevación)**:
  * Arduino D10 -> AIN1 (Dirección Elevación)
  * Arduino D11 -> AIN2 (Dirección Elevación)
  * Arduino D6 (PWM) -> PWMA (Velocidad Elevación)
  * Puente H STBY -> VCC (5V)
  * Salidas AO1/AO2 -> Bornes Motor Elevación

### 3. Mecanismo de Interactividad CSS/JS
- Los cables en el SVG se trazarán usando `<path>` o `<line>` con una clase `wire-line` y atributos `data-connection-id` (ej. `data-connection-id="uart-tx"`).
- Las filas de la tabla de conexiones tendrán la misma propiedad `data-connection-id`.
- Se agregarán eventos `mouseenter` y `mouseleave` en JS para inyectar la clase `active-connection` que aumenta el grosor del cable y le da brillo neón mediante filtros SVG de sombra.

## Risks / Trade-offs

- **[Riesgo]** El trazado del SVG inline puede ser complejo de escribir a mano.
  - **[Mitigación]** Estructuraremos el SVG de forma modular, definiendo primero los bloques de los componentes (rectángulos estilizados con etiquetas de texto) y luego líneas con rutas limpias y coordenadas relativas.
