#include <WiFi.h>
#include <HTTPClient.h>

String firebaseURL = "https://iot-project-31da3-default-rtdb.asia-southeast1.firebasedatabase.app/";

#define SOIL_PIN 34

void setup() {
  Serial.begin(115200);

  WiFi.begin("Wokwi-GUEST", "");
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) delay(300);
  Serial.println("\nWiFi Connected!");
}

void loop() {
  int moisture = analogRead(SOIL_PIN);
  Serial.print("Soil Moisture: ");
  Serial.println(moisture);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = firebaseURL + "soilMoisture.json";

    String json = String(moisture);

    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    int code = http.PUT(json); 

    if (code > 0) Serial.println("Firebase Updated");
    else Serial.println("Failed to Update Firebase");

    http.end();
  }

  delay(5000);  
}
