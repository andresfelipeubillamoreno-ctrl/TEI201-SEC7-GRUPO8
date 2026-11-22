# Iteración 3 – Revisión de conexiones y nuevo sensor

**Avance asociado:** Avance #2 → Avance #3 (entrega final)

## Problema identificado
Las fotos del montaje no permitían confirmar que las dos resistencias formaran un divisor de voltaje correcto ni que el punto central llegara a GPIO34. Además, el sensor inicial seguía entregando lecturas inestables (70–210 RAW en la misma muestra).

Terminales del módulo del sensor: **G** (tierra), **A** (salida analógica), **D** (salida digital), **V** (alimentación). Se usa la salida A y D queda sin conectar.

## Riesgo
Si el divisor está mal conectado, la salida analógica puede superar los 3,3 V que admite la entrada del ESP32.

## Acciones
1. Protocolo de verificación con multímetro antes de reconectar: voltaje V–G, salida A–G, valor real de las resistencias, voltaje a la salida del divisor y continuidad hasta GPIO34.
2. **Cambio de sensor** al **DFRobot SEN0189** (Gravity Analog Turbidity Sensor).
3. **Rediseño del encapsulado** en Fusion 360 para el nuevo sensor (ver [`diseno_3d/`](../../diseno_3d/)).
4. Firmware con promedio de 20 lecturas, OLED y página web por Wi-Fi (ver [`software/`](../../software/)).

## Resultados (20-11-2026)

| Muestra | Promedio RAW | Rango RAW | Voltaje promedio |
|---|---|---|---|
| Agua limpia | 2286 | 2284 – 2288 | 2,041 V |
| Agua turbia | 2221 | 2211 – 2241 | 1,986 V |

- La variación dentro de una muestra bajó de ~140 RAW a 4 RAW (agua limpia).
- El agua limpia da más voltaje que la turbia, como corresponde a un sensor óptico.
- Las dos muestras no se superponen.

Datos: [`testing/datos/pruebas_sen0189_2026-11-20.csv`](../../testing/datos/pruebas_sen0189_2026-11-20.csv)

## Aprendizaje
Tener dos resistencias en la protoboard no garantiza que formen un divisor bien conectado: hay que medir. Y cuando un componente entrega datos que no se repiten, cambiarlo puede ahorrar más tiempo que seguir ajustando el código.

## Pendiente
Más ensayos con niveles intermedios y altos de turbiedad, y repeticiones en distintos días, para confirmar los umbrales.

Notas originales: [`notas_revision_conexiones.md`](notas_revision_conexiones.md)
