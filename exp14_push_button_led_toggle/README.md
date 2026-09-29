# Experiment 14: Push Button LED Toggle

Push Button & Buzzer | Arduino Nano | Button State Detection | LED Toggle

## Objective
To make one button press toggle an LED state instead of requiring the button to be held down.

## Components Required

| S. No. | Component                  | Quantity    |
|--------|----------------------------|-------------|
| 1      | Arduino Nano               | 1           |
| 2      | Push button                | 1           |
| 3      | LED                        | 1           |
| 4      | Current-limiting resistor  | 1           |
| 5      | Breadboard                 | 1           |
| 6      | Jumper Wires               | As required |

## Circuit Connections

| Component   | Arduino Pin | Connection                                    |
|-------------|-------------|-----------------------------------------------|
| LED         | D2          | D2 → resistor → LED anode; cathode → GND      |
| Push button | D3          | One side → D3; other side → GND; INPUT_PULLUP |

## Build Procedure
1. Build the push button and LED circuit according to the connection table.
2. Upload the Arduino sketch.
3. Press the button once: the LED turns ON.
4. Release the button and press it again: the LED turns OFF.
5. Continue pressing and releasing the button to toggle the LED between ON and OFF.
6. Observe that the LED remembers its previous state between button presses.

## Arduino Program
See [exp14_push_button_led_toggle.ino](exp14_push_button_led_toggle.ino)

```cpp
const int LED = 2;   // LED output pin
const int BTN = 3;   // Push button input pin (active-LOW with INPUT_PULLUP)

bool ledState = false;    // Stores the current LED state (OFF at start)
bool lastState = HIGH;    // Stores the previous button reading

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  bool currentState = digitalRead(BTN);

  // Detect a button press: HIGH -> LOW transition
  if (lastState == HIGH && currentState == LOW) {
    ledState = !ledState;            // Reverse the LED state
    digitalWrite(LED, ledState);     // Update the LED
    delay(40);                       // Simple debounce delay
  }

  lastState = currentState;          // Remember the button state
}
```

## Working Principle
The program stores the LED's current state in the variable `ledState`. It also stores the previous button reading in `lastState`. A button press is detected when the input changes from HIGH to LOW. When this transition occurs, `ledState` is reversed using the `!` operator, and the new state is written to the LED. The short 40 ms delay helps reduce unwanted rapid triggering caused by button bounce.

## Button and LED Behavior

| Action       | Button Transition | LED State Change | Result        |
|--------------|-------------------|------------------|---------------|
| First press  | HIGH → LOW        | OFF → ON         | LED turns ON  |
| Second press | HIGH → LOW        | ON → OFF         | LED turns OFF |
| Third press  | HIGH → LOW        | OFF → ON         | LED turns ON  |

## Result / Observation
Each complete button press changes the LED to the opposite state. The LED remains ON or OFF after the button is released, demonstrating stored program state.

## Important Notes
- With `INPUT_PULLUP`, the button is active LOW: released = HIGH and pressed = LOW.
- The program toggles only when it detects a HIGH-to-LOW transition, so holding the button does not repeatedly toggle the LED.
- The 40 ms delay provides simple debounce protection. A more advanced project can use non-blocking debounce logic.
- Use a current-limiting resistor with the LED.

## Experiment Parameters

| Parameter         | Value                    |
|-------------------|--------------------------|
| LED pin           | D2                       |
| Button pin        | D3                       |
| Button mode       | INPUT_PULLUP             |
| Pressed state     | LOW                      |
| Released state    | HIGH                     |
| Initial LED state | OFF                      |
| Toggle condition  | HIGH → LOW transition    |
| Debounce delay    | 40 ms                    |

## Quick Reference

| Pin / Function | Typical Use                            |
|----------------|----------------------------------------|
| D2             | LED output in this experiment          |
| D3             | Push button input in this experiment   |
| D2-D6          | LED outputs in many examples           |
| D7             | IR sensor / button in many examples    |
| D8             | Buzzer                                 |
| A0             | Potentiometer / analog input           |
| D5             | PWM pin for brightness control         |
| D9             | BC547 base in the final project        |

## Conclusion
The experiment demonstrates how Arduino can detect a button transition and use a stored Boolean variable to control an output state. It introduces the concepts of edge detection, state memory, Boolean logic, and simple button debouncing.
