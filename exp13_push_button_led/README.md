# Experiment 13: Push Button Controlled LED

Push Button & Buzzer | Arduino Nano | Digital Input | INPUT_PULLUP

## Objective
To learn digital input by using a push button to control an LED with an Arduino Nano.

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
1. Connect the LED to Arduino pin D2 through a current-limiting resistor.
2. Connect the push button between D3 and GND.
3. Set D3 as `INPUT_PULLUP` in the Arduino program.
4. Upload the sketch to the Arduino Nano.
5. Press and release the button and observe the LED.

## Arduino Program
See [exp13_push_button_led.ino](exp13_push_button_led.ino)

```cpp
const int LED = 2;   // LED output pin
const int BTN = 3;   // Push button input pin (active-LOW with INPUT_PULLUP)

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BTN) == LOW) {
    digitalWrite(LED, HIGH);   // Button pressed: LED ON
  } else {
    digitalWrite(LED, LOW);    // Button released: LED OFF
  }
}
```

## Working Principle
The push button is configured with the Arduino's internal pull-up resistor. When the button is released, the D3 input remains HIGH. When the button is pressed, it connects D3 to GND, causing the input to become LOW. The program continuously reads the button state and turns the LED ON when the button is pressed and OFF when the button is released.

## Input and LED Behavior

| Button State | D3 Reading | LED State |
|--------------|------------|-----------|
| Released     | HIGH       | OFF       |
| Pressed      | LOW        | ON        |

## Result / Observation
The LED turns ON while the push button is pressed and turns OFF when the button is released. This demonstrates how an Arduino digital input can directly control a digital output.

## Important Notes
- With `INPUT_PULLUP`, the button is active LOW: pressed = LOW and released = HIGH.
- Connect the LED through a suitable current-limiting resistor to protect the LED and the Arduino output pin.
- The simple program responds continuously to the current button state; no separate debounce routine is included.

## Experiment Parameters

| Parameter      | Value                                     |
|----------------|-------------------------------------------|
| LED pin        | D2                                        |
| Button pin     | D3                                        |
| Button mode    | INPUT_PULLUP                              |
| Pressed state  | LOW                                       |
| Released state | HIGH                                      |
| LED response   | ON when button is pressed; OFF when released |

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
The experiment demonstrates the use of a push button as a digital input and an LED as a digital output. It also shows how `INPUT_PULLUP` can simplify button wiring by using the Arduino's internal pull-up resistor.
