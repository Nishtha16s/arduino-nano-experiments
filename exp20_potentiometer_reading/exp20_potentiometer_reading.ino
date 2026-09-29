const int POT = A0;   // Potentiometer middle pin connected to A0

void setup() {
  Serial.begin(9600);   // Start serial communication at 9600 baud
}

void loop() {
  int value = analogRead(POT);   // Read analog value (0 to 1023)
  Serial.println(value);         // Print the value on Serial Monitor
  delay(200);                    // Wait 200 ms before next reading
}
