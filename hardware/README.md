# Hardware – Agua Clara

## Componentes

| Componente | Función |
|---|---|
| Placa ESP32 (Circuito UAI, ESP32-S) con 2 relés integrados | Lee el sensor, procesa, controla la OLED y crea la red Wi-Fi. Los relés están conectados pero desactivados en el firmware actual. |
| Sensor de turbiedad **DFRobot SEN0189** + módulo | Entrega un voltaje analógico que depende de la luz que atraviesa el agua |
| Pantalla OLED I2C 128×64 (SSD1306) | Muestra la lectura y el estado del agua |
| Divisor de voltaje (2 resistencias) | Baja la salida del sensor para no superar los 3,3 V de GPIO34 |
| Protoboard, cables Dupont, cable Micro-USB | Montaje y alimentación |

Detalle de conexiones: [`componentes_y_conexiones.md`](componentes_y_conexiones.md) · Costos: [`bom/`](bom/)

## Conexiones

| Componente | Pin ESP32 |
|---|---|
| Sensor – salida analógica (A), vía divisor de voltaje | GPIO34 |
| Sensor – alimentación (V) / tierra (G) | Alimentación / GND |
| OLED – SDA | GPIO19 |
| OLED – SCL | GPIO18 |
| Relé 1 / Relé 2 (desactivados) | GPIO13 / GPIO15 |

Las tierras (GND) están unificadas, aislando la potencia de los relés para evitar reinicios de la placa.

## Pasos de ensamblaje

1. Conectar la OLED a GPIO19 (SDA), GPIO18 (SCL), 3,3 V y GND.
2. Armar el divisor de voltaje en la protoboard y **medir con multímetro** que su salida no supere 3,3 V.
3. Conectar la salida A del sensor a la entrada del divisor, y la salida del divisor a GPIO34. La salida D queda sin conectar.
4. Unificar las tierras.
5. Cargar el firmware (ver [`software/`](../software/)) y verificar las lecturas en el monitor serial.
6. Montar todo dentro del encapsulado; solo la sonda queda afuera.

## Fotos

| Montaje (Avance #2) | Nuevo sensor SEN0189 |
|---|---|
| ![Montaje 1](Imagen%201.jpg) | ![Nuevo sensor 1](Imagen%20Nuevo%20Sensor.1.jpeg) |
| ![Montaje 2](imagen%202.jpg) | ![Nuevo sensor 2](Imagen%20Nuevo%20Sensor.2.jpeg) |
| ![Montaje 3](imagen%203.jpg) | ![Nuevo sensor 3](Imagen%20Nuevo%20Sensor.3.jpeg) |
| ![Montaje 4](imagen%204.jpg) | ![Nuevo sensor 4](Imagen%20Nuevo%20Sensor.4.jpeg) |

Más fotos del montaje: [`imagen 5.jpg`](imagen%205.jpg), [`imagen 6.jpg`](imagen%206.jpg), [`imagen 7.jpg`](imagen%207.jpg).

## Precauciones

- ⚠️ No conectar al ESP32 una señal mayor a 3,3 V.
- ⚠️ No conectar cargas de 220 V a los relés.
- ⚠️ No mojar la placa ni el módulo del sensor; solo la sonda entra al agua.

## Solución de problemas

| Problema | Posible causa | Solución |
|---|---|---|
| Lecturas que saltan | Cable flojo o divisor mal armado | Revisar continuidad hasta GPIO34 y medir el divisor |
| La placa se reinicia | Consumo de los relés | Mantener las tierras unificadas y la potencia del relé aislada |
| OLED apagada | SDA/SCL invertidos | Revisar GPIO19 y GPIO18 |
