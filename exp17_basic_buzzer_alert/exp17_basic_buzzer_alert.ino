const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  tone(BUZZ, 1000);   // Play a 1 kHz tone
  delay(300);         // Tone ON for 300 ms
  noTone(BUZZ);       // Stop the tone
  delay(700);         // Silence for 700 ms
}
