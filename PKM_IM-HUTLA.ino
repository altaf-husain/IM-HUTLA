#include <WiFi.h>
#include <ESPAsyncWebSrv.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Replace with your network credentials
const char *ssid = "IM-HUTLA";
const char *password = "PKMKC2023";

// Create an instance of the DHT sensor
#define DHT_PIN 14
#define DHT_TYPE DHT22
DHT dht(DHT_PIN, DHT_TYPE);

// Define soil moisture sensor pin
#define SOIL_MOISTURE_PIN 34

// Create an instance of the server
AsyncWebServer server(80);

void setup() {
  // Start Serial Monitor
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize DHT sensor
  dht.begin();

  // Set relay pins as output
  pinMode(RELAY_1_PIN, OUTPUT);
  pinMode(RELAY_2_PIN, OUTPUT);

  // Serve HTML and handle requests
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    String html = "<html><body>";
    html += "<h1>ESP32 Web Server</h1>";
    html += "<p>Temperature: " + String(getTemperature()) + " &#8451;</p>";
    html += "<p>Humidity: " + String(getHumidity()) + " %</p>";
    html += "<p>Soil Moisture: " + String(getSoilMoisture()) + "</p>";
    html += "<form action='/relay' method='post'>";
    html += "<label>Relay 1:</label><input type='checkbox' name='relay1' " + String(digitalRead(RELAY_1_PIN) ? "checked" : "") + " onchange='this.form.submit()'>";
    html += "<label>Relay 2:</label><input type='checkbox' name='relay2' " + String(digitalRead(RELAY_2_PIN) ? "checked" : "") + " onchange='this.form.submit()'>";
    html += "</form>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  server.on("/relay", HTTP_POST, [](AsyncWebServerRequest *request) {
    if (request->hasParam("relay1")) {
      digitalWrite(RELAY_1_PIN, request->getParam("relay1")->value() == "on");
    }
    if (request->hasParam("relay2")) {
      digitalWrite(RELAY_2_PIN, request->getParam("relay2")->value() == "on");
    }
    request->send(200, "text/plain", "OK");
  });

  // Start server
  server.begin();

  // Print the IP address
  Serial.println("HTTP server started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Nothing to do here
}

float getTemperature() {
  return dht.readTemperature();
}

float getHumidity() {
  return dht.readHumidity();
}

int getSoilMoisture() {
  // Read value from soil moisture sensor
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);

  // Map the raw value to a percentage (0 to 100)
  int moisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100);
  moisturePercentage = constrain(moisturePercentage, 0, 100);

  return moisturePercentage;
}
