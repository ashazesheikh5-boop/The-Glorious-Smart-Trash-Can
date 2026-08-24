/*
 * The Glorious Smart Trash-Can
 * 
 * A touchless, sensor-driven trash bin that automatically opens/closes its lid
 * based on proximity detection and displays status on a 16x2 LCD screen.
 */

#include <Arduino.h>
#include <Servo.h>        // Library for controlling the servo motor
#include <LiquidCrystal.h> // Library for 16x2 LCD display

// ===== HC-SR04 Ultrasonic Sensor Pins =====
const int trigPin = 8;    // Trigger pin sends ultrasonic pulse
const int echoPin = 9;    // Echo pin receives reflected pulse

// ===== Servo Motor Pin =====
const int servoPin = 6;   // PWM pin controlling servo motor (lid actuator)

// ===== 16x2 LCD Display Pins =====
const int rs = 12;        // Register Select pin
const int en = 11;        // Enable pin
const int d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Data pins D4-D7

// ===== LCD and Servo Initialization =====
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo lidServo;

// ===== Servo Position Constants =====
int lidClosePos = 0;      // Servo angle when lid is closed (degrees)
int lidOpenPos = 90;      // Servo angle when lid is open (degrees)

void setup() {
  // Initialize Serial communication for debugging (9600 baud rate)
  Serial.begin(9600);
  
  // Configure ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);   // Trigger pin outputs the ultrasonic pulse
  pinMode(echoPin, INPUT);    // Echo pin reads the reflected pulse
  
  // Attach servo motor to PWM pin and initialize to closed position
  lidServo.attach(servoPin);
  lidServo.attach(servoPin);
  lidServo.write(lidClosePos); // Set lid to closed position
  
  // Initialize 16x2 LCD display
  lcd.begin(16, 2);
  
  // Display startup message on LCD
  lcd.setCursor(0, 0);
  lcd.print("   SMART BIN   ");
  lcd.setCursor(0, 1);
  lcd.print(" Ready for use ");
  
  // Hold startup message for 2.5 seconds
  delay(2500);
  lcd.clear();
}

void loop() {
  long duration, cm;
  
  // ===== Trigger Ultrasonic Sensor =====
  // Send a 10 microsecond pulse to trigger the ultrasonic measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // ===== Read Ultrasonic Sensor =====
  // pulseIn() measures how long the echo pin stays HIGH (in microseconds)
  // This time correlates to the distance of the nearest object
  duration = pulseIn(echoPin, HIGH);
  
  // Convert duration to distance in centimeters
  // Speed of sound = 343 m/s, so: distance = (duration * speed) / 2
  // Simplified: cm = duration / 29 / 2 (accounting for round-trip)
  cm = duration / 29 / 2;
  
  // ===== Object Detection Logic =====
  // If object is detected within ~12cm (duration <= 410 microseconds), open lid
  if (duration > 0 && duration <= 410) {
    // Open the trash can lid
    lidServo.write(lidOpenPos);
    
    // Display "LID: OPEN" and distance on LCD
    lcd.setCursor(0, 0);
    lcd.print("    LID: OPEN   ");
    lcd.setCursor(0, 1);
    lcd.print("Dist: ");
    lcd.print(cm);
    lcd.print("cm       ");
    
    // Keep lid open for 2.5 seconds before checking again
    delay(2500);
  }
  else {
    // No object detected: close the trash can lid
    lidServo.write(lidClosePos);
    
    // Display "LID: CLOSED" and distance on LCD
    lcd.setCursor(0, 0);
    lcd.print("   LID: CLOSED  ");
    lcd.setCursor(0, 1);
    lcd.print("Dist: ");
    lcd.print(cm);
    lcd.print("cm       "); 
    
    // Brief delay before next sensor reading
    delay(900);
  }
  
  // Small delay to prevent sensor saturation and allow LCD update
  delay(20);
}
