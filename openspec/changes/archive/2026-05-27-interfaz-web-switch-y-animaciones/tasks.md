## 1. Modificaciones en la Interfaz Web (`index.html`)

- [x] 1.1 Insertar los estilos CSS de tipo slider/switch deslizante (`.switch-container`, `.slider`, etc.) dentro de la sección `<style>`.
- [x] 1.2 Insertar el elemento HTML del checkbox deslizante (`modeSwitch` con trigger `onchange="enviarComando('/toggle-mode')"`) en el header, al lado izquierdo del indicador de conexión.
- [x] 1.3 Actualizar la función `updateTelemetry()` de JavaScript para ajustar el atributo `checked` del checkbox `modeSwitch` basándose en el valor de `"mode"` recibido en la telemetría.

## 2. Modificaciones en el Firmware de Arduino (`grua_arduino.ino`)

- [x] 2.1 Corregir el formato serial de impresión JSON re-mapeando `"cx"` para `valCarro`, `"cy"` para `valElev`, `"cz"` para `valGiro` e incluir `"sw"` para el estado del pulsador.
