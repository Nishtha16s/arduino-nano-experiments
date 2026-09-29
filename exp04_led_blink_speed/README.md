# Experiment 04: Arduino & LED Basics (Change LED Blinking Speed)

## Objective
To understand how delay values control the speed of a blinking LED.

## Introduction
This experiment demonstrates how changing the `delay()` value affects the blinking speed of an LED. Smaller delay values make the LED blink faster, while larger values make it blink slower.

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
1. Build the LED circuit on pin D2.
2. Upload the program.
3. Observe the blinking LED.
4. Change the delay from 500 ms to 100 ms, and then to 1000 ms.
5. Compare the blinking speeds and try other values.

## Arduino Code
See [exp04_led_blink_speed.ino](exp04_led_blink_speed.ino)

```cpp
const int LED = 2;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(500);   // Try 100 for faster, 1000 for slower

  digitalWrite(LED, LOW);
  delay(500);   // Try 100 for faster, 1000 for slower
}
```

## Code Explanation
- Pin D2 is configured as an OUTPUT.
- The LED turns ON for 500 ms and OFF for 500 ms.
- Changing the delay values changes the blinking speed.

## Working Principle
The Arduino repeatedly sends HIGH and LOW signals to pin D2. The `delay()` function controls how long the LED stays ON and OFF. Smaller delay values increase the blinking speed, while larger values decrease it.

## Expected Output
The LED blinks continuously. Changing the delay values changes the blinking speed.

## Observations

| Delay (ms) | Blinking Speed |
|------------|----------------|
| 100        | Fast           |
| 500        | Medium         |
| 1000       | Slow           |

## Applications
- Learning Arduino timing functions
- Signal indicators
- Robotics projects
- Embedded systems

## Advantages
- Simple experiment
- Easy to understand timing concepts
- Useful for beginners

## Precautions
- Use a resistor with the LED.
- Connect the LED with correct polarity.
- Verify all connections before powering the circuit.

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
This experiment teaches how the `delay()` function affects the blinking speed of an LED, helping students understand timing control in Arduino programming.
