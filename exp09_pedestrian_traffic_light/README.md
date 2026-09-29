# Experiment 09: Pedestrian Detection Traffic Light

Traffic & Interactive Projects | Arduino Nano + IR Sensor

## Objective
To use an IR sensor module to detect a pedestrian or nearby object and automatically change a three-LED traffic signal. Under normal conditions the green LED remains ON. When detection occurs, the system changes to yellow and then red for a short crossing period before returning to green.

## Components Required

| S. No. | Component                        | Quantity    |
|--------|----------------------------------|-------------|
| 1      | Arduino Nano                     | 1           |
| 2      | IR sensor module                 | 1           |
| 3      | Red LED                          | 1           |
| 4      | Yellow LED                       | 1           |
| 5      | Green LED                        | 1           |
| 6      | Current-limiting resistor        | 3           |
| 7      | Breadboard                       | 1           |
| 8      | Jumper Wires                     | As required |
| 9      | USB Cable and computer           | 1           |

## Circuit Connections

| Component      | Arduino Connection          | Purpose                   |
|----------------|-----------------------------|---------------------------|
| IR Sensor VCC  | 5V                          | Power supply              |
| IR Sensor GND  | GND                         | Common ground             |
| IR Sensor OUT  | D7                          | Digital detection input   |
| Red LED        | D2 → resistor → LED anode   | Stop signal               |
| Yellow LED     | D3 → resistor → LED anode   | Warning signal            |
| Green LED      | D4 → resistor → LED anode   | Go / normal signal        |
| LED cathodes   | GND                         | Common ground             |

> Each LED should use its own current-limiting resistor. Connect the LED cathodes to GND. The IR sensor receives 5V power and sends its digital detection signal to D7.

## Important IR Sensor Note
Many IR obstacle sensor modules are **active-LOW**, meaning the OUT pin becomes LOW when an object is detected. Some modules work in the opposite way and output HIGH during detection. Test your module before final operation. If your sensor works opposite to the program, change the condition from `digitalRead(IR) == LOW` to `digitalRead(IR) == HIGH`.

## Build Procedure
1. Connect the IR sensor VCC pin to Arduino 5V and GND to Arduino GND.
2. Connect the IR sensor OUT pin to digital pin D7.
3. Connect the red LED to D2 through a current-limiting resistor.
4. Connect the yellow LED to D3 through a current-limiting resistor.
5. Connect the green LED to D4 through a current-limiting resistor.
6. Connect all LED cathodes to GND.
7. Power the Arduino Nano and verify the circuit connections.
8. Upload the traffic-light program to the Arduino Nano.
9. Keep the sensor area clear and observe the normal green state.
10. Place an object in front of the sensor and observe the yellow state followed by the red state.
11. After the crossing period, observe the system returning to green.

## Arduino Program
See [exp09_pedestrian_traffic_light.ino](exp09_pedestrian_traffic_light.ino)

```cpp
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
```

## Working Principle
The Arduino continuously reads the digital output of the IR sensor connected to D7. During normal operation, the green LED is ON while the yellow and red LEDs are OFF. When the sensor detects an object and produces the expected detection signal, the Arduino turns the green LED OFF and the yellow LED ON for 1 second. It then turns yellow OFF and red ON for 5 seconds to represent the pedestrian crossing period. After this delay, the loop repeats and the green LED is restored.

## Traffic Signal Sequence

| Condition / Step                | Green | Yellow | Red |
|---------------------------------|-------|--------|-----|
| Normal / No Detection           | ON    | OFF    | OFF |
| Object Detected                 | OFF   | ON     | OFF |
| After 1 second                  | OFF   | OFF    | ON  |
| After 5-second crossing period  | ON    | OFF    | OFF |

## Result / Observation
With the sensor area clear, the green LED remains ON. When an object is detected, the green LED turns OFF, the yellow LED remains ON for approximately 1 second, and then the red LED turns ON for approximately 5 seconds. After the crossing period, the system returns to the normal green state.

## Experiment Parameters
- Yellow-light duration: 1000 ms (1 second)
- Red-light / crossing duration: 5000 ms (5 seconds)

These values can be changed in the `delay()` statements to adjust the timing of the traffic sequence.

## Quick Reference

| Pin / Item | Common Use in These Examples              |
|------------|-------------------------------------------|
| D2-D6      | LED digital outputs                       |
| D7         | IR sensor / button input                  |
| D8         | Buzzer                                    |
| A0         | Potentiometer                             |
| D5         | PWM output for LED brightness             |
| D9         | BC547 transistor base in the final project |

## Conclusion
The experiment successfully demonstrates an interactive traffic-light system using an Arduino Nano and an IR sensor. It shows how a digital sensor input can control multiple LED outputs and how timing delays can be used to create a simple pedestrian-crossing sequence.
