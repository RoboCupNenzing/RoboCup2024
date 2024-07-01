//Programm HAI - Flosse (Arduino UNO)

//A4 - SDA Pin - grünes Kabel
//A5 - SCL Pin - gelbes Kabel

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//Serielle Kommunikation
#include <SoftwareSerial.h>
#define rxPin 2  //gelbes Kabel
#define txPin 3  //grünes Kabel

SoftwareSerial Connect(rxPin, txPin);


// Neuer Servodriver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 130   // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 550   // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 600      // This is the rounded 'minimum' microsecond length based on the minimum pulse of 50
#define USMAX 2400     // This is the rounded 'maximum' microsecond length based on the maximum pulse of 150
#define SERVO_FREQ 50  // Analog servos run at ~50 Hz updates

uint8_t servonum = 0;  //Board 0 (es wird nur 1 board verwendet)


// Pulslängen für Servos
int pulselength = 0;

int pause1 = 1000;


void setup() {
  //Serielle Kommunikation
  Serial.begin(9600);
  Connect.begin(9600);

  //Servoboard
  pwm.begin();

  // Analog servos run at ~60 Hz updates
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);

  //Servo auf Ausgangsposition
  bewegenFlosse(90);

  delay(200);
  Serial.println("Start");
}

void loop() {

  

  while (1) {
    String readString;
    String Daten;
    while (Connect.available()) {
      delay(1);
      if (Connect.available() > 0) {
        char c = Connect.read();  //gets one byte from serial buffer
        if (isControl(c)) {
          //'Serial.println("it's a control character");
          break;
        }
        readString += c;  //makes the string readString
      }
    }


    Daten = readString;

    //Serial.println(Daten);

    if (Daten == "1") {
      
      Serial.println(1);
      MOVE_Flosse(2);
      

      Serial.println("Flosse");
    }

    
  }
}

void bewegenFlosse(int grad)
{

  pulselength = map(grad, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(0, 0, pulselength);             //Steckplatz 0, board 0
  
}

void MOVE_Flosse(int WH)
{
  for(int i = 0; i <= WH; i++) {
        
      
      for (int i = 70; i <= 110; i++) {
        bewegenFlosse(i);
        delay(10);
      }

      for (int i = 110; i >= 70; i--) {
        bewegenFlosse(i);
        delay(10);
      }
      } 

}