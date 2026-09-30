const int IR = 7;    // IR sensor OUT pin connected to D7
const int LED = 2;   // Warning LED connected to D2

void setup() {
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    // Object detected: flash the LED
    digitalWrite(LED, HIGH);
    delay(150);
    digitalWrite(LED, LOW);
    delay(150);
  } else {
    digitalWrite(LED, LOW);   // No object: LED OFF
  }
}
