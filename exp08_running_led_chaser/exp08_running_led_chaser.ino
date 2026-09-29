const int leds[] = {2, 3, 4, 5, 6};   // LED pins: D2 to D6
const int NUM_LEDS = 5;

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);   // Set each LED pin as output
  }
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i], HIGH);   // Turn LED ON
    delay(120);                    // Keep it ON for 120 ms
    digitalWrite(leds[i], LOW);    // Turn LED OFF
  }
}
