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
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, MAX);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, MAX);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, MAX);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, MAX);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, MAX);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, MAX);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, MIN);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, MIN);
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
