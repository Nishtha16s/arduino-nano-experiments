# Experiment 21: Potentiometer & PWM - LED Brightness Control

Arduino Nano | Analog Input | PWM Output | map() Function

## Objective
To learn how to use a potentiometer to control the brightness of an LED using PWM with an Arduino Nano.

## Introduction
A potentiometer can provide a variable analog value based on the position of its knob. Arduino can read this value using an analog input pin.

In this experiment, the potentiometer is connected to A0, and an LED is connected to the PWM pin D5 through a resistor. The potentiometer reading is converted from a range of 0-1023 into a PWM range of 0-255. As the potentiometer is rotated, the LED brightness changes accordingly.

## Components Required

| S. No. | Component              | Quantity    |
|--------|------------------------|-------------|
| 1      | Arduino Nano           | 1           |
| 2      | 10k Potentiometer      | 1           |
| 3      | LED                    | 1           |
| 4      | 220Ω / 330Ω Resistor   | 1           |
| 5      | Breadboard             | 1           |
| 6      | Jumper Wires           | As required |
| 7      | USB Cable              | 1           |

## Circuit Connections

**Potentiometer**

| Potentiometer Pin | Arduino Connection |
|-------------------|--------------------|
| One outer pin     | 5V                 |
| Other outer pin   | GND                |
| Middle pin        | A0                 |

**LED**

| LED Terminal         | Arduino Connection    |
|----------------------|-----------------------|
| Anode (long leg)     | D5 through resistor   |
| Cathode (short leg)  | GND                   |

## Connection Explanation
The potentiometer is used as an analog input device.
- One outer pin is connected to 5V.
- The other outer pin is connected to GND.
- The middle pin is connected to A0.

The LED is connected to D5, which is a PWM-capable pin on the Arduino Nano. A resistor is connected in series with the LED to limit current and protect the LED. When the potentiometer is rotated, the analog value at A0 changes. The Arduino converts this value into a PWM value and uses it to control the apparent brightness of the LED.

## Build Steps
1. Place the potentiometer on the breadboard.
2. Connect one outer pin of the potentiometer to 5V.
3. Connect the other outer pin to GND.
4. Connect the middle pin to A0.
5. Place the LED on the breadboard.
6. Connect the LED anode through a 220Ω/330Ω resistor to D5.
7. Connect the LED cathode to GND.
8. Connect the Arduino Nano to the computer using a USB cable.
9. Select the correct Board and Port.
10. Upload the given Arduino sketch.
11. Slowly rotate the potentiometer.
12. Observe the LED brightness changing.

## Arduino Code
See [exp21_led_brightness_control.ino](exp21_led_brightness_control.ino)

```cpp
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
```

## How the Program Works
- `POT = A0` assigns analog pin A0 to the potentiometer.
- `LED = 5` assigns digital pin D5 to the LED.
- `pinMode(LED, OUTPUT)` sets D5 as an output.
- `analogRead(POT)` reads the potentiometer value from approximately 0 to 1023.
- `map()` converts the analog value from 0-1023 into a PWM value from 0-255.
- `analogWrite(LED, brightness)` sends the PWM value to D5 and controls the apparent brightness of the LED.

## Working Principle
The potentiometer controls the LED brightness through three steps:

Potentiometer → Analog Reading (0-1023) → PWM Value (0-255) → LED Brightness

When the potentiometer is rotated, the analog value changes. The Arduino maps this value to a PWM range and adjusts the LED output accordingly.

## Analog-to-PWM Mapping

| Potentiometer Reading | PWM Value | LED Brightness |
|-----------------------|-----------|----------------|
| 0                     | 0         | OFF            |
| ~256                  | ~64       | Low            |
| ~512                  | ~128      | Medium         |
| ~768                  | ~192      | High           |
| 1023                  | 255       | Maximum        |

## Understanding PWM
PWM (Pulse Width Modulation) is a technique used to control the average power supplied to an output. The Arduino Nano uses PWM values from 0 to 255 with `analogWrite()`.

- 0 → LED OFF
- 255 → Maximum output
- Values between 0 and 255 → Different apparent brightness levels

D5 is a PWM-capable pin, which makes it suitable for this experiment.

## Expected Output
- Minimum position → LED OFF / very dim
- Middle position → LED medium bright
- Maximum position → LED maximum brightness

The brightness changes smoothly as the potentiometer knob is rotated.

## Learning Outcomes
- How to use a potentiometer as an analog input.
- How to read analog values using `analogRead()`.
- How to use PWM for controlling LED brightness.
- How the `map()` function converts one range into another.
- How `analogWrite()` controls a PWM output.
- Why a resistor is required with an LED.
- How an analog input can control an output device.

## Precautions
1. Always connect a resistor in series with the LED.
2. Connect the LED in the correct polarity.
3. Make sure the potentiometer middle pin is connected to A0.
4. Do not accidentally connect 5V and GND directly together.
5. Make sure D5 is used for the LED because it supports PWM.
6. Check all connections before powering the Arduino.
7. Do not change circuit connections while the Arduino is powered.

## Quick Reference

| Arduino Pin | Common Use                        |
|-------------|-----------------------------------|
| D2-D6       | LEDs in many examples             |
| D7          | IR sensor / button                |
| D8          | Buzzer                            |
| A0          | Potentiometer                     |
| D5          | PWM / brightness control          |
| D9          | BC547 base in the final project   |

## Result
The Arduino Nano successfully controlled the brightness of the LED using a potentiometer. The analog reading from A0 was mapped from 0-1023 to a PWM range of 0-255, allowing the LED brightness to change as the potentiometer was rotated.
