const int leds[] = {2, 3, 4};   // LED pins: D2, D3, D4
const int NUM_LEDS = 3;

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);   // Set each LED pin as output
  }
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i], HIGH);   // Turn LED ON
    delay(300);                    // Keep it ON for 300 ms
    digitalWrite(leds[i], LOW);    // Turn LED OFF
  }
}
