## MODIFIED Requirements

### Requirement: Animación SVG en Tiempo Real
El panel web SHALL animar el estado de la grúa física en tiempo real utilizando gráficos vectoriales (SVG).

#### Scenario: Side View movement animation containing dynamic trolley
- **WHEN** Se reciben actualizaciones de telemetría indicando el cambio en la posición de carro y gancho
- **THEN** El SVG de la vista lateral desplaza dinámicamente el carro rojo a lo largo de la pluma y altera el cable y el gancho según los datos reales computados.
