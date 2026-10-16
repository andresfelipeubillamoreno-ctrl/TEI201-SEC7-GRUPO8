Información del Equipo
Integrantes:

Raimundo Liedloff Díaz - Investigación, testing y validación del problema
Benjamín Sotomayor - Diseño del encapsulado y documentación técnica
Andrés Ubilla Moreno - Programación, conectividad e integración IoT
José Tomás Tabja - Hardware, montaje electrónico y pruebas del sensor
ODS seleccionado: ODS 6: Agua limpia y saneamiento

Problema a resolver:
Las familias de sectores rurales de Colina que utilizan pozos o norias pueden carecer de una herramienta doméstica sencilla que les permita detectar y visualizar cambios en la turbiedad del agua que obtienen o almacenan.

Descripción del Proyecto
Agua Clara es un dispositivo portátil de alerta preliminar que utiliza un sensor de turbiedad conectado a una placa ESP32 para detectar cambios relativos en la apariencia óptica de una muestra de agua.

El sistema procesará la lectura del sensor, mostrará el resultado y un estado de alerta en una pantalla OLED, activará un actuador físico y transmitirá los datos mediante Wi-Fi a un celular o computador.

El dispositivo no mide todos los parámetros asociados con la calidad del agua y no certifica potabilidad. Su propósito es advertir cambios de turbiedad y orientar al usuario para que repita la medición o solicite una evaluación complementaria cuando corresponda.

Agua Clara detecta cambios de turbiedad; no certifica potabilidad.

Estado del Proyecto
Versión actual: v3.0-alpha
Última actualización: 16 de octubre de 2026
Estado: Prototipo Alpha IoT en desarrollo
Avance actual
Definición del problema y alcance actualizado
Selección del sensor de turbiedad
Recolección inicial de componentes
Inspección visual preliminar del hardware
Confirmación del modelo y pinout de la placa ESP32-S
Verificación eléctrica del sensor de turbiedad
Primera lectura analógica segura
Integración de pantalla OLED
Integración del relé como actuador
Implementación de conectividad Wi-Fi
Testing integrado durante cinco minutos
Prototipo final

---

##  Estructura del Repositorio
```
├── hardware/          # Circuitos, esquemas y BOM
├── software/          # Código Arduino y librerías
├── diseno_3d/        # Modelos Fusion 360 y renders
├── testing/          # Validación con usuarios
├── documentacion/    # Reportes y presentación
└── iteraciones/      # Historial de versiones
```

---

##  Inicio Rápido

### Requisitos Previos
- Arduino IDE 2.x
- Fusion 360
- [Otras herramientas necesarias]

### Instalación
1. Clonar el repositorio
2. Instalar librerías (ver `software/librerias/`)
3. Cargar código en ESP32/Arduino
4. [Pasos adicionales]

---

##  Checklist de Entrega

### Hardware ✓
- [ ] Esquema del circuito (Fritzing/Wokwi)
- [ ] BOM completo
- [ ] Fotos de alta resolución

### Software ✓
- [ ] Código comentado
- [ ] Librerías documentadas
- [ ] Manual de instalación

### Diseño 3D ✓
- [ ] Archivos Fusion 360 (.f3d) con TODOS los componentes
- [ ] Renders de alta calidad (1+ ángulos)
- [ ] Planos técnicos

### Testing ✓
- [ ] Reporte de testing con usuarios (mín. 5)
- [ ] Evidencias fotográficas/videos
- [ ] Datos cuantitativos

### Documentación ✓
- [ ] Reporte final (máx. 15 páginas)
- [ ] Presentación (10 min)

---


---

##  Licencia
Este proyecto es desarrollado como parte del curso TEI201 - Facultad de Ingenieria y Ciencias - Universidad Adolfo Ibañez
