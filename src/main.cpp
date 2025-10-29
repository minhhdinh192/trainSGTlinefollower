//line follower = 2 ir sensors x esp32 devkit v1
#include <Arduino.h>

#define LEFT_IRS 34
#define RIGHT_IRS 35
#define ENA 25
#define IN1 26
#define IN2 27
#define ENB 14
#define IN3 12
#define IN4 13
#define MAX 255
#define MIN 0

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(LEFT_IRS, INPUT);
  pinMode(RIGHT_IRS, INPUT);
}
void forward() {
  analogWrite(IN1, HIGH);
  analogWrite(IN2, LOW);
  digitalWrite(ENA, MAX);
  analogWrite(IN3, HIGH);
  analogWrite(IN4, LOW);
  digitalWrite(ENB, MAX);
}

void left() {
  analogWrite(IN1, LOW);
  analogWrite(IN2, HIGH);
  digitalWrite(ENA, MAX);
  analogWrite(IN3, HIGH);
  analogWrite(IN4, LOW);
  digitalWrite(ENB, MAX);
}

void right() {
  analogWrite(IN1, HIGH);
  analogWrite(IN2, LOW);
  digitalWrite(ENA, MAX);
  analogWrite(IN3, LOW);
  analogWrite(IN4, HIGH);
  digitalWrite(ENB, MAX);
}

void stop() {
  analogWrite(IN1, LOW);
  analogWrite(IN2, LOW);
  digitalWrite(ENA, MIN);
  analogWrite(IN3, LOW);
  analogWrite(IN4, LOW);
  digitalWrite(ENB, MIN);
}

void loop() {
  int LEFTVAL = digitalRead(LEFT_IRS);
  int RIGHTVAL = digitalRead(RIGHT_IRS);
  if ((LEFTVAL == 1) && (RIGHTVAL == 1)) forward();
  else if ((LEFTVAL == 1) && (RIGHTVAL == 0)) left();
  else if (((LEFTVAL == 0) && (RIGHTVAL == 1))) right();
  else stop();
  delay(500);
}
