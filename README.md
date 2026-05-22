# 🏗️ ¡Bienvenidos al Proyecto Grúa Torre de Control Dual!

Este proyecto es una maqueta interactiva de una **Grúa Torre** real. Está diseñado para que estudiantes y entusiastas de la tecnología aprendan cómo dar vida a la ingeniería y la electrónica de forma divertida.

La grúa se puede manejar de dos formas al mismo tiempo:
1.  **Con palancas manuales (Joysticks):** Sentado frente a la grúa, moviendo las palancas físicas como si fueras un operador real en la cabina.
2.  **Desde tu celular, tablet o computadora (Control Web):** Presionando botones en una pantalla táctil bonita desde cualquier rincón de la habitación.

---

## 🖥️ El Menú de Pantalla (¿Qué pasa al encender la grúa?)

1. Conecta el Cerebro Wi-Fi a tu computadora.
2. Aparecerá un menú con una cuenta regresiva de 5 segundos.
3. Si quieres usar la grúa desde tu celular o computadora:
    * Presiona `1`, o no hagas nada y espera 5 segundos.
    * La grúa buscará tu Wi-Fi y te mostrará una dirección IP.
    * Escribe esa dirección en el navegador de tu celular.
4. Si quieres dejar la grúa lista para editar código:
    * Presiona `2` antes de que acabe la cuenta regresiva.
    * La grúa se quedará en pausa y no conectará ni moverá motores.

---

## 🕹️ Manual de Movimientos: ¿Qué puedes hacer?

Con cualquiera de los dos controles (físico o digital), puedes realizar los siguientes movimientos:

1.  **Carro (Trolley - Adelante y Atrás):** Mueve el carrito rojo a lo largo del brazo horizontal de la grúa para acercar o alejar la carga de la torre.
2.  **Gancho (Hoist - Subir y Bajar):** Sube o baja el gancho naranja con el cable para levantar o soltar objetos.
3.  **Giro (Slew - Rotación):** Gira toda la cabina y el brazo de la grúa en redondo hacia la izquierda o hacia la derecha.

---

## 📊 La Súper Pantalla de Control y Telemetría

Cuando entras desde tu celular o computadora a la dirección IP de la grúa, verás un panel visual premium:
*   **Dibujos Animados en Vivo:** Hay un gráfico interactivo que se mueve exactamente igual que tu grúa física. Si el carrito se mueve o el gancho baja en la realidad, ¡también verás el cambio en tu pantalla!
*   **Regletas de Medición:** Te muestra en centímetros exactos la posición del carrito y la altura del gancho, además de los grados de giro de la grúa.
*   **Monitor de Palancas:** Si alguien está moviendo las palancas físicas de la grúa, verás barras de colores reaccionando en tu pantalla táctil para saber qué está haciendo el operador manual.

---

## 🛡️ Sistemas de Seguridad Integrados (¿Cómo se autoprotege la grúa?)

Para evitar accidentes y golpes, la grúa cuenta con dos reglas de oro automatizadas:

1.  **¡El humano siempre manda primero! (Prioridad Manual)**
    *   Si un usuario está controlando la grúa desde el celular, pero de repente alguien mueve una palanca física (Joystick) en la maqueta, **el control manual toma el mando de inmediato** e ignora las órdenes del celular. Esto sirve para reaccionar rápido ante cualquier peligro.
2.  **Detector de Desconexión (Parada de Emergencia)**
    *   Para evitar que la grúa siga moviéndose si se corta el Wi-Fi o si cierras la ventana del navegador por error, el celular envía señales de "sigo aquí" constantemente. Si la grúa deja de recibir estas señales por más de **medio segundo (500 milisegundos)**, todos los motores se apagan automáticamente.
