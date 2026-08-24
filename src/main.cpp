#include <Arduino.h>
#include <Servo.h>

#include <LiquidCrystal.h>

const int trigPin = 8;
const int echoPin = 9;
const int servoPin = 6;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo lidServo;

int lidClosePos = 0;
int lidOpenPos = 90;

void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
lidServo.attach(servoPin);
lidServo.attach(servoPin);
lidServo.write(lidClosePos);

lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print("   SMART BIN   ");
lcd.setCursor(0, 1);
lcd.print(" Ready for use ");

delay (2500);
lcd.clear();

}

void loop() {
long duration, cm;

digitalWrite(trigPin, LOW);
delayMicroseconds (2);
digitalWrite(trigPin, HIGH);
delayMicroseconds (10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
cm = duration / 29 / 2;

if (duration > 0 && duration <= 410) {
  lidServo.write (lidOpenPos);

  lcd.setCursor(0, 0);
  lcd.print("    LID: OPEN   ");
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(cm);
  lcd.print("cm       ");
  delay (2500);
}
else {
  lidServo.write (lidClosePos);

  lcd.setCursor(0, 0);
  lcd.print("   LID: CLOSED  ");
  lcd.setCursor(0, 1);
   lcd.print("Dist: ");
  lcd.print(cm);
  lcd.print("cm       "); 
  delay(900);
  
}
delay (20);
}
