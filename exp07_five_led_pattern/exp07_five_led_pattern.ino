const int leds[] = {2, 3, 4, 5, 6};   // LED pins: D2 to D6
const int NUM_LEDS = 5;

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);   // Set each LED pin as output
  }
}

void loop() {
  // Forward: D2 -> D6
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i], HIGH);
    delay(150);
    digitalWrite(leds[i], LOW);
  }

  // Backward: D5 -> D3 (end LEDs are not repeated)
  for (int i = NUM_LEDS - 2; i >= 1; i--) {
    digitalWrite(leds[i], HIGH);
    delay(150);
    digitalWrite(leds[i], LOW);
  }
}
