const int leds[] = {2, 3, 4, 5, 6};   // LED pins: D2 to D6
const int NUM_LEDS = 5;
const int BTN = 7;                    // Push button (active-LOW with INPUT_PULLUP)

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(BTN, INPUT_PULLUP);
  randomSeed(analogRead(A0));         // Floating A0 gives a random seed
}

// Show a value from 1 to 5 by turning ON the first n LEDs
void showNumber(int n) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i], LOW);       // Turn all LEDs OFF first
  }
  for (int i = 0; i < n && i < NUM_LEDS; i++) {
    digitalWrite(leds[i], HIGH);      // Turn ON the first n LEDs
  }
}

void loop() {
  if (digitalRead(BTN) == LOW) {      // Button pressed
    delay(30);                        // Debounce delay
    if (digitalRead(BTN) == LOW) {
      int n = random(1, 6);           // Random value from 1 to 5
      showNumber(n);
      while (digitalRead(BTN) == LOW) {}   // Wait until button is released
      delay(200);
    }
  }
}
