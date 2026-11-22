# Iteración 2 – Primeras lecturas del sensor

**Avance asociado:** Avance #2

## Objetivo
Comprobar si el sensor de turbiedad entregaba una señal analógica observable por GPIO34.

## Método
Pruebas exploratorias con agua limpia y agua turbia, registrando valores RAW en el monitor serial (promedio de 20 lecturas, ADC de 12 bits).

## Resultados

| Sesión | Muestra | Lectura |
|---|---|---|
| 1 | Agua limpia | Menos de 70 RAW |
| 1 | Agua turbia | 109,69 RAW promedio |
| 2 | Agua limpia | ≈ 210 RAW |
| 2 | Agua turbia | ≈ 195 RAW |

Datos: [`testing/datos/pruebas_iniciales.csv`](../../testing/datos/pruebas_iniciales.csv) · Captura: [`testing/evidencias/resultados_prueba_inicial_avance2.jpg`](../../testing/evidencias/resultados_prueba_inicial_avance2.jpg)

## Problema encontrado
Los resultados no mantuvieron la misma relación entre agua limpia y turbia: en la sesión 1 la turbia dio más, en la sesión 2 la limpia dio más.

## Posibles causas
- Conexiones eléctricas inestables
- Divisor de voltaje no verificado
- Distinta posición o profundidad de la sonda
- Distinto tiempo de estabilización
- Variaciones en las muestras y en la alimentación

## Decisión
No definir todavía estados de turbiedad baja, media o alta, y revisar las conexiones (→ Iteración 3).

## Aprendizaje
Que dos muestras den lecturas distintas no basta para validar el sensor: el resultado tiene que repetirse bajo condiciones comparables.

Notas originales: [`notas_primeras_lecturas.md`](notas_primeras_lecturas.md)
