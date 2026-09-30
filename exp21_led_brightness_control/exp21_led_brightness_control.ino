const int POT = A0;   // Potentiometer middle pin connected to A0
const int LED = 5;    // LED on D5 (PWM-capable pin)

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  int value = analogRead(POT);                    // Read analog value (0 to 1023)
  int brightness = map(value, 0, 1023, 0, 255);   // Convert to PWM range (0 to 255)
  analogWrite(LED, brightness);                   // Set LED brightness
}
