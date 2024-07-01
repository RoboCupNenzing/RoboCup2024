// Libraries für Pixy
#include <SPI.h>
#include <Pixy2.h>
#include <SoftwareSerial.h>

// Pins für Motor links hinten
#define lh_dir 8
#define lh_pwm 2
#define lh_enc 20

// Pins für Motor links vorne
#define lv_dir 10
#define lv_pwm 4
#define lv_enc 19

// Pins für Motor rechts vorne
#define rv_dir 11
#define rv_pwm 5
#define rv_enc 18

// Pins für Motor rechts hinten
#define rh_dir 9
#define rh_pwm 3
#define rh_enc 21

// Pin für Time of Flight Sensor
#define TOF_Eingang 25

// Serielle Schnittstelle zu Arduino UNO
#define rxPin 13
#define txPin 12
SoftwareSerial Serialneu(rxPin, txPin);

//ENCODER-Werte einrichten
volatile long ENCODER_value_LH = 0;
volatile long ENCODER_value_LV = 0;
volatile long ENCODER_value_RV = 0;
volatile long ENCODER_value_RH = 0;

// Neue Pixy anlegen
Pixy2 pixy;

// Variable für Geschwindigkeit
int speed = 70;

void setup() {
  // pinMode für Motoren
  pinMode(lh_pwm, OUTPUT);
  pinMode(lh_dir, OUTPUT);
  pinMode(lv_pwm, OUTPUT);
  pinMode(lv_dir, OUTPUT);
  pinMode(rh_pwm, OUTPUT);
  pinMode(rh_dir, OUTPUT);
  pinMode(rv_pwm, OUTPUT);
  pinMode(rv_dir, OUTPUT);


  // pinMode für Encoder
  pinMode(lh_enc, INPUT_PULLUP);
  pinMode(lv_enc, INPUT_PULLUP);
  pinMode(rh_enc, INPUT_PULLUP);
  pinMode(rv_enc, INPUT_PULLUP);

  //pinMode für Time of Flight Sensor
  pinMode(TOF_Eingang, INPUT_PULLUP);

  //Geschwindigkeit auf Null setzen
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);

  // Encoder Pins
  digitalWrite(lh_enc, HIGH);
  digitalWrite(lv_enc, HIGH);
  digitalWrite(rh_enc, HIGH);
  digitalWrite(rv_enc, HIGH);

  //Interrupts anlegen
  attachInterrupt(digitalPinToInterrupt(lh_enc), ENCODER_LH, RISING);
  attachInterrupt(digitalPinToInterrupt(lv_enc), ENCODER_LV, RISING);
  attachInterrupt(digitalPinToInterrupt(rh_enc), ENCODER_RH, RISING);
  attachInterrupt(digitalPinToInterrupt(rv_enc), ENCODER_RV, RISING);

  //Serielle Kommunikation starten
  Serial.begin(9600);     //Kommunikation zu PC
  Serialneu.begin(9600);  //Kommunikation zu Körper
  Serial2.begin(9600);    //Kommunikation zu ZigBee

  //Pixy starten
  pixy.init();
}

void loop() {



  // Der Pirat wird via ZigBee gestartet
  ZigbeeAbfragen("1");
  delay(1000);

  // Befehl an Oberkörper --> Laufen
  Serialneu.println(1);

  // Bewegen zur Meerjungfrau
  MOVE_forward(speed, 680);
  delay(400);
  TURN_right(speed, 290);    //290 steps sind eine 90 Grad Drehung
  delay(400);
  MOVE_forward(speed, 350);
  delay(400);
  MOVE_rightforward(speed, 800);

  // Auf Übergabe von Schatzkarte warten
  DatenAbfragen("1");

  
  // Bewegen zurück hinter die Kulisse
  MOVE_leftbackward(speed, 800);
  delay(400);
  MOVE_backward(speed, 350);
  delay(400);
  TURN_left(speed, 300);
  delay(400);
  MOVE_backward(speed, 680);
  delay(400);

  //Befehl von ZigBee für Phase 2 
  ZigbeeAbfragen("4");
  delay(2000);
  
  // Befehl an Oberkörper --> Laufen
  Serialneu.println(2);

  // Bewegen zu Schatzinsel
  MOVE_forward(speed, 450);
  delay(400);
  MOVE_rightforward(speed, 700);
  delay(400);
  TURN_left(speed, 145);

  // Arm anheben
  Serialneu.println(3);

  // Navigieren mit Pixy
  
  
  delay(2000);
  MOVE_PIXY(35);
  delay(400);
  MOVE_forward(30, 65);

 
  // Befehl an Oberkörper --> Schlange aufheben
  Serialneu.println(4);

  // Warten auf Schlange
  DatenAbfragen("3");

  // Rückzug 
  MOVE_backward(speed, 250);
  delay(400);

  // Arm wieder Absenken
  Serialneu.println(5);

  // auf geöffnete Schatzkiste warten
  delay(2000);

  // zum Publikum drehen
  TURN_right(speed, 435);
  delay(400);

  // in die Mitte bewegen
  MOVE_rightforward(speed, 700); 

   ZigbeeAbfragen("C");

   MOVE_forward(speed, 60);



  // Tanz
  delay(10000000000);
}


void MOVE_PIXY(int sp) {

  digitalWrite(lh_dir, HIGH);
  digitalWrite(lv_dir, HIGH);
  digitalWrite(rv_dir, HIGH);
  digitalWrite(rh_dir, HIGH);


  while (digitalRead(TOF_Eingang) == LOW) {

    pixy.ccc.getBlocks();
    delay(15);
    if (pixy.ccc.numBlocks) {
      if (pixy.ccc.blocks[0].m_x < 150) {

        //nach rechts
        digitalWrite(lh_dir, HIGH);
        digitalWrite(lv_dir, LOW);
        digitalWrite(rv_dir, HIGH);
        digitalWrite(rh_dir, LOW);

        analogWrite(lh_pwm, sp);
        analogWrite(lv_pwm, sp);
        analogWrite(rv_pwm, sp);
        analogWrite(rh_pwm, sp);

      } else if (pixy.ccc.blocks[0].m_x > 170) {
        //nach Links
        digitalWrite(lh_dir, LOW);
        digitalWrite(lv_dir, HIGH);
        digitalWrite(rv_dir, LOW);
        digitalWrite(rh_dir, HIGH);

        analogWrite(lh_pwm, sp);
        analogWrite(lv_pwm, sp); 
        analogWrite(rv_pwm, sp);
        analogWrite(rh_pwm, sp);

      } else if (pixy.ccc.blocks[0].m_x >= 150 && pixy.ccc.blocks[0].m_x <= 170) {

        // GERADEAUS
        digitalWrite(lh_dir, HIGH);
        digitalWrite(lv_dir, HIGH);
        digitalWrite(rv_dir, HIGH);
        digitalWrite(rh_dir, HIGH);

        analogWrite(lh_pwm, sp);
        analogWrite(lv_pwm, sp);
        analogWrite(rv_pwm, sp);
        analogWrite(rh_pwm, sp);
      }
    }
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);
   Serial.println(ENCODER_value_LH);
  Serial.println(ENCODER_value_LV);
  Serial.println(ENCODER_value_RH);
  Serial.println(ENCODER_value_RV);
  CLEAR_VALUE();
}


void MOVE_forward(int sp, int steps) {
  digitalWrite(lh_dir, HIGH);
  digitalWrite(lv_dir, HIGH);
  digitalWrite(rv_dir, HIGH);
  digitalWrite(rh_dir, HIGH);

  analogWrite(lh_pwm, sp);
  analogWrite(lv_pwm, sp);
  analogWrite(rv_pwm, sp);
  analogWrite(rh_pwm, sp);




  while (ENCODER_value_LH < steps) {
    delay(1);
  }

  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);

  Serial.println(ENCODER_value_LH);
  Serial.println(ENCODER_value_LV);
  Serial.println(ENCODER_value_RH);
  Serial.println(ENCODER_value_RV);

  CLEAR_VALUE();
}

void MOVE_backward(int sp, int steps) {
  digitalWrite(lh_dir, LOW);
  digitalWrite(lv_dir, LOW);
  digitalWrite(rv_dir, LOW);
  digitalWrite(rh_dir, LOW);

  analogWrite(lh_pwm, sp);
  analogWrite(lv_pwm, sp);
  analogWrite(rv_pwm, sp);
  analogWrite(rh_pwm, sp);

  while (ENCODER_value_LH < steps) {
    delay(1);
  }

  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);

   Serial.println(ENCODER_value_LH);
  Serial.println(ENCODER_value_LV);
  Serial.println(ENCODER_value_RH);
  Serial.println(ENCODER_value_RV);
  CLEAR_VALUE();
}

void MOVE_left(int sp, int steps) {
  digitalWrite(lh_dir, HIGH);
  digitalWrite(lv_dir, LOW);
  digitalWrite(rv_dir, HIGH);
  digitalWrite(rh_dir, LOW);

  analogWrite(lh_pwm, sp);
  analogWrite(lv_pwm, sp);
  analogWrite(rv_pwm, sp);
  analogWrite(rh_pwm, sp);

  while (ENCODER_value_LH < steps) {
    delay(1);
  }

  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);
   Serial.println(ENCODER_value_LH);
  Serial.println(ENCODER_value_LV);
  Serial.println(ENCODER_value_RH);
  Serial.println(ENCODER_value_RV);
  CLEAR_VALUE();
}


void MOVE_right(int sp, int steps) {
  digitalWrite(lh_dir, LOW);
  digitalWrite(lv_dir, HIGH);
  digitalWrite(rv_dir, LOW);
  digitalWrite(rh_dir, HIGH);

  analogWrite(lh_pwm, sp);
  analogWrite(lv_pwm, sp);
  analogWrite(rv_pwm, sp);
  analogWrite(rh_pwm, sp);

  while (ENCODER_value_LH < steps) {
    delay(1);
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);
     Serial.println(ENCODER_value_LH);
  Serial.println(ENCODER_value_LV);
  Serial.println(ENCODER_value_RH);
  Serial.println(ENCODER_value_RV);
  CLEAR_VALUE();
}

void MOVE_leftforward(int sp, int steps) {
  digitalWrite(lh_dir, HIGH);
  digitalWrite(lv_dir, LOW);
  digitalWrite(rv_dir, HIGH);
  digitalWrite(rh_dir, LOW);

  analogWrite(lh_pwm, sp);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, sp);
  analogWrite(rh_pwm, 0);

  while (ENCODER_value_LH < steps) {
    delay(1);
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);
     Serial.println(ENCODER_value_LH);
  Serial.println(ENCODER_value_LV);
  Serial.println(ENCODER_value_RH);
  Serial.println(ENCODER_value_RV);
  CLEAR_VALUE();
}

void MOVE_rightforward(int sp, int steps) {
  digitalWrite(lh_dir, LOW);
  digitalWrite(lv_dir, HIGH);
  digitalWrite(rv_dir, LOW);
  digitalWrite(rh_dir, HIGH);

  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, sp);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, sp);

  while (ENCODER_value_LV < steps) {
    delay(1);
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);
 Serial.println(ENCODER_value_LH);
  Serial.println(ENCODER_value_LV);
  Serial.println(ENCODER_value_RH);
  Serial.println(ENCODER_value_RV);
  CLEAR_VALUE();
}

void MOVE_leftbackward(int sp, int steps) {
  digitalWrite(lh_dir, HIGH);
  digitalWrite(lv_dir, LOW);
  digitalWrite(rv_dir, HIGH);
  digitalWrite(rh_dir, LOW);

  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, sp);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, sp);

  while (ENCODER_value_LV < steps) {
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);

   Serial.println(ENCODER_value_LH);
  Serial.println(ENCODER_value_LV);
  Serial.println(ENCODER_value_RH);
  Serial.println(ENCODER_value_RV);

  CLEAR_VALUE();
}


void TURN_left(int sp, int steps) {
  digitalWrite(lh_dir, LOW);
  digitalWrite(lv_dir, LOW);
  digitalWrite(rv_dir, HIGH);
  digitalWrite(rh_dir, HIGH);

  analogWrite(lh_pwm, sp);
  analogWrite(lv_pwm, sp);
  analogWrite(rv_pwm, sp);
  analogWrite(rh_pwm, sp);

  while (ENCODER_value_LH < steps) {
    delay(1);
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);

   Serial.println(ENCODER_value_LH);
  Serial.println(ENCODER_value_LV);
  Serial.println(ENCODER_value_RH);
  Serial.println(ENCODER_value_RV);

  CLEAR_VALUE();
}

void TURN_right(int sp, int steps) {
  digitalWrite(lh_dir, HIGH);
  digitalWrite(lv_dir, HIGH);
  digitalWrite(rv_dir, LOW);
  digitalWrite(rh_dir, LOW);

  analogWrite(lh_pwm, sp);
  analogWrite(lv_pwm, sp);
  analogWrite(rv_pwm, sp);
  analogWrite(rh_pwm, sp);

  while (ENCODER_value_LH < steps) {
    delay(1);
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);

   Serial.println(ENCODER_value_LH);
  Serial.println(ENCODER_value_LV);
  Serial.println(ENCODER_value_RH);
  Serial.println(ENCODER_value_RV);
  CLEAR_VALUE();
}

void ENCODER_LH() {
  ENCODER_value_LH++;
}

void ENCODER_LV() {
  ENCODER_value_LV++;
}

void ENCODER_RH() {
  ENCODER_value_RH++;
}

void ENCODER_RV() {
  ENCODER_value_RV++;
}

void CLEAR_VALUE() {
  ENCODER_value_LH = 0;
  ENCODER_value_LV = 0;
  ENCODER_value_RH = 0;
  ENCODER_value_RV = 0;
}

void ZigbeeAbfragen(String Zahl) {
  while (1) {
    String readString;
    String Daten;
    while (Serial2.available()) {
      delay(1);
      if (Serial2.available() > 0) {
        char c = Serial2.read();
        if (isControl(c)) {
          break;
        }
        readString += c;
      }
    }
    Daten = readString;

    if (Daten == Zahl) {
      break;
    }
  }
}


void DatenAbfragen(String Zahl) {
  while (1) {
    String readString;
    String Daten;
    while (Serialneu.available()) {
      delay(1);
      if (Serialneu.available() > 0) {
        char c = Serialneu.read();
        if (isControl(c)) {
          break;
        }
        readString += c;
      }
    }
    Daten = readString;

    if (Daten == Zahl) {
      break;
    }
  }
}