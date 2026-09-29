const int BTN = 3;    // Push button (active-LOW with INPUT_PULLUP)
const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(BTN, INPUT_PULLUP);
  pinMode(BUZZ, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(A0));   // Floating A0 gives a random seed
}

void loop() {
  delay(random(1000, 3000));    // Random wait: 1 to 3 seconds

  tone(BUZZ, 1500, 200);        // Beep at 1500 Hz for 200 ms
  unsigned long start = millis();   // Timer starts after the beep

  while (digitalRead(BTN) == HIGH) {
    // Wait until the button is pressed (LOW)
  }

  unsigned long t = millis() - start;   // Response time

  Serial.print("Response: ");
  Serial.print(t);
  Serial.println(" ms");

  delay(1500);                  // Pause before the next round
}
