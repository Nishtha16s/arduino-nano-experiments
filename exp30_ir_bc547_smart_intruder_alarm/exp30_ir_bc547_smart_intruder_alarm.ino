const int IR = 7;     // IR sensor OUT pin connected to D7
const int LED = 2;    // Warning LED connected to D2
const int BASE = 9;   // BC547 base (through 1k resistor) connected to D9

void setup() {
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BASE, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    digitalWrite(LED, HIGH);    // Object detected: warning LED ON
    digitalWrite(BASE, HIGH);   // Turn ON BC547, buzzer sounds
  } else {
    digitalWrite(LED, LOW);     // No object: LED OFF
    digitalWrite(BASE, LOW);    // Turn OFF BC547, buzzer stops
  }
}
