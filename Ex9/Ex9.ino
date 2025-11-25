#include <WiFi.h>
#include <HTTPClient.h>

String firebaseURL = "https://iot-project-31da3-default-rtdb.asia-southeast1.firebasedatabase.app/";

#define SENSOR_PIN 34

void setup() {
  Serial.begin(115200);

  WiFi.begin("Wokwi-GUEST", "");
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
  }
  Serial.println("WiFi Connected");
}

void loop() {
  int value = analogRead(SENSOR_PIN);
 
  String json = "{\"sensor_type\":\"light\",\"value\":" + String(value) + "}";

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(firebaseURL + "sensor_data.json"); 
    http.addHeader("Content-Type", "application/json");

    int code = http.POST(json);
    Serial.println("Status Code: " + String(code));

    http.end();
  }

  delay(5000); 
}
