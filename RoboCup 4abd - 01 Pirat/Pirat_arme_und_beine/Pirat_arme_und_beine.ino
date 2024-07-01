// Adafruit PWM Servo Driver Library
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>

// Neuen Adafruit Servodriver anlegen
Adafruit_PWMServoDriver pwmTreiber = Adafruit_PWMServoDriver();

//Einstellungen für den Servo-Driver
#define SERVOMIN 150
#define SERVOMAX 500
#define USMIN 600
#define USMAX 2400
#define SERVO_FREQ 60


// Variablen für den Servo-Driver
int ServoPuls0 = 0;
int ServoPuls1 = 0;
int ServoPuls2 = 0;
int ServoPuls3 = 0;
int ServoPuls4 = 0;
int ServoPuls5 = 0;
int ServoPuls6 = 0;
int ServoPuls7 = 0;

// Die Nummer des Servo-Drivers
uint8_t servonum = 0;

// Pins für den Elektro-Magneten
#define In1 4
#define In2 5

// Serielle Schnittstelle zu Arduino Mega
#define rxPin 8
#define txPin 9
SoftwareSerial Serialneu(rxPin, txPin);

void setup() {
  // PinMode für den Elektromagneten
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);

  // Start des Servo-Drivers
  pwmTreiber.begin();
  pwmTreiber.setPWMFreq(SERVO_FREQ);

  // Wir schalten den Elektromagneten aus
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);

  Serial.begin(9600);
  Serialneu.begin(9600);

  Bewegenrechts(90, 0, 90, 90);
  Bewegenlinks(90, 0, 90, 90);
}


void loop() {



  // ----------------------- Szene 1 -------------------
  DatenAbfragen("1");
  // Serial.println("ankommen");
  //delay(1000);

  laufen();
  laufen();
  laufen();
  laufen();
  laufen();
  
  delay(1500);

  // Arm zur Meerjungfrau ausstrecken
  Magnetanziehen();
  for (int i = 0; i <= 45; i++) {
    int j= i*2;
    Bewegenrechts(90, i, 90, 90);
    delay(10);
  }
  delay(1000);

  //Schatzkarte dem Publikum zeigen
  for (int i = 45; i >= 0; i--) {
    int j= i*2;
    Bewegenrechts(j, i, j, 90);
    delay(20);
  }

  Serialneu.println(1);

  laufenmitKarte();
  laufenmitKarte();
  laufenmitKarte();
  laufenmitKarte();
  laufenmitKarte();
  laufenmitKarte();

  //Hand herunter nehmen
  for (int i = 0; i <= 90; i++) {
    Bewegenrechts(i, 0, 90, 90);
    delay(10);
  }
  delay(1000);
  Magnetloesen();



  // ----------------------- Szene 2 -------------------
  DatenAbfragen("2");
  
  
  laufen();
  laufen();
  laufen();

  Magnetanziehen();

  DatenAbfragen("3");

  //Hand heben um Schlange zu greifen
  for (int i = 90; i >= 0; i--) {
    Bewegenrechts(i, 0, 90, 90);
    delay(10);
  }

  DatenAbfragen("4");

  delay(1000);


  for (int i = 0; i <= 25; i++) {
    Bewegenrechts(i, 0, 90 - i, 90);
    delay(15);
  }

  delay(1000);
  for (int i = 25; i >= 0; i--) {
    Bewegenrechts(i, 0, 90 - i, 90);
    delay(15);
  }
  delay(200);

  Serialneu.println(3);
  Serial.println("Zahl 3 gesendet");


  

  DatenAbfragen("5");
  delay(2000);
  Magnetloesen();
  delay(2000);

  for (int i = 0; i <= 90; i++) {
    Bewegenrechts(i, 0, i, 90);
    delay(10);
  }

  laufen();
  laufen();
  DatenAbfragen("6");

  tanzen1();
  Serialneu.println(4);
  tanzen2();
  tanzen3();
  GymBro();
  ChickenDance();
  NewskidsDance();

}



void Bewegenlinks(int Grad0, int Grad1, int Grad2, int Grad6) {
  ServoPuls0 = map(Grad0, 0, 180, SERVOMIN, SERVOMAX);
  ServoPuls1 = map(Grad1, 0, 180, SERVOMIN, SERVOMAX);
  ServoPuls2 = map(Grad2, 0, 180, SERVOMIN, SERVOMAX);
  ServoPuls6 = map(Grad6, 0, 180, SERVOMIN, SERVOMAX);

  pwmTreiber.setPWM(0, 0, ServoPuls0);
  pwmTreiber.setPWM(1, 0, ServoPuls1);
  pwmTreiber.setPWM(2, 0, ServoPuls2);
  pwmTreiber.setPWM(6, 0, ServoPuls6);
}

void Bewegenrechts(int Grad3, int Grad4, int Grad5, int Grad7) {
  Grad3 = 180 - Grad3;
  Grad7 = 180 - Grad7;

  ServoPuls3 = map(Grad3, 0, 180, SERVOMIN, SERVOMAX);
  ServoPuls4 = map(Grad4, 0, 180, SERVOMIN, SERVOMAX);
  ServoPuls5 = map(Grad5, 0, 180, SERVOMIN, SERVOMAX);
  ServoPuls7 = map(Grad7, 0, 180, SERVOMIN, SERVOMAX);
  pwmTreiber.setPWM(3, 0, ServoPuls3);
  pwmTreiber.setPWM(4, 0, ServoPuls4);
  pwmTreiber.setPWM(5, 0, ServoPuls5);
  pwmTreiber.setPWM(7, 0, ServoPuls7);
}

void Magnetanziehen() {

  // Magnet anziehen:
  digitalWrite(In1, HIGH);
}

void Magnetloesen() {
  digitalWrite(In1, LOW);
  // Restmagnetfeld lösen
  digitalWrite(In2, HIGH);
  delay(10);
  digitalWrite(In2, LOW);
}



void laufen() {

  for (int i = 90; i >= 40; i--) {
    Bewegenlinks(i, 0, 90, 180 - i);
    Bewegenrechts(180 - i, 0, 90, i);
    delay(10);
  }


  for (int i = 40; i <= 90; i++) {
    Bewegenlinks(i, 0, 90, 180 - i);
    Bewegenrechts(180 - i, 0, 90, i);
    delay(10);
  }


  for (int i = 90; i >= 40; i--) {
    Bewegenlinks(180 - i, 0, 90, i);
    Bewegenrechts(i, 0, 90, 180 - i);
    delay(10);
  }


  for (int i = 40; i <= 90; i++) {
    Bewegenlinks(180 - i, 0, 90, i);
    Bewegenrechts(i, 0, 90, 180 - i);
    delay(10);
  }
}

void laufenmitKarte() {

  for (int i = 90; i >= 40; i--) {
    Bewegenlinks(i, 0, 90, 180 - i);
    Bewegenrechts(0, 0, 0, i);
    delay(10);
  }


  for (int i = 40; i <= 90; i++) {
    Bewegenlinks(i, 0, 90, 180 - i);
    Bewegenrechts(0, 0, 0, i);
    delay(10);
  }


  for (int i = 90; i >= 40; i--) {
    Bewegenlinks(180 - i, 0, 90, i);
    Bewegenrechts(0, 0, 0, 180 - i);
    delay(10);
  }


  for (int i = 40; i <= 90; i++) {
    Bewegenlinks(180 - i, 0, 90, i);
    Bewegenrechts(0, 0, 0, 180 - i);
    delay(10);
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


void tanzen1() {

  for (int i = 90; i >= 0; i--) {
    Bewegenlinks(90, 0, 90, 90);
    Bewegenrechts(i, 0, 90, 90);
    delay(3);
  }

  for (int i = 0; i <= 90; i++) {
    Bewegenlinks(90 - i, 0, 90, 90);
    Bewegenrechts(i, 0, 90, 90);
    delay(3);
  }

  for (int i = 0; i <= 90; i++) {
    Bewegenlinks(i, 0, 90, 90);
    Bewegenrechts(90 - i, 0, 90, 90);
    delay(3);
  }

  for (int i = 0; i <= 90; i++) {
    Bewegenlinks(90 - i, 0, 90, 90);
    Bewegenrechts(i, 0, 90, 90);
    delay(3);
  }

  for (int i = 0; i <= 90; i++) {
    Bewegenlinks(i, 0, 90, 90);
    Bewegenrechts(90 - i, 0, 90, 90);
    delay(3);
  }

  for (int i = 0; i <= 90; i++) {
    Bewegenlinks(90, 0, 90, 90);
    Bewegenrechts(i, 0, 90, 90);
    delay(3);
  }
}

void tanzen2() {

  for (int i = 90; i >= 0; i--) {
    Bewegenlinks(i, 0, 90, 90);
    Bewegenrechts(90, 0, 90, 90);
    delay(3);
  }

  delay(4000);

  for (int i = 90; i >= 0; i--) {
    Bewegenlinks(90 - i, 0, 90, 90);
    Bewegenrechts(90, 0, 90, 90);
    delay(3);
  }
}

void tanzen3() {

  for (int i = 90; i >= 0; i--) {
    Bewegenlinks(90, 0, 90, 90);
    Bewegenrechts(i, 0, 90, 90);
    delay(3);
  }

  delay(4000);

  for (int i = 90; i >= 0; i--) {
    Bewegenlinks(90, 0, 90, 90);
    Bewegenrechts(90 - i, 0, 90, 90);
    delay(3);
  }
}

void ChickenDance() {
  for (int i = 90; i > 0; i--) {
    Bewegenlinks(90, 0, i, 90);
    Bewegenrechts(90, 0, i, 90);
    delay(8);
  }

  for (int i = 0; i < 2; i++) {
    for (int i = 0; i < 90; i++) {
      Bewegenlinks(90, i, 0, 90);
      Bewegenrechts(90, i, 0, 90);
      delay(6);
    }

    for (int i = 90; i > 0; i--) {
      Bewegenlinks(90, i, 0, 90);
      Bewegenrechts(90, i, 0, 90);
      delay(6);
    }
  }

  for (int i = 0; i < 90; i++) {
    Bewegenlinks(90, 0, i, 90);
    Bewegenrechts(90, 0, i, 90);
    delay(8);
  }
}


void GymBro() {
  for (int i = 0; i < 90; i++) {
    Bewegenlinks(90 - i, i, 90 - i, 90);
    Bewegenrechts(90 + i, i, 90 - i, 90);
    delay(8);
  }
  delay(500);

  for (int i = 0; i < 2; i++) {
    for (int i = 0; i < 180; i++) {
      Bewegenlinks(i, 90, 0, 90);
      Bewegenrechts(180 - i, 90, 0, 90);
      delay(8);
    }

    for (int i = 180; i > 0; i--) {
      Bewegenlinks(i, 90, 0, 90);
      Bewegenrechts(180 - i, 90, 0, 90);
      delay(8);
    }
  }

  for (int i = 90; i > 0; i--) {
    Bewegenlinks(90 - i, i, 90 - i, 90);
    Bewegenrechts(90 + i, i, 90 - i, 90);
    delay(8);
  }
}

void NewskidsDance() {
  // links: 90,0,90,90 --> 0,0,90,90
  // rechts 90,0,90,90
  for (int i = 90; i > 0; i--) {
    Bewegenlinks(i, 0, 90, 90);
    delay(10);
  }

  for (int i = 0; i < 2; i++) {
    // links: 0,0,90,90 --> 90,0,90,90
    // rechts 90,0,90,90 --> 0,0,90,90
    for (int i = 90; i > 0; i--) {
      Bewegenlinks(90 - i, 0, 90, 90);
      Bewegenrechts(i, 0, 90, 90);
      delay(10);
    }

    // links: 90,0,90,90 --> 0,0,90,90
    // rechts: 0,0,90,90 --> 90,0,90,90
    for (int i = 90; i > 0; i--) {
      Bewegenlinks(i, 0, 90, 90);
      Bewegenrechts(90 - i, 0, 90, 90);
      delay(10);
    }
  }

  // links: 90,0,90,90 --> 0,0,90,90
  // rechts 90,0,90,90
  for (int i = 90; i > 0; i--) {
    Bewegenlinks(90 - i, 0, 90, 90);
    delay(10);
  }
}

void SuperDuper() {
  for (int i = 90; i > 0; i--) {
    Bewegenlinks(i, 90 - i, i, 90);
    Bewegenrechts(i, 90 - i, i, 90);
    delay(10);
  }

  for (int i = 0; i < 90; i++) {
    Bewegenlinks(i, 90 - i, i, 90);
    Bewegenrechts(i, 90 - i, i, 90);
    delay(10);
  }
}
