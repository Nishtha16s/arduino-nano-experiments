# Experiment 10: Emergency LED Warning Pattern

Traffic & Interactive Projects | Arduino Nano | Coordinated LED Outputs

## Objective
To create a visual emergency or warning pattern using three LEDs connected to an Arduino Nano. The experiment demonstrates coordinated digital outputs and timing by making the LEDs flash in an alternating pattern.

## Components Required

| S. No. | Component                  | Quantity    |
|--------|----------------------------|-------------|
| 1      | Arduino Nano               | 1           |
| 2      | LED                        | 3           |
| 3      | Current-limiting resistor  | 3           |
| 4      | Breadboard                 | 1           |
| 5      | Jumper Wires               | As required |
| 6      | USB Cable and computer     | 1           |

## Circuit Connections

| LED / Signal    | Arduino Connection          | Purpose           |
|-----------------|-----------------------------|-------------------|
| Red LED (R)     | D2 → resistor → LED anode   | Warning output 1  |
| Yellow LED (Y)  | D3 → resistor → LED anode   | Warning output 2  |
| Green LED (G)   | D4 → resistor → LED anode   | Warning output 3  |
| LED cathodes    | GND                         | Common ground     |

> Use one current-limiting resistor for each LED. Connect each LED anode to its assigned Arduino pin through the resistor and connect all LED cathodes to GND.

## Build Procedure
1. Place the three LEDs on the breadboard.
2. Connect the red LED through a resistor to D2.
3. Connect the yellow LED through a resistor to D3.
4. Connect the green LED through a resistor to D4.
5. Connect all LED cathodes to GND.
6. Connect the Arduino Nano to the computer using a USB cable.
7. Open the Arduino IDE and select the correct board and port.
8. Upload the warning-pattern program.
9. Observe the alternating LED flashing pattern.
10. Change the delay value to create a faster, slower or customized warning pattern.

## Arduino Program
See [exp10_emergency_led_warning.ino](exp10_emergency_led_warning.ino)

```cpp
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
```

## Working Principle
The Arduino uses three digital output pins to coordinate the LEDs. In the first state, the red and green LEDs are switched ON while the yellow LED is OFF. This state remains active for 200 ms. The Arduino then changes to the second state, where the red and green LEDs are OFF and the yellow LED is ON for 200 ms. These two states repeat continuously, producing an alternating emergency warning pattern.

## Warning Pattern Sequence

| Step   | Red (D2) | Yellow (D3) | Green (D4) | Duration |
|--------|----------|-------------|------------|----------|
| 1      | ON       | OFF         | ON         | 200 ms   |
| 2      | OFF      | ON          | OFF        | 200 ms   |
| Repeat | ON       | OFF         | ON         | 200 ms   |

## Result / Observation
The three LEDs flash in an alternating pattern. Red and green LEDs turn ON together for approximately 200 ms while yellow remains OFF; then yellow turns ON while red and green turn OFF for approximately 200 ms. The pattern repeats continuously.

## Customization
The warning effect can be customized by changing the `delay()` value. A smaller value, such as `delay(100)`, makes the flashing faster, while a larger value, such as `delay(500)`, makes it slower. The HIGH and LOW combinations can also be changed to create different warning patterns.

## Experiment Parameters
Default flashing interval: 200 ms per state. The complete two-state pattern takes approximately 400 ms before repeating.

## Quick Reference

| Pin / Item | Common Use in These Examples              |
|------------|-------------------------------------------|
| D2-D6      | LED digital outputs                       |
| D7         | IR sensor / button                        |
| D8         | Buzzer                                    |
| A0         | Potentiometer                             |
| D5         | PWM output for LED brightness             |
| D9         | BC547 transistor base in the final project |

## Conclusion
The experiment successfully demonstrates coordinated control of multiple LEDs using Arduino Nano digital outputs. It shows how timing delays and `digitalWrite()` can be combined to produce a simple visual emergency or warning signal.
