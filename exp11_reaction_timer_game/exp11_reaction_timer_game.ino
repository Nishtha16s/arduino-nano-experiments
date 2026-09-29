const int LED = 2;   // Reaction signal LED
const int BTN = 3;   // Push button (active-LOW with INPUT_PULLUP)

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(A0));   // Floating A0 gives a random seed
}

void loop() {
  digitalWrite(LED, LOW);
  delay(random(1000, 4000));    // Random wait: 1 to 4 seconds

  digitalWrite(LED, HIGH);      // LED ON: timer starts
  unsigned long start = millis();

  while (digitalRead(BTN) == HIGH) {
    // Wait until the button is pressed (LOW)
  }

  unsigned long reaction = millis() - start;
  digitalWrite(LED, LOW);

  Serial.print("Reaction time: ");
  Serial.print(reaction);
  Serial.println(" ms");

  delay(2000);                  // Pause before the next round
}
