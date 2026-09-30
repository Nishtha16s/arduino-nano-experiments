const int POT = A0;   // Potentiometer middle pin connected to A0
const int LED = 2;    // LED connected to D2

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // Convert potentiometer reading (0-1023) into delay time (50-1000 ms)
  int delayTime = map(analogRead(POT), 0, 1023, 50, 1000);

  digitalWrite(LED, HIGH);   // LED ON
  delay(delayTime);

  digitalWrite(LED, LOW);    // LED OFF
  delay(delayTime);
}
