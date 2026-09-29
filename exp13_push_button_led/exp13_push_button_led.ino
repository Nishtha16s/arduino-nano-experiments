const int LED = 2;   // LED output pin
const int BTN = 3;   // Push button input pin (active-LOW with INPUT_PULLUP)

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BTN) == LOW) {
    digitalWrite(LED, HIGH);   // Button pressed: LED ON
  } else {
    digitalWrite(LED, LOW);    // Button released: LED OFF
  }
}
