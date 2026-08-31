# The Glorious Smart Trash-Can

The trash can of the future.

## Overview

This project aims to make a smart trash can that helps mitigate hygiene problems associated with public bins and encourages a sustainable mindset. It also displays the status of the smart bin via the LCD. This includes a start up message as whether or not the lid is open. Furthermore, the display also shows the distance (in cm) from the nearest object.
## Key Features

- Touchless actuation using an HC-SR04 ultrasonic sensor and servo-driven lid.
- Environmental facts displayed on a 16x2 LCD.
- Randomized content using an analog pin as an entropy seed.
- Sensor timeout handling to help prevent microcontroller lockup.

## Hardware

| Component | Quantity | Pin mapping / notes |
| --- | ---: | --- |
| ELEGOO Mega 2500 | 1 | ATmega2560 controller |
| HC-SR04 sensor | 1 | Trig: 8, Echo: 9 |
| SG90 servo motor | 1 | PWM: 6 |
| 16x2 LCD display | 1 | RS: 12, EN: 11, D4-D7: 5, 4, 3, 2 |
| 10k potentiometer | 1 | Display contrast: V0 |
| Trash can (made from an ice cream box) | 1 | Main bin body |
| 10 cm length of string | 1 | Used to connect the lid mechanism |
| Wooden toy crate | 1 | Used as a platform to host the servo motor |

> The wooden toy crate was used as a platform to host the servo motor for the trash-lid mechanism.

## Schematic View

![Schematic view](<docs/images/Screenshot 2026-08-21 214549.png>)

## Tinkercad Wiring

![Tinkercad wiring](<docs/images/Screenshot 2026-08-21 214607.png>)

## User's Guide

1. Connect the Arduino to a 5V source (like a laptop)
2. Wait for the start up message to appear (startup message is "SMART BIN, Ready to use")
3. Wave your hand near the ultrasonic sensor
4. This will cause the lid to open up automatically
5. Dispose of trash
6. Lid will close automatically after 2.5s

## Troubleshooting

| Problem | Solution |
| --- | --- |
| LCD screen is blank | Adjust the contrast potentiometer (10kΩ pot on pin V0) slowly until teh white text is clearly visible |
| Lid won't open when hand/object is near sensor | Ensure your hand is within 7cm of the HC-SR04 sensor; check that the sensor is not blocked and that the servo is free to move |
| Lid opens randomly without motion | The sensor may be picking up vibrations; keep the trash can on a stable surface |
| Lid won't close after opening | Check that the servo motor can rotate freely; verify servo is powered at 5V |
| LCD shows corrupted text | Verify all LCD data pins (D4-D7) are properly connected to Arduino pins 5, 4, 3 and 2 |
| Arduino not responding | Disconnect and reconnect the 5V power source; reload the firmware using PlatformIO |
