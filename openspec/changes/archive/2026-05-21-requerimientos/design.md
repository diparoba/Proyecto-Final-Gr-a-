## Context
El desarrollo conjunto del prototipo por diferentes perfiles requiere definir un mapa claro de pines (pinout) y del protocolo de comunicación de datos para evitar colisiones lógicas en el código del microcontrolador.

## Goals / Non-Goals
**Goals:**
- Documentar las conexiones de pines para los circuitos integrados TB6612FNG y DRV8825.
- Registrar el mapa de pines UART del ESP32 y el LED indicador.
- Acordar el protocolo serial a 9600 bps para el intercambio de datos.

**Non-Goals:**
- Implementar programas o subir firmwares a las placas de desarrollo.

## Decisions
- **Decisión 1: Separación de microcontroladores**: El Arduino Nano gestiona el control de motores y temporizaciones en tiempo real; el ESP32 asume la conectividad de red y la publicación del servidor web.

## Risks / Trade-offs
- *No se identifican riesgos técnicos relevantes al tratarse de una especificación escrita.*
