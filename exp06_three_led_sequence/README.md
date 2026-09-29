# Experiment 06: LED Patterns - Three LED Sequence

Arduino Nano | Digital Outputs | LEDs, Resistors & Breadboard

## Objective
To create a three-step LED sequence using multiple digital output pins of an Arduino Nano. The experiment demonstrates how arrays and for-loops can be used to control several LEDs one at a time.

## Components Required

| S. No. | Component                       | Quantity    |
|--------|---------------------------------|-------------|
| 1      | Arduino Nano                    | 1           |
| 2      | LED                             | 3           |
| 3      | Resistor (one for each LED)     | 3           |
| 4      | Breadboard                      | 1           |
| 5      | Jumper Wires                    | As required |
| 6      | USB Cable and computer          | 1           |

## Circuit Connections

| Arduino Pin | Connection                        | Purpose          |
|-------------|-----------------------------------|------------------|
| D2          | Through resistor → LED 1 anode    | LED 1 control    |
| D3          | Through resistor → LED 2 anode    | LED 2 control    |
| D4          | Through resistor → LED 3 anode    | LED 3 control    |
| GND         | All LED cathodes → GND            | Common ground    |

> **Important:** Use an individual current-limiting resistor for each LED. Connect the LED anode (longer leg) toward the Arduino output through the resistor, and the cathode (shorter leg) to GND.

## Build Procedure
1. Place three LEDs on the breadboard with enough space to identify them individually.
2. Connect one resistor in series with each LED.
3. Connect the three LED/resistor combinations to digital pins D2, D3 and D4.
4. Connect all LED cathodes to the Arduino GND rail.
5. Connect the Arduino Nano to the computer using a USB cable.
6. Open the Arduino IDE and select the correct board and port.
7. Paste the program given below and upload it to the Arduino Nano.
8. Observe the LEDs turning on one after another.
9. Change the delay value to adjust the speed of the sequence.

## Arduino Program
See [exp06_three_led_sequence.ino](exp06_three_led_sequence.ino)

```cpp
const int leds[] = {2, 3, 4};   // LED pins: D2, D3, D4
const int NUM_LEDS = 3;

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);   // Set each LED pin as output
  }
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i], HIGH);   // Turn LED ON
    delay(300);                    // Keep it ON for 300 ms
    digitalWrite(leds[i], LOW);    // Turn LED OFF
  }
}
```

## Working Principle
The program stores the three LED pin numbers (D2, D3 and D4) in an array named `leds[]`. In `setup()`, a for-loop configures each pin as an OUTPUT. In `loop()`, another for-loop selects each LED in sequence. The selected LED is switched ON using `digitalWrite(HIGH)`, kept ON for 300 milliseconds using `delay(300)`, and then switched OFF using `digitalWrite(LOW)`. The loop then moves to the next LED and repeats continuously.

## Sequence of Operation

| Step   | LED   | Arduino Pin | Action                  |
|--------|-------|-------------|-------------------------|
| 1      | LED 1 | D2          | ON for 300 ms → OFF     |
| 2      | LED 2 | D3          | ON for 300 ms → OFF     |
| 3      | LED 3 | D4          | ON for 300 ms → OFF     |
| Repeat | LED 1 | D2          | Sequence starts again   |

## Result / Observation
The three LEDs glow one after another in the order D2 → D3 → D4. Each LED remains ON for approximately 300 ms before turning OFF, producing a repeating three-step LED sequence.

## Experiment Parameters
Default sequence delay: 300 ms per LED.
- To make the sequence faster, reduce the delay value (for example, `delay(100)`).
- To make it slower, increase the delay value (for example, `delay(500)`).

## Quick Reference

| Pin / Item | Common Use in These Examples          |
|------------|---------------------------------------|
| D2-D6      | LED digital outputs                   |
| D7         | IR sensor / button                    |
| D8         | Buzzer                                |
| A0         | Potentiometer                         |
| D5         | PWM output for LED brightness         |
| D9         | BC547 transistor base in final project |

## Conclusion
The experiment successfully demonstrates sequential control of multiple LEDs using Arduino Nano digital output pins. It also introduces the practical use of arrays and for-loops, which make it easier to control multiple components with compact Arduino code.
