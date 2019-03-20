#include <Arduino.h>
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
    Ottobot.putMouth(13);
    Ottobot.sing(4);
    
    for(int __i__=0;__i__<4;++__i__)
    {
        Ottobot.move(1,1000,25);
    }
    
     Ottobot.playGesture(0);

      for(int __i__=0;__i__<4;++__i__)
    {
        Ottobot.move(12,1000,25);
    }
         
}

void loop(){
    
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}
