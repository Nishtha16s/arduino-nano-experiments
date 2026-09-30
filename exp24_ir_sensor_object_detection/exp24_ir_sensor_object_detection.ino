const int IR = 7;   // IR sensor OUT pin connected to D7

void setup() {
  pinMode(IR, INPUT);
  Serial.begin(9600);   // Start serial communication at 9600 baud
}

void loop() {
  int state = digitalRead(IR);   // Read the sensor output

  if (state == LOW) {
    Serial.println("Object detected");   // LOW = object in front of sensor
  } else {
    Serial.println("No object");         // HIGH = no object
  }

  delay(200);   // Short delay between readings
}
