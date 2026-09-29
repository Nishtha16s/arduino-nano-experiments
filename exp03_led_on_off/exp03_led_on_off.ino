const int LED = 2;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(2000);   // LED ON for 2 seconds

  digitalWrite(LED, LOW);
  delay(1000);   // LED OFF for 1 second
}
