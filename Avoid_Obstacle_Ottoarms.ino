
//#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <Servo.h>
#include <EEPROM.h>
 #include "Otto.h"

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
Otto Ottobot;



void setup(){
    Ottobot.defaultInit();
    Ottobot.init(2,3,4,5,6,7,true,A6,13,8,9);
    Ottobot.initMatrix(10,11,12);
    
}

void loop(){
    
    while(!((Ottobot.getDistance()) > ( 15 )))
    {
        _loop();
        Ottobot.sing(2);
        Ottobot.playGesture(5);
        Ottobot.putMouth(14);
        for(int __i__=0;__i__<3;++__i__)
        {
            Ottobot.move(3,1000,25);
        }
    }
    Ottobot.putMouth(10);
    Ottobot.move(1,1000,25);
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}
