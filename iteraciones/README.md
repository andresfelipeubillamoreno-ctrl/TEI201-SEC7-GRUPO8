# Historial de Iteraciones

Esta carpeta documenta cómo evolucionó Agua Clara: qué problema apareció en cada etapa, qué decidimos y qué aprendimos.

| Iteración | Avance | Tema | Decisión / resultado |
|---|---|---|---|
| [1](iteracion_1/) | Avance #1–#2 | Cambio de alcance | Pasamos de medir pH, conductividad y turbiedad a medir **solo turbiedad**. |
| [2](iteracion_2/) | Avance #2 | Primeras lecturas del sensor | Las lecturas no se repetían entre sesiones (70–210 RAW en la misma muestra). No se fijaron umbrales. |
| [3](iteracion_3/) | Avance #2 → #3 | Revisión de conexiones y nuevo sensor | Se revisó el divisor de voltaje y se cambió al sensor **DFRobot SEN0189**, con lecturas estables. |

## Resumen de la evolución

| Aspecto | Iteración 1 | Iteración 2 | Iteración 3 (final) |
|---|---|---|---|
| Variables medidas | pH, conductividad y turbiedad (propuesta) | Turbiedad | Turbiedad |
| Sensor | — | Sensor óptico inicial | DFRobot SEN0189 |
| Estabilidad de lectura | — | 70–210 RAW en la misma muestra | 4 RAW en agua limpia, ~30 RAW en agua turbia |
| Visualización | — | Monitor serial | OLED + página web por Wi-Fi |
| Encapsulado | — | Modelo conceptual (v01) | Case final rediseñado en Fusion 360 |

Cada carpeta contiene un `README.md` con el detalle y las notas originales de la iteración.
