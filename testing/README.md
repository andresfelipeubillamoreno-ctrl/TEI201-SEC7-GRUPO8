# Testing y validación

Objetivo: comprobar que el prototipo detecta cambios relativos de turbiedad con lecturas estables y repetibles.

| Carpeta | Contenido |
|---|---|
| [`reportes/`](reportes/) | Reporte de testing (Avance #2 y Avance #3) |
| [`datos/`](datos/) | Datos de las pruebas en CSV |
| [`evidencias/`](evidencias/) | Fotos del sensor en la muestra y del monitor serial |

## Resumen de resultados

| Avance | Sensor | Agua limpia | Agua turbia | Estabilidad |
|---|---|---|---|---|
| #2 | Sensor óptico inicial | < 70 y ≈ 210 RAW (según sesión) | 109,69 y ≈ 195 RAW | No repetible: la relación limpia/turbia se invirtió entre sesiones |
| #3 | DFRobot SEN0189 | 2286 RAW · 2,041 V | 2221 RAW · 1,986 V | Variación de 4 RAW (limpia) y ~30 RAW (turbia); muestras sin superposición |

## Método (Avance #3)

- ESP32 Dev Module, ADC de 12 bits (0–4095) por GPIO34.
- Cada lectura es el promedio de 20 muestras tomadas cada 10 ms, reportada cada ~1 s en el monitor serial.
- Sonda sumergida en la muestra, quieta y a la misma profundidad.

## Limitaciones

- Una sesión con una muestra de cada tipo; faltan niveles intermedios y repeticiones en distintos días.
- Las lecturas son valores RAW/voltaje, **no NTU**, y no determinan potabilidad.
- No se realizaron todavía pruebas con usuarios del grupo objetivo.
