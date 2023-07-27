#include <LiquidCrystal.h>

/**************************************************
Author:         Fawaaz Kamali Siddiqui
Date:           31 October 2022
Description:    This device is called the portable distance calculator. It 
                contains an LCD display to output distances between the ultrasonic
                sensor and the object in front of it. A power bank is used to supply
                the Arduino Nano. Distances are either in cm or m.
---------------------------------------------------
Connections:    echo: 11
                trig: 12
                rs:   2
                e:    3
                d4:   4
                d5:   5
                d6:   6
                d7:   7
**************************************************/

// variables
int rs = 2;
int e = 3;
int d4 = 4;
int d5 = 5;
int d6 = 6;
int d7 = 7;
int trigPin = 12;
int echoPin = 11;
int distance;
int time;

// instantiation
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {

  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {

  // collect sensor values
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // calculate distance to object
  time = pulseIn(echoPin, HIGH);
  distance = time * (0.034 / 2); // take out time taken for ping to bounce back
  Serial.println(distance);

  // display distance in m if distance is large
  if (distance > 100) {
    lcd.setCursor(0,0);
    lcd.print("Distance in m:");
    lcd.setCursor(0,1);
    lcd.print(distance/100.);
    lcd.print(" m");
    delay(250);
    lcd.clear();
  }

  // display distance in cm if distance is small
  else if (distance <= 100) {
    lcd.setCursor(0,0);
    lcd.print("Distance in cm:");
    lcd.setCursor(0,1);
    lcd.print(distance);
    lcd.print(" cm");
    delay(250);
    lcd.clear();    
  }

}
