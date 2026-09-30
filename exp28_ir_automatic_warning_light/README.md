# Experiment 28: IR Sensor & Automation - IR Automatic Warning Light

Arduino Nano | IR Obstacle Sensor | LED | Flashing Warning Indicator

## Objective
To create a flashing warning light that automatically activates when an object is detected by an IR sensor.

## Introduction
An IR Automatic Warning Light is a simple sensor-based automation project. It uses an IR sensor to detect an object and an LED to provide a visual warning.

When an object is detected, the Arduino makes the LED blink continuously. When the object is removed, the LED turns OFF. This project demonstrates how a sensor can automatically control a warning indicator.

## Components Required

| S. No. | Component            | Quantity    | Purpose                              |
|--------|----------------------|-------------|--------------------------------------|
| 1      | Arduino Nano         | 1           | Controls the warning light           |
| 2      | IR Sensor Module     | 1           | Detects an object                    |
| 3      | LED                  | 1           | Provides flashing warning indication |
| 4      | 220Ω / 330Ω Resistor | 1           | Protects the LED                     |
| 5      | Breadboard           | 1           | Makes circuit connections easy       |
| 6      | Jumper Wires         | As required | Connects components                  |
| 7      | USB Cable            | 1           | Powers and programs the Arduino      |

## Circuit Connections

**IR Sensor**

| IR Sensor Pin | Arduino Nano |
|---------------|--------------|
| VCC           | 5V           |
| GND           | GND          |
| OUT           | D7           |

**LED**

| LED Connection          | Arduino Nano                     |
|-------------------------|----------------------------------|
| D2                      | Resistor → LED Anode (long leg)  |
| LED Cathode (short leg) | GND                              |

## Connection Explanation

**IR Sensor**
- VCC is connected to 5V to power the sensor.
- GND is connected to Arduino GND.
- OUT is connected to D7.
- D7 allows the Arduino to read the sensor's digital detection signal.

**LED**
- The LED is controlled through D2.
- A 220Ω or 330Ω resistor is connected in series with the LED.
- The resistor limits current and protects the LED.
- The LED cathode is connected to GND.

## Build Steps
1. Place the IR sensor on the breadboard.
2. Connect IR VCC to Arduino 5V.
3. Connect IR GND to Arduino GND.
4. Connect IR OUT to D7.
5. Connect D2 to a 220Ω/330Ω resistor.
6. Connect the resistor to the LED anode.
7. Connect the LED cathode to GND.
8. Connect the Arduino Nano to the computer using USB.
9. Upload the warning light program.
10. Place an object near the IR sensor.
11. Observe the LED flashing while the object is detected.
12. Remove the object and observe that the LED stops flashing.

## Arduino Code
See [exp28_ir_automatic_warning_light.ino](exp28_ir_automatic_warning_light.ino)

```cpp
const int IR = 7;    // IR sensor OUT pin connected to D7
const int LED = 2;   // Warning LED connected to D2

void setup() {
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    // Object detected: flash the LED
    digitalWrite(LED, HIGH);
    delay(150);
    digitalWrite(LED, LOW);
    delay(150);
  } else {
    digitalWrite(LED, LOW);   // No object: LED OFF
  }
}
```

## How the Program Works
The Arduino continuously checks the IR sensor using `digitalRead(IR)`.

When the sensor detects an object and gives a LOW signal:
1. The LED turns ON.
2. The Arduino waits for 150 milliseconds.
3. The LED turns OFF.
4. The Arduino waits for another 150 milliseconds.
5. The process repeats while the object remains detected.

When the object is removed, the LED remains OFF.

## Working Principle
The IR sensor detects an object using reflected infrared light. When an object enters the sensor's detection range, the sensor sends a digital signal to the Arduino through D7. The Arduino detects the LOW signal and starts repeatedly switching the LED ON and OFF.

Object Detected → IR Sensor → Arduino → LED ON/OFF → Flashing Warning

When there is no object:

No Object → IR Sensor → Arduino → LED OFF

## Warning Light Logic

| Condition        | IR Output | LED Action |
|------------------|-----------|------------|
| No object        | HIGH      | OFF        |
| Object detected  | LOW       | Flashing   |

> **Note:** Many common IR obstacle sensor modules use LOW for object detection. Some modules may have opposite output logic.

## Understanding the Flashing Pattern
The program uses `delay(150);`, so the LED stays:
- ON for 150 ms
- OFF for 150 ms

This creates a continuous flashing effect while the object is detected. The complete ON + OFF cycle is 150 ms + 150 ms = 300 ms, so the LED completes approximately 3.3 flash cycles per second while detection continues.

## Why the LED Stops Flashing
The `else` section of the program is executed when the IR sensor does not detect an object:

```cpp
else {
  digitalWrite(LED, LOW);
}
```

This keeps the LED OFF until another object is detected.

## Expected Output
- No object detected: LED is OFF.
- Object detected: LED flashes ON → OFF → ON → OFF continuously.

The flashing continues as long as the object remains within the sensor's detection range.

## Applications
This type of warning system can be used as a basic concept for:
- Entry warning lights
- Restricted-area indicators
- Object detection warnings
- Parking-area indicators
- Machine safety indicators
- Automatic alert systems

## Learning Outcomes
- How an IR sensor detects objects.
- How the Arduino reads a digital sensor.
- How to control an LED using Arduino.
- How `delay()` can create a flashing effect.
- How a sensor can automatically control a warning indicator.
- How ON/OFF timing affects LED blinking speed.

## Precautions
- Always use a 220Ω or 330Ω resistor with the LED.
- Check the LED polarity before powering the circuit.
- Connect IR sensor VCC and GND correctly.
- Do not connect 5V directly to GND.
- Keep jumper wires properly connected.

## Quick Reference

| Pin   | Common Use                    |
|-------|-------------------------------|
| D2-D6 | LEDs in many examples         |
| D7    | IR sensor / button            |
| D8    | Buzzer                        |
| A0    | Potentiometer                 |
| D5    | PWM brightness control        |
| D9    | BC547 base in final project   |

## Result
The IR Automatic Warning Light was successfully built using an Arduino Nano, an IR sensor, and an LED. When an object was detected, the LED flashed continuously, and when the object was removed, the LED turned OFF. This demonstrated how a sensor can automatically control a flashing warning indicator.
