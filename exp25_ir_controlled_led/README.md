# Experiment 25: IR Sensor & Automation - IR Controlled LED

Arduino Nano | IR Obstacle Sensor | Digital Input | Sensor-Based Automation

## Objective
To learn how to automatically control an LED using an IR obstacle sensor when an object is detected.

## Introduction
An IR obstacle sensor can detect an object by sensing reflected infrared light. The sensor provides a digital output signal to the Arduino Nano.

In this experiment, the IR sensor is connected to digital pin D7 and the LED is connected to digital pin D2 through a resistor. When an object is detected by the IR sensor, the Arduino turns the LED ON. When no object is detected, the LED remains OFF. This experiment demonstrates a simple example of sensor-based automation.

## Components Required

| S. No. | Component                   | Quantity    |
|--------|-----------------------------|-------------|
| 1      | Arduino Nano                | 1           |
| 2      | IR Obstacle Sensor Module   | 1           |
| 3      | LED                         | 1           |
| 4      | 220Ω / 330Ω Resistor        | 1           |
| 5      | Breadboard                  | 1           |
| 6      | Jumper Wires                | As required |
| 7      | USB Cable                   | 1           |

## Circuit Connections

**IR Sensor**

| IR Sensor Pin | Arduino Nano |
|---------------|--------------|
| VCC           | 5V           |
| GND           | GND          |
| OUT           | D7           |

**LED**

| LED Connection      | Arduino Nano          |
|---------------------|-----------------------|
| Anode (long leg)    | D2 through resistor   |
| Cathode (short leg) | GND                   |

## Connection Explanation
The IR sensor receives power from the Arduino through the VCC and GND pins. Its OUT pin is connected to D7, which allows the Arduino to read the sensor's digital detection signal.

The LED is connected to D2 through a 220Ω/330Ω resistor. The resistor limits the current flowing through the LED and protects it from excessive current. When the IR sensor detects an object, its output becomes LOW. The Arduino detects this LOW signal and turns the LED ON.

## Build Steps
1. Place the IR sensor module on the breadboard.
2. Connect IR VCC to Arduino 5V.
3. Connect IR GND to Arduino GND.
4. Connect IR OUT to Arduino D7.
5. Place the LED on the breadboard.
6. Connect the LED anode through a 220Ω/330Ω resistor to D2.
7. Connect the LED cathode to GND.
8. Connect the Arduino Nano to the computer using USB.
9. Select the correct board and port in the Arduino IDE.
10. Upload the sketch.
11. Move an object in front of the IR sensor.
12. Observe the LED turn ON during detection.

## Arduino Code
See [exp25_ir_controlled_led.ino](exp25_ir_controlled_led.ino)

```cpp
const int IR = 7;    // IR sensor OUT pin connected to D7
const int LED = 2;   // LED connected to D2

void setup() {
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    digitalWrite(LED, HIGH);   // Object detected: LED ON
  } else {
    digitalWrite(LED, LOW);    // No object: LED OFF
  }
}
```

## How the Program Works
- `IR = 7` defines D7 as the IR sensor input.
- `LED = 2` defines D2 as the LED output.
- `pinMode(IR, INPUT)` configures D7 to receive the sensor signal.
- `pinMode(LED, OUTPUT)` configures D2 to control the LED.
- `digitalRead(IR)` reads the current state of the IR sensor.
- If the sensor output is LOW, the LED is turned ON.
- If the sensor output is HIGH, the LED is turned OFF.
- The Arduino continuously repeats this process.

## Working Principle
Object → IR Sensor Detects Reflection → OUT Becomes LOW → Arduino Reads D7 → LED Turns ON

When the object is removed:

No Object → Sensor OUT Becomes HIGH → Arduino Reads D7 → LED Turns OFF

The Arduino continuously monitors the sensor and immediately changes the LED state according to the sensor output.

## Sensor and LED Logic

| IR Sensor State  | Arduino Input | LED |
|------------------|---------------|-----|
| Object detected  | LOW           | ON  |
| No object        | HIGH          | OFF |

> **Note:** This LOW/HIGH behavior is common for digital IR obstacle sensor modules. Some modules may have opposite output logic. If the LED works in reverse, check the sensor module's output behavior.

## Expected Output
- No object in front of the IR sensor: LED is OFF.
- Object placed in front of the IR sensor: LED is ON.
- Object moved away: LED is OFF.

The LED automatically follows the detection state of the IR sensor.

## Understanding Sensor-Based Automation
This experiment demonstrates a basic automation system:

Input → Processing → Output

- **Input:** IR sensor
- **Processing:** Arduino Nano
- **Output:** LED

The IR sensor provides information about the surroundings, the Arduino processes the sensor signal, and the LED responds automatically.

## Learning Outcomes
- How an IR sensor can be used for automation.
- How to read a digital sensor using `digitalRead()`.
- How to control an LED using `digitalWrite()`.
- How sensors can automatically control outputs.
- The importance of using a resistor with an LED.
- The basic concept of input → processing → output.

## Precautions
1. Connect IR VCC to 5V and GND to GND correctly.
2. Connect IR OUT to D7.
3. Always use a 220Ω/330Ω resistor with the LED.
4. Check the LED polarity before powering the circuit.
5. Keep the IR sensor surface clean.
6. Adjust the IR sensor potentiometer if the detection range needs adjustment.
7. Check all connections before uploading the program.
8. Do not change circuit connections while the Arduino is powered.
9. If the LED works in reverse, check the sensor's output logic.

## Quick Reference

| Pin   | Common Use                    |
|-------|-------------------------------|
| D2-D6 | LEDs in many examples         |
| D7    | IR sensor / button            |
| D8    | Buzzer                        |
| A0    | Potentiometer                 |
| D5    | PWM pin for brightness        |
| D9    | BC547 base in final project   |

## Result
The Arduino Nano successfully controlled an LED using an IR obstacle sensor. When an object was detected, the LED turned ON, and when the object was removed, the LED turned OFF. This demonstrated the basic concept of sensor-based automation.
