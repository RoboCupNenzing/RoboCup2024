
//Testprogramm 1 Servo  (longruner 6V)
//HAI Flossenbewegung

#include <Adafruit_PWMServoDriver.h>

// Neuer Servodriver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  130        // This is the 'minimum' pulse length count (out of 4096) 
#define SERVOMAX  550        // This is the 'maximum' pulse length count (out of 4096) 
#define USMIN  600           // This is the rounded 'minimum' microsecond length based on the minimum pulse of 50 
#define USMAX  2400          // This is the rounded 'maximum' microsecond length based on the maximum pulse of 150 
#define SERVO_FREQ 50        // Analog servos run at ~50 Hz updates 

uint8_t servonum = 0;        //Board 0 (es wird nur 1 board verwendet)


// Pulslängen für Servos
int pulselength = 0;

int pause = 1000;


void setup()
{
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(10);
}

void loop()
{

  for(int i = 50; i < 120; i++)
  {
    bewegenFlosse(i);
    delay(10);
  }

  for(int i = 120; i > 70; i--)
  {
    bewegenFlosse(i);
    delay(10);
  }

//  delay(1000);
//  bewegenFlosse(120);
//  //delay(1000);
//  //bewegenFlosse(90);
//  delay(1000);
//  bewegenFlosse(50);
  
  
}

void bewegenFlosse(int grad)
{
 pulselength = map(grad, 0, 180, SERVOMIN, SERVOMAX);
 pwm.setPWM(0, 0, pulselength);                          //Steckplatz 0, board 0
}
