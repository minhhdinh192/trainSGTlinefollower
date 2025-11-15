#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>

#define servo_pin 18
#define pm 34
#define min 0
#define adcmax 4096
#define servolim 180
#define lcdsize 0x27
#define lcdcol 16
#define lcdlines 2
#define sda 13
#define scl 12
LiquidCrystal_I2C lcd(lcdsize, lcdcol, lcdlines);
int angle;

Servo servo;

void setup() {
  Serial.begin(9600);
  Wire.begin(sda, scl);
  lcd.init();
  lcd.backlight();
  pinMode(pm, INPUT);
  servo.attach(servo_pin, 500, 2400);
}

void loop() {
  lcd.clear();
  angle = analogRead(pm);
  angle = map(angle, min, adcmax, min, servolim);
  servo.write(angle);
  lcd.setCursor(0, 0);
  lcd.print("Angle (degree): ");
  lcd.print(angle);
  delay(15);
}