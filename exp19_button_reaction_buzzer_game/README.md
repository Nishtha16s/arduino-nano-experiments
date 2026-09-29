# Experiment 19: Push Button & Buzzer - Button Reaction Buzzer Game

Arduino Nano | Push Button Input | Buzzer Output | Reaction Time

## Objective
To combine a button, buzzer and timing to make a simple response game.

## Components Required

| S. No. | Component    | Quantity |
|--------|--------------|----------|
| 1      | Arduino Nano | 1        |
| 2      | Push button  | 1        |
| 3      | Buzzer       | 1        |

## Circuit Connections

| Component         | Arduino Connection                     |
|-------------------|----------------------------------------|
| Push button       | D3 → GND (using INPUT_PULLUP)          |
| Buzzer Positive + | D8                                     |
| Buzzer Negative - | GND                                    |

## Build Steps
1. Connect the button and buzzer.
2. Upload the sketch.
3. Wait for the beep.
4. Press the button after the beep.
5. The program measures the response time and prints it to the Serial Monitor.

## Arduino Code
See [exp19_button_reaction_buzzer_game.ino](exp19_button_reaction_buzzer_game.ino)

```cpp
const int BTN = 3;    // Push button (active-LOW with INPUT_PULLUP)
const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(BTN, INPUT_PULLUP);
  pinMode(BUZZ, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(A0));   // Floating A0 gives a random seed
}

void loop() {
  delay(random(1000, 3000));    // Random wait: 1 to 3 seconds

  tone(BUZZ, 1500, 200);        // Beep at 1500 Hz for 200 ms
  unsigned long start = millis();   // Timer starts after the beep

  while (digitalRead(BTN) == HIGH) {
    // Wait until the button is pressed (LOW)
  }

  unsigned long t = millis() - start;   // Response time

  Serial.print("Response: ");
  Serial.print(t);
  Serial.println(" ms");

  delay(1500);                  // Pause before the next round
}
```

## How It Works
The Arduino waits for a random time of 1 to 3 seconds and then plays a short beep. Right after the beep, `millis()` records the start time. The program waits until the button is pressed (D3 reads LOW), then subtracts the start time from the current `millis()` value to get the response time. The result is printed to the Serial Monitor in milliseconds, and after a short pause a new round begins.

## Game Sequence

| Step | Buzzer          | Button      | Action                                   |
|------|-----------------|-------------|------------------------------------------|
| 1    | OFF             | Not pressed | Random 1-3 second wait                   |
| 2    | Beep (1500 Hz)  | Not pressed | Response timer starts                    |
| 3    | OFF             | Pressed     | Timer stops and time is calculated       |
| 4    | OFF             | -           | Result printed to Serial Monitor         |
| 5    | OFF             | -           | 1.5-second pause, then a new round       |

## Expected Output
Open the Serial Monitor at **9600 baud**. After each beep and button press, a line like this appears:

```
Response: 312 ms
```

## Important Notes
- The button is active-LOW because `INPUT_PULLUP` is enabled.
- The Serial Monitor must be set to 9600 baud.
- A0 is read only to provide a seed for `random()`; it is not the reaction input.
- Press the button only **after** the beep. If the button is already held down before the beep, the program will show a very small response time.

## Experiment Parameters

| Parameter                | Value        |
|--------------------------|--------------|
| Button pin               | D3           |
| Buzzer pin               | D8           |
| Random waiting period    | 1-3 seconds  |
| Beep frequency           | 1500 Hz      |
| Beep duration            | 200 ms       |
| Serial baud rate         | 9600         |
| Pause after result       | 1.5 seconds  |

## Quick Reference

| Arduino Pin | Common Use                                           |
|-------------|------------------------------------------------------|
| D2-D6       | LEDs in many examples                                |
| D7          | IR sensor / button                                   |
| D8          | Buzzer                                               |
| A0          | Potentiometer (random seed source in this experiment) |
| D5          | PWM pin for brightness                               |
| D9          | BC547 base in the final project                      |

## Conclusion
The experiment combines a push button, a buzzer, `millis()` timing and Serial Monitor output to build a simple sound-based reaction game.
