## Context

El conexionado del prototipo requiere precisión física y una experiencia de usuario cómoda al consultar el esquema interactivo en pantallas pequeñas o grandes. El diseño anterior contenía un único bloque para los joysticks, y dos líneas GND (el retorno del H2 y de los mandos) quedaban aisladas en el aire en el SVG por no extender el bus de tierra horizontal. Además, el auto-scroll durante el hover sobre los cables generaba un comportamiento inestable e invasivo.

## Goals / Non-Goals

**Goals:**
- Separar el bloque de joystick en Joystick 1 y Joystick 2 en el diagrama SVG de `schema.html`.
- Extender el cable de bus de tierra horizontal en el SVG (`y = 295`) de extremo a extremo (desde `x = 5` hasta `x = 760`) para que todas las líneas GND (Arduino, ESP32, H1, H2, Joystick 1 y Joystick 2) se conecten físicamente y de manera visual en un punto común.
- Modificar el comportamiento de `mouseenter` en JavaScript para evitar el auto-scroll al pasar el ratón.
- Añadir un manejador de eventos `click` en los cables del SVG que active el scroll suave y centrado en la fila correspondiente de la tabla de mapeo.

**Non-Goals:**
- Modificar los endpoints del ESP32 o el firmware de Arduino Nano.

## Decisions

### 1. Modificación de los Componentes en el SVG
Separaremos el joystick en dos rectángulos independientes:
- **Joystick 1 (Cabina / Elevación)**: ubicado en `x = 540, y = 320, width = 110, height = 170`. Pines: VCC, GND, VRX (Joy1 X - Giro A0), VRY (Joy1 Y - Elev A1).
- **Joystick 2 (Carro / Modo)**: ubicado en `x = 690, y = 320, width = 110, height = 170`. Pines: VCC, GND, VRX (Joy2 X - Carro A2), SW (Joy Pulsador - A3).

### 2. Corrección del Bus de Tierra (GND Común)
El bus GND se rediseñará como una línea principal horizontal a `y = 295` que cruza todo el esquema:
- El bus irá desde `x = 5` hasta `x = 760` en `y = 295`.
- Todos los componentes conectarán sus líneas de GND verticales hacia este bus.

### 3. Lógica de Interacción JS (Hover vs Clic)
- **Hover (`mouseenter`)**: Únicamente añade la clase `active-connection` en el SVG y resalta la fila en la tabla (`active-row`), pero sin alterar la posición de scroll de la ventana.
- **Clic (`click`)**: Añadido a los elementos de cable SVG. Al hacer clic, ejecuta `targetRow.scrollIntoView({ behavior: 'smooth', block: 'center' })` para enfocar la fila de la tabla lateral.

## Risks / Trade-offs

- Ninguno identificado. Los cambios mejoran la precisión del diagrama y la usabilidad.
