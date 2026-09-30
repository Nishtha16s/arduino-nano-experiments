# Experiment 26: IR Sensor & Automation - IR Controlled Buzzer

Arduino Nano | IR Obstacle Sensor | Buzzer | Sensor-Based Alert

## Objective
To use an IR sensor to trigger an audible alert.

## Components Required

| S. No. | Component                   | Quantity |
|--------|-----------------------------|----------|
| 1      | Arduino Nano                | 1        |
| 2      | IR Obstacle Sensor Module   | 1        |
| 3      | Buzzer                      | 1        |

## Circuit Connections

| Component        | Arduino Connection |
|------------------|--------------------|
| IR Sensor VCC    | 5V                 |
| IR Sensor GND    | GND                |
| IR Sensor OUT    | D7                 |
| Buzzer Positive  | D8                 |
| Buzzer Negative  | GND                |

## Build Steps
1. Connect the IR sensor and buzzer.
2. Upload the sketch.
3. Keep the detection area clear.
4. Place an object in front of the sensor.
5. The buzzer sounds while detection is active.

## Arduino Code
See [exp26_ir_controlled_buzzer.ino](exp26_ir_controlled_buzzer.ino)

```cpp
const int IR = 7;     // IR sensor OUT pin connected to D7
const int BUZZ = 8;   // Buzzer connected to D8

void setup() {
  pinMode(IR, INPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  if (digitalRead(IR) == LOW) {
    tone(BUZZ, 1200);   // Object detected: play 1200 Hz tone
  } else {
    noTone(BUZZ);       // No object: stop the tone
  }
}
```

## How It Works
The IR sensor becomes the trigger for the buzzer. The Arduino continuously reads the sensor output on D7. When an object is detected, the output becomes LOW and the Arduino plays a 1200 Hz tone on D8. When the object is removed, the output becomes HIGH and the Arduino stops the tone.

## Working Principle
Object → IR Sensor Detects Reflection → OUT Becomes LOW → Arduino Reads D7 → Buzzer Sounds

No Object → Sensor OUT Becomes HIGH → Arduino Reads D7 → Buzzer Stops

## Sensor and Buzzer Logic

| IR Sensor State  | Arduino Input | Buzzer |
|------------------|---------------|--------|
| Object detected  | LOW           | ON     |
| No object        | HIGH          | OFF    |

> **Note:** This LOW/HIGH behavior is common for digital IR obstacle sensor modules, but some modules have opposite output logic. If the buzzer sounds when there is no object, change `LOW` to `HIGH` in the `if` condition.

## Expected Output
- Detection area clear: the buzzer is silent.
- Object placed in front of the sensor: the buzzer sounds.
- Object moved away: the buzzer stops.

## Quick Reference

| Pin   | Common Use                    |
|-------|-------------------------------|
| D2-D6 | LEDs in many examples         |
| D7    | IR sensor / button            |
| D8    | Buzzer                        |
| A0    | Potentiometer                 |
| D5    | PWM pin for brightness        |
| D9    | BC547 base in final project   |

## Conclusion
The experiment shows how an IR sensor can act as a trigger for an audible alert. The buzzer sounds for as long as an object is detected, which is the basic idea behind simple proximity alarms.
