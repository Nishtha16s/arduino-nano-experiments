# Experiment 07: LED Patterns - Five LED Pattern

Arduino Nano | Five Digital Outputs | Scanner-Style LED Pattern

## Objective
To create a programmed LED pattern across five LED positions using the Arduino Nano. The LEDs are controlled sequentially in the forward direction and then in the backward direction, creating a scanner-style effect.

## Components Required

| S. No. | Component                                | Quantity    |
|--------|------------------------------------------|-------------|
| 1      | Arduino Nano                             | 1           |
| 2      | LED                                      | 5           |
| 3      | Current-limiting resistor (one per LED)  | 5           |
| 4      | Breadboard                               | 1           |
| 5      | Jumper Wires                             | As required |
| 6      | USB Cable and computer                   | 1           |

## Circuit Connections

| Arduino Pin | Connection                        | Purpose        |
|-------------|-----------------------------------|----------------|
| D2          | Through resistor → LED 1 anode    | LED 1 control  |
| D3          | Through resistor → LED 2 anode    | LED 2 control  |
| D4          | Through resistor → LED 3 anode    | LED 3 control  |
| D5          | Through resistor → LED 4 anode    | LED 4 control  |
| D6          | Through resistor → LED 5 anode    | LED 5 control  |
| GND         | All LED cathodes → GND            | Common ground  |

> Each LED must have its own current-limiting resistor. Connect the LED anode (longer leg) to the Arduino digital pin through the resistor, and the cathode (shorter leg) to GND.

## Important Note
For five independently driven LEDs, use one current-limiting resistor per LED. Do not operate multiple LEDs without proper current limiting.

## Build Procedure
1. Place five LEDs in a row on the breadboard.
2. Connect each LED to Arduino digital pins D2-D6 through a suitable current-limiting resistor.
3. Connect all LED cathodes to the common GND connection.
4. Connect the Arduino Nano to the computer using a USB cable.
5. Open the Arduino IDE and select the correct board and port.
6. Paste the pattern program and upload it to the Arduino Nano.
7. Observe the LEDs running from the first position to the fifth position and then back toward the center.

## Arduino Program
See [exp07_five_led_pattern.ino](exp07_five_led_pattern.ino)

```cpp
const int leds[] = {2, 3, 4, 5, 6};   // LED pins: D2 to D6
const int NUM_LEDS = 5;

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);   // Set each LED pin as output
  }
}

void loop() {
  // Forward: D2 -> D6
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i], HIGH);
    delay(150);
    digitalWrite(leds[i], LOW);
  }

  // Backward: D5 -> D3 (end LEDs are not repeated)
  for (int i = NUM_LEDS - 2; i >= 1; i--) {
    digitalWrite(leds[i], HIGH);
    delay(150);
    digitalWrite(leds[i], LOW);
  }
}
```

## Working Principle
The five LED pin numbers are stored in the `leds[]` array. In `setup()`, a for-loop configures D2-D6 as OUTPUT pins. In `loop()`, the first for-loop turns the LEDs on one at a time from D2 to D6, and each LED stays ON for 150 milliseconds before turning OFF. A second for-loop then moves backward from the fourth LED to the second LED (D5 → D4 → D3), producing a continuous scanner-style pattern without immediately repeating the end LEDs.

## LED Sequence

| Step   | LED Position | Pin | Action                 |
|--------|--------------|-----|------------------------|
| 1      | LED 1        | D2  | ON for 150 ms → OFF    |
| 2      | LED 2        | D3  | ON for 150 ms → OFF    |
| 3      | LED 3        | D4  | ON for 150 ms → OFF    |
| 4      | LED 4        | D5  | ON for 150 ms → OFF    |
| 5      | LED 5        | D6  | ON for 150 ms → OFF    |
| 6      | LED 4        | D5  | ON for 150 ms → OFF    |
| 7      | LED 3        | D4  | ON for 150 ms → OFF    |
| 8      | LED 2        | D3  | ON for 150 ms → OFF    |
| Repeat | LED 1        | D2  | Sequence starts again  |

## Result / Observation
The five LEDs glow sequentially from D2 to D6 and then move backward from D5 to D3. This creates a repeating scanner-style LED pattern. Each LED remains ON for approximately 150 ms.

## Experiment Parameters
Default delay: 150 ms per LED.
- Decrease the delay to make the scanner faster, for example `delay(75)`.
- Increase the delay to make the pattern slower, for example `delay(300)`.

## Quick Reference

| Pin / Item | Common Use in These Examples              |
|------------|-------------------------------------------|
| D2-D6      | LED digital outputs                       |
| D7         | IR sensor / button                        |
| D8         | Buzzer                                    |
| A0         | Potentiometer                             |
| D5         | PWM output for LED brightness             |
| D9         | BC547 transistor base in the final project |

## Conclusion
The experiment successfully demonstrates programmed control of five LEDs using Arduino Nano digital output pins D2-D6. It reinforces the use of arrays, for-loops, digital outputs and timing delays to create a visually programmed LED pattern.
