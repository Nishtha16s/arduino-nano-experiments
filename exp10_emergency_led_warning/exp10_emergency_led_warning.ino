const int R = 2;   // Red LED
const int Y = 3;   // Yellow LED
const int G = 4;   // Green LED

void setup() {
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  // State 1: Red and Green ON, Yellow OFF
  digitalWrite(R, HIGH);
  digitalWrite(Y, LOW);
  digitalWrite(G, HIGH);
  delay(200);

  // State 2: Yellow ON, Red and Green OFF
  digitalWrite(R, LOW);
  digitalWrite(Y, HIGH);
  digitalWrite(G, LOW);
  delay(200);
}
