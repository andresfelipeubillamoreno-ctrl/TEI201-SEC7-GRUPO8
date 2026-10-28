/*
  AGUA CLARA - TEI201 UAI
  Simulador Wokwi del prototipo alpha.

  Wokwi NO dispone de nuestra placa UAI personalizada ni del sensor
  optico especifico: se utiliza ESP32 DevKit v1 y un potenciometro
  como fuente de datos ANALOGICOS SIMULADOS en GPIO34.

  Lo que muestra el proyecto:
  - Entrada analogica variable -> GPIO34
  - Pantalla OLED I2C 128x64 -> SDA GPIO19 / SCL GPIO18
  - Rele 1 (aviso) -> GPIO13
  - Rele 2 (alarma) -> GPIO15
  - LED amarillo / rojo alimentados por los contactos de los reles
    SOLO para hacer visible su activacion en el simulador.

  No es una calibracion real ni determina si el agua es potable.
  Los umbrales se usan exclusivamente para la demostracion.
*/

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

constexpr int PIN_TURBIEDAD = 34;
constexpr int PIN_SDA = 19;
constexpr int PIN_SCL = 18;
constexpr int PIN_RELE_AVISO = 13;
constexpr int PIN_RELE_ALARMA = 15;

// Umbrales SOLO para probar los tres estados en Wokwi.
// Un valor RAW mas alto representa menor turbiedad aparente
// siguiendo la logica del software original de Agua Clara.
constexpr int UMBRAL_BAJA = 2800;
constexpr int UMBRAL_ALTA = 1800;

constexpr uint32_t INTERVALO_MS = 300;
Adafruit_SSD1306 oled(128, 64, &Wire, -1);
bool oledLista = false;
uint32_t ultimoMuestreo = 0;
uint32_t ultimaConsola = 0;
int estadoAnterior = -1;

enum Estado : int {
  BAJA_TURBIEDAD = 0,
  VERIFICAR_MUESTRA = 1,
  TURBIEDAD_ELEVADA = 2
};

Estado calcularEstado(int lectura) {
  if (lectura >= UMBRAL_BAJA) return BAJA_TURBIEDAD;
  if (lectura >= UMBRAL_ALTA) return VERIFICAR_MUESTRA;
  return TURBIEDAD_ELEVADA;
}

const char *nombreEstado(Estado estado) {
  switch (estado) {
    case BAJA_TURBIEDAD: return "BAJA TURBIEDAD";
    case VERIFICAR_MUESTRA: return "VERIFICAR";
    case TURBIEDAD_ELEVADA: return "TURBIEDAD ALTA";
  }
  return "SIN ESTADO";
}

int leerSensorSimulado() {
  // Promedio sencillo para evitar pequenas fluctuaciones del ADC.
  uint32_t suma = 0;
  for (int i = 0; i < 16; i++) {
    suma += analogRead(PIN_TURBIEDAD);
  }
  return static_cast<int>(suma / 16);
}

void activarReles(Estado estado) {
  // Los reles de la placa UAI real se probaron como activos en HIGH.
  // En Wokwi los dos relays se configuran para activar NO con IN=HIGH.
  digitalWrite(PIN_RELE_AVISO, estado == VERIFICAR_MUESTRA ? HIGH : LOW);
  digitalWrite(PIN_RELE_ALARMA, estado == TURBIEDAD_ELEVADA ? HIGH : LOW);
}

void actualizarOLED(int raw, Estado estado) {
  if (!oledLista) return;

  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(2);
  oled.setCursor(0, 0);
  oled.println("AGUA CLARA");
  oled.drawLine(0, 19, 127, 19, SSD1306_WHITE);
  oled.setTextSize(1);
  oled.setCursor(0, 25);
  oled.print("RAW SIM: ");
  oled.println(raw);
  oled.setCursor(0, 39);
  oled.println(nombreEstado(estado));
  oled.setCursor(0, 55);
  oled.print("SOLO SIMULACION");
  oled.display();
}

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);  // 0 a 4095
  pinMode(PIN_TURBIEDAD, INPUT);

  pinMode(PIN_RELE_AVISO, OUTPUT);
  pinMode(PIN_RELE_ALARMA, OUTPUT);
  digitalWrite(PIN_RELE_AVISO, LOW);
  digitalWrite(PIN_RELE_ALARMA, LOW);

  Wire.begin(PIN_SDA, PIN_SCL);
  oledLista = oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  Serial.println();
  Serial.println("===========================================");
  Serial.println(" AGUA CLARA | SIMULADOR WOKWI | TEI201");
  Serial.println("===========================================");
  Serial.println("SENSOR OPTICO REEMPLAZADO POR POTENCIOMETRO");
  Serial.println("Mueve la perilla para cambiar el valor RAW.");
  Serial.println("La simulacion NO certifica potabilidad.");
  Serial.printf("OLED detectada: %s\n", oledLista ? "SI" : "NO");
}

void loop() {
  uint32_t ahora = millis();
  if (ahora - ultimoMuestreo < INTERVALO_MS) return;
  ultimoMuestreo = ahora;

  int raw = leerSensorSimulado();
  Estado estado = calcularEstado(raw);
  activarReles(estado);
  actualizarOLED(raw, estado);

  if (static_cast<int>(estado) != estadoAnterior || ahora - ultimaConsola >= 1500) {
    Serial.printf("SIMULADO | GPIO34 RAW: %d | Estado: %s | R1=%d R2=%d\n",
                  raw, nombreEstado(estado),
                  estado == VERIFICAR_MUESTRA,
                  estado == TURBIEDAD_ELEVADA);
    estadoAnterior = static_cast<int>(estado);
    ultimaConsola = ahora;
  }
}
