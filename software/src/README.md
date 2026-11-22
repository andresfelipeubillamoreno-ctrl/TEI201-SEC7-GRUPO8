# Código fuente

| Archivo | Descripción |
|---|---|
| [`agua_clara.ino`](agua_clara.ino) | Código principal: lectura del sensor, estados, OLED, relés (desactivados) y servidor web |
| [`explicacion_codigo.md`](explicacion_codigo.md) | Explicación de librerías, variables y funciones |

## Estructura del código

- `leerSensor()` – promedio de 20 lecturas analógicas de GPIO34
- `calcularEstado()` / `nombreEstado()` – clasificación en tres estados
- `actualizarReles()` – control de relés (solo si `USAR_RELES = true`)
- `actualizarOLED()` – muestra lectura y estado en la pantalla
- `crearPagina()` – arma la página web con color según el estado
- `setup()` – inicia serial, ADC de 12 bits, OLED, red Wi-Fi y servidor
- `loop()` – lee y actualiza cada ~1 s usando temporizadores (sin `delay()` largos)
