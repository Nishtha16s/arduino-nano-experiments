# Experiment 12: Electronic Dice with LEDs

Traffic & Interactive Projects | Arduino Nano | Random Number Generation | LED Display

## Objective
To use a push button to generate a random dice value and display the result using LEDs connected to an Arduino Nano.

## Components Required

| S. No. | Component                                          | Quantity    |
|--------|----------------------------------------------------|-------------|
| 1      | Arduino Nano                                       | 1           |
| 2      | LED                                                | 5           |
| 3      | Current-limiting resistor (one per LED, recommended) | 5         |
| 4      | Push button                                        | 1           |
| 5      | Breadboard                                         | 1           |
| 6      | Jumper Wires                                       | As required |

## Circuit Connections

| Component   | Arduino Pin | Connection                                    |
|-------------|-------------|-----------------------------------------------|
| LED 1       | D2          | D2 → resistor → LED anode; cathode → GND      |
| LED 2       | D3          | D3 → resistor → LED anode; cathode → GND      |
| LED 3       | D4          | D4 → resistor → LED anode; cathode → GND      |
| LED 4       | D5          | D5 → resistor → LED anode; cathode → GND      |
| LED 5       | D6          | D6 → resistor → LED anode; cathode → GND      |
| Push button | D7          | One side → D7; other side → GND; INPUT_PULLUP |

## Build Procedure
1. Arrange five LEDs in a simple dice-style display.
2. Connect each LED to Arduino pins D2-D6 through its own current-limiting resistor.
3. Connect the push button between D7 and GND.
4. Upload the Arduino program.
5. Press the button to generate a random value from 1 to 5 in this simple version.
6. Observe the corresponding LED pattern.

## Arduino Program
See [exp12_electronic_dice.ino](exp12_electronic_dice.ino)

```cpp
const int leds[] = {2, 3, 4, 5, 6};   // LED pins: D2 to D6
const int NUM_LEDS = 5;
const int BTN = 7;                    // Push button (active-LOW with INPUT_PULLUP)

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(BTN, INPUT_PULLUP);
  randomSeed(analogRead(A0));         // Floating A0 gives a random seed
}

// Show a value from 1 to 5 by turning ON the first n LEDs
void showNumber(int n) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i], LOW);       // Turn all LEDs OFF first
  }
  for (int i = 0; i < n && i < NUM_LEDS; i++) {
    digitalWrite(leds[i], HIGH);      // Turn ON the first n LEDs
  }
}

void loop() {
  if (digitalRead(BTN) == LOW) {      // Button pressed
    delay(30);                        // Debounce delay
    if (digitalRead(BTN) == LOW) {
      int n = random(1, 6);           // Random value from 1 to 5
      showNumber(n);
      while (digitalRead(BTN) == LOW) {}   // Wait until button is released
      delay(200);
    }
  }
}
```

## Working Principle
The push button uses `INPUT_PULLUP`, so the button is detected when the D7 input reads LOW. When the button is pressed, the program waits briefly for switch bounce, generates a random number from 1 to 5, and calls `showNumber()` to display that value. The random seed is initialized from the analog reading on A0 so repeated rolls are less predictable.

## LED Display Sequence

| Generated Value | LED Display               |
|-----------------|---------------------------|
| 1               | First 1 LED ON (D2)       |
| 2               | First 2 LEDs ON (D2-D3)   |
| 3               | First 3 LEDs ON (D2-D4)   |
| 4               | First 4 LEDs ON (D2-D5)   |
| 5               | First 5 LEDs ON (D2-D6)   |

## Result / Observation
When the push button is pressed, the Arduino generates a random value from 1 to 5 and displays it using the five LEDs. Each successful button press can produce a different value.

## Important Notes & Limitation
- This program intentionally generates values from 1 to 5 because only five LEDs are available.
- A true six-face dice display requires a six-LED arrangement or a multiplexed display design that can represent six distinct values.
- Use one current-limiting resistor for each LED. Five independently driven LEDs should have five resistors.
- If a different dice-style pattern is required, the `showNumber()` function can be modified to control individual LEDs for each face.

## Experiment Parameters

| Parameter       | Value                                |
|-----------------|--------------------------------------|
| LED pins        | D2, D3, D4, D5, D6                   |
| Button pin      | D7                                   |
| Button logic    | INPUT_PULLUP; pressed = LOW          |
| Random range    | 1-5                                  |
| Display method  | First n LEDs ON                      |
| Debounce delay  | 30 ms                                |
| Release delay   | 200 ms                               |
| Resistors       | 5 recommended, one per LED           |

## Quick Reference

| Pin / Function | Typical Use                                         |
|----------------|-----------------------------------------------------|
| D2-D6          | LED outputs                                         |
| D7             | Push button / IR sensor input                       |
| D8             | Buzzer                                              |
| A0             | Potentiometer / analog input and random seed source |
| D5             | PWM pin for brightness control                      |
| D9             | BC547 base in the final project                     |

## Conclusion
The experiment demonstrates how a push button can trigger random-number generation and how multiple digital outputs can be used to represent a result. It also introduces button debouncing, `INPUT_PULLUP`, arrays, functions, and `random()` in Arduino programming.
