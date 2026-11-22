#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const bool MODO_SIMULACION = false;
const bool USAR_RELES = false;

const int PIN_TURBIDEZ = 34;
const int PIN_SDA = 19;
const int PIN_SCL = 18;
const int RELE_1 = 13;
const int RELE_2 = 15;

const int RELE_ACTIVO = HIGH;
const int RELE_INACTIVO = LOW;

// LIMITES PROVISIONALES DE SIMULACION
// TODAVIA NO ESTAN CALIBRADOS
const int LIMITE_1 = 2800;
const int LIMITE_2 = 1800;

// OLED
Adafruit_SSD1306 oled(128, 64, &Wire, -1);
bool oledDisponible = false;

// Wi-Fi local
const char* ssid = "AguaClara";
const char* password = "aguaclara123";
WebServer servidor(80);

// Datos actuales
float lecturaActual = 0;
int estadoActual = 0;
unsigned long ultimaLectura = 0;
unsigned long ultimoCambio = 0;
int pasoSimulacion = 0;

const int valoresSimulados[3] = {
  3200, 2400, 1200
};

// =======================================
// LECTURA DEL SENSOR
// =======================================

float leerSensor() {
  if (MODO_SIMULACION) {
    return valoresSimulados[pasoSimulacion];
  }

  unsigned long suma = 0;

  for (int i = 0; i < 20; i++) {
    suma += analogRead(PIN_TURBIDEZ);
    delay(10);
  }

  return suma / 20.0;
}

// =======================================
// ESTADOS DE TURBIEDAD
// =======================================

int calcularEstado(float valor) {
  if (valor >= LIMITE_1) {
    return 0;
  } else if (valor >= LIMITE_2) {
    return 1;
  } else {
    return 2;
  }
}

String nombreEstado() {
  if (estadoActual == 0) {
    return "BAJA TURBIEDAD";
  }

  if (estadoActual == 1) {
    return "VERIFICAR";
  }

  return "TURBIEDAD ELEVADA";
}

// =======================================
// CONTROL DE RELES
// =======================================

void actualizarReles() {
  if (!USAR_RELES) return;

  digitalWrite(
    RELE_1,
    estadoActual == 1 ? RELE_ACTIVO : RELE_INACTIVO
  );

  digitalWrite(
    RELE_2,
    estadoActual == 2 ? RELE_ACTIVO : RELE_INACTIVO
  );
}

// =======================================
// PANTALLA OLED
// =======================================

void actualizarOLED() {
  if (!oledDisponible) return;

  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);

  oled.setCursor(0, 0);
  oled.println("AGUA CLARA");
  oled.println("----------------");

  oled.print("RAW: ");
  oled.println(lecturaActual, 0);

  oled.println();
  oled.println("Estado:");

  if (estadoActual == 0) {
    oled.println("BAJA TURBIEDAD");
  } else if (estadoActual == 1) {
    oled.println("VERIFICAR");
  } else {
    oled.println("TURBIEDAD ALTA");
  }

  if (MODO_SIMULACION) {
    oled.println("MODO SIMULACION");
  }

  oled.display();
}

// =======================================
// PAGINA WEB
// =======================================

String crearPagina() {
  String color = "verde";

  if (estadoActual == 1) {
    color = "amarillo";
  } else if (estadoActual == 2) {
    color = "rojo";
  }

  String html = R"HTML(
<!DOCTYPE html>
<html lang="es">
<head>
<meta charset="UTF-8">
<meta name="viewport"
      content="width=device-width, initial-scale=1">
<meta http-equiv="refresh" content="3">
<title>Agua Clara</title>
<style>
body {
  font-family: Arial, sans-serif;
  background: #eaf6fb;
  text-align: center;
  padding: 20px;
  color: #163a52;
}
.tarjeta {
  background: white;
  max-width: 400px;
  margin: 30px auto;
  padding: 25px;
  border-radius: 18px;
  box-shadow: 0 4px 15px #0002;
}
.valor {
  font-size: 44px;
  font-weight: bold;
  margin: 20px 0;
}
.estado {
  color: white;
  padding: 15px;
  border-radius: 12px;
  font-weight: bold;
}
.verde { background: #228b54; }
.amarillo { background: #d99a00; }
.rojo { background: #d83b3b; }
.nota {
  font-size: 13px;
  color: #687c89;
  margin-top: 20px;
}
</style>
</head>
<body>
<div class="tarjeta">
  <h1>AGUA CLARA</h1>
  <p>Monitor de turbiedad del agua</p>

  <h3>Lectura RAW</h3>
  <div class="valor">%VALOR%</div>

  <div class="estado %COLOR%">
    %ESTADO%
  </div>

  <p class="nota">%MODO%</p>
  <p class="nota">
    La turbiedad no determina por si sola
    si el agua es potable.
  </p>
</div>
</body>
</html>
)HTML";

  html.replace(
    "%VALOR%",
    String(lecturaActual, 0)
  );

  html.replace(
    "%ESTADO%",
    nombreEstado()
  );

  html.replace(
    "%COLOR%",
    color
  );

  html.replace(
    "%MODO%",
    MODO_SIMULACION ?
    "DEMOSTRACION CON DATOS SIMULADOS" :
    "LECTURA DEL SENSOR"
  );

  return html;
}

// =======================================
// CONFIGURACION INICIAL
// =======================================

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("=== AGUA CLARA ===");

  analogReadResolution(12);

  if (USAR_RELES) {
    digitalWrite(RELE_1, RELE_INACTIVO);
    digitalWrite(RELE_2, RELE_INACTIVO);

    pinMode(RELE_1, OUTPUT);
    pinMode(RELE_2, OUTPUT);
  }

  Wire.begin(PIN_SDA, PIN_SCL);

  // Comprobar presencia de OLED por I2C
  Wire.beginTransmission(0x3C);

  if (Wire.endTransmission() == 0) {
    oledDisponible =
      oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  }

  if (oledDisponible) {
    Serial.println("OLED detectada");
  } else {
    Serial.println("OLED no detectada");
  }

  WiFi.mode(WIFI_AP);

  if (WiFi.softAP(ssid, password)) {
    Serial.print("IP: ");
    Serial.println(WiFi.softAPIP());
  } else {
    Serial.println("Error al crear Wi-Fi");
  }

  servidor.on("/", []() {
    servidor.send(
      200,
      "text/html",
      crearPagina()
    );
  });

  servidor.begin();
  Serial.println("Servidor web iniciado");
}

// =======================================
// BUCLE PRINCIPAL
// =======================================

void loop() {
  servidor.handleClient();

  unsigned long ahora = millis();

  // Cambiar muestra simulada cada 6 segundos
  if (MODO_SIMULACION &&
      ahora - ultimoCambio >= 6000) {

    ultimoCambio = ahora;
    pasoSimulacion = (pasoSimulacion + 1) % 3;
  }

  // Actualizar medicion cada segundo
  if (ahora - ultimaLectura >= 1000) {
    ultimaLectura = ahora;

    lecturaActual = leerSensor();
    estadoActual = calcularEstado(lecturaActual);

    actualizarReles();
    actualizarOLED();

    Serial.print("RAW: ");
    Serial.print(lecturaActual, 0);

    Serial.print(" | Estado: ");
    Serial.println(nombreEstado());
  }
}
