const int BUZZ = 8;   // Buzzer connected to D8

// Reusable function: one beep of 'ms' milliseconds, then a short pause
void beep(int ms) {
  tone(BUZZ, 1200);   // Play a 1200 Hz tone
  delay(ms);          // Keep the tone ON for 'ms' milliseconds
  noTone(BUZZ);       // Stop the tone
  delay(120);         // Short pause between beeps
}

void setup() {
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  beep(150);          // Short beep
  beep(150);          // Short beep
  beep(500);          // Long beep
  delay(800);         // Long pause before the pattern repeats
}
