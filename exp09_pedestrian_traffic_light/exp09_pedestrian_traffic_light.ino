const int RED    = 2;
const int YELLOW = 3;
const int GREEN  = 4;
const int IR     = 7;   // IR sensor OUT pin

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(IR, INPUT);
}

void loop() {
  // Normal state: green ON
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);

  // Change LOW to HIGH if your IR module works the opposite way
  if (digitalRead(IR) == LOW) {
    // Object detected: green OFF, yellow ON for 1 second
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    delay(1000);

    // Pedestrian crossing: yellow OFF, red ON for 5 seconds
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
    delay(5000);
  }
}
