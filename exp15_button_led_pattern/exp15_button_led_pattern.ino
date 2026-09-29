const int leds[] = {2, 3, 4};   // LED pins: D2, D3, D4
const int NUM_LEDS = 3;
const int BTN = 7;              // Push button (active-LOW with INPUT_PULLUP)

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BTN) == LOW) {          // Button pressed
    for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(leds[i], HIGH);        // Turn LED ON
      delay(250);                         // Keep it ON for 250 ms
      digitalWrite(leds[i], LOW);         // Turn LED OFF
    }
    while (digitalRead(BTN) == LOW) {}    // Wait until button is released
  }
}
