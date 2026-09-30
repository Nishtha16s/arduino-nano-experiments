const int IR = 7;     // IR sensor OUT pin connected to D7
const int LED = 2;    // Alarm LED connected to D2
const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    digitalWrite(LED, HIGH);   // Object detected: LED ON
    tone(BUZZ, 1500);          // Play 1500 Hz alarm tone
  } else {
    digitalWrite(LED, LOW);    // No object: LED OFF
    noTone(BUZZ);              // Stop the buzzer
  }
}
