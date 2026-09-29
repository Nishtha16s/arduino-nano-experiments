# Experiment 16: Push Button & Buzzer - Button Controlled Buzzer

Arduino Nano | Push Button Input | Buzzer Output | INPUT_PULLUP

## Objective
To learn how to use a push button as an input and control a buzzer using an Arduino Nano.

## Introduction
A push button is an input device that allows the user to give a signal to the Arduino. In this project, the push button is connected to digital pin D3 and the buzzer is connected to digital pin D8. When the button is pressed, the Arduino generates a 1 kHz tone through the buzzer. When the button is released, the buzzer stops.

The Arduino uses the `INPUT_PULLUP` mode, so an external resistor is not required for the push button.

## Components Required

| S. No. | Component    | Quantity    |
|--------|--------------|-------------|
| 1      | Arduino Nano | 1           |
| 2      | Push Button  | 1           |
| 3      | Buzzer       | 1           |
| 4      | Breadboard   | 1           |
| 5      | Jumper Wires | As required |
| 6      | USB Cable    | 1           |

## Circuit Connections

| Component           | Connection |
|---------------------|------------|
| Push Button         | One side → D3 |
| Push Button         | Other side → GND |
| Buzzer Positive (+) | → D8 |
| Buzzer Negative (-) | → GND |

## Connection Explanation

**Push Button:** The push button is connected between D3 and GND. Pin D3 is configured as `INPUT_PULLUP`, so the Arduino normally reads the pin as HIGH. When the button is pressed, the pin is connected to GND and the Arduino reads LOW.

**Buzzer:** The positive terminal of the buzzer is connected to D8 and the negative terminal is connected to GND. When the button is pressed, the Arduino uses D8 to generate a 1 kHz tone, which makes the buzzer produce sound.

## Build Steps
1. Place the push button on the breadboard.
2. Connect one side of the push button to D3 of the Arduino Nano.
3. Connect the other side of the push button to GND.
4. Connect the positive terminal of the buzzer to D8.
5. Connect the negative terminal of the buzzer to GND.
6. Connect the Arduino Nano to the computer using a USB cable.
7. Select the correct Board and Port in Arduino IDE.
8. Upload the given Arduino sketch.
9. Press the push button.
10. Observe that the buzzer produces sound.
11. Release the button and observe that the buzzer stops.

## Arduino Code
See [exp16_button_controlled_buzzer.ino](exp16_button_controlled_buzzer.ino)

```cpp
const int BTN = 3;    // Push button (active-LOW with INPUT_PULLUP)
const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(BTN, INPUT_PULLUP);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  if (digitalRead(BTN) == LOW) {
    tone(BUZZ, 1000);   // Button pressed: play 1 kHz tone
  } else {
    noTone(BUZZ);       // Button released: stop the tone
  }
}
```

## How the Program Works
- `BTN = 3` assigns digital pin D3 to the push button.
- `BUZZ = 8` assigns digital pin D8 to the buzzer.
- `INPUT_PULLUP` activates the Arduino's internal pull-up resistor.
- When the button is not pressed, D3 reads HIGH.
- When the button is pressed, D3 reads LOW.
- `tone(BUZZ, 1000)` generates a 1000 Hz (1 kHz) sound on D8.
- `noTone(BUZZ)` stops the buzzer sound.

## Working Principle
The project works on a simple input → processing → output principle.

- **Button Pressed:** D3 reads LOW → Arduino detects button press → D8 generates 1 kHz tone → Buzzer sounds
- **Button Released:** D3 reads HIGH → Arduino detects release → `noTone()` → Buzzer stops

## Expected Output

| Button Condition | Arduino Input | Buzzer |
|------------------|---------------|--------|
| Not Pressed      | HIGH          | OFF    |
| Pressed          | LOW           | ON     |
| Released         | HIGH          | OFF    |

## Learning Outcomes
- How a push button works as an input device.
- How to use `INPUT_PULLUP`.
- How Arduino reads digital input.
- How to control a buzzer using a digital output.
- How the `tone()` and `noTone()` functions work.
- How an input device can control an output device.

## Result
The push button successfully controls the buzzer. The buzzer produces a 1 kHz tone when the button is pressed and stops when the button is released.

## Precautions
1. Check the buzzer polarity before making the connections.
2. Make sure the button connections are correct.
3. Ensure that GND connections are properly connected.
4. Select the correct Arduino board and COM port before uploading.
5. Do not make or change connections while the circuit is powered.

## Quick Reference

| Arduino Pin | Common Use                        |
|-------------|-----------------------------------|
| D2-D6       | LEDs in many examples             |
| D7          | IR sensor / button                |
| D8          | Buzzer                            |
| D5          | PWM / brightness control          |
| D9          | BC547 base in the final project   |
| A0          | Potentiometer                     |
