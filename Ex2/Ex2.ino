#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define LDR_PIN A0
#define PIR_PIN 3
#define LED_PIN 13

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
}

void loop() {

  float temp = dht.readTemperature();   // read temperature
  int lightValue = analogRead(LDR_PIN); // read LDR
  int pirValue = digitalRead(PIR_PIN);  // read PIR

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C, Light: ");
  Serial.print(lightValue);
  Serial.print(", PIR: ");
  Serial.println(pirValue);

  // LED turns ON when light is low
  if (lightValue < 300) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(1000);
}
