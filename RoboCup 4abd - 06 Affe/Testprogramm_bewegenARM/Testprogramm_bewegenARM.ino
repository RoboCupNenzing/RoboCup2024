//Testprogramm 2 Servo  (hiwonder LD-260MG 7,1V) (6 - 8,4V)
//AFFE Armbewegung



#include <Adafruit_PWMServoDriver.h>

// Neuer Servodriver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  130 // This is the 'minimum' pulse length count (out of 4096) 
#define SERVOMAX  550 // This is the 'maximum' pulse length count (out of 4096) 
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 50 
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 150 
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates 

uint8_t servonum = 0;  //Board 0 (es wird nur 1 board verwendet)


// Pulslängen für Servos
int pulselength = 0;

int pause1 = 1000;

void setup()

{
  
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(10);

}

void loop()

{

  for(int i = 90; i<=180; i++)
  {
    bewegenARM(i);
    delay(10);
  }

  for(int i = 180; i>=90; i--)
  {
    bewegenARM(i);
    delay(10);
  }



}

void bewegenARM(int grad)
{

  pulselength = map(grad, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(1, 0, pulselength);                           //Steckplatz 0, board 0
  
}
