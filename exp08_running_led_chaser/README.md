# Experiment 08: LED Patterns - Running LED / Chaser Light

Arduino Nano | Five LEDs | Running-Light Effect

## Objective
To build a moving light effect using five LEDs connected to an Arduino Nano and to practice the use of arrays, loops, digital outputs and timing delays.

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

> Connect each LED through its own current-limiting resistor. The LED anode (longer leg) connects toward the Arduino pin through the resistor, while the cathode (shorter leg) connects to GND.

## Important Note
Five independently controlled LEDs normally require five current-limiting resistors. Do not operate multiple LEDs without proper current limiting.

## Build Procedure
1. Place five LEDs in a row on the breadboard.
2. Connect each LED through its resistor to Arduino digital pins D2-D6.
3. Connect all LED cathodes to the common GND connection.
4. Connect the Arduino Nano to the computer using a USB cable.
5. Open the Arduino IDE and select the correct board and port.
6. Paste the chaser program and upload it to the Arduino Nano.
7. Observe the ON state moving from one LED to the next.
8. Change the delay value to make the chaser faster or slower.

## Arduino Program
See [exp08_running_led_chaser.ino](exp08_running_led_chaser.ino)

```cpp
const int leds[] = {2, 3, 4, 5, 6};   // LED pins: D2 to D6
const int NUM_LEDS = 5;

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);   // Set each LED pin as output
  }
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i], HIGH);   // Turn LED ON
    delay(120);                    // Keep it ON for 120 ms
    digitalWrite(leds[i], LOW);    // Turn LED OFF
  }
}
```

## Working Principle
The five LED pin numbers are stored in the `leds[]` array. In `setup()`, a for-loop sets D2-D6 as OUTPUT pins. In `loop()`, another for-loop selects each LED in order. The selected LED is switched ON using `digitalWrite(HIGH)`, remains ON for 120 milliseconds, and is then switched OFF. The loop immediately moves to the next LED. When the fifth LED is completed, the sequence starts again, creating a continuous running-light or chaser effect.

## LED Sequence

| Step   | LED Position | Pin | Action                 |
|--------|--------------|-----|------------------------|
| 1      | LED 1        | D2  | ON for 120 ms → OFF    |
| 2      | LED 2        | D3  | ON for 120 ms → OFF    |
| 3      | LED 3        | D4  | ON for 120 ms → OFF    |
| 4      | LED 4        | D5  | ON for 120 ms → OFF    |
| 5      | LED 5        | D6  | ON for 120 ms → OFF    |
| Repeat | LED 1        | D2  | Sequence starts again  |

## Result / Observation
The five LEDs light up one after another from D2 to D6 and then the sequence repeats. This produces a continuous moving-light or chaser-light effect. Each LED remains ON for approximately 120 ms.

## Experiment Parameters
Default delay: 120 ms per LED.
- Reduce the delay to make the chaser faster, for example `delay(60)`.
- Increase the delay to make the chaser slower, for example `delay(250)`.

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
The experiment successfully demonstrates a running LED/chaser effect using five Arduino Nano digital outputs. The activity reinforces the use of arrays and for-loops to control multiple outputs efficiently and shows how changing a delay value affects the speed of a visual sequence.
