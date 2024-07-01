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

//ENCODER
volatile long ENCODER_value_LH = 0;
volatile long ENCODER_value_LV = 0;
volatile long ENCODER_value_RV = 0;
volatile long ENCODER_value_RH = 0;

// Neue Pixy anlegen
Pixy2 pixy;

int speed = 80;

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
  Serial3.begin(9600);    //Kommunikation zu ZigBee

  //Pixy starten
  pixy.init();
}

void loop() {
  //290 steps sind eine 90 Grad Drehung

  //ZigbeeAbfragen(1);

  delay(1000);
/*
  Serialneu.println(1);

  MOVE_forward(speed, 680);
  delay(200);
  TURN_right(speed, 290);
  delay(200);
  MOVE_forward(speed, 350);
  delay(200);

  MOVE_rightforward(speed, 800);


  DatenAbfragen("1");


  MOVE_leftbackward(speed, 800);
  delay(200);
  MOVE_backward(speed, 350);
  delay(200);
  TURN_left(speed, 300);
  delay(200);
  MOVE_backward(speed, 680);
  delay(200);

  //ZigBee warten

  Serialneu.println(2);
  MOVE_forward(speed, 400);
  delay(200);
  MOVE_rightforward(speed, 700);
  delay(200);
  TURN_left(speed, 145);

  */
  delay(1000);
   Serialneu.println(3);
  

  MOVE_PIXY(50);
  MOVE_forward(30, 20);
  Serialneu.println(4);
  
  DatenAbfragen("3");

   MOVE_backward(speed, 200);
  delay(200);

  Serialneu.println(4);
  
  


  delay(10000000000);
}


void MOVE_PIXY(int sp) {

  digitalWrite(lh_dir, HIGH);
  digitalWrite(lv_dir, HIGH);
  digitalWrite(rv_dir, HIGH);
  digitalWrite(rh_dir, HIGH);

  // Serial.println("Pixy wird aufgerufen");

  while (digitalRead(TOF_Eingang) == LOW) {

    //Serial.println(digitalRead(TOF_Eingang));

    pixy.ccc.getBlocks();
    delay(15);
    if (pixy.ccc.numBlocks) {
      if (pixy.ccc.blocks[0].m_x < 180) {

        //nach rechts
        digitalWrite(lh_dir, HIGH);
        digitalWrite(lv_dir, LOW);
        digitalWrite(rv_dir, HIGH);
        digitalWrite(rh_dir, LOW);

        analogWrite(lh_pwm, sp);
        analogWrite(lv_pwm, sp);
        analogWrite(rv_pwm, sp);
        analogWrite(rh_pwm, sp);

      } else if (pixy.ccc.blocks[0].m_x > 220) {
        //nach Links
        digitalWrite(lh_dir, LOW);
        digitalWrite(lv_dir, HIGH);
        digitalWrite(rv_dir, LOW);
        digitalWrite(rh_dir, HIGH);

        analogWrite(lh_pwm, sp);
        analogWrite(lv_pwm, sp);
        analogWrite(rv_pwm, sp);
        analogWrite(rh_pwm, sp);

      } else if (pixy.ccc.blocks[0].m_x >= 180 && pixy.ccc.blocks[0].m_x <= 220) {

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
  }

  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);

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
  }

  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);

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
  }

  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);
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
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);
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
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);
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
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);
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
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);
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
  }
  analogWrite(lh_pwm, 0);
  analogWrite(lv_pwm, 0);
  analogWrite(rv_pwm, 0);
  analogWrite(rh_pwm, 0);
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
    while (Serial3.available()) {
      delay(1);
      if (Serial3.available() > 0) {
        char c = Serial3.read();
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