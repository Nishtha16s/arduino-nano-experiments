const int IR = 7;    // IR sensor OUT pin connected to D7
const int LED = 2;   // LED connected to D2

void setup() {
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    digitalWrite(LED, HIGH);   // Object detected: LED ON
  } else {
    digitalWrite(LED, LOW);    // No object: LED OFF
  }
}
