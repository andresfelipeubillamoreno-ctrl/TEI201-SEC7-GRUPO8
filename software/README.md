# Software – Agua Clara

Firmware del ESP32 que lee el sensor de turbiedad, clasifica el agua en tres estados y muestra el resultado en una pantalla OLED y en una página web por Wi-Fi.

## Contenido

| Carpeta / archivo | Contenido |
|---|---|
| [`src/agua_clara.ino`](src/agua_clara.ino) | Código principal del ESP32 |
| [`src/explicacion_codigo.md`](src/explicacion_codigo.md) | Explicación de las variables y funciones |
| [`simulacion_wokwi/`](simulacion_wokwi/) | Simulación del prototipo en Wokwi (sensor reemplazado por un potenciómetro) |
| [`librerias/`](librerias/) | Librerías necesarias |
| [`docs/`](docs/) | Manual de uso y solución de problemas |

## Plataforma

- **Placa:** ESP32 Dev Module (Arduino IDE 2.3.x, paquete `esp32` de Espressif)
- **Lenguaje:** C/C++ (Arduino)
- **Librerías:** `WiFi`, `WebServer`, `Wire` (incluidas con el paquete ESP32), `Adafruit GFX Library` y `Adafruit SSD1306`

## Cómo cargar el código

1. Instalar Arduino IDE 2.x.
2. En *Boards Manager*, instalar **esp32 by Espressif Systems**.
3. En *Library Manager*, instalar **Adafruit GFX Library** y **Adafruit SSD1306**.
4. Abrir `src/agua_clara.ino` (Arduino IDE pedirá moverlo a una carpeta con el mismo nombre; aceptar).
5. Seleccionar la placa **ESP32 Dev Module** y el puerto COM correspondiente.
6. Subir el código y abrir el monitor serial a **115200 baud**.

## Funcionamiento

1. Cada ~1 s el ESP32 lee GPIO34 20 veces (cada 10 ms) y calcula el promedio.
2. Clasifica la lectura en **BAJA TURBIEDAD**, **VERIFICAR** o **TURBIEDAD ELEVADA** según `LIMITE_1` y `LIMITE_2`.
3. Muestra la lectura y el estado en la OLED (I2C, SDA = GPIO19, SCL = GPIO18).
4. Crea la red Wi-Fi **AguaClara** y sirve una página web (IP por defecto `192.168.4.1`) que se actualiza cada 3 s y cambia de color según el estado.

## Configuración (constantes al inicio del código)

| Constante | Uso |
|---|---|
| `MODO_SIMULACION` | `true` usa valores simulados para probar OLED y web sin sensor |
| `USAR_RELES` | Activa los relés de la placa (desactivado en la versión actual) |
| `PIN_TURBIDEZ` | Pin analógico del sensor (GPIO34) |
| `LIMITE_1`, `LIMITE_2` | Umbrales RAW entre estados (provisionales, en calibración) |
