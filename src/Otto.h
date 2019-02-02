#ifndef Otto_h
#define Otto_h

#include <Servo.h>
#include "Oscillator.h"
#include <EEPROM.h>

#include "US.h"
#include "MaxMatrix.h"
#include "BatReader.h"

#include "Otto_mouths.h"
#include "Otto_sounds.h"
#include "Otto_gestures.h"
#include "SoftSerialCommand.h"

//-- Constants
#define FORWARD     1
#define BACKWARD    -1
#define LEFT        1
#define RIGHT       -1
#define SMALL       5
#define MEDIUM      15
#define BIG         30

#define HIP_L   2        // connect Servo Hip left to D2
#define FOOT_L  4        // Connect Servo Foot Left to D4
#define HIP_R   3        // Connect Servo Hip right to D3
#define FOOT_R  5        // COnnect Servo Foot Right to D5
#define ARM_L   6        // connect Servo Arm Left to D6
#define ARM_R   7        // connect Servo Arm Right to D7

#define PIN_Buzzer  13
#define PIN_Trigger 8
#define PIN_Echo    9
#define PIN_NoiseSensor 6 //Analog Pin 6
///define Bluetooth in SoftwareSerial 
#define BT_Rx   6  
#define BT_Tx   7
//define Max7219 pins 
#define PIN_DIN    10   //max 7219
#define PIN_CS     11
#define PIN_CLK    12

class Otto
{
  public:
   // Otto() {init(HIP_L, HIP_R, FOOT_L, FOOT_R, ARM_L, ARM_R, true, PIN_NoiseSensor, PIN_Buzzer,PIN_Trigger, PIN_Echo);}
    //-- Otto initialization
    
    void init(int YL, int YR, int RL, int RR, int LA, int RA, bool load_calibration=true, int NoiseSensor=PIN_NoiseSensor, int Buzzer=PIN_Buzzer, int USTrigger=PIN_Trigger, int USEcho=PIN_Echo);
    void initMatrix(int MaxDin,int MaxCS,int MaxClk)
     {Max7219_Din=MaxDin;Max7219_Cs=MaxCS;Max7219_Clk=MaxClk;}
    //-- Attach & detach functions
     void defaultInit();
    void attachServos();
    void detachServos();

    //-- Oscillator Trims
     void setTrims(int YL, int YR, int RL, int RR, int LA, int RA);
     void saveTrimsOnEEPROM();

    //-- Predetermined Motion Functions

    void _moveServos(int time, int  servo_target[]);
    void calib_homePos();
    void oscillateServos(int A[6], int O[6], int T, double phase_diff[6], float cycle);

    //-- HOME = Otto at rest position
    void home();
    bool getRestState();
    void setRestState(bool state);
    
    //-- Predetermined Motion Functions
    void jump(float steps=1, int T = 2000);

    void walk(float steps=4, int T=1000, int dir = FORWARD);
    void turn(float steps=4, int T=2000, int dir = LEFT);
    void bend (int steps=1, int T=1400, int dir=LEFT);
    void shakeLeg (int steps=1, int T = 2000, int dir=RIGHT);

    void updown(float steps=1, int T=1000, int h = 20);
    void swing(float steps=1, int T=1000, int h=20);
    void tiptoeSwing(float steps=1, int T=900, int h=20);
    void jitter(float steps=1, int T=500, int h=20);
    void ascendingTurn(float steps=1, int T=900, int h=20);

    void moonwalker(float steps=1, int T=900, int h=20, int dir=LEFT);
    void crusaito(float steps=1, int T=900, int h=20, int dir=FORWARD);
    void flapping(float steps=1, int T=1000, int h=20, int dir=FORWARD);
    void move(int moveID,int time, int _moveSize);
    //-- Sensors functions
    float getDistance(); //US sensor
    int   getNoise();      //Noise Sensor

    //-- Battery
    double getBatteryLevel();
    double getBatteryVoltage();
    
    //-- Mouth & Animations
    void putMouth(unsigned long int mouth,bool predefined = true);
    void putAnimationMouth(unsigned long int anim, int index);
    void clearMouth();
 
    //-- Sounds
    void _tone (float noteFrequency, long noteDuration, int silentDuration);
    void _playNote(float noteFrequency, long noteDuration);
    void bendTones (float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration);
    void sing(int songName);

    //-- Gestures
    void playGesture(int gesture);

 
  private:
    int Max7219_Din = PIN_DIN;
    int Max7219_Cs = PIN_CS;
    int Max7219_Clk = PIN_CLK;
    MaxMatrix ledmatrix=MaxMatrix(Max7219_Din,Max7219_Cs,Max7219_Clk, 1);  // init Max7219 LED Matrix, 1 module
    BatReader battery;
    Oscillator servo[6];
    US us;
  
    int servo_pins[6];
    int servo_trim[6];
    int servo_position[6];

    int pinBuzzer;
    int pinNoiseSensor;
    
    unsigned long final_time;
    unsigned long partial_time;
    float increment[6];

    bool isOttoResting;

    unsigned long int getMouthShape(int number);
    unsigned long int getAnimShape(int anim, int index);
    void _execute(int A[6], int O[6], int T, double phase_diff[6], float steps);

};

#endif


