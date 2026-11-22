Iteración 02: primeras lecturas del sensor
Objetivo
Comprobar si el sensor de turbiedad entregaba una señal analógica observable mediante GPIO34.

Método inicial
Se realizaron pruebas exploratorias con muestras descritas como agua limpia y agua turbia. Se registraron valores RAW mediante el Monitor Serial.

Resultados
Sesión	Muestra	Lectura
1	Agua limpia	Menos de 70 RAW
1	Agua turbia	109,69 RAW promedio
2	Agua limpia	Aproximadamente 210 RAW
2	Agua turbia	Aproximadamente 195 RAW
Problema encontrado
Los resultados no mantuvieron la misma relación entre agua limpia y agua turbia.

En la primera sesión, el agua turbia produjo una lectura mayor. En la segunda, el agua limpia produjo una lectura mayor.

Interpretación
Las diferencias indican que las pruebas iniciales no son suficientemente repetibles para establecer umbrales de clasificación.

Posibles causas
Conexiones eléctricas inestables.
Divisor de voltaje no verificado.
Diferente posición o profundidad de la sonda.
Diferente tiempo de estabilización.
Variaciones en las muestras.
Cambios en la alimentación.
Decisión
No definir todavía estados de turbiedad baja, media o alta.

Próximo paso
Revisar las conexiones y repetir el ensayo manteniendo constantes las condiciones experimentales.

Aprendizaje
Una lectura diferente entre muestras no es suficiente para validar el sensor. El resultado debe poder repetirse bajo condiciones comparables.
