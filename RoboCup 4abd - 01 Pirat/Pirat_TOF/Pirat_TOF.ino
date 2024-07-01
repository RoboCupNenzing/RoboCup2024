#include "Adafruit_VL53L0X.h"
 
int Entfernung = 400 ;
Adafruit_VL53L0X Sensor = Adafruit_VL53L0X();
 
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("Start");
 
  if (!Sensor.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
  Serial.println("Test");
  digitalWrite(13, LOW);
 
}
 
void loop() {
 
 
 
  VL53L0X_RangingMeasurementData_t measure;
  Sensor.rangingTest(&measure, false);
 
  Entfernung = measure.RangeMilliMeter;
  Serial.println(Entfernung);
  if (Entfernung <200)
  { 
    digitalWrite(13, HIGH);
   
  }
  else
  {
     digitalWrite(13, LOW);
  }
  delay(20);
 
}
 