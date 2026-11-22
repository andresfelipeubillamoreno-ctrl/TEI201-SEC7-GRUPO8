Fuentes, librerías y herramientas utilizadas
Este documento declara las librerías, herramientas, fuentes externas y sistemas de inteligencia artificial utilizados durante el desarrollo del proyecto Agua Clara.

El equipo revisó, adaptó y probó los recursos utilizados antes de incorporarlos al prototipo.

1. Librerías utilizadas
El software del prototipo utiliza las siguientes librerías:

Librería	Versión	Uso en Agua Clara	Desarrollador o fuente
Wire	Incluida en el núcleo de ESP32	Comunicación I2C entre la placa ESP32 y la pantalla OLED	Arduino / núcleo ESP32
Adafruit GFX Library	1.13.0	Escritura de texto, líneas y elementos gráficos en la pantalla OLED	Adafruit Industries
Adafruit SSD1306	2.5.17	Inicialización y control de la pantalla OLED SSD1306 de 128 × 64 píxeles	Adafruit Industries
2. Configuración principal del software
El código implementado en el prototipo utiliza la siguiente configuración:

Parámetro	Configuración
Placa de procesamiento	Placa basada en ESP32
Entrada analógica del sensor	GPIO34
Pin SDA de la pantalla OLED	GPIO19
Pin SCL de la pantalla OLED	GPIO18
Resolución de la pantalla OLED	128 × 64 píxeles
Dirección I2C de la pantalla	0x3C
Resolución del ADC	12 bits
Atenuación del ADC	ADC_11db
Cantidad de lecturas promediadas	30
Intervalo entre lecturas	10 ms
Velocidad del monitor serial	115200 baudios
Umbral provisional	2,02 V
Intervalo principal de actualización	700 ms
El programa realiza 30 mediciones consecutivas mediante analogReadMilliVolts(). Posteriormente, calcula el promedio y convierte el resultado a voltios.

El valor obtenido se presenta mediante:

El monitor serial de Arduino IDE.
Una pantalla OLED de 128 × 64 píxeles.
Una clasificación preliminar de turbidez alta o turbidez baja.
El criterio implementado es:

Voltaje inferior a 2,02 V: turbidez alta.
Voltaje igual o superior a 2,02 V: turbidez baja.
3. Limitaciones del umbral
El umbral de 2,02 V es un valor provisional definido mediante las pruebas realizadas por el equipo con el prototipo.

Este umbral permite diferenciar preliminarmente entre condiciones de mayor y menor turbidez, pero no corresponde a una calibración certificada en unidades nefelométricas de turbidez, NTU.

Agua Clara es un prototipo de alerta preliminar y no un instrumento certificado para determinar la potabilidad del agua.

El dispositivo no detecta microorganismos, sustancias químicas ni todos los parámetros necesarios para determinar si una muestra de agua es segura para el consumo humano.

4. Desarrollo del software
El software fue desarrollado y adaptado específicamente para el proyecto Agua Clara con apoyo de ChatGPT.

El programa integra las siguientes funciones:

Lectura analógica del sensor de turbiedad mediante GPIO34.
Obtención de la señal mediante analogReadMilliVolts().
Promedio de 30 mediciones para reducir fluctuaciones instantáneas.
Conversión y presentación del resultado en voltios.
Comparación de la lectura con un umbral provisional de 2,02 V.
Clasificación preliminar entre turbidez alta y turbidez baja.
Comunicación I2C con una pantalla OLED.
Presentación del resultado en la pantalla OLED.
Presentación del voltaje y del estado mediante el monitor serial.
Detección de errores durante la inicialización de la pantalla OLED.
El código generado o sugerido con apoyo de inteligencia artificial fue revisado, adaptado y probado por el equipo con el circuito físico.

5. Uso de inteligencia artificial
Durante el desarrollo de Agua Clara se utilizaron ChatGPT y Microsoft Copilot como herramientas de apoyo.

Las respuestas y propuestas generadas por estas herramientas no se incorporaron automáticamente. El equipo fue responsable de revisar, adaptar, probar y validar los resultados antes de utilizarlos.

5.1 ChatGPT
ChatGPT se utilizó principalmente como apoyo para crear y desarrollar el software del prototipo.

Su asistencia incluyó:

Generación y estructuración inicial de partes del código.
Desarrollo de la lectura analógica del sensor de turbiedad.
Configuración de la entrada analógica GPIO34 del ESP32.
Implementación del promedio de 30 mediciones.
Conversión y presentación de las lecturas en voltios.
Configuración de la comunicación I2C.
Configuración de la pantalla OLED.
Integración de las librerías Wire, Adafruit GFX y Adafruit SSD1306.
Presentación de la información mediante la pantalla OLED.
Presentación de las lecturas mediante el monitor serial.
Implementación de la comparación con el umbral provisional.
Revisión, explicación y corrección del código durante el desarrollo.
El equipo probó el software en la placa ESP32 y realizó los ajustes necesarios de acuerdo con el comportamiento del prototipo físico.

5.2 Microsoft Copilot
Microsoft Copilot se utilizó como herramienta de apoyo para:

Orientar paso a paso el modelado del encapsulado en Autodesk Fusion.
Revisar las medidas interiores y exteriores del encapsulado.
Diseñar una caja inferior y una tapa superior independientes.
Definir los espesores y las holguras del case.
Crear la abertura para la pantalla OLED.
Crear la abertura para la sonda del sensor de turbiedad.
Exportar la caja y la tapa como archivos STL independientes.
Elaborar y revisar el plano técnico del encapsulado.
Actualizar el README principal del repositorio.
Revisar la estructura y organización del repositorio en GitHub.
Organizar y redactar la documentación técnica del proyecto.
Preparar y revisar este archivo FUENTES.md.
6. Validación y responsabilidad del equipo
El equipo mantuvo la responsabilidad sobre las decisiones técnicas, el montaje electrónico, el software, el diseño 3D y las pruebas del prototipo.

Las actividades realizadas directamente por el equipo incluyeron:

Montaje físico del circuito electrónico.
Conexión del sensor de turbiedad.
Conexión de la pantalla OLED.
Carga y ejecución del código en la placa ESP32.
Pruebas de lectura con el sensor original.
Detección de la inestabilidad del sensor original.
Revisión de las conexiones, los cables y el código.
Adquisición de un sensor de reemplazo en Reini.
Instalación y prueba del sensor nuevo.
Comprobación de la estabilidad del sensor nuevo.
Definición y prueba del umbral provisional.
Revisión del código generado con asistencia de ChatGPT.
Diseño y revisión del encapsulado.
Impresión 3D del case.
Comprobación física del espacio disponible.
Rediseño del case debido a que la primera versión resultó demasiado pequeña.
Validación del nuevo encapsulado con los componentes físicos.
El funcionamiento del sensor nuevo fue verificado mediante pruebas realizadas por el equipo. Sin embargo, estas pruebas no corresponden a una calibración certificada de turbiedad en NTU.

7. Herramientas utilizadas
Herramienta	Aplicación en el proyecto
Arduino IDE	Edición, compilación y carga del código en la placa ESP32
Autodesk Fusion	Modelado 3D del encapsulado y elaboración del plano técnico
Wokwi	Simulación y pruebas preliminares del circuito
GitHub	Control de versiones, organización de archivos y documentación
ChatGPT	Apoyo en la creación y desarrollo del software
Microsoft Copilot	Apoyo en diseño 3D, documentación y revisión del repositorio
8. Hardware y documentación técnica consultada
Durante el proyecto se utilizaron o consultaron los siguientes componentes y recursos técnicos:

Documentación de la placa basada en ESP32.
Documentación de las funciones ADC del ESP32.
Documentación de comunicación I2C mediante la librería Wire.
Documentación de la pantalla OLED SSD1306.
Documentación de Adafruit GFX Library.
Documentación de Adafruit SSD1306.
Información técnica del sensor óptico de turbiedad.
Información del sensor de reemplazo adquirido en Reini.
Material y requisitos entregados en el curso TEI201.
Cuando fue necesario, la documentación técnica se complementó con pruebas físicas realizadas directamente sobre el prototipo.

9. Recursos desarrollados por el equipo
Los siguientes elementos corresponden al trabajo desarrollado, adaptado o validado por el equipo:

Montaje electrónico del prototipo.
Código adaptado para Agua Clara.
Configuración de pines del ESP32.
Umbral provisional de funcionamiento.
Integración del sensor y la pantalla OLED.
Pruebas con el sensor original.
Identificación de la falla del sensor original.
Pruebas con el sensor de reemplazo.
Diseño del encapsulado en Autodesk Fusion.
Rediseño del encapsulado a partir de las dimensiones físicas.
Archivos STL de la caja inferior y la tapa superior.
Plano técnico del encapsulado.
Registro de las iteraciones del proyecto.
Documentación del repositorio.
10. Archivos principales relacionados
Software
software/src/Codigo Proyecto
software/src/Explicacion codigo
software/src/README.md
software/README.md
Diseño 3D
AguaClara_CajaInferior.stl
AguaClara_TapaSuperior.stl
Archivo editable de Autodesk Fusion.
Plano técnico del encapsulado.
Documentación
README.md
FUENTES.md
Archivos disponibles en la carpeta documentacion/.
Evidencias disponibles en la carpeta testing/.
11. Declaración final
ChatGPT y Microsoft Copilot fueron utilizados como herramientas de apoyo durante el desarrollo de Agua Clara.

El equipo revisó y adaptó las respuestas generadas, realizó el montaje físico, ejecutó las pruebas y tomó las decisiones finales de ingeniería.

La incorporación de herramientas de inteligencia artificial se declara de forma transparente para reconocer su participación en el proceso y diferenciarla del trabajo experimental, técnico y de validación realizado por el equipo.
