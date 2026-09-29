const int LED1 = 2;
const int LED2 = 3;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);   // LED1 ON
  digitalWrite(LED2, LOW);    // LED2 OFF
  delay(500);

  digitalWrite(LED1, LOW);    // LED1 OFF
  digitalWrite(LED2, HIGH);   // LED2 ON
  delay(500);
}
