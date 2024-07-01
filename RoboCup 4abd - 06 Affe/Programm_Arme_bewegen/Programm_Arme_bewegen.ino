//Testprogramm 2 Servo  (hiwonder LD-260MG 7,1V) (6 - 8,4V)
//AFFE Armbewegung



#include <Adafruit_PWMServoDriver.h>

// Neuer Servodriver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 130   // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 550   // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 600      // This is the rounded 'minimum' microsecond length based on the minimum pulse of 50
#define USMAX 2400     // This is the rounded 'maximum' microsecond length based on the maximum pulse of 150
#define SERVO_FREQ 50  // Analog servos run at ~50 Hz updates

uint8_t servonum = 0;  //Board 0 (es wird nur 1 board verwendet)


// Pulslängen für Servos
int pulselength0 = 0;
int pulselength1 = 0;

int pause1 = 1000;

void setup()

{

  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(10);

  //Startposition der Arme (90 grad)
  bewegenARMlinks(90);
  bewegenARMrechts(90);

}

void loop() {
  StartpositionArme();
  WALKArme(5);
  delay(1000);
  TANZArme(3);
  delay(1000);
  Armhochlinks(2000);
  delay(1000);
  Armhochrechts(2000);
  delay(1000);
}



void bewegenARMlinks(int grad0) {

  pulselength0 = map(grad0, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(1, 0, pulselength0);  //Steckplatz 0, board 0
}



void bewegenARMrechts(int grad1) {
  pulselength1 = map(grad1, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(2, 0, pulselength1);
}

void StartpositionArme()
{
  //Startposition der Arme (90 grad)
  bewegenARMlinks(90);
  bewegenARMrechts(90);

}


void WALKArme(int Anzahl) {
  for (int i = 0; i < Anzahl; i++) {
    for (int i = 60; i <= 140; i++) {
      bewegenARMlinks(i);
      bewegenARMrechts(180 - i);
      delay(10);
    }

    for (int i = 140; i >= 60; i--) {
      bewegenARMlinks(i);
      bewegenARMrechts(180 - i);
      delay(10);
    }
  }
  StartpositionArme();
}

void TANZArme(int Anzahl) {
      for (int i = 0; i < Anzahl; i++) {
        for (int i = 90; i <= 180; i++) {
          bewegenARMlinks(i);
          bewegenARMrechts(i);
          delay(5);
        }

        for (int i = 180; i >= 90; i--) {
          bewegenARMlinks(i);
          bewegenARMrechts(i);
          delay(5);
        }
      }
    StartpositionArme();
}


void Armhochlinks(int time) {
      
        for (int i = 90; i <= 180; i++) {
          bewegenARMlinks(i);
          bewegenARMrechts(90);
          delay(5);
        }
        delay(time);
StartpositionArme();
        
}

void Armhochrechts(int time) {
      
        for (int i = 90; i <= 180; i++) {
          bewegenARMlinks(90);
          bewegenARMrechts(i);
          delay(5);
        }
        delay(time);
StartpositionArme();
        
}
  
