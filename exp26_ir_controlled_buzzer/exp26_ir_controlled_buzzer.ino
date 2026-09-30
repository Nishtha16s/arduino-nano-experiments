const int IR = 7;     // IR sensor OUT pin connected to D7
const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(IR, INPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    tone(BUZZ, 1200);   // Object detected: play 1200 Hz tone
  } else {
    noTone(BUZZ);       // No object: stop the tone
  }
}
