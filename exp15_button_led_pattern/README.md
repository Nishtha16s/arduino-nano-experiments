# Experiment 15: Button Controlled LED Pattern

Push Button & Buzzer | Arduino Nano | Push Button Trigger | Multi-LED Sequence

## Objective
To use one push button to trigger a multi-LED sequence using three LEDs connected to an Arduino Nano.

## Components Required

| S. No. | Component                  | Quantity    |
|--------|----------------------------|-------------|
| 1      | Arduino Nano               | 1           |
| 2      | Push button                | 1           |
| 3      | LED                        | 3           |
| 4      | Current-limiting resistor  | 3           |
| 5      | Breadboard                 | 1           |
| 6      | Jumper Wires               | As required |

## Circuit Connections

| Component   | Arduino Pin | Connection                                    |
|-------------|-------------|-----------------------------------------------|
| LED 1       | D2          | D2 → resistor → LED anode; cathode → GND      |
| LED 2       | D3          | D3 → resistor → LED anode; cathode → GND      |
| LED 3       | D4          | D4 → resistor → LED anode; cathode → GND      |
| Push button | D7          | One side → D7; other side → GND; INPUT_PULLUP |

## Build Procedure
1. Connect three LEDs to Arduino pins D2-D4, using one resistor for each LED.
2. Connect the push button between D7 and GND.
3. Upload the Arduino sketch.
4. Press the button to run the LED pattern.
5. Release the button after the pattern starts.
6. Press the button again to run the pattern again.

## Arduino Program
See [exp15_button_led_pattern.ino](exp15_button_led_pattern.ino)

```cpp
const int leds[] = {2, 3, 4};   // LED pins: D2, D3, D4
const int NUM_LEDS = 3;
const int BTN = 7;              // Push button (active-LOW with INPUT_PULLUP)

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BTN) == LOW) {          // Button pressed
    for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(leds[i], HIGH);        // Turn LED ON
      delay(250);                         // Keep it ON for 250 ms
      digitalWrite(leds[i], LOW);         // Turn LED OFF
    }
    while (digitalRead(BTN) == LOW) {}    // Wait until button is released
  }
}
```

## Working Principle
The push button is configured with `INPUT_PULLUP`, so a pressed button produces a LOW reading on D7. When a LOW is detected, the Arduino starts a three-step sequence. Each LED is turned ON for 250 ms and then turned OFF before the next LED is activated. After the sequence finishes, the program waits until the button is released, preventing one long press from immediately starting another sequence.

## LED Pattern Sequence

| Step | LED   | Arduino Pin | ON Time |
|------|-------|-------------|---------|
| 1    | LED 1 | D2          | 250 ms  |
| 2    | LED 2 | D3          | 250 ms  |
| 3    | LED 3 | D4          | 250 ms  |

## Result / Observation
When the button is pressed, the three LEDs light one after another. Each LED remains ON for 250 ms before turning OFF, producing a simple running-light pattern. The same pattern can be triggered again with another button press.

## Important Notes
- With `INPUT_PULLUP`, the button is active LOW: pressed = LOW and released = HIGH.
- Use one current-limiting resistor for each LED.
- The `while` loop waits for the button to be released before allowing another trigger.
- The sequence timing can be changed by modifying `delay(250)`.
- The pattern can be expanded by adding more LEDs to the array and updating the loop.

## Experiment Parameters

| Parameter         | Value                                        |
|-------------------|----------------------------------------------|
| LED pins          | D2, D3, D4                                   |
| Button pin        | D7                                           |
| Button mode       | INPUT_PULLUP                                 |
| Pressed state     | LOW                                          |
| LED sequence      | D2 → D3 → D4                                 |
| LED ON time       | 250 ms per LED                               |
| Trigger type      | Button press                                 |
| Repeat condition  | Button must be released before next trigger  |

## Quick Reference

| Pin / Function | Typical Use                            |
|----------------|----------------------------------------|
| D2-D4          | LED outputs in this experiment         |
| D2-D6          | LED outputs in many examples           |
| D7             | IR sensor / button in many examples    |
| D8             | Buzzer                                 |
| A0             | Potentiometer / analog input           |
| D5             | PWM pin for brightness control         |
| D9             | BC547 base in the final project        |

## Conclusion
The experiment demonstrates how a push button can be used as a trigger for a programmed sequence rather than continuously controlling an output. It combines digital input, arrays, loops, timing delays, and multiple digital outputs in one interactive project.
