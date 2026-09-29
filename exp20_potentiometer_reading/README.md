# Experiment 20: Potentiometer & PWM - Potentiometer Value Reading

Arduino Nano | Analog Input | analogRead() | Serial Monitor

## Objective
To learn how to read an analog input from a potentiometer using the Arduino Nano and display its value on the Serial Monitor.

## Introduction
A potentiometer is a variable resistor that can be used to control voltage. By rotating its knob, the output voltage from the middle pin changes.

In this experiment, the potentiometer is connected to the A0 analog input pin of the Arduino Nano. The Arduino reads the changing voltage and converts it into a numerical value between approximately 0 and 1023. The value is displayed on the Serial Monitor at a baud rate of 9600.

## Components Required

| S. No. | Component           | Quantity    |
|--------|---------------------|-------------|
| 1      | Arduino Nano        | 1           |
| 2      | 10k Potentiometer   | 1           |
| 3      | Breadboard          | 1           |
| 4      | Jumper Wires        | As required |
| 5      | USB Cable           | 1           |

## Circuit Connections

| Potentiometer Pin | Arduino Connection |
|-------------------|--------------------|
| One outer pin     | 5V                 |
| Other outer pin   | GND                |
| Middle pin        | A0                 |

## Connection Explanation
A potentiometer generally has three pins.
- One outer pin is connected to 5V.
- The other outer pin is connected to GND.
- The middle pin is connected to A0.

The middle pin provides a variable voltage depending on the position of the potentiometer knob. When the knob is rotated, the voltage at A0 changes. The Arduino reads this voltage using its built-in analog-to-digital converter.

## Build Steps
1. Place the 10k potentiometer on the breadboard.
2. Connect one outer pin of the potentiometer to 5V.
3. Connect the other outer pin to GND.
4. Connect the middle pin to A0.
5. Connect the Arduino Nano to the computer using a USB cable.
6. Open the Arduino IDE.
7. Select the correct Board and Port.
8. Upload the given Arduino sketch.
9. Open the Serial Monitor.
10. Set the baud rate to 9600.
11. Slowly rotate the potentiometer knob.
12. Observe the changing values on the Serial Monitor.

## Arduino Code
See [exp20_potentiometer_reading.ino](exp20_potentiometer_reading.ino)

```cpp
const int POT = A0;   // Potentiometer middle pin connected to A0

void setup() {
  Serial.begin(9600);   // Start serial communication at 9600 baud
}

void loop() {
  int value = analogRead(POT);   // Read analog value (0 to 1023)
  Serial.println(value);         // Print the value on Serial Monitor
  delay(200);                    // Wait 200 ms before next reading
}
```

## How the Program Works
- `POT = A0` assigns analog pin A0 to the potentiometer.
- `Serial.begin(9600)` starts serial communication at 9600 baud.
- `analogRead(POT)` reads the voltage present at A0.
- The Arduino converts the analog voltage into a value from approximately 0 to 1023.
- `Serial.println(value)` displays the value on the Serial Monitor.
- `delay(200)` waits for 200 milliseconds before taking the next reading.

## Working Principle
The potentiometer produces a variable voltage according to the position of its knob.

Rotate Potentiometer → Voltage at A0 changes → Arduino reads voltage → Value converted to 0-1023 → Value displayed on Serial Monitor

When the knob is rotated in one direction, the reading moves toward one end of the range. Rotating it in the opposite direction moves the reading toward the other end.

## Expected Output
The Serial Monitor will display values similar to:

```
0
125
284
512
746
895
1023
```

The exact values may vary depending on the potentiometer position and the circuit.

## Analog Value Range

| Potentiometer Position | Approximate Reading |
|------------------------|---------------------|
| Minimum                | 0                   |
| Low                    | 1-300               |
| Middle                 | Around 512          |
| High                   | 700-1000            |
| Maximum                | 1023                |

## Serial Monitor
After uploading the program:
1. Open **Tools → Serial Monitor** in the Arduino IDE.
2. Set the baud rate to 9600.
3. Rotate the potentiometer.
4. Observe the changing numerical values.

The Serial Monitor allows us to see the analog readings received by the Arduino.

## Learning Outcomes
- What an analog input is.
- How a potentiometer works.
- How to connect a potentiometer to Arduino.
- How `analogRead()` works.
- How Arduino converts analog voltage into a numerical value.
- How to display sensor values using the Serial Monitor.
- How rotating a potentiometer changes an analog reading.

## Precautions
1. Make sure the potentiometer's middle pin is connected to A0.
2. Do not accidentally connect 5V and GND directly together.
3. Check all connections before powering the Arduino.
4. Set the Serial Monitor to 9600 baud.
5. Rotate the potentiometer slowly while observing the readings.
6. Do not change circuit connections while the Arduino is powered.

## Quick Reference

| Arduino Pin | Common Use                        |
|-------------|-----------------------------------|
| D2-D6       | LEDs in many examples             |
| D7          | IR sensor / button                |
| D8          | Buzzer                            |
| A0          | Potentiometer                     |
| D5          | PWM / brightness control          |
| D9          | BC547 base in the final project   |

## Result
The Arduino Nano successfully read the variable voltage from the potentiometer and displayed the corresponding analog value on the Serial Monitor. The value changed approximately from 0 to 1023 as the potentiometer knob was rotated.
