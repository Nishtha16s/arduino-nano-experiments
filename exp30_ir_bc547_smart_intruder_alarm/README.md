# Experiment 30: Transistor & Final Project - IR + BC547 Smart Intruder Alarm

Arduino Nano | IR Obstacle Sensor | BC547 Transistor | Buzzer | LED

## Objective
To combine IR object detection, Arduino decision-making, and a BC547 transistor to control a buzzer alarm load.

## Introduction
The IR + BC547 Smart Intruder Alarm is the final integrated project of this experiment series. It combines three important concepts:

- **IR Sensor:** detects an object.
- **Arduino Nano:** reads the sensor and makes the decision.
- **BC547 Transistor:** works as an electronic switch to control the buzzer.

When an object is detected, the Arduino turns ON the warning LED and sends a HIGH signal to the BC547 base. The transistor then allows current to flow through the buzzer, activating the alarm. This project demonstrates how a transistor can be used to switch a load using a low-power control signal from the Arduino.

## Components Required

| S. No. | Component            | Quantity    | Purpose                                   |
|--------|----------------------|-------------|-------------------------------------------|
| 1      | Arduino Nano         | 1           | Reads the sensor and controls the circuit |
| 2      | IR Sensor Module     | 1           | Detects an object                         |
| 3      | BC547 Transistor     | 1           | Acts as an electronic switch              |
| 4      | Buzzer               | 1           | Provides the alarm sound                  |
| 5      | LED                  | 1           | Provides visual warning                   |
| 6      | 220Ω / 330Ω Resistor | 1           | Protects the LED                          |
| 7      | 1kΩ Resistor         | 1           | Limits current into the transistor base   |
| 8      | Breadboard           | 1           | Makes circuit connections easy            |
| 9      | Jumper Wires         | As required | Connects components                       |
| 10     | USB Cable            | 1           | Programs and powers the Arduino           |

## Circuit Connections

**IR Sensor**

| IR Sensor Pin | Arduino Nano |
|---------------|--------------|
| VCC           | 5V           |
| GND           | GND          |
| OUT           | D7           |

**Warning LED**

| LED Connection | Arduino Nano                    |
|----------------|---------------------------------|
| D2             | 220Ω/330Ω resistor → LED Anode  |
| LED Cathode    | GND                             |

**BC547 and Buzzer**

| Connection          | Connection Point            |
|---------------------|-----------------------------|
| BC547 Emitter       | GND                         |
| BC547 Collector     | Buzzer Negative (-)         |
| Buzzer Positive (+) | 5V                          |
| Arduino D9          | 1kΩ resistor → BC547 Base   |
| Arduino GND         | Common GND                  |

## BC547 Pin Identification
Before making the circuit, **identify the Emitter, Base, and Collector of the exact BC547 transistor being used.** The physical pin arrangement can vary between transistor versions or manufacturers. Do not assume the pin order from the appearance of the transistor. Check the component's datasheet or manufacturer information before connecting it.

## Connection Explanation

**IR Sensor**
- VCC connects to 5V.
- GND connects to common GND.
- OUT connects to D7.
- The Arduino reads the sensor signal through D7.

**LED**
- D2 controls the warning LED.
- A suitable resistor is connected in series with the LED.
- The LED cathode connects to GND.

**BC547**
- Emitter connects to GND.
- Collector connects to the negative terminal of the buzzer.
- Base receives the control signal from D9 through a 1kΩ resistor.

**Buzzer**
- Positive terminal connects to 5V.
- Negative terminal connects to the BC547 collector.

When D9 becomes HIGH, the BC547 turns ON and provides a path from the buzzer negative terminal to GND.

## Build Steps
1. Identify the BC547 Emitter, Base, and Collector from the exact component datasheet/package.
2. Insert the BC547 correctly into the breadboard.
3. Connect the BC547 emitter to GND.
4. Connect the buzzer positive terminal to 5V.
5. Connect the buzzer negative terminal to the BC547 collector.
6. Connect Arduino D9 to a 1kΩ resistor.
7. Connect the other side of the 1kΩ resistor to the BC547 base.
8. Connect the IR sensor VCC to 5V.
9. Connect the IR sensor GND to common GND.
10. Connect the IR sensor OUT to D7.
11. Connect the warning LED to D2 through a suitable resistor.
12. Connect the LED cathode to GND.
13. Make sure all grounds are common.
14. Connect the Arduino Nano to the computer using USB.
15. Upload the final program.
16. Place an object in front of the IR sensor.
17. Observe the LED and buzzer response.

## Arduino Code
See [exp30_ir_bc547_smart_intruder_alarm.ino](exp30_ir_bc547_smart_intruder_alarm.ino)

```cpp
const int IR = 7;     // IR sensor OUT pin connected to D7
const int LED = 2;    // Warning LED connected to D2
const int BASE = 9;   // BC547 base (through 1k resistor) connected to D9

void setup() {
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BASE, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    digitalWrite(LED, HIGH);    // Object detected: warning LED ON
    digitalWrite(BASE, HIGH);   // Turn ON BC547, buzzer sounds
  } else {
    digitalWrite(LED, LOW);     // No object: LED OFF
    digitalWrite(BASE, LOW);    // Turn OFF BC547, buzzer stops
  }
}
```

## How the Program Works
The Arduino continuously reads the IR sensor connected to D7.

When the sensor detects an object and gives a LOW signal, the Arduino performs two actions:
1. Turns ON the warning LED (`digitalWrite(LED, HIGH)`).
2. Sends a HIGH signal to D9 (`digitalWrite(BASE, HIGH)`), which drives the BC547 transistor.

When no object is detected, the LED turns OFF and the transistor is switched OFF.

## Working Principle
The complete system works in three stages:

**Stage 1: Detection.** The IR sensor detects an object and sends a signal to the Arduino through D7.

**Stage 2: Decision.** The Arduino checks the sensor signal. If the signal is LOW, it identifies that an object has been detected.

**Stage 3: Switching.** The Arduino turns ON the LED and sends a HIGH signal through D9 to the BC547 base. The BC547 switches ON and allows current to flow through the buzzer.

Object → IR Sensor → Arduino → D9 → BC547 → Buzzer

At the same time:

Object → IR Sensor → Arduino → D2 → LED

## BC547 as an Electronic Switch
The BC547 is an NPN transistor. In this project, it is used as an electronic switch instead of connecting the buzzer directly to an Arduino output.

- D9 LOW: BC547 OFF → Buzzer OFF
- D9 HIGH: BC547 ON → Buzzer ON

The transistor allows the Arduino's low-power control signal to switch the buzzer circuit.

## Why a Base Resistor Is Used
The Arduino D9 pin is connected to the BC547 base through approximately 1kΩ.

Arduino D9 → 1kΩ Resistor → BC547 Base

The resistor limits the current flowing into the transistor base and provides safer operation of the Arduino output pin. The transistor base should **not** be connected directly to the Arduino pin without an appropriate current-limiting resistor.

## Intruder Alarm Logic

| Condition        | IR Output | LED | D9   | BC547 | Buzzer |
|------------------|-----------|-----|------|-------|--------|
| No object        | HIGH      | OFF | LOW  | OFF   | OFF    |
| Object detected  | LOW       | ON  | HIGH | ON    | ON     |

> **Note:** Many common IR modules use LOW for object detection, but the output logic can vary between modules.

## Expected Output

**When no object is detected:**
- LED: OFF
- BC547: OFF
- Buzzer: OFF

**When an object is detected:**
- LED: ON
- D9: HIGH
- BC547: ON
- Buzzer: ON

The alarm remains active while the IR sensor reports detection.

## Important Note About the Buzzer
The program gives a steady HIGH signal to the transistor, not a tone. This works with an **active buzzer**, which has a built-in oscillator and sounds when powered. A **passive buzzer** would only click with a steady signal; it needs a `tone()` signal on D9 to produce sound.

## Understanding the Complete System
This final project combines the concepts learned throughout the previous experiments:

| Concept               | Used In This Project        |
|-----------------------|-----------------------------|
| Digital input         | IR sensor on D7             |
| Digital output        | LED on D2                   |
| Transistor switching  | BC547                       |
| Base resistor         | 1kΩ                         |
| Sensor automation     | Automatic alarm             |
| Common ground         | Entire circuit              |
| Load control          | Buzzer through transistor   |

This makes the project a simple example of an integrated automation and security system.

## Applications
The basic concept can be extended to:
- Intruder detection systems
- Entry alert systems
- Restricted-area monitoring
- Automatic warning systems
- Object detection alarms
- Model security systems
- School robotics demonstrations

## Learning Outcomes
- How an IR sensor detects objects.
- How the Arduino processes a sensor signal.
- How an LED can provide a visual warning.
- How a BC547 can work as an electronic switch.
- Why a base resistor is required.
- How a transistor can control a load.
- How multiple components can be combined into one automation system.
- How a simple security alarm can be designed using Arduino.

## Important Precautions
- **Confirm the BC547 pinout from the exact component datasheet/package before wiring.**
- Do not assume the transistor pin order.
- Always use a suitable base resistor, approximately 1kΩ in this project.
- Make sure all circuit grounds are common.
- Check the LED polarity before powering the circuit.
- Use a suitable resistor with the LED.
- Check buzzer polarity where applicable.
- Do not short 5V directly to GND.
- Verify every connection before powering the circuit.
- Different IR sensor modules may use different detection logic.
- If the buzzer is a high-current load, use an appropriate driver/protection arrangement rather than exceeding the Arduino or transistor ratings.

## Quick Reference

| Pin   | Common Use                        |
|-------|-----------------------------------|
| D2-D6 | LEDs in many examples             |
| D7    | IR sensor / button                |
| D8    | Buzzer in direct-drive examples   |
| A0    | Potentiometer                     |
| D5    | PWM brightness control            |
| D9    | BC547 base in final project       |

## Result
The IR + BC547 Smart Intruder Alarm was successfully designed as a final integrated project. The IR sensor detects an object, the Arduino processes the detection signal, the LED provides a visual warning, and the BC547 acts as an electronic switch to activate the buzzer.
