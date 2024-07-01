// Libraries
#include "Adafruit_VL53L0X.h"
#include <Wire.h>

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

int sp_A = 100;
int sp_B = 92;

// Variablen für Entfernungsmesser
int EntfernungRechts = 0;
int EntfernungLinks = 0;

// Sensoren initiieren
Adafruit_VL53L0X Sensor1 = Adafruit_VL53L0X();
Adafruit_VL53L0X Sensor2 = Adafruit_VL53L0X();


void setup() {

  // I2C Bus starten
  Wire.begin();
  Serial.begin(9600);
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

  Serial.println("Test");
  if (!Sensor1.begin()) {
    Serial.println(F("Failed to boot VL53L0X Nummer 1"));
    while (1)
      ;
  }

  // Zweiten Sensor starten
  TCA9548A(3);
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

 Rampefahren();

  analogWrite(PWMB, sp_B);
  analogWrite(PWMA, sp_A);
  delay(2000);
  analogWrite(PWMB, 0);
  analogWrite(PWMA, 0);
  delay(20000000);
}

// I2C-Bus
void TCA9548A(uint8_t bus) {
  Wire.beginTransmission(0x70);
  Wire.write(1 << bus);
  Wire.endTransmission();
}

void Rampefahren()
{
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
}

void Messenrechts()
{
      TCA9548A(2);
    VL53L0X_RangingMeasurementData_t measure1;
    Sensor1.rangingTest(&measure1, false);

    EntfernungRechts = measure1.RangeMilliMeter;
    Serial.println(EntfernungRechts);
}

void Messenlinks()
{
      TCA9548A(3);
    VL53L0X_RangingMeasurementData_t measure2;
    Sensor2.rangingTest(&measure2, false);

    EntfernungLinks = measure2.RangeMilliMeter;
    Serial.println(EntfernungLinks);
}