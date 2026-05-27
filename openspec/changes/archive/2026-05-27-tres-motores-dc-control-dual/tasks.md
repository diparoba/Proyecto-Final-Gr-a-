## 1. Actualización de Documentación

- [x] 1.1 Modificar el archivo principal `requirements.md` especificando los 3 motores DC reales (Carro en puente H 1 canal A, Giro en puente H 1 canal B, Elevación en puente H 2 canal A) y la lectura analógica de 3 ejes de joystick.
- [x] 1.2 Actualizar el archivo `roadmap.md` ajustando el Hito 6 para detallar el control de los 3 motores DC y la reactivación del carro (trolley).

## 2. Modificaciones del Firmware Arduino (`grua_arduino.ino`)

- [x] 2.1 Reorganizar los pines de los motores en el código (Carro en D2/D3/D4, Giro en D7/D5/D8, Elevación en D10/D6/D11).
- [x] 2.2 Reestablecer constantes de velocidad máxima (`VEL_MAX_CARRO`, `VEL_MAX_GIRO`, `VEL_MAX_ELEV`) en el archivo del firmware.
- [x] 2.3 Adaptar la lectura del joystick físico para procesar los 3 ejes analógicos (Giro en A0, Elevación en A1, Carro en A2).
- [x] 2.4 Habilitar el control del motor del carro mediante comandos web ('F' para adelante, 'B' para atrás, 'S' para parar) a su velocidad máxima.
- [x] 2.5 Reestablecer la integración física virtual en tiempo real de la posición del carro (`posCarro` de 0 a 30 cm) basada en la velocidad aplicada.
- [x] 2.6 Reportar el valor dinámico calculado de `posCarro` en la trama de telemetría serial JSON hacia el ESP32 en lugar de una constante fija.
