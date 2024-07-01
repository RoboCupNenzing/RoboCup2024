//Programm HAI Reifen - fahren (ESP32)

//Kabelgebundene Serielle Kommunikation
  #define rxPin 32    //grünes Kabel
  #define txPin 33    //gelbes Kabel

//Serielle Kommunikation - Zigbee
  #define rxPinZ 27   //grünes Kabel
  #define txPinZ 14   //gelbes Kabel

//Servoboard
#include <Adafruit_PWMServoDriver.h>

#define STBY 17 /* Pin mit dem die Verbindung zum Motor hergestellt bzw. unterbrochen wird */

//Motorsteuerung:
#define PWMA 22   //(weiß) Pin für die Geschwindigkeit (Wert: 0 - 255)
#define AIN1 16  //(gruen) Pin1 für die Richtung (Vorwärts: HIGH, Rückwärts: LOW)
#define AIN2 23   //(gelb) Pin2 für die Richtung (Vorwärts: LOW, RÜckwärts: HIGH)

#define PWMB 19  // Pin für die Geschwindigkeit (Wert: 0 - 255)
#define BIN1 5   // Pin1 für die Richtung (Vorwärts: HIGH, Rückwärts: LOW)
#define BIN2 18  // Pin2 für die Richtung (Vorwärts: LOW, RÜckwärts: HIGH)

//Encoder
#define ENCODER_Pin_A 4
#define ENCODER_Pin_B 15

volatile long ENCODER_value_A = 0;
volatile long ENCODER_value_B = 0;


//int pause1 = 1000;




void setup() {
  

//Kabelgebundene serielle Kommunikation
  Serial.begin(9600);   //Serielle Monitor
  
  Serial.println("Hallo Welt");

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  Serial2.begin(9600, SERIAL_8N1, rxPin, txPin);
  
  
//Serielle Kommunikation - Zigbee
  pinMode(rxPinZ, INPUT);
  pinMode(txPinZ, OUTPUT);
  Serial1.begin(9600, SERIAL_8N1, rxPinZ, txPinZ);
  

//Motoren
  
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  //Motoren mit Strom versorgen
  digitalWrite(STBY, HIGH);

  //ENCODER
  pinMode(ENCODER_Pin_A, INPUT_PULLUP);
  pinMode(ENCODER_Pin_B, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCODER_Pin_A), ENCODER_A, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCODER_Pin_B), ENCODER_B, RISING);
  

}

void loop() {

  Serial.println("Test");
    
 
ZigbeeAbfragen("1");     //Signal "1" von Schatzkarte
  Serial.println(1);


ZigbeeAbfragen("2");    
  Serial.println(2);
  
  //Hai wartet in der Insel
  delay(8000);

  //Hai fährt los
  Serial2.print(5);       //Befehl an Flosse
  MOVE_forward(140, 2000);
  delay(100);
  
  //Drehung zum Schiff
  Serial2.print(2);      //FLosse
  MOVE_left(140, 2000);
  delay(100);
  
  //Hai fährt vor und zurück
  Serial2.print(7);       //Flosse
  Serial.println(7);
  MOVE_forward(140, 2000);
  delay(100);
  MOVE_backward(140, 1000);
  delay(100);
  MOVE_forward(140, 1000);
  delay(100);
  MOVE_backward(140, 1000);
  delay(100);
  MOVE_forward(140, 1000);
  delay(100);
  MOVE_backward(140, 1000);
  delay(100);


ZigbeeAbfragen("3");    
  Serial.println(3);

  //Hai dreht sich vom Schiff weg und fährt hinter die linke Insel
  Serial2.print(1);     //Flosse
  TURN_left(140, 400);
  delay(100);

  Serial2.print(2);          //Flosse
  MOVE_forward(140, 2000);
  delay(100);

  TURN_right(140, 400);
  delay(100);

  
  Serial2.print(10);       //Flosse
  Serial.println(10);
  MOVE_forward(140, 11000);

  

ZigbeeAbfragen("4");    
  Serial.println(4);

ZigbeeAbfragen("5");    
  Serial.println(5);



}

void MOVE_forward(int sp, int steps) {

    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);

    analogWrite(PWMA, sp);
    analogWrite(PWMB, sp);

    while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps)) {
    }

    Serial.print("Value A: ");
    Serial.println(ENCODER_value_A);
    Serial.print("Value B: ");
    Serial.println(ENCODER_value_B);

    STOP();
    CLEAR_VALUE();
  }

  void STOP() {

    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);

    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
  }

  void MOVE_backward(int sp, int steps) {

    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);

    analogWrite(PWMA, sp);
    analogWrite(PWMB, sp);

    while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps)) {
    }

    Serial.print("Value A: ");
    Serial.println(ENCODER_value_A);
    Serial.print("Value B: ");
    Serial.println(ENCODER_value_B);

    STOP();
    CLEAR_VALUE();
  }

  void TURN_right(int sp, int steps) {

    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);

    analogWrite(PWMA, sp);
    analogWrite(PWMB, sp);

    Serial.print("Value A: ");
    Serial.println(ENCODER_value_A);
    Serial.print("Value B: ");
    Serial.println(ENCODER_value_B);

    while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps)) {
    }
    STOP();
    CLEAR_VALUE();
  }


  void TURN_left(int sp, int steps) {

    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);

    analogWrite(PWMA, sp);
    analogWrite(PWMB, sp);


    while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps)) {
    }

    STOP();
    CLEAR_VALUE();
  }


  void MOVE_left(int sp, int steps) {

    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);

    int sp_left = sp * 0.7;
    int sp_right = sp;

    analogWrite(PWMA, sp_left);
    analogWrite(PWMB, sp_right);

    while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps)) {
    }

    Serial.print("Value A: ");
    Serial.println(ENCODER_value_A);
    Serial.print("Value B: ");
    Serial.println(ENCODER_value_B);

    STOP();
    CLEAR_VALUE();
  }


  void MOVE_right(int sp, int steps) {

    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);

    int sp_left = sp;
    int sp_right = sp * 0.7;

    analogWrite(PWMA, sp_left);
    analogWrite(PWMB, sp_right);

    while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps)) {
    }

    Serial.print("Value A: ");
    Serial.println(ENCODER_value_A);
    Serial.print("Value B: ");
    Serial.println(ENCODER_value_B);

    STOP();
    CLEAR_VALUE();
  }


  void ENCODER_A() {
    ENCODER_value_A++;
  }

  void ENCODER_B() {
    ENCODER_value_B++;
  }

  void CLEAR_VALUE() {
    ENCODER_value_A = 0;
    ENCODER_value_B = 0;
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