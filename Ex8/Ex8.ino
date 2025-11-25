// Ex-8 To develop a simple IoT application that reads light intensity values
// using an LDR sensor and displays them on the Serial Monitor.


const int sensorPin = A0;  
void setup() {
  Serial.begin(9600);
  Serial.println("Light Sensor Reading:");
}

void loop() {
  int sensorValue = analogRead(sensorPin);  
  Serial.print("LDR Value: ");
  Serial.println(sensorValue);  
  delay(1000);  
}
