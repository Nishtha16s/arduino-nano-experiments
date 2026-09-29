# Experiment 02: Arduino & LED Basics (My First LED Blink)

## Objective
To learn how to connect an external LED safely and control it using an Arduino Nano digital output.

## Introduction
An LED emits light when current flows through it. A resistor limits the current to protect the LED. The Arduino toggles pin D2 HIGH and LOW to blink the LED.

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
1. Place the LED on the breadboard.
2. Connect the resistor in series with the LED anode.
3. Connect the other end of the resistor to D2.
4. Connect the LED cathode to GND.
5. Upload the sketch.
6. Observe the LED blinking.

## Arduino Code
See [exp02_led_blink.ino](exp02_led_blink.ino)

```cpp
const int LED = 2;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);

  digitalWrite(LED, LOW);
  delay(1000);
}
```

## Working Principle
Pin D2 outputs HIGH (5V) and LOW (0V). HIGH turns the LED ON and LOW turns it OFF. The resistor limits the current and protects the LED.

## Expected Output
The external LED connected to D2 blinks continuously, staying ON for 1 second and OFF for 1 second.

## Applications
- Indicator circuits
- Arduino learning
- Robotics projects
- IoT basics

## Advantages
- Easy to build
- Safe
- Demonstrates digital output

## Precautions
- Always use a resistor with the LED.
- Connect the LED with correct polarity.
- Check the wiring before powering the board.

## Quick Reference

| Pin   | Common Use in Examples   |
|-------|--------------------------|
| D2-D6 | LEDs                     |
| D7    | IR Sensor / Button       |
| D8    | Buzzer                   |
| A0    | Potentiometer            |
| D5    | PWM LED brightness       |
| D9    | BC547 base               |

## Conclusion
This experiment introduces Arduino digital output control by blinking an LED. It forms the basis for future electronics and robotics projects.
