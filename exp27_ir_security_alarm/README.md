# Experiment 27: IR Sensor & Automation - IR Security Alarm

Arduino Nano | IR Obstacle Sensor | LED | Buzzer | Security Alarm

## Objective
To build a basic intrusion/security alarm using an IR sensor, LED, and buzzer. The system detects an object and activates both visual and audio alerts.

## Introduction
An IR Security Alarm is a simple automation project that uses an IR sensor to detect an object entering a monitored area.

The IR sensor sends a digital signal to the Arduino. When an object is detected, the Arduino turns ON the LED and activates the buzzer. When there is no object, both the LED and buzzer remain OFF. This project demonstrates the basic working of a sensor-based security system.

## Components Required

| S. No. | Component            | Quantity    | Purpose                          |
|--------|----------------------|-------------|----------------------------------|
| 1      | Arduino Nano         | 1           | Controls the complete system     |
| 2      | IR Sensor Module     | 1           | Detects an object                |
| 3      | LED                  | 1           | Provides visual alarm indication |
| 4      | 220Ω / 330Ω Resistor | 1           | Protects the LED                 |
| 5      | Buzzer               | 1           | Provides audio alarm             |
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
- OUT is connected to D7 so that the Arduino can read the sensor signal.

**LED**
- D2 controls the LED.
- A 220Ω or 330Ω resistor is connected in series with the LED to limit current.
- The LED cathode is connected to GND.

**Buzzer**
- The positive terminal is connected to D8.
- The negative terminal is connected to GND.
- The Arduino uses D8 to control the alarm sound.

## Build Steps
1. Place the IR sensor module on the breadboard.
2. Connect IR VCC to Arduino 5V.
3. Connect IR GND to Arduino GND.
4. Connect IR OUT to D7.
5. Connect the LED to D2 through a 220Ω/330Ω resistor.
6. Connect the LED cathode to GND.
7. Connect the buzzer positive terminal to D8.
8. Connect the buzzer negative terminal to GND.
9. Connect the Arduino Nano to the computer using USB.
10. Upload the security alarm program.
11. Place the IR sensor at the desired entry or monitoring point.
12. Place an object in front of the sensor and observe the LED and buzzer.

## Arduino Code
See [exp27_ir_security_alarm.ino](exp27_ir_security_alarm.ino)

```cpp
const int IR = 7;     // IR sensor OUT pin connected to D7
const int LED = 2;    // Alarm LED connected to D2
const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    digitalWrite(LED, HIGH);   // Object detected: LED ON
    tone(BUZZ, 1500);          // Play 1500 Hz alarm tone
  } else {
    digitalWrite(LED, LOW);    // No object: LED OFF
    noTone(BUZZ);              // Stop the buzzer
  }
}
```

## How the Program Works
The Arduino continuously reads the IR sensor using `digitalRead(IR)`.

When the sensor gives a **LOW** signal:
- The LED turns ON.
- The buzzer produces a 1500 Hz tone.

When the sensor gives a **HIGH** signal:
- The LED turns OFF.
- The buzzer stops.

## Working Principle
The IR sensor detects an object using reflected infrared light. When an object comes within the detection range, the sensor changes its output signal. The Arduino reads this signal through D7. If the signal is LOW, the Arduino considers that an object has been detected and activates both alarm outputs.

The system therefore works as:

Object → IR Sensor → Arduino → LED + Buzzer

## Security Alarm Logic

| Condition        | IR Output | LED | Buzzer |
|------------------|-----------|-----|--------|
| No object        | HIGH      | OFF | OFF    |
| Object detected  | LOW       | ON  | ON     |

> **Note:** Many common IR obstacle sensor modules use LOW for detection, but some modules may work with opposite logic.

## Understanding the Alarm Outputs
- **LED:** provides a visual indication that an object has been detected.
- **Buzzer:** provides an audible warning when the sensor detects an object.

Using both outputs makes the alarm easier to notice.

## Understanding tone()
The command `tone(BUZZ, 1500);` generates a sound of 1500 Hz on the buzzer connected to D8. The command `noTone(BUZZ);` stops the sound.

## Expected Output
- No object in front of the IR sensor: LED is OFF and buzzer is OFF.
- Object detected: LED is ON and buzzer is ON.

> The provided program keeps the LED continuously ON while detection is active. It does not actually flash the LED. Flashing can be added later using timing logic.

## Understanding the Security System
This project demonstrates the basic idea behind automatic security systems. A similar concept can be used in:
- Door entry alarms
- Restricted-area monitoring
- Object detection systems
- Automatic warning systems
- Simple intrusion detection projects

The IR sensor acts as the trigger, while the Arduino decides what action should happen after detection.

## Learning Outcomes
- How an IR sensor detects objects.
- How to read a digital sensor signal.
- How Arduino controls an LED.
- How Arduino activates a buzzer.
- How sensors can be used for security automation.
- How multiple outputs can respond to one sensor.

## Precautions
- Always connect the LED with a suitable resistor.
- Check LED polarity before powering the circuit.
- Make sure the IR sensor VCC and GND are connected correctly.
- Do not short 5V directly to GND.
- Keep jumper connections firm.
- Adjust the IR sensor's sensitivity potentiometer if required.
- Check the sensor's output logic because different modules may behave differently.

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
The IR Security Alarm was successfully built using an Arduino Nano, IR sensor, LED, and buzzer. When an object is detected, the Arduino activates the LED and buzzer, demonstrating a simple sensor-based security alarm system.
