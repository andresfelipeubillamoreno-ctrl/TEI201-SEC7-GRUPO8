# Iteración 1 – Cambio de alcance

**Avance asociado:** Avance #1 / inicio del Avance #2

## Situación inicial
La propuesta inicial consideraba medir varios parámetros del agua: pH, conductividad y turbiedad.

## Cambio realizado
Se decidió concentrar el prototipo únicamente en detectar **cambios relativos de turbiedad**.

## Motivo
Reducir el alcance permite priorizar un prototipo Alpha IoT funcional, estable y demostrable dentro del tiempo disponible.

## Resultado
Arquitectura definida:

```
Sensor de turbiedad → ESP32 → procesamiento → pantalla OLED → conectividad Wi-Fi
```

## Aprendizaje
Concentrar el alcance en una sola variable permite dedicar más tiempo a verificar conexiones, mejorar la estabilidad y documentar las pruebas.

## Limitación
El prototipo no mide todos los parámetros de calidad del agua y no certifica potabilidad.

Notas originales: [`notas_cambio_de_alcance.md`](notas_cambio_de_alcance.md)
