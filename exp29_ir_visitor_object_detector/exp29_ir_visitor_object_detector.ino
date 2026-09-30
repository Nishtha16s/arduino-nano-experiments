const int IR = 7;     // IR sensor OUT pin connected to D7
const int LED = 2;    // Indicator LED connected to D2
const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    digitalWrite(LED, HIGH);    // Object detected: LED ON
    tone(BUZZ, 1200, 150);      // Short 1200 Hz beep for 150 ms
    delay(300);
    digitalWrite(LED, LOW);     // LED OFF
    delay(300);                 // Pause before checking again
  }
}
