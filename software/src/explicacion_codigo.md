# Código ESP32 - Agua Clara

Este es el código principal de nuestro prototipo. Como tuvimos varios problemas de inestabilidad con el sensor, el código está pensado para promediar lecturas y evitar que el sistema se quede pegado.

## Librerías Utilizadas
- **WiFi.h y WebServer.h:** Las usamos para que el ESP32 cree su propia red Wi-Fi ("AguaClara") y levante una página web donde ver los datos desde el celular.
- **Wire.h, Adafruit_GFX.h y Adafruit_SSD1306.h:** Son necesarias para controlar la pequeña pantalla OLED y que muestre los textos.

## Variables Clave
- `PIN_TURBIDEZ = 34`: Es el pin analógico donde conectamos el cable de señal del sensor de turbiedad.
- `MODO_SIMULACION` y `USAR_RELES`: Son "interruptores" (true/false) que dejamos en el código. Nos sirvieron mucho para probar la pantalla y el Wi-Fi cuando los cables físicos fallaban.
- `LIMITE_1` y `LIMITE_2`: Son los números de corte (RAW) que deciden cuándo cambiar de estado. Están calibrados con las pruebas del sensor SEN0189: `LIMITE_1 = 2273` (≈2,030 V) y `LIMITE_2 = 2238` (≈2,000 V). Con eso el agua limpia (~2286) da "Baja Turbiedad" y la turbia (~2221) da "Turbiedad Elevada".

## Lógica Principal (Funciones)
- **`leerSensor()`:** En vez de tomar un solo dato (que nos daba saltos súper locos), esta función toma 20 lecturas rápidas y saca un promedio. Esto nos ayudó a estabilizar un poco los números inestables que estábamos recibiendo.
- **`calcularEstado()`:** Toma el promedio del sensor y lo clasifica en tres niveles: "Baja Turbiedad" (verde), "Verificar" (amarillo) o "Turbiedad Elevada" (rojo).
- **`crearPagina()`:** Arma el diseño de la página web que se ve en el celular, cambiando el color de fondo según el estado del agua.
- **`loop()`:** Es el ciclo infinito que mantiene todo funcionando. Cada 1 segundo lee el sensor, actualiza la pantalla OLED y manda los datos nuevos a la web mediante temporizadores (sin usar `delay()` largos que congelen la placa).
