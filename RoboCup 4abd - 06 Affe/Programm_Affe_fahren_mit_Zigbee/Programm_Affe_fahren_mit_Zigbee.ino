//Programm AFFE - fahren

//Libraries einbinden
#include "Adafruit_VL53L0X.h"
#include <Wire.h>


// Variablen für Entfernungsmesser
int EntfernungRechts = 0;
int EntfernungLinks = 0;

// Sensoren initiieren
Adafruit_VL53L0X Sensor1 = Adafruit_VL53L0X();
Adafruit_VL53L0X Sensor2 = Adafruit_VL53L0X();

// Motor Aus
#define STBY 10

// Motorsteuerung Motor A:
#define PWMA 5
#define AIN1 8
#define AIN2 9

// Motorsteuerung Motor B:
#define PWMB 6
#define BIN1 11
#define BIN2 12

//Geschwindigkeiten der Motoren
int sp_A = 100;
int sp_B = 92;




void setup() {



  // I2C Bus starten
  Wire.begin();
  Serial.begin(9600);
  Serial1.begin(9600);       //Zigbee
  Serial2.begin(9600);       //kabelgebundene Kommunikation

  Serial.println("Start");

  // PinMode für Motoren
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);



  // Erster Sensor starten
  TCA9548A(2);
  Serial.println("Erster Sensor");
  if (!Sensor1.begin()) {
    Serial.println(F("Failed to boot VL53L0X Nummer 1"));
    while (1)
      ;
  }

  // Zweiten Sensor starten
  TCA9548A(3);
  Serial.println("Zweiter Sensor");
  if (!Sensor2.begin()) {
    Serial.println(F("Failed to boot VL53L0X Nummer 2"));
    while (1)
      ;
  }

  // STBY setzen
  digitalWrite(STBY, HIGH);

  //Richtung einstellen
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void loop() {

  /*
  //Empfang "A" - Zigbee (PIRAT)
  
  //ZigbeeAbfragen("A");
  //Serial.println("A");
  delay(3000);
  Serial2.print(1);         //Befehl WALKArme
  Serial.println(1);
 
  Rampefahren();
  delay(500);
  */
  Serial2.print(2);         //Befehl TANZArme
  MOVE_clockwise();
  Serial.println(2);
 
   //Empfang "B" - Zigbee (PIRAT)
  //ZigbeeAbfragen("B");
  Serial.println("B");
    delay(10000);

  Serial2.print(3);         //Befehl TANZArme
  Serial.println(3);
  delay(2000);
  MOVE_clockwise();
  delay(2000);
  MOVE_conter_clockwise();
  delay(2000);

  delay(20000000);
}

// I2C-Bus
void TCA9548A(uint8_t bus) {
  Wire.beginTransmission(0x70);
  Wire.write(1 << bus);
  Wire.endTransmission();
}

void Rampefahren() {
  while (EntfernungRechts < 200 && EntfernungLinks < 200) {

    Messenlinks();

    Messenrechts();

    if (EntfernungRechts < 40) {
      Serial.println("Links Abstand halten");
      analogWrite(PWMA, 0);
    } else {
      analogWrite(PWMA, sp_A);
    }

    if (EntfernungLinks < 40) {
      Serial.println("Rechts Abstand halten");
      analogWrite(PWMB, 0);
    } else {
      analogWrite(PWMB, sp_B);
    }
  }
  //2 Sek weiterfahren
  analogWrite(PWMB, sp_B);
  analogWrite(PWMA, sp_A);
  delay(2000);
  STOP();
}

void Messenrechts() {
  TCA9548A(2);
  VL53L0X_RangingMeasurementData_t measure1;
  Sensor1.rangingTest(&measure1, false);

  EntfernungRechts = measure1.RangeMilliMeter;
  Serial.println(EntfernungRechts);
}

void Messenlinks() {
  TCA9548A(3);
  VL53L0X_RangingMeasurementData_t measure2;
  Sensor2.rangingTest(&measure2, false);

  EntfernungLinks = measure2.RangeMilliMeter;
  Serial.println(EntfernungLinks);
}

void STOP() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  //Geschwindigkeit
  analogWrite(PWMB, 0);
  analogWrite(PWMA, 0);
}

void MOVE_clockwise() {
  //Richtung
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  //Geschwindigkeit
  analogWrite(PWMA, sp_A);
  analogWrite(PWMB, sp_B);
  delay(1000);
  STOP();
}

void MOVE_conter_clockwise() {
 //Richtung
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  //Geschwindigkeit
  analogWrite(PWMA, sp_A);
  analogWrite(PWMB, sp_B);
  delay(1000);
  STOP(); 
}

void ZigbeeAbfragen(String Zahl)
{
  while (1)
  {
    String readString;
    String Daten;
    while (Serial1.available())
    {
      delay(1);
      if (Serial1.available() > 0)
      {
        char c = Serial1.read();
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
