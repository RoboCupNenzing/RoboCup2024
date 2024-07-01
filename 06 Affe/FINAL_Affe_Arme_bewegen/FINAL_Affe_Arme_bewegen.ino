//Programm AFFE Armbewegung (2 Servos)

//Serielle Kommunikation

  #include <SoftwareSerial.h>
  #define rxPin 8      //grünes Kabel
  #define txPin 9     //gelbes Kabel
  SoftwareSerial Connect (rxPin, txPin);


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

//int pause1 = 1000;

void setup()

{
  //Serielle Kommuniktaion
  Serial.begin(9600);
  Connect.begin(9600);

  //Servos
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(10);

  //Startposition der Arme (90 grad)
  bewegenARMlinks(90);
  bewegenARMrechts(90);
  
}

void loop() {
  
  StartpositionArme();
  Serial.println("Start");
  
  //Rampe fahren
  DatenAbfragen("1");
  Serial.println(1);
  WALKArme(5);
  
  //Tanz mit den Armen
  DatenAbfragen("2");
  Serial.println(2);
  TANZArme(6);



//TANZ MIT PIRAT

DatenAbfragen("3");
  Serial.println(3);
  
  WALKArme(2);

DatenAbfragen("4");
  Serial.println(4);
  
  TANZArme(3);
  Armhochlinks(5000);
  
DatenAbfragen("5");
  Serial.println(5);
  
  Armhochrechts(5000);

DatenAbfragen("6");
  Serial.println(6);

  TANZArme(3);


DatenAbfragen("7");
  Serial.println(7);

  WALKArme(2);
  TANZArmesynchron(3);
  
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
          bewegenARMrechts(270-i);
          delay(5);
        }

        for (int i = 180; i >= 90; i--) {
          bewegenARMlinks(i);
          bewegenARMrechts(270-i);
          delay(5);
        }
      }
    StartpositionArme();
}

void TANZArmesynchron(int Anzahl) {
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


void DatenAbfragen(String Zahl)
{
  while (1)
  {
    String readString;
    String Daten;
    while (Connect.available())
    {
      delay(1);
      if (Connect.available() > 0)
      {
        char c = Connect.read();
        if (isControl(c)) {
          break;
        }
        readString += c;
      }
    }
    Daten = readString;
   
    if (Daten == Zahl)
    {
      break;
    }
  }
}
