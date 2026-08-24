The Glorious Smart Trash-Can 
(The trash can of the future)


OVERVIEW:
This project aims to make a smart trash that is aimed to mitigate hygiene problems usually associated with public bins/trash-cans and instil a sustainable mindset within its users. It will also educate users on taking care of one's environment by displaying random fun facts on the outer LCD display.

KEY FEATURES & SYSTEM DESIGN:
- Touchless Actuation: Uses an HC-SR04 ultrasonic sensor for real-time distance measurement to trigger a servo-driven lid mechanism.
- Dynamic Content Engine: Utilizes an unassigned, floating analog pin (`A5`) as a random entropy seed to cycle through environmental facts without repetition patterns across system resets.
- Robust Exception Handling: Implements precise timeout bounds (`pulseIn()` at 30ms) to prevent microcontroller lockup from sensor signal drops or out-of-range reflections.
- Interactive Educational Display: Dual-line LCD interface delivers rotating micro-facts to educate users on recycling impact, material degradation timelines, and resource conservation.

HARDWARE:

|        Component     | Quantity |        Description          | Pin Mapping                       |
| ELEGOO Mega 2500     |    1     | ATmega2560 Core Controller  |                                   |
| HC-SR04 Sensor       |    1     | Proximity Sensor            | Trig: 8, Echo: 9                  |
| SG90 Servo Motor     |    1     | Lid Actuator                | PWM Signal: 6                     |
| 16x2 LCD Display     |    1     | Character Interface         | RS: 12, EN: 11, D4–D7: 5, 4, 3, 2 |
| 10kΩ Potentiometer   |    1     | Display Contrast Adjustment | V0                                |
| Breadboard & Jumpers |    1     | Circuit Interconnects       | 5V / GND Bus                      |


SCHEMATIC VIEW:
![alt text](<Screenshot 2026-08-21 214549.png>)


Tinkercad wiring:
![alt text](<Screenshot 2026-08-21 214607.png>)
