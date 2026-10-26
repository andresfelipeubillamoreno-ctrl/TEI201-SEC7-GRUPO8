Iteración 03: revisión de conexiones
Problema identificado
Las fotografías del montaje no permiten confirmar que las dos resistencias formen correctamente un divisor de voltaje ni que el punto central llegue realmente a GPIO34.

Información confirmada visualmente
El módulo del sensor presenta los terminales:

G: tierra.
A: salida analógica.
D: salida digital.
V: alimentación.
La prueba utiliza la salida analógica A y mantiene D sin conexión.

Riesgo
La salida analógica podría superar el voltaje admisible por la entrada del ESP32 si el divisor está mal conectado o sus resistencias tienen valores incorrectos.

Acción definida
Antes de volver a conectar la salida analógica al ESP32 se debe:

Medir el voltaje entre V y G.
Medir la salida A respecto de G.
Medir el valor real de las resistencias.
Verificar la estructura del divisor de voltaje.
Medir el voltaje en la salida del divisor.
Confirmar continuidad entre el divisor y GPIO34.
Estado
Pendiente de medición con multímetro.

Resultado esperado
Confirmar que la señal cambia entre muestras y que el voltaje aplicado a GPIO34 se encuentra dentro del rango seguro.

Aprendizaje
La presencia física de dos resistencias en la protoboard no garantiza que formen un divisor correctamente conectado.
