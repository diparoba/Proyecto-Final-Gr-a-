# 🗺️ Mapa de Ruta del Proyecto: Grúa Torre de Doble Control

Este documento contiene el historial de desarrollo de nuestra Grúa Torre basado en los commits reales de nuestro repositorio de **GitHub**, además de las metas y expansiones futuras planificadas para el prototipo.

---

## 📈 Hitos de Desarrollo Realizados (Basado en GitHub)

Toda la evolución del proyecto está respaldada por nuestro historial de versiones subidas a la plataforma de desarrollo. A continuación, se detallan las fases completadas:

### 1. 🐣 Hito 1: La Versión Inicial
*   **Identificador de Versión (Commit):** `e0b7cfd Initial commit` (15 de Mayo de 2026)
*   **Logros:** Creación básica de la maqueta y la primera estructura de archivos del sistema. Conexión y pruebas preliminares de los componentes del circuito electrónico básico.

### 2. 📊 Hito 2: El Tablero Digital (Telemetría)
*   **Identificador de Versión (Commit):** `328a88b Telemetría` (20 de Mayo de 2026)
*   **Logros:** Implementación del sistema de envío de datos del Arduino Nano al ESP32. Se logró que la pantalla del celular o computadora pueda mostrar en tiempo real la información exacta del carrito, la altura del gancho y el ángulo de giro de la grúa.

### 3. 📝 Hito 3: Estándares Técnicos
*   **Identificador de Versión (Commit):** `55fa49e requirements.md` (21 de Mayo de 2026)
*   **Logros:** Creación del archivo de requerimientos técnicos detallados (`requirements.md`). Se definió formalmente la arquitectura de hardware, la distribución y mapeo de los pines del circuito electrónico y las directrices técnicas del proyecto.

### 4. 🎛️ Hito 4: Integración del Servidor y Menú Interactivos
*   **Identificadores de Versión (Commits):** `38c5a32 boot.py y main.py` y `b72e53b wifi` (21 de Mayo de 2026)
*   **Logros:** 
    *   Diseño y acoplamiento de la lógica del servidor web asíncrono para servir el panel interactivo `index.html`.
    *   Mejoras en el inicio del Wi-Fi y configuración inicial del menú en la consola de la computadora.

### 5. 🛡️ Hito 5: Acoplamiento Seguro de Código (Cierre de Seguridad)
*   **Logros:**
    *   **Menú terminal inteligente**: Se implementó una cuenta regresiva de 5 segundos en `boot.py` que permite seleccionar cómodamente entre arrancar la grúa normalmente o detenerla de inmediato para programar (REPL libre).
    *   **Cierre controlado por teclado**: Integración del bloque de seguridad `KeyboardInterrupt` en `main.py` para detener el servidor de manera controlada y sin fallos del procesador.

### 6. ⚙️ Hito 6: Migración a Motores DC y Control Exclusivo Alternado (Mayo de 2026)
*   **Logros:**
    *   **Reemplazo del Motor a Pasos**: Sustitución del motor Nema 17 por un motorreductor DC de 30 RPM para el eje de giro, manejado mediante puente H.
    *   **Control de 3 Motores DC**: Configuración final con 3 motores DC reales (Carro, Elevación y Giro) con velocidades ajustables por software en Arduino.
    *   **Conmutación Alternada Bidireccional**: Conmutador de modo exclusivo mediante pulsador físico (A3) e interruptor web (endpoint `/toggle-mode`), permitiendo telemetría en tiempo real de los 3 movimientos desde el joystick hacia la web de forma dinámica.

---

## 🔮 Plan de Expansión Futuro (El Camino por Recorrer)

A continuación, detallamos las fases planificadas para las siguientes clases o versiones de nuestro proyecto escolar de Grúa Torre:

### 🚀 Fase A: Sensores de Choque y Alertas (Corto Plazo)
*   **Meta:** Evitar que los operadores choquen el carro contra los extremos del brazo horizontal o suban demasiado el gancho.
*   **Mejoras de Hardware:** Incorporar sensores de botón físico (finales de carrera) en los topes de la grúa.
*   **Mejoras de Software:** Hacer que el cerebro mecánico (Arduino) detenga de inmediato el motor si se activa uno de estos sensores, ignorando cualquier orden adicional de avance.

### 🎵 Fase B: Alarmas de Sonido (Corto Plazo)
*   **Meta:** Hacer que la grúa emita alertas auditivas según sus movimientos.
*   **Mejoras de Hardware:** Añadir un zumbador (buzzer) en la maqueta.
*   **Mejoras de Software:** Programar sonidos de "bip-bip" mientras la grúa esté girando o moviendo carga pesada para simular el comportamiento de una obra de construcción real.

### 🤖 Fase C: Grabadora de Movimientos - Modo Piloto Automático (Mediano Plazo)
*   **Meta:** Hacer que la grúa sea inteligente y pueda repetir acciones por sí misma.
*   **Mejoras de Software:** Añadir una opción en la interfaz web para "Grabar Ruta". El usuario podrá mover la grúa manualmente y guardar esa trayectoria en memoria para que, con un solo botón, la grúa la reproduzca de forma autónoma (piloto automático).

### 📹 Fase D: Súper Grúa con Sensor de Peso y Ojo Virtual (Largo Plazo)
*   **Meta:** Proteger a la grúa de levantar demasiado peso y ver la carga en directo.
*   **Mejoras de Hardware:** 
    *   Añadir una pequeña cámara inalámbrica en la cabina o el gancho.
    *   Instalar una celda de carga (sensor de peso) para medir los gramos de la carga.
*   **Mejoras de Software:** 
    *   Transmitir el vídeo de la cámara en vivo dentro de la pantalla del celular (`index.html`).
    *   Apagar la elevación de inmediato y activar una alarma roja en la pantalla táctil si el peso de la carga excede el límite recomendado para la maqueta.
