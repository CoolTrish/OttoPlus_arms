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
    
    Ottobot.putMouth(10);
    Ottobot.sing(6);
    for(int __i__=0;__i__<2;++__i__)
    {
        Ottobot.move(12,1000,20);
    }
    Ottobot.putMouth(11);
    Ottobot.sing(7);
    for(int __i__=0;__i__<3;++__i__)
    {
        Ottobot.move(19,1000,20);
    }
    Ottobot.putMouth(16);
    Ottobot.sing(11);
    for(int __i__=0;__i__<3;++__i__)
    {
        Ottobot.move(6,1700,25);
    }
    Ottobot.putAnimationMouth(0,0);
    Ottobot.putMouth(13);
    Ottobot.sing(0);
    for(int __i__=0;__i__<3;++__i__)
    {
        Ottobot.move(7,1000,25);
    }
    Ottobot.putMouth(14);
    Ottobot.sing(2);
    for(int __i__=0;__i__<3;++__i__)
    {
        Ottobot.move(9,1700,25);
    }
    Ottobot.move(15,1300,25);
    Ottobot.move(16,1300,25);
    Ottobot.sing(3);
   /* for(int __i__=0;__i__<2;++__i__)
    {
        Ottobot.move(17,1300,25);
    }

    {
     Ottobot.move(0,1300,25); 
    }
    
    
    for(int __i__=0;__i__<2;++__i__) 
    { 
        Ottobot.move(18,1300,25);
    }*/
    
    Ottobot.putMouth(25);
    Ottobot.sing(4);    
   // Ottobot.putAnimationMouth(3,0);
    for(int __i__=0;__i__<1;++__i__)
    {
        Ottobot.move(1,1300,25);
        _delay(0.5);
        Ottobot.move(0,1300,25);
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
