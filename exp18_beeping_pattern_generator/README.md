# Experiment 18: Push Button & Buzzer - Beeping Pattern Generator

Arduino Nano | Buzzer Output | Functions | Beep Patterns

## Objective
To create different buzzer beep patterns by controlling the tone frequency and timing using an Arduino Nano.

## Introduction
A buzzer can be used to create different sound patterns by changing the frequency and duration of the sound. In this experiment, a reusable `beep()` function is created. It generates a beep for a specified duration and then creates a short pause. Three beeps are used to create a short-short-long pattern.

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
The positive terminal of the buzzer is connected to digital pin D8 of the Arduino Nano. The negative terminal of the buzzer is connected to GND. The Arduino generates a 1200 Hz tone through D8, and the duration of each beep is controlled by the `beep()` function.

## Build Steps
1. Place the buzzer on the breadboard.
2. Connect the positive terminal of the buzzer to D8.
3. Connect the negative terminal to GND.
4. Connect the Arduino Nano to the computer using a USB cable.
5. Select the correct Board and Port in Arduino IDE.
6. Upload the given Arduino program.
7. Listen to the short-short-long beep pattern.
8. Modify the duration values to create your own beep pattern.
9. Upload the modified program and observe the new pattern.

## Arduino Code
See [exp18_beeping_pattern_generator.ino](exp18_beeping_pattern_generator.ino)

```cpp
const int BUZZ = 8;   // Buzzer connected to D8

// Reusable function: one beep of 'ms' milliseconds, then a short pause
void beep(int ms) {
  tone(BUZZ, 1200);   // Play a 1200 Hz tone
  delay(ms);          // Keep the tone ON for 'ms' milliseconds
  noTone(BUZZ);       // Stop the tone
  delay(120);         // Short pause between beeps
}

void setup() {
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  beep(150);          // Short beep
  beep(150);          // Short beep
  beep(500);          // Long beep
  delay(800);         // Long pause before the pattern repeats
}
```

## How the Program Works
- `BUZZ = 8` assigns digital pin D8 to the buzzer.
- `beep(int ms)` is a reusable function that creates one beep.
- `tone(BUZZ, 1200)` generates a 1200 Hz tone.
- `delay(ms)` keeps the buzzer ON for the specified time.
- `noTone(BUZZ)` stops the sound.
- `delay(120)` creates a 120 ms pause between beeps.
- `beep(150)` creates a short beep.
- `beep(500)` creates a long beep.
- `delay(800)` creates a longer pause before the pattern repeats.

## Working Principle
The program uses the same `beep()` function three times with different durations.

Short beep → Short beep → Long beep → Long pause → Repeat

The pattern is: 150 ms → 150 ms → 500 ms → 800 ms pause. This creates a recognizable short-short-long sound pattern.

## Beep Pattern

| Beep  | Duration | Type       |
|-------|----------|------------|
| 1st   | 150 ms   | Short      |
| 2nd   | 150 ms   | Short      |
| 3rd   | 500 ms   | Long       |
| Pause | 800 ms   | Long Pause |

## Experiment with Your Own Pattern
You can change the values inside the `beep()` function calls. For example:

```cpp
beep(100);
beep(300);
beep(100);
beep(600);
```

This creates a different sound pattern. The frequency can also be changed:

```cpp
tone(BUZZ, 2000);
```

A higher frequency produces a higher-pitched sound.

## Learning Outcomes
- How to generate buzzer patterns.
- How to use functions in Arduino programming.
- How to control sound duration using `delay()`.
- How frequency changes the pitch of a buzzer.
- How reusable functions make programs easier to modify.
- How different timings can create different alert patterns.

## Precautions
1. Check the buzzer polarity before connecting it.
2. Connect the buzzer negative terminal to GND.
3. Make sure D8 is correctly connected to the buzzer.
4. Select the correct Arduino board and COM port before uploading.
5. Do not change circuit connections while the Arduino is powered.

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
The Arduino Nano successfully generated a short-short-long buzzer pattern using different beep durations. The pattern can be modified by changing the frequency and timing values in the program.
