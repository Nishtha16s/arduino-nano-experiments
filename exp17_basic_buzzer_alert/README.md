# Experiment 17: Push Button & Buzzer - Basic Buzzer Alert

Arduino Nano | Buzzer Output | tone() and noTone()

## Objective
To learn how to generate a buzzer tone directly from an Arduino Nano and create a repeating sound alert.

## Introduction
A buzzer is an output device that produces sound when an electrical signal is applied to it. In this experiment, the buzzer is connected directly to digital pin D8 of the Arduino Nano. The Arduino generates a 1 kHz tone for 300 milliseconds and then stops the sound for 700 milliseconds. This process repeats continuously, creating a repeating buzzer alert.

## Components Required

| S. No. | Component    | Quantity    |
|--------|--------------|-------------|
| 1      | Arduino Nano | 1           |
| 2      | Buzzer       | 1           |
| 3      | Breadboard   | 1           |
| 4      | Jumper Wires | As required |
| 5      | USB Cable    | 1           |

## Circuit Connections

| Buzzer Terminal | Arduino Connection |
|-----------------|--------------------|
| Positive (+)    | D8                 |
| Negative (-)    | GND                |

## Connection Explanation
The positive terminal of the buzzer is connected to digital pin D8 of the Arduino Nano. The negative terminal of the buzzer is connected to GND. The Arduino controls the buzzer by generating an electrical signal on D8. The `tone()` function creates the sound, while the `noTone()` function stops it.

## Build Steps
1. Place the buzzer on the breadboard.
2. Connect the positive terminal of the buzzer to D8.
3. Connect the negative terminal of the buzzer to GND.
4. Connect the Arduino Nano to the computer using a USB cable.
5. Select the correct Board and Port in Arduino IDE.
6. Upload the given Arduino sketch.
7. Listen to the repeating buzzer alert.
8. Observe that the buzzer turns ON and OFF repeatedly.
9. Change the tone frequency or delay values and observe the difference.

## Arduino Code
See [exp17_basic_buzzer_alert.ino](exp17_basic_buzzer_alert.ino)

```cpp
const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  tone(BUZZ, 1000);   // Play a 1 kHz tone
  delay(300);         // Tone ON for 300 ms
  noTone(BUZZ);       // Stop the tone
  delay(700);         // Silence for 700 ms
}
```

## How the Program Works
- `BUZZ = 8` assigns digital pin D8 to the buzzer.
- `pinMode(BUZZ, OUTPUT)` sets D8 as an output pin.
- `tone(BUZZ, 1000)` generates a 1000 Hz (1 kHz) sound on D8.
- `delay(300)` keeps the tone ON for 300 milliseconds.
- `noTone(BUZZ)` stops the buzzer sound.
- `delay(700)` keeps the buzzer silent for 700 milliseconds.

## Working Principle
The Arduino's `tone()` function produces a square wave of the given frequency on the selected pin, and the buzzer converts it into sound. The buzzer stays ON for 300 ms and OFF for 700 ms, so one complete cycle takes 1 second and repeats continuously.

## Expected Output

| Step | Buzzer       | Duration |
|------|--------------|----------|
| 1    | ON (1 kHz)   | 300 ms   |
| 2    | OFF          | 700 ms   |
| Repeat | ON (1 kHz) | 300 ms   |

## Experiment Parameters

| Parameter        | Value         |
|------------------|---------------|
| Buzzer pin       | D8            |
| Tone frequency   | 1000 Hz       |
| Beep duration    | 300 ms        |
| Silence duration | 700 ms        |
| Cycle time       | 1000 ms (1 s) |

Change the frequency in `tone(BUZZ, 1000)` (for example 500 for a lower pitch or 2000 for a higher pitch) and the delay values to create different alert patterns.

## Result
The buzzer produces a short beep every second: 0.3 seconds of sound followed by 0.7 seconds of silence, repeating continuously.

## Precautions
1. Check the buzzer polarity before making the connections.
2. Ensure that the GND connection is properly connected.
3. Select the correct Arduino board and COM port before uploading.
4. Do not make or change connections while the circuit is powered.

## Quick Reference

| Arduino Pin | Common Use                        |
|-------------|-----------------------------------|
| D2-D6       | LEDs in many examples             |
| D7          | IR sensor / button                |
| D8          | Buzzer                            |
| D5          | PWM / brightness control          |
| D9          | BC547 base in the final project   |
| A0          | Potentiometer                     |

## Conclusion
The experiment demonstrates how an Arduino can generate a repeating sound alert using a buzzer with the `tone()` and `noTone()` functions.
