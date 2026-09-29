# Experiment 01: Arduino Basics

Getting started with the Arduino Nano.

## Objective
To set up the Arduino Nano, connect it to a computer, upload a first Arduino sketch, and verify that the board, USB connection, and programming environment are working correctly.

## Components Required

| S. No. | Component     | Quantity    |
|--------|---------------|-------------|
| 1      | Arduino Nano  | 1           |
| 2      | USB Cable     | 1           |
| 3      | Breadboard    | 1           |
| 4      | Jumper Wires  | As required |

## Purpose of Components
- **Arduino Nano:** Main microcontroller board that runs the program.
- **USB Cable:** Connects the Nano to the computer for programming and power.
- **Breadboard:** Convenient platform for placing and connecting components.
- **Jumper Wires:** Used for electrical connections when an external circuit is required.

## Connections
Connect the Arduino Nano to the computer using the USB cable. No external circuit is required because the onboard LED is used.

## Build Steps
1. Place the Arduino Nano on the breadboard if desired.
2. Connect the USB cable to the Nano and the computer.
3. Open the Arduino IDE and select the correct Nano board, processor, and COM port.
4. Create the sketch and compile it.
5. Upload the sketch and confirm there is no error.
6. Observe the onboard LED while the sketch is running.

## Code
See [exp01_arduino_basics.ino](exp01_arduino_basics.ino)

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);

  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
```

## Code Explanation
- `void setup()`: runs once when the Arduino starts.
- `pinMode(LED_BUILTIN, OUTPUT);`: sets the onboard LED pin as an output.
- `void loop()`: runs repeatedly as long as the Arduino is powered.
- `digitalWrite(LED_BUILTIN, HIGH);`: turns the onboard LED ON.
- `delay(500);`: waits for 500 milliseconds (0.5 seconds).
- `digitalWrite(LED_BUILTIN, LOW);`: turns the onboard LED OFF.

## How It Works
The Arduino Nano repeatedly turns its built-in LED ON and OFF. The LED stays ON for 0.5 seconds and OFF for 0.5 seconds, and this pattern repeats continuously. Successful blinking confirms that the Nano, USB connection, Arduino IDE setup, and program upload are working.

## Working Sequence
Start → Connect Nano → Select Board & COM Port → Compile Sketch → Upload Program → LED ON → Wait 0.5 sec → LED OFF → Wait 0.5 sec → Repeat

## Expected Output
The onboard LED blinks continuously with equal ON and OFF intervals of 0.5 seconds.

## Result
The Arduino Nano was successfully connected to the computer and programmed using the Arduino IDE. The onboard LED blinked continuously, confirming successful board setup, programming, and operation.

## Precautions
- Use a good-quality USB cable that supports data transfer.
- Select the correct Arduino Nano board and processor in the Arduino IDE.
- Select the correct COM port before uploading.
- Do not disconnect the USB cable during upload.
- Ensure the Nano is placed correctly on the breadboard if one is used.
- Check for upload errors if the onboard LED does not blink.

## Quick Reference

| Pin | Common Use in Examples          |
|-----|---------------------------------|
| D2-D6 | LEDs                          |
| D7  | IR sensor / Button              |
| D8  | Buzzer                          |
| A0  | Potentiometer                   |
| D5  | PWM / LED brightness control    |
| D9  | BC547 base in the final project |

## Learning Outcomes
- Understand the basic setup of an Arduino Nano.
- Learn how to connect the Nano to a computer.
- Understand board, processor, and COM port selection.
- Learn how to compile and upload an Arduino sketch.
- Understand the use of `LED_BUILTIN`.
- Verify that the Arduino development environment is working correctly.
