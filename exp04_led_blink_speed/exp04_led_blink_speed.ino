const int LED = 2;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(500);   // Try 100 for faster, 1000 for slower

  digitalWrite(LED, LOW);
  delay(500);   // Try 100 for faster, 1000 for slower
}
