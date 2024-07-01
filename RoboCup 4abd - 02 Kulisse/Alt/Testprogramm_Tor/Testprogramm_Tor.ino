#include <SoftwareSerial.h>
//Testprogramm TOR
 
//TOR - Motor rechts
  #define DIR_R 5
  #define PUL_R 6        //PWM
  #define ENA_R 4
 
//TOR - Motor links
  #define DIR_L 9
  #define PUL_L 10       //PWM
  #define ENA_L 8

  #define rxPin 2
  #define txPin 3

  SoftwareSerial Zigbee(rxPin, txPin);
 
void setup()
{
  //TOR
  pinMode(DIR_R, OUTPUT);
  pinMode(PUL_R, OUTPUT);
  pinMode(ENA_R, OUTPUT);
 
  pinMode(DIR_L, OUTPUT);
  pinMode(PUL_L, OUTPUT);
  pinMode(ENA_L, OUTPUT);
 
  digitalWrite(ENA_R, LOW);
  digitalWrite(ENA_L, LOW);

  // Kommunikation mit ZigBee
  Zigbee.begin(9600);
}
void loop()
 {
  Zigbee.print("1");

  // warten
  delay(3000);

  Zigbee.print("2");  
  TOR_AUF_ZU();
  delay(3000);
  // Code von LEDs bis zum Hai
  Zigbee.print("3");
  // Code von LEDs bis zum Blitz
  Zigbee.print("4");
  //Code bis zum Schatz


}
 
void TOR_AUF_ZU()
{
  //Tor öffnen
   
  
    digitalWrite(DIR_R, HIGH);
    digitalWrite(DIR_L, LOW);
   
    for(int i = 0; i <= 230; i++)
      {
      digitalWrite(PUL_R, HIGH);
      digitalWrite(PUL_L, HIGH);
      delayMicroseconds(1700);
      digitalWrite(PUL_R, LOW);
      digitalWrite(PUL_L, LOW);
      delayMicroseconds(1700);
      }
    delay(15000);       //15 Sek geöffnet
 
  //Tor schließen
   
    digitalWrite(DIR_R, LOW);
    digitalWrite(DIR_L, HIGH);
   
    for(int i = 0; i <= 250; i++)
      {
      digitalWrite(PUL_R, HIGH);
      digitalWrite(PUL_L, HIGH);
      delayMicroseconds(1700);
      digitalWrite(PUL_R, LOW);
      digitalWrite(PUL_L, LOW);
      delayMicroseconds(1700);
      }
}

void Explosion()
{

  // Code
}