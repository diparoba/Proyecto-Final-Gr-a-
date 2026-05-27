## Context

La página web necesita un interruptor interactivo visible en lugar de un indicador textual estático. Adicionalmente, el re-mapeo previo de variables seriales en el Nano alteró las lecturas que la interfaz web procesa para mover las barras del depurador y actualizar las coordenadas de animación, por lo que es necesario restablecer la alineación de las variables `cx` (carro), `cy` (elevación) y `cz` (giro).

## Goals / Non-Goals

**Goals:**
- Insertar un switch deslizante estéticamente agradable e integrado en el diseño oscuro/glassmorphism de `index.html`.
- Corregir el orden de impresión JSON en el firmware de Arduino para alinear los datos de telemetría del joystick con los del depurador en la web.
- Sincronizar el estado del interruptor web para que se mueva automáticamente si el modo cambia a través del pulsador físico (A3).

**Non-Goals:**
- Cambiar la maquetación principal o alterar la paleta de colores de la interfaz web.

## Decisions

- **Decisión 1: Colocación del Switch**: Ubicar el interruptor deslizante en la cabecera (`<header>`) justo al lado izquierdo del estado de conexión para aprovechar el espacio existente sin mover la cuadrícula principal de tarjetas.
- **Decisión 2: Re-mapeo de JSON**: Configurar el Arduino Nano para emitir `"cx": valCarro`, `"cy": valElev`, y `"cz": valGiro`. El estado del pulsador de modo se transmitirá bajo un nuevo campo opcional `"sw"`.

## Risks / Trade-offs

- **Riesgo**: El re-renderizado periódico del switch podría provocar un parpadeo visual si se sobrescribe su estado mientras el usuario lo desliza.
- **Mitigación**: El switch solo se actualizará desde la telemetría si el usuario no está interactuando activamente con él, o sincronizándolo de forma pasiva a través del valor de modo establecido.
