#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wokwi-GUEST";
const char* password = "";

String apiKey = "8DJK7W2EZCMP1XRB";

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(200);
  Serial.println("WiFi Connected");
}

void loop() {
  float temp = dht.readTemperature();
  if (isnan(temp)) return;

  Serial.println("Temperature: " + String(temp));

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = "http://api.thingspeak.com/update?api_key=" +
                  apiKey + "&field1=" + String(temp);

    http.begin(url);
    int code = http.GET();

    if (code > 0) Serial.println("Posted Successfully");
    else Serial.println("Post Failed");

    http.end();
  }

  delay(20000);  // 20 seconds
}
