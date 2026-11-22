# Manual de uso – Agua Clara

## Encendido
1. Conectar el ESP32 por cable Micro-USB a un computador o cargador USB.
2. Esperar unos segundos: la OLED muestra "AGUA CLARA", la lectura RAW y el estado.

## Medir una muestra
1. Llenar un vaso con la muestra de agua.
2. Introducir **solo la sonda** del sensor (nunca el módulo electrónico ni la placa).
3. Esperar ~1 minuto con la sonda quieta, siempre a la misma profundidad.
4. Leer el estado en la OLED o en el celular.

## Ver los datos en el celular
1. Conectarse a la red Wi-Fi **AguaClara** (contraseña `aguaclara123`).
2. Abrir el navegador en `http://192.168.4.1`.
3. La página se actualiza sola cada 3 segundos: verde = baja turbiedad, amarillo = verificar, rojo = turbiedad elevada.

## Apagado
Desconectar el cable USB. Secar la sonda antes de guardarla.

## Solución de problemas

| Problema | Causa probable | Solución |
|---|---|---|
| La OLED no muestra nada | Cables SDA/SCL sueltos o dirección I2C distinta | Revisar GPIO19 (SDA) y GPIO18 (SCL); el monitor serial dice "OLED no detectada" |
| No aparece la red AguaClara | El ESP32 no inició o se reinició | Revisar el monitor serial (115200 baud) y la alimentación |
| Lecturas que saltan mucho | Conexión floja o sonda moviéndose | Revisar cables del sensor y el divisor de voltaje; mantener la sonda quieta |
| Siempre el mismo estado | Umbrales no calibrados | Ajustar `LIMITE_1` y `LIMITE_2` según las pruebas |

⚠️ El resultado es una alerta preliminar de turbiedad: **no certifica que el agua sea potable**.
