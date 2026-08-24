# The Glorious Smart Trash-Can

The trash can of the future.

## Overview

This project aims to make a smart trash can that helps mitigate hygiene problems associated with public bins and encourages a sustainable mindset. It also educates users by displaying random environmental facts on an outer LCD display.

## Key Features

- Touchless actuation using an HC-SR04 ultrasonic sensor and servo-driven lid.
- Environmental facts displayed on a 16x2 LCD.
- Randomized content using an analog pin as an entropy seed.
- Sensor timeout handling to help prevent microcontroller lockup.

## Hardware

| Component | Quantity | Pin mapping |
| --- | ---: | --- |
| ELEGOO Mega 2500 | 1 | ATmega2560 controller |
| HC-SR04 sensor | 1 | Trig: 8, Echo: 9 |
| SG90 servo motor | 1 | PWM: 6 |
| 16x2 LCD display | 1 | RS: 12, EN: 11, D4-D7: 5, 4, 3, 2 |
| 10k potentiometer | 1 | Display contrast: V0 |

## Schematic View

![Schematic view](<src/Screenshot 2026-08-21 214549.png>)

## Tinkercad Wiring

![Tinkercad wiring](<src/Screenshot 2026-08-21 214607.png>)
