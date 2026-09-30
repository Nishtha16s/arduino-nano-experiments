const int POT = A0;    // Potentiometer middle pin connected to A0
const int BUZZ = 8;    // Buzzer connected to D8

void setup() {
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  // Convert potentiometer reading (0-1023) into frequency (200-2000 Hz)
  int freq = map(analogRead(POT), 0, 1023, 200, 2000);

  tone(BUZZ, freq);   // Play the selected frequency
  delay(50);          // Short delay before the next reading
}
