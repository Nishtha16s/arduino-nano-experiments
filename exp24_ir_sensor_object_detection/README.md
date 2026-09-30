# Experiment 24: IR Sensor & Automation - IR Sensor Introduction & Object Detection

Arduino Nano | IR Obstacle Sensor | Digital Input | Serial Monitor

## Objective
To learn how a digital IR obstacle sensor detects the presence of an object using reflected infrared light.

## Introduction
An IR (Infrared) obstacle sensor is used to detect objects placed in front of it. The sensor sends infrared light and detects the light reflected back from an object.

The IR sensor module provides a digital output signal. When an object is detected, the output is commonly LOW, and when no object is detected, the output is commonly HIGH.

In this experiment, the sensor output is connected to digital pin D7 of the Arduino Nano. The detected status is displayed on the Serial Monitor.

## Components Required

| S. No. | Component                   | Quantity    |
|--------|-----------------------------|-------------|
| 1      | Arduino Nano                | 1           |
| 2      | IR Obstacle Sensor Module   | 1           |
| 3      | Jumper Wires                | As required |
| 4      | USB Cable                   | 1           |

## Circuit Connections

| IR Sensor Pin | Arduino Nano |
|---------------|--------------|
| VCC           | 5V           |
| GND           | GND          |
| OUT           | D7           |

## Connection Explanation
The IR sensor module has three main pins:
- **VCC:** provides 5V power to the sensor.
- **GND:** provides the common ground connection.
- **OUT:** sends the digital detection signal to Arduino D7.

The sensor detects reflected infrared light from an object and changes its OUT signal accordingly.

## Build Steps
1. Place the IR sensor module on the breadboard.
2. Connect IR VCC to Arduino 5V.
3. Connect IR GND to Arduino GND.
4. Connect IR OUT to Arduino D7.
5. Connect the Arduino Nano to the computer using USB.
6. Select the correct board and port in the Arduino IDE.
7. Upload the sketch.
8. Open the Serial Monitor.
9. Set the Serial Monitor baud rate to 9600.
10. Place an object in front of the IR sensor.
11. Observe the detected / not-detected message.

## Arduino Code
See [exp24_ir_sensor_object_detection.ino](exp24_ir_sensor_object_detection.ino)

```cpp
const int IR = 7;   // IR sensor OUT pin connected to D7

void setup() {
  pinMode(IR, INPUT);
  Serial.begin(9600);   // Start serial communication at 9600 baud
}

void loop() {
  int state = digitalRead(IR);   // Read the sensor output

  if (state == LOW) {
    Serial.println("Object detected");   // LOW = object in front of sensor
  } else {
    Serial.println("No object");         // HIGH = no object
  }

  delay(200);   // Short delay between readings
}
```

## How the Program Works
- `IR = 7` defines D7 as the IR sensor input.
- `pinMode(IR, INPUT)` configures D7 as an input.
- `Serial.begin(9600)` starts serial communication at 9600 baud.
- `digitalRead(IR)` reads the digital signal from the sensor.
- If the signal is LOW, the Arduino prints "Object detected".
- If the signal is HIGH, the Arduino prints "No object".
- `delay(200)` provides a short delay between readings.

## Working Principle
IR Sensor → Sends Infrared Light → Light Reflects from Object → Sensor Detects Reflection → Digital Signal → Arduino Reads D7 → Detection Message

The IR module continuously checks the area in front of its sensor. When an object reflects enough infrared light back to the receiver, the sensor changes its digital output.

## Sensor Output Logic

| IR Sensor State  | Arduino Input | Serial Monitor  |
|------------------|---------------|-----------------|
| Object detected  | LOW           | Object detected |
| No object        | HIGH          | No object       |

> **Note:** This LOW/HIGH behavior is common for digital IR obstacle sensor modules, but some modules may have opposite output logic. Always check the specific module if the result appears reversed.

## Serial Monitor
To observe the sensor output:
1. Upload the program.
2. Open **Tools → Serial Monitor**.
3. Set the baud rate to 9600.
4. Keep the sensor clear and observe the message.
5. Place an object in front of the sensor.
6. Observe the message change.

Example output:

```text
No object
No object
Object detected
Object detected
No object
```

## IR Sensor Adjustment
Many IR obstacle sensor modules have a small potentiometer. It can be used to adjust the sensor's detection sensitivity or range.

1. Place an object at the desired detection distance.
2. Slowly rotate the sensor potentiometer.
3. Observe the sensor's indicator LED, if available.
4. Stop when the sensor detects the object reliably.

## Expected Output
- No object in front of the sensor: `No object`
- Object placed in front of the sensor: `Object detected`

The message changes automatically as the object moves into or out of the sensor's detection area.

## Learning Outcomes
- What an IR obstacle sensor is.
- How reflected infrared light is used for object detection.
- How a digital sensor provides HIGH/LOW output.
- How to use `digitalRead()`.
- How to display sensor data using the Serial Monitor.
- How to adjust an IR sensor's detection range.

## Precautions
1. Connect VCC to 5V and GND to GND correctly.
2. Connect the sensor OUT pin to D7.
3. Check the sensor connections before powering the Arduino.
4. Keep the sensor surface clean for reliable detection.
5. Avoid very bright external light directly entering the sensor.
6. Adjust the sensor potentiometer slowly if required.
7. Do not change circuit connections while the Arduino is powered.
8. If the detection result appears reversed, check the sensor module's output logic.

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
The Arduino Nano successfully read the digital output of the IR obstacle sensor and displayed whether an object was detected or not on the Serial Monitor. The experiment demonstrated the basic principle of IR-based object detection and digital sensor input.
