# Librerías

No se usan librerías personalizadas. Todas se instalan desde Arduino IDE.

| Librería | Origen | Uso |
|---|---|---|
| `WiFi.h` | Incluida en el paquete esp32 (Espressif) | Crear la red Wi-Fi "AguaClara" (modo punto de acceso) |
| `WebServer.h` | Incluida en el paquete esp32 | Servir la página web con el estado del agua |
| `Wire.h` | Incluida en el paquete esp32 | Comunicación I2C con la OLED |
| `Adafruit GFX Library` | Library Manager | Gráficos y texto para la pantalla |
| `Adafruit SSD1306` | Library Manager | Controlador de la OLED 128×64 |

**Paquete de placa:** `esp32 by Espressif Systems` (Boards Manager), placa **ESP32 Dev Module**.

Instalación: `Sketch > Include Library > Manage Libraries…` y buscar cada nombre.
