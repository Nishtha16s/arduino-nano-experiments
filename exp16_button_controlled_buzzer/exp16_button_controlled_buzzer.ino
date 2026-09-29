const int BTN = 3;    // Push button (active-LOW with INPUT_PULLUP)
const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(BTN, INPUT_PULLUP);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  if (digitalRead(BTN) == LOW) {
    tone(BUZZ, 1000);   // Button pressed: play 1 kHz tone
  } else {
    noTone(BUZZ);       // Button released: stop the tone
  }
}
