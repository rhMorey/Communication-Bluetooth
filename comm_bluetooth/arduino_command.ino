#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
double status;

void setup(){
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(6,OUTPUT);
}

void loop(){
    if(((status)==(1))){
        digitalWrite(4,1);
        analogWrite(5,150);
        digitalWrite(7,1);
        analogWrite(6,0);
    }
    if(((status)==(2))){
        digitalWrite(4,1);
        analogWrite(5,0);
        digitalWrite(7,1);
        analogWrite(6,0);
    }
    if(((status)==(4))){
        digitalWrite(4,0);
        analogWrite(5,200);
        digitalWrite(7,1);
        analogWrite(6,25);
    }
    if(((status)==(3))){
        digitalWrite(4,0);
        analogWrite(5,25);
        digitalWrite(7,1);
        analogWrite(6,200);
    }
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}
