Agua Clara

Prototipo Alpha IoT desarrollado para TEI201, Taller de Diseño en Ingeniería, de la Universidad Adolfo Ibáñez.

Información del equipo
Integrantes:
Raimundo Liedloff Díaz: montaje electrónico y pruebas del sensor.
Benjamín Sotomayor: investigación, testing y validación del problema.
Andrés Ubilla Moreno: diseño del encapsulado y documentación técnica.
José Tomás Tabja: programación, conectividad e integración IoT.

ODS seleccionado:
ODS 6: Agua limpia y saneamiento.

Problema abordado:
Las familias de sectores rurales de Colina que utilizan pozos o norias pueden carecer de una herramienta doméstica sencilla para detectar y visualizar cambios en la turbiedad del agua que obtienen o almacenan.
Esta necesidad corresponde a una hipótesis del proyecto que debe validarse mediante entrevistas y pruebas con usuarios.

Descripción del proyecto:
Agua Clara es un dispositivo portátil de alerta preliminar que utiliza un sensor de turbiedad conectado a una placa ESP32 para detectar cambios relativos en la apariencia óptica de una muestra de agua.
El sistema procesa la lectura del sensor, muestra el resultado, activa un actuador físico y transmite información mediante Wi-Fi a un celular o computador.
Agua Clara detecta cambios de turbiedad; no certifica potabilidad.
El prototipo no detecta microorganismos, sustancias químicas ni todos los parámetros asociados con la calidad del agua.

Arquitectura del sistema:
Muestra de agua → sensor de turbiedad → ESP32 → procesamiento → actuador → Wi-Fi → celular o computador.

Estado actual:
Versión: v3.0-alpha
Estado: prototipo Alpha IoT en desarrollo
Última actualización: 25 de octubre de 2026.

Actualmente, el prototipo se encuentra en una etapa donde el funcionamiento es inestable y las lecturas del sensor entregan resultados irregulares (por ejemplo, arrojando valores muy distintos para la misma muestra de agua limpia o turbia). Para intentar corregir estos errores y cumplir con la evidencia de testing, hemos implementado los siguientes cambios: Modificamos las conexiones físicas y cambiamos los cables en múltiples ocasiones buscando reducir la inestabilidad. Ajustamos y reescribimos el código de programación varias veces para probar distintas formas de leer el sensor. Realizamos pruebas continuas rearmando el circuito base. 
Aunque el prototipo aún no entrega los resultados óptimos y presenta fallos en su operación, estos problemas están documentados como parte del proceso de aprendizaje del Avance #2 y esperamos estabilizar el sistema para las próximas entregas.

Avances completados:
Definición del problema y alcance.
Selección del sensor de turbiedad.
Recolección inicial de componentes.
Código inicial para lectura analógica.
Modelo 3D conceptual inicial.
Inspección visual del montaje.

Avances en desarrollo:
Confirmar eléctricamente las conexiones del sensor.
Verificar la salida analógica con multímetro.
Confirmar el divisor de voltaje.
Obtener lecturas estables por GPIO34.
Integrar la pantalla OLED.
Integrar el relé como actuador.
Implementar la conectividad Wi-Fi.
Ejecutar una prueba continua de cinco minutos.
Documentar los resultados finales.

Estructura del repositorio:
software: código del ESP32.
hardware: componentes, conexiones y diagramas.
testing: datos y evidencias de las pruebas.
iteraciones: problemas, cambios y mejoras.
diseno_3d: modelo conceptual del encapsulado.
documentacion: material complementario.

Componentes principales:
Placa basada en ESP32 con dos relés integrados.
Sensor óptico de turbiedad.
Módulo electrónico con salida analógica y digital.
Pantalla OLED I2C.
Protoboard.
Resistencias para protección de la entrada analógica.
Cables Dupont.
Cable Micro-USB.
Multímetro.

Advertencias de seguridad:
No conectar una señal superior al rango permitido por el ESP32.
No conectar cargas de 220 V a los relés.
No sumergir el módulo electrónico ni la placa ESP32.
Solo la sección diseñada de la sonda debe entrar en contacto con el agua.
No declarar resultados en NTU sin una calibración válida.
