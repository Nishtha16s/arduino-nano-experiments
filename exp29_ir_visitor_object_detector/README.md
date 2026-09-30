# Experiment 29: IR Sensor & Automation - IR Visitor / Object Detector

Arduino Nano | IR Obstacle Sensor | LED | Buzzer | Entry Alert

## Objective
To create a simple entry detector that provides a light and sound indication whenever an object passes in front of the IR sensor.

## Introduction
An IR Visitor / Object Detector is a simple sensor-based automation project. It uses an IR sensor to detect an object passing through a particular area.

When an object is detected, the Arduino briefly turns ON an LED and produces a short buzzer sound. This gives a simple visual and audio indication that something has passed the sensor. The project can be demonstrated as a basic entry alert or visitor detection system.

## Components Required

| S. No. | Component            | Quantity    | Purpose                          |
|--------|----------------------|-------------|----------------------------------|
| 1      | Arduino Nano         | 1           | Controls the detection system    |
| 2      | IR Sensor Module     | 1           | Detects passing objects          |
| 3      | LED                  | 1           | Provides visual indication       |
| 4      | 220Ω / 330Ω Resistor | 1           | Protects the LED                 |
| 5      | Buzzer               | 1           | Provides audio indication        |
| 6      | Breadboard           | 1           | Makes circuit connections easy   |
| 7      | Jumper Wires         | As required | Connects components              |
| 8      | USB Cable            | 1           | Powers and programs the Arduino  |

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

**Buzzer**

| Buzzer Pin   | Arduino Nano |
|--------------|--------------|
| Positive (+) | D8           |
| Negative (-) | GND          |

## Connection Explanation

**IR Sensor**
- VCC is connected to 5V to power the sensor.
- GND is connected to Arduino GND.
- OUT is connected to D7.
- D7 receives the digital detection signal from the sensor.

**LED**
- The LED is controlled using D2.
- A 220Ω or 330Ω resistor is connected in series with the LED.
- The resistor limits current and protects the LED.
- The LED cathode is connected to GND.

**Buzzer**
- The positive terminal is connected to D8.
- The negative terminal is connected to GND.
- The Arduino uses D8 to generate the short alert sound.

## Build Steps
1. Position the IR sensor facing the path where an object will pass.
2. Connect IR VCC to Arduino 5V.
3. Connect IR GND to Arduino GND.
4. Connect IR OUT to D7.
5. Connect the LED to D2 through a 220Ω/330Ω resistor.
6. Connect the LED cathode to GND.
7. Connect the buzzer positive terminal to D8.
8. Connect the buzzer negative terminal to GND.
9. Connect the Arduino Nano to the computer using USB.
10. Upload the visitor/object detector program.
11. Pass an object in front of the IR sensor.
12. Observe the short LED and buzzer indication.

## Arduino Code
See [exp29_ir_visitor_object_detector.ino](exp29_ir_visitor_object_detector.ino)

```cpp
const int IR = 7;     // IR sensor OUT pin connected to D7
const int LED = 2;    // Indicator LED connected to D2
const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    digitalWrite(LED, HIGH);    // Object detected: LED ON
    tone(BUZZ, 1200, 150);      // Short 1200 Hz beep for 150 ms
    delay(300);
    digitalWrite(LED, LOW);     // LED OFF
    delay(300);                 // Pause before checking again
  }
}
```

## How the Program Works
The Arduino continuously checks the IR sensor using `digitalRead(IR)`.

When the IR sensor detects an object and gives a LOW signal:
1. The LED turns ON.
2. The buzzer produces a 1200 Hz sound for 150 milliseconds.
3. The Arduino waits for 300 milliseconds.
4. The LED turns OFF.
5. The Arduino waits for another 300 milliseconds.
6. The Arduino continues checking for the next detection.

## Working Principle
The IR sensor uses infrared light to detect an object in front of it. When an object passes through the sensor's detection area, the sensor output changes. The Arduino reads this signal through D7. When the signal is LOW, the Arduino activates the LED and buzzer for a short indication.

Object Passes → IR Sensor Detects → Arduino → LED + Buzzer Indication

## Visitor Detection Logic

| Condition        | IR Output | LED         | Buzzer      |
|------------------|-----------|-------------|-------------|
| No object        | HIGH      | OFF         | OFF         |
| Object detected  | LOW       | Briefly ON  | Short sound |

> **Note:** Many common IR obstacle sensor modules use LOW for detection, but some modules may have opposite output logic.

## Understanding tone()
The program uses:

```cpp
tone(BUZZ, 1200, 150);
```

- `BUZZ`: the buzzer is connected to D8.
- `1200`: the sound frequency is 1200 Hz.
- `150`: the sound duration is 150 milliseconds.

After the specified duration, the tone stops automatically, so `noTone()` is not needed here.

## Understanding the Delay
The program uses `delay(300);` after the detection. The Arduino waits for 300 milliseconds before turning the LED OFF, and another 300 milliseconds before checking for the next detection. This creates a clear, short indication instead of keeping the alarm continuously active.

## Expected Output
- No object detected: LED is OFF and buzzer is OFF.
- Object passes in front of the sensor: LED is briefly ON and the buzzer gives a short sound.

The system then returns to monitoring for another object.

## Entry Alert Demonstration
This project can be demonstrated by placing the IR sensor at the entrance of a small model area. When a person or object passes in front of the sensor:

Entry → Detection → Light Indication + Sound Indication

This demonstrates the basic concept of an automatic visitor or entry alert system.

## Learning Outcomes
- How an IR sensor detects an object.
- How the Arduino reads a digital sensor signal.
- How to control an LED using Arduino.
- How to generate a short buzzer sound.
- How `tone()` can create a timed sound.
- How a sensor can trigger multiple outputs.
- How basic visitor detection systems work.

## Precautions
- Always use a 220Ω or 330Ω resistor with the LED.
- Check the LED polarity before powering the circuit.
- Check the buzzer polarity before connecting it.
- Connect IR sensor VCC and GND correctly.
- Do not connect 5V directly to GND.
- Keep jumper wires properly connected.
- Adjust the IR sensor's sensitivity potentiometer if required.

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
The IR Visitor / Object Detector was successfully built using an Arduino Nano, an IR sensor, an LED, and a buzzer. When an object passed in front of the sensor, the LED turned ON briefly and the buzzer gave a short sound, demonstrating a simple entry alert system.
