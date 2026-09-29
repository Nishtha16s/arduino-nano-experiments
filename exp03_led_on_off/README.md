# Experiment 03: Arduino & LED Basics (LED ON/OFF Using Arduino)

## Objective
To learn direct digital control of an LED using an Arduino Nano.

## Introduction
This experiment demonstrates digital control of an LED using the Arduino Nano. The LED stays ON for 2 seconds and OFF for 1 second.

## Components Required

| S. No. | Component              | Quantity    |
|--------|------------------------|-------------|
| 1      | Arduino Nano           | 1           |
| 2      | LED                    | 1           |
| 3      | 220Ω / 330Ω Resistor   | 1           |
| 4      | Breadboard             | 1           |
| 5      | Jumper Wires           | As required |
| 6      | USB Cable              | 1           |

## Connections

| From                      | To                    |
|---------------------------|-----------------------|
| D2                        | Resistor              |
| Resistor                  | LED Anode (long leg)  |
| LED Cathode (short leg)   | GND                   |

## Build Steps
1. Build the LED circuit using pin D2.
2. Upload the sketch.
3. Observe the LED.
4. Change the HIGH/LOW timing and delay values to see the effect.

## Arduino Code
See [exp03_led_on_off.ino](exp03_led_on_off.ino)

```cpp
const int LED = 2;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(2000);   // LED ON for 2 seconds

  digitalWrite(LED, LOW);
  delay(1000);   // LED OFF for 1 second
}
```

## Working Principle
Pin D2 outputs HIGH and LOW signals. HIGH turns the LED ON and LOW turns it OFF. The resistor protects the LED.

## Expected Output
The LED stays ON for 2 seconds and OFF for 1 second, repeating continuously.

## Applications
- Arduino learning
- Digital output control
- Robotics

## Advantages
- Simple
- Safe
- Easy to understand

## Precautions
- Always use a resistor with the LED.
- Connect the LED with correct polarity.

## Quick Reference

| Pin   | Common Use in Examples |
|-------|------------------------|
| D2-D6 | LEDs                   |
| D7    | IR Sensor / Button     |
| D8    | Buzzer                 |
| A0    | Potentiometer          |
| D5    | PWM                    |
| D9    | BC547 base             |

## Conclusion
This experiment teaches Arduino digital output timing by controlling the LED ON and OFF duration.
