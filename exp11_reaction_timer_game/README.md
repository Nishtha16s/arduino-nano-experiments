# Experiment 11: Reaction Timer Game

Traffic & Interactive Projects | Arduino Nano | LED + Push Button

## Objective
To measure how quickly a player responds after an LED turns ON. The Arduino Nano waits for a random period, switches the LED ON, measures the time until the push button is pressed, and displays the reaction time in milliseconds through the Serial Monitor.

## Components Required

| S. No. | Component                          | Quantity    |
|--------|------------------------------------|-------------|
| 1      | Arduino Nano                       | 1           |
| 2      | LED                                | 1           |
| 3      | Current-limiting resistor          | 1           |
| 4      | Push button                        | 1           |
| 5      | Breadboard                         | 1           |
| 6      | Jumper Wires                       | As required |
| 7      | USB Cable and computer             | 1           |

## Circuit Connections

| Component    | Arduino Connection                         | Purpose                   |
|--------------|--------------------------------------------|---------------------------|
| LED          | D2 → resistor → anode; cathode → GND       | Reaction signal           |
| Push button  | One side → D3; other side → GND            | Player input              |
| Button mode  | D3 configured as INPUT_PULLUP              | Internal pull-up resistor |

> With `INPUT_PULLUP`, the button normally reads HIGH and reads LOW when pressed, so no external pull-up resistor is required.

## Build Procedure
1. Connect the LED to D2 through a current-limiting resistor and connect its cathode to GND.
2. Connect one side of the push button to D3 and the other side to GND.
3. Connect the Arduino Nano to the computer using USB.
4. Upload the program using the Arduino IDE.
5. Open Serial Monitor and set the baud rate to 9600.
6. Wait for the LED to turn ON after the random delay.
7. Press the button as quickly as possible.
8. Read the reaction time displayed in milliseconds.

## Arduino Program
See [exp11_reaction_timer_game.ino](exp11_reaction_timer_game.ino)

```cpp
const int LED = 2;   // Reaction signal LED
const int BTN = 3;   // Push button (active-LOW with INPUT_PULLUP)

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(A0));   // Floating A0 gives a random seed
}

void loop() {
  digitalWrite(LED, LOW);
  delay(random(1000, 4000));    // Random wait: 1 to 4 seconds

  digitalWrite(LED, HIGH);      // LED ON: timer starts
  unsigned long start = millis();

  while (digitalRead(BTN) == HIGH) {
    // Wait until the button is pressed (LOW)
  }

  unsigned long reaction = millis() - start;
  digitalWrite(LED, LOW);

  Serial.print("Reaction time: ");
  Serial.print(reaction);
  Serial.println(" ms");

  delay(2000);                  // Pause before the next round
}
```

## Working Principle
The LED is first turned OFF and the Arduino waits for a random period of about 1-4 seconds. When the LED turns ON, `millis()` records the starting time. The program waits until the button is pressed, then calculates the elapsed time by subtracting the start value from the current `millis()` value. The result is printed to the Serial Monitor.

## Game Sequence

| Step | LED | Button       | Action                                  |
|------|-----|--------------|-----------------------------------------|
| 1    | OFF | Not pressed  | Random 1-4 second wait                  |
| 2    | ON  | Not pressed  | Reaction timer starts                   |
| 3    | ON  | Pressed      | Timer stops and time is calculated      |
| 4    | OFF | -            | Result printed to Serial Monitor        |
| 5    | OFF | -            | 2-second pause, then new round          |

## Result / Observation
After the LED turns ON, pressing the button stops the timer. The measured reaction time is displayed in the Serial Monitor in milliseconds, for example:

```
Reaction time: 245 ms
```

## Important Notes
- The button is active-LOW because `INPUT_PULLUP` is enabled.
- Serial Monitor must be set to 9600 baud.
- A0 is read only to provide a seed for `random()`; it is not the reaction input.
- The player should press the button only after the LED turns ON.

## Experiment Parameters
- Random waiting period: approximately 1-4 seconds
- Serial communication: 9600 baud
- Delay after displaying the result: 2 seconds

## Quick Reference

| Pin / Item | Common Use                                  |
|------------|---------------------------------------------|
| D2-D6      | LED digital outputs                         |
| D7         | IR sensor / button                          |
| D8         | Buzzer                                      |
| A0         | Potentiometer / analog input; random seed here |
| D5         | PWM brightness                              |
| D9         | BC547 base in final project                 |

## Conclusion
The experiment successfully demonstrates reaction-time measurement using an Arduino Nano, `millis()`, a digital LED output, a push-button input, random timing and Serial Monitor output.
