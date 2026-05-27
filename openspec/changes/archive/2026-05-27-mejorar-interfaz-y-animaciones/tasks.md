## 1. Modificaciones en la Interfaz Web (index.html)

- [x] 1.1 Modificar la cabecera de `index.html` para incluir una etiqueta explicativa del switch toggle ("Mando Web") y mejorar su visibilidad.
- [x] 1.2 Añadir estilos CSS en `index.html` para el estado `:disabled` de los botones `.btn` de control manual (excluyendo el botón de parada de emergencia `.btn-stop`).
- [x] 1.3 Actualizar `updateTelemetry()` en JavaScript para habilitar o deshabilitar dinámicamente los botones de control manual según el valor del modo recibido (`mode === 'WEB'`).
- [x] 1.4 Verificar la correcta inicialización y actualización de las animaciones SVG (Vista Lateral del carro/gancho y Vista Superior del ángulo de giro) a partir de los datos recibidos de la telemetría bidireccional.
