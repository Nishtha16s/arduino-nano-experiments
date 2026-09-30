# Experiment 22: Potentiometer & PWM - Potentiometer Controlled Blink Speed

Arduino Nano | Analog Input | map() Function | Timing Control

## Objective
To learn how to use an analog input to continuously control the blinking speed of an LED using a potentiometer and an Arduino Nano.

## Introduction
A potentiometer can be used as an analog input to provide a variable value to the Arduino. By rotating the potentiometer knob, the analog reading changes.

In this experiment, the potentiometer is connected to **A0** and the LED is connected to digital pin **D2** through a resistor. The Arduino converts the potentiometer reading into a delay time between **50 and 1000 milliseconds**. As the potentiometer is rotated, the LED blinking speed changes continuously.

## Components Required

| S. No. | Component            | Quantity    |
|--------|----------------------|-------------|
| 1      | Arduino Nano         | 1           |
| 2      | 10k Potentiometer    | 1           |
| 3      | LED                  | 1           |
| 4      | 220Ω / 330Ω Resistor | 1           |
| 5      | Breadboard           | 1           |
| 6      | Jumper Wires         | As required |
| 7      | USB Cable            | 1           |

## Circuit Connections

**Potentiometer**

| Potentiometer Pin | Arduino Connection |
|-------------------|--------------------|
| One outer pin     | 5V                 |
| Other outer pin   | GND                |
| Middle pin        | A0                 |

**LED**

| LED Terminal        | Arduino Connection   |
|---------------------|----------------------|
| Anode (long leg)    | D2 through resistor  |
| Cathode (short leg) | GND                  |

## Connection Explanation
The potentiometer is used to provide a variable analog input to the Arduino.
- One outer pin is connected to 5V.
- The other outer pin is connected to GND.
- The middle pin is connected to A0.

The LED is connected to D2 through a resistor. The resistor limits current and protects the LED. When the potentiometer is rotated, the analog value read from A0 changes, and the Arduino uses this value to calculate the LED's delay time.

## Build Steps
1. Place the potentiometer on the breadboard.
2. Connect one outer pin of the potentiometer to 5V.
3. Connect the other outer pin to GND.
4. Connect the middle pin to A0.
5. Place the LED on the breadboard.
6. Connect the LED anode through a 220Ω/330Ω resistor to D2.
7. Connect the LED cathode to GND.
8. Connect the Arduino Nano to the computer using a USB cable.
9. Select the correct Board and Port.
10. Upload the given Arduino sketch.
11. Slowly rotate the potentiometer knob.
12. Observe the LED blinking speed change.

## Arduino Code
See [exp22_pot_controlled_blink_speed.ino](exp22_pot_controlled_blink_speed.ino)

```cpp
const int POT = A0;   // Potentiometer middle pin connected to A0
const int LED = 2;    // LED connected to D2

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // Convert potentiometer reading (0-1023) into delay time (50-1000 ms)
  int delayTime = map(analogRead(POT), 0, 1023, 50, 1000);

  digitalWrite(LED, HIGH);   // LED ON
  delay(delayTime);

  digitalWrite(LED, LOW);    // LED OFF
  delay(delayTime);
}
```

## How the Program Works
- `POT = A0` assigns analog pin A0 to the potentiometer.
- `LED = 2` assigns digital pin D2 to the LED.
- `pinMode(LED, OUTPUT)` sets D2 as an output.
- `analogRead(POT)` reads the potentiometer value from approximately 0 to 1023.
- `map()` converts the analog reading into a delay time between 50 and 1000 milliseconds.
- `digitalWrite(LED, HIGH)` turns the LED ON.
- `delay(delayTime)` keeps the LED ON for the calculated time.
- `digitalWrite(LED, LOW)` turns the LED OFF.
- The second `delay(delayTime)` keeps the LED OFF for the same amount of time.

## Working Principle
The potentiometer controls the LED blinking speed by changing the delay time.

Potentiometer → Analog Reading (0-1023) → Delay Time (50-1000 ms) → LED ON/OFF Timing → Blink Speed

When the delay is small, the LED blinks faster. When the delay is large, the LED blinks slower.

## Analog Reading to Delay Mapping

| Potentiometer Reading | Delay Time | LED Behaviour |
|----------------------:|-----------:|---------------|
| 0                     | 50 ms      | Very Fast     |
| ~256                  | ~288 ms    | Fast          |
| ~512                  | ~525 ms    | Medium        |
| ~768                  | ~763 ms    | Slow          |
| 1023                  | 1000 ms    | Very Slow     |

## Understanding the map() Function
The `map()` function converts a value from one range into another range. In this experiment:

```cpp
map(analogRead(POT), 0, 1023, 50, 1000);
```

The Arduino takes the potentiometer reading (0-1023) and converts it into 50-1000 milliseconds. This converted value is stored in the `delayTime` variable and is used to control the blinking speed.

## Expected Output
- Minimum position → Short delay → LED blinks very fast
- Middle position → Medium delay → LED blinks at medium speed
- Maximum position → Long delay → LED blinks very slowly

The blinking speed changes continuously as the potentiometer knob is rotated.

## Learning Outcomes
- How to use a potentiometer as an analog input.
- How to read analog values using `analogRead()`.
- How the `map()` function converts one range into another.
- How `delay()` can control LED blinking speed.
- How an analog input can control the timing of an output.
- How changing delay time affects the speed of an LED blink.

## Precautions
1. Always connect a resistor in series with the LED.
2. Connect the LED in the correct polarity.
3. Make sure the potentiometer middle pin is connected to A0.
4. Do not accidentally connect 5V and GND directly together.
5. Check all connections before powering the Arduino.
6. Make sure the correct Board and Port are selected before uploading.
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
The Arduino Nano successfully controlled the blinking speed of the LED using a potentiometer. The analog reading from A0 was converted into a delay time between 50 and 1000 milliseconds, allowing the LED blinking speed to change as the potentiometer was rotated.
