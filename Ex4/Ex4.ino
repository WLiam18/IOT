#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin("Wokwi-GUEST", "");
  while (WiFi.status() != WL_CONNECTED) delay(100);
  Serial.println("WiFi Connected");
}

void loop() {
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();
  if (isnan(temp) || isnan(hum)) return;

  Serial.println("Temp: " + String(temp) + "°C  Hum: " + String(hum));

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://httpbin.org/get?temp=" + String(temp) + "&hum=" + String(hum));
    int code = http.GET();

    if (code > 0) Serial.println("Response: " + http.getString());
    http.end();
  }

  delay(10000);
}
