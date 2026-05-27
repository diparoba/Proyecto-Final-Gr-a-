## Context

El panel de control actual tiene un switch toggle en la cabecera, pero no tiene una etiqueta que describa qué hace o en qué estado se encuentra, lo que dificulta al usuario entender y ver su funcionamiento. Adicionalmente, el panel web permite interactuar con los botones de control incluso si la grúa está en modo Joystick, lo que genera confusión. Por último, se debe garantizar la correcta actualización de los gráficos vectoriales (SVG) en base a la telemetría recibida.

## Goals / Non-Goals

**Goals:**
- Añadir etiquetas textuales explicativas dinámicas en el interruptor de modo de control (ej. "Modo Web: Activo" / "Modo Joystick: Activo").
- Deshabilitar visual y funcionalmente los botones de control de la interfaz web cuando el modo de control actual no sea `WEB`.
- Asegurar que la animación lateral del carro/gancho y la animación de giro/slew de cabina respondan de forma correcta a las actualizaciones de telemetría.

**Non-Goals:**
- Modificar el diseño oscuro, la paleta de colores original o las fuentes tipográficas del panel.
- Modificar el firmware del ESP32 o el Arduino Nano, ya que ambos dispositivos ya envían y reciben el estado de modo y telemetría correctamente.

## Decisions

### 1. Etiquetado del Switch
Añadiremos un elemento `<span>` antes del switch toggle para mostrar un texto explicativo como "Control desde Web". Cuando el switch esté desactivado (Modo Joystick), el texto cambiará o el switch indicará visualmente su estado. El texto se actualizará dinámicamente en `updateTelemetry()` según `data.mode` sea `WEB` o `JOYSTICK`.

### 2. Deshabilitar botones de control
Utilizaremos el atributo HTML `disabled` nativo en los botones del panel de control web.
Agregaremos estilos CSS para el estado `:disabled` de los botones:
```css
.btn:disabled {
    opacity: 0.4;
    cursor: not-allowed;
    pointer-events: none;
    box-shadow: none;
}
```
En la función `updateTelemetry()`, si `data.mode === 'WEB'`, seleccionaremos todos los botones con clase `.btn` (excepto el botón de parada de emergencia por seguridad) y les asignaremos `disabled = false`. Si el modo es `JOYSTICK` o `INACTIVO`, les asignaremos `disabled = true`.

### 3. Animaciones SVG
Validar que la animación lateral y de giro use correctamente las fórmulas de mapeo de porcentaje basándose en `data.pCarro`, `data.pElev` y `data.pGiro`.

## Risks / Trade-offs

- **[Riesgo]** El botón de parada de emergencia no debe deshabilitarse nunca por seguridad.
  - **[Mitigación]** Excluiremos el botón `.btn-stop` de la lógica de desactivación para permitir paradas en cualquier momento.
