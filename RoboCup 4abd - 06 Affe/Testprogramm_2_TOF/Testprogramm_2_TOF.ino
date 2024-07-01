#include "Adafruit_VL53L0X.h"
#include <Wire.h>

int Entfernung1 = 0;
int Entfernung2 = 0;
Adafruit_VL53L0X Sensor1 = Adafruit_VL53L0X();
Adafruit_VL53L0X Sensor2 = Adafruit_VL53L0X();

void TCA9548A(uint8_t bus) {
  Wire.beginTransmission(0x70);
  Wire.write(1 << bus);
  Wire.endTransmission();
}

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Start");

  TCA9548A(2);
  Serial.println("Test");
  if (!Sensor1.begin()) {
    Serial.println(F("Failed to boot VL53L0X Nummer 1"));
    while (1);
  }

  TCA9548A(3);
  if (!Sensor2.begin()) {
    Serial.println(F("Failed to boot VL53L0X Nummer 2"));
    while (1);
  }

}

void loop() {

  TCA9548A(2);
  VL53L0X_RangingMeasurementData_t measure1;
  Sensor1.rangingTest(&measure1, false);

  Entfernung1 = measure1.RangeMilliMeter;
  Serial.println(Entfernung1);

  TCA9548A(3);
  VL53L0X_RangingMeasurementData_t measure2;
  Sensor2.rangingTest(&measure2, false);

  Entfernung2 = measure2.RangeMilliMeter;
  Serial.println(Entfernung2);


  delay(200);
}
