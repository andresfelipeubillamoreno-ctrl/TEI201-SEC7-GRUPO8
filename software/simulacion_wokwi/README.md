# Agua Clara — Simulación del prototipo Alpha (TEI201 UAI)

**Objetivo:** representar el prototipo de alerta preliminar de turbiedad de agua dirigido a hogares que utilizan pozos y norias en sectores rurales de Colina. Es una alerta preliminar: **no mide potabilidad ni certifica que el agua sea segura para beber**.

## Componentes representados

- **ESP32 DevKit v1**: reemplaza visualmente la placa Circuito UAI personalizada, que también utiliza ESP32.
- **OLED SSD1306, 128 × 64, I2C**: muestra valor RAW y estado de alerta.
- **Potenciómetro**: **simula** la salida analógica del sensor de turbiedad. No es una sonda física real ni reproduce su respuesta óptica.
- **Dos módulos de relé**: representan los relés internos de la placa UAI. En Wokwi son módulos independientes.
- **LED amarillo y rojo con resistencias de 330 Ω**: cargas visuales de los contactos de los relés, **solo en la simulación**. No son parte de los componentes actualmente instalados en el prototipo real.

## Mapa de conexiones

| Elemento | Pin | ESP32 / destino |
|---|---|---|
| Potenciómetro (sensor simulado) | SIG | GPIO34 (ADC1) |
| Potenciómetro | VCC / GND | 3V3 / GND |
| OLED | SDA | GPIO19 |
| OLED | SCL | GPIO18 |
| OLED | VCC / GND | 3V3 / GND |
| Relé aviso | IN | GPIO13 |
| Relé alarma | IN | GPIO15 |
| Relés | VCC / GND | VIN (5 V simulado) / GND |
| Relé aviso | COM → NO | Alimentación de LED amarillo con resistencia de 330 Ω |
| Relé alarma | COM → NO | Alimentación de LED rojo con resistencia de 330 Ω |

> **Importante:** el montaje físico del sensor usa una salida de hasta 4,5 V y dos resistencias de **10 kΩ** como divisor de tensión antes de GPIO34. Esa etapa **no se reproduce** en Wokwi, porque su simulación analógica no permite modelar correctamente resistencias conectadas con componentes analógicos. En Wokwi el potenciómetro entrega directamente una señal simulada compatible con el ADC.

## Cómo ejecutarlo en wokwi.com

1. Abre https://wokwi.com/projects/new/esp32 .
2. En la pestaña `diagram.json`, reemplaza TODO el contenido por el archivo `diagram.json` de este repositorio.
3. En la pestaña `sketch.ino`, reemplaza TODO el contenido por el archivo `sketch.ino`.
4. En `Library Manager`, agrega `Adafruit GFX Library` y `Adafruit SSD1306`, o utiliza el contenido de `libraries.txt` en la pestaña correspondiente.
5. Presiona **Start Simulation** (botón Play verde).
6. **Gira el potenciómetro**: el número RAW cambia en la OLED, el Monitor Serie informa el estado y se activa el relé/LED correspondiente.
7. Selecciona **Save** en Wokwi para crear un proyecto guardado y, si necesitas un enlace público, utiliza **Share**. El archivo ZIP por sí solo no constituye un enlace Wokwi publicado.

## Lógica de demostración (NO calibrada)

| RAW simulado | Estado | Actuación |
|---|---|---|
| >= 2800 | Baja turbiedad aparente | Relés desactivados |
| 1800 a 2799 | Verificar muestra | Relé 1 y LED amarillo |
| < 1800 | Turbiedad elevada | Relé 2 y LED rojo |

Los límites 2800/1800 son **provisionales para la simulación**. No son valores NTU ni se deben presentar como umbrales sanitarios.

## Diferencia frente al prototipo físico

En la placa física Circuito UAI ya funcionan ESP32, OLED, red Wi-Fi local `AguaClara`, página en `192.168.4.1` y dos relés, durante una prueba continua de 5 minutos **con datos simulados**. La sonda real de turbiedad todavía no entregó diferencias confiables entre muestras; sigue en diagnóstico o pendiente de reemplazo.

**Wokwi no expone automáticamente una red Wi-Fi `AguaClara` al teléfono.** El programa de esta carpeta se centra en el diagrama eléctrico, lectura analógica simulada, OLED y actuadores. El sistema web local se comprobó en la placa real con otro sketch. Publicar el proyecto en Wokwi **no equivale** a validar el sensor ni la conectividad en condiciones reales.

## Archivos

- `diagram.json` — componentes y cables de Wokwi.
- `sketch.ino` — código Arduino para la simulación interactiva.
- `libraries.txt` — dependencias de pantalla OLED.
- `README.md` — instrucciones, pinout y alcances.

## Referencias técnicas

- https://docs.wokwi.com/diagram-format
- https://docs.wokwi.com/parts/wokwi-potentiometer
- https://docs.wokwi.com/parts/board-ssd1306
- https://docs.wokwi.com/parts/wokwi-relay-module
- https://docs.wokwi.com/parts/wokwi-resistor
- https://docs.wokwi.com/guides/esp32-wifi
