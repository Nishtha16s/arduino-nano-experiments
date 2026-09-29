const int LED = 2;   // LED output pin
const int BTN = 3;   // Push button input pin (active-LOW with INPUT_PULLUP)

bool ledState = false;    // Stores the current LED state (OFF at start)
bool lastState = HIGH;    // Stores the previous button reading

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  bool currentState = digitalRead(BTN);

  // Detect a button press: HIGH -> LOW transition
  if (lastState == HIGH && currentState == LOW) {
    ledState = !ledState;            // Reverse the LED state
    digitalWrite(LED, ledState);     // Update the LED
    delay(40);                       // Simple debounce delay
  }

  lastState = currentState;          // Remember the button state
}
