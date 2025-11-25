#include <WiFi.h>
#include <HTTPClient.h>


String firebaseURL = "https://iot-project-31da3-default-rtdb.asia-southeast1.firebasedatabase.app/";

#define TRIG 5
#define ECHO 18

long readDist() {
  digitalWrite(TRIG, LOW); delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  return (pulseIn(ECHO, HIGH) * 0.034) / 2;
}

void setup() {
  Serial.begin(115200);
  WiFi.begin("Wokwi-GUEST", "");
  
  
  pinMode(TRIG, OUTPUT); 
  pinMode(ECHO, INPUT);


  while (WiFi.status() != WL_CONNECTED) delay(200);
  Serial.println("WiFi Connected");
}

void loop() {
  long d = readDist();
  Serial.println("Distance: " + String(d) + " cm");

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(firebaseURL + "distance.json");
    http.addHeader("Content-Type", "application/json");
    int code = http.PUT(String(d));
    if(code > 0) Serial.println("Updated Successfully");
    else Serial.println(("failed"));
    http.end();
  }

  delay(20000);
}
