# Experiment 05: LED Patterns (Two LED Alternate Blinking)

## Objective
To control two outputs and create an alternating LED blinking pattern using an Arduino Nano.

## Introduction
This experiment demonstrates how an Arduino Nano can control two LEDs independently. One LED turns ON while the other remains OFF, and then their states are reversed to create an alternating blinking effect.

## Components Required

| S. No. | Component                | Quantity    |
|--------|--------------------------|-------------|
| 1      | Arduino Nano             | 1           |
| 2      | LED                      | 2           |
| 3      | 220Ω / 330Ω Resistor     | 2           |
| 4      | Breadboard               | 1           |
| 5      | Jumper Wires             | As required |
| 6      | USB Cable                | 1           |

## Connections

| From                          | To                       |
|-------------------------------|--------------------------|
| D2                            | Resistor → LED1 Anode    |
| D3                            | Resistor → LED2 Anode    |
| LED1 and LED2 Cathodes        | GND                      |

(Anode = long leg, Cathode = short leg)

## Build Steps
1. Place two LEDs on the breadboard.
2. Connect a resistor in series with each LED.
3. Connect LED1 to D2 and LED2 to D3.
4. Connect both LED cathodes to GND.
5. Upload the sketch.
6. Observe both LEDs blinking alternately.

## Arduino Code
See [exp05_two_led_alternate.ino](exp05_two_led_alternate.ino)

```cpp
const int LED1 = 2;
const int LED2 = 3;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);   // LED1 ON
  digitalWrite(LED2, LOW);    // LED2 OFF
  delay(500);

  digitalWrite(LED1, LOW);    // LED1 OFF
  digitalWrite(LED2, HIGH);   // LED2 ON
  delay(500);
}
```

## Code Explanation
- Pins D2 and D3 are configured as OUTPUT.
- LED1 turns ON while LED2 remains OFF for 500 ms.
- Then LED1 turns OFF and LED2 turns ON for 500 ms.
- This sequence repeats continuously.

## Working Principle
The Arduino alternates HIGH and LOW signals between digital pins D2 and D3. Only one LED is ON at a time, creating an alternating blinking pattern.

## Expected Output
LED1 and LED2 blink alternately every 500 milliseconds.

## Applications
- Traffic light simulation
- Indicator systems
- Robotics projects
- Learning multiple digital outputs

## Advantages
- Simple multi-output control
- Easy to understand
- Useful for beginners and robotics applications

## Precautions
- Use a separate resistor for each LED.
- Connect the LEDs with correct polarity.
- Verify the wiring before powering the circuit.

## Quick Reference

| Pin   | Common Use in Examples |
|-------|------------------------|
| D2-D6 | LEDs                   |
| D7    | IR Sensor / Button     |
| D8    | Buzzer                 |
| A0    | Potentiometer          |
| D5    | PWM Brightness         |
| D9    | BC547 base             |

## Conclusion
This experiment teaches how to control multiple digital output pins by creating an alternating LED blinking pattern.
