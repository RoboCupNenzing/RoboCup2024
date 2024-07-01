//Testprogramm Mittlere INSEL

//Motor Wasser links
#define DIR_WL 25
#define PUL_WL 3  //PWM
#define ENA_WL 33

//Motor Wasser rechts
#define DIR_WR 27
#define PUL_WR 4  //PWM
#define ENA_WR 35

//Motor Gras links
#define DIR_GL 23
#define PUL_GL 2  //PWM
#define ENA_GL 31

//Motor Gras rechts
#define DIR_GR 29
#define PUL_GR 5  //PWM
#define ENA_GR 37

void setup() {

  pinMode(DIR_WL, OUTPUT);
  pinMode(PUL_WL, OUTPUT);
  pinMode(ENA_WL, OUTPUT);

  pinMode(DIR_GL, OUTPUT);
  pinMode(PUL_GL, OUTPUT);
  pinMode(ENA_GL, OUTPUT);

  pinMode(DIR_WR, OUTPUT);
  pinMode(PUL_WR, OUTPUT);
  pinMode(ENA_WR, OUTPUT);

  pinMode(DIR_GR, OUTPUT);
  pinMode(PUL_GR, OUTPUT);
  pinMode(ENA_GR, OUTPUT);
}

void loop() {
 
  delay(3000);
 
  Wasserauf();
  delay(500);
  Wasserwackeln();
  delay(250);
  Wasserwackeln();
  delay(250);
  Wasserwackeln();
  delay(1500);
  Wasserab();
  delay(1000);

  Grasauf();
  delay(400);
  Graswackeln();
  delay(250);
  Graswackeln();
  delay(250);
  Graswackeln();
  delay(1200);
  Grasab();

  delay(1000000000);
}

void Wasserauf() {
  digitalWrite(ENA_WL, LOW);
  digitalWrite(ENA_WR, LOW);

  // Motor links
  digitalWrite(DIR_WL, LOW);
  // Motoren rechts
  digitalWrite(DIR_WR, LOW);

  for (int i = 0; i <= 800; i++) {
    digitalWrite(PUL_WL, HIGH);
    digitalWrite(PUL_WR, HIGH);
    delayMicroseconds(1200);
    digitalWrite(PUL_WL, LOW);
    digitalWrite(PUL_WR, LOW);
    delayMicroseconds(1200);
  }

  digitalWrite(ENA_WL, HIGH);
  digitalWrite(ENA_WR, HIGH);
}

void Wasserab() {
  digitalWrite(ENA_WL, LOW);
  digitalWrite(ENA_WR, LOW);

  // Motoren links
  digitalWrite(DIR_WL, HIGH);

  // Motoren rechts
  digitalWrite(DIR_WR, HIGH);

  for (int i = 0; i <= 800; i++) {
    digitalWrite(PUL_WL, HIGH);
    digitalWrite(PUL_WR, HIGH);
    delayMicroseconds(1200);
    digitalWrite(PUL_WL, LOW);
    digitalWrite(PUL_WR, LOW);
    delayMicroseconds(1200);
  }

  digitalWrite(ENA_WL, HIGH);
  digitalWrite(ENA_WR, HIGH);
}

void Grasauf() {
  digitalWrite(ENA_GL, LOW);
  digitalWrite(ENA_GR, LOW);

  // Motoren links
  digitalWrite(DIR_GL, LOW);

  // Motoren rechts
  digitalWrite(DIR_GR, LOW);

  for (int i = 0; i <= 950; i++) {
    digitalWrite(PUL_GL, HIGH);
    digitalWrite(PUL_GR, HIGH);
    delayMicroseconds(1200);
    digitalWrite(PUL_GL, LOW);
    digitalWrite(PUL_GR, LOW);
    delayMicroseconds(1200);
  }

  digitalWrite(ENA_GL, HIGH);
  digitalWrite(ENA_GR, HIGH);
}

void Grasab() {
  digitalWrite(ENA_GL, LOW);
  digitalWrite(ENA_GR, LOW);

  // Motor links
  digitalWrite(DIR_GL, HIGH);

  // Motor rechts
  digitalWrite(DIR_GR, HIGH);

  for (int i = 0; i <= 950; i++) {
    digitalWrite(PUL_GL, HIGH);
    digitalWrite(PUL_GR, HIGH);
    delayMicroseconds(1200);
    digitalWrite(PUL_GL, LOW);
    digitalWrite(PUL_GR, LOW);
    delayMicroseconds(1200);
  }

  digitalWrite(ENA_GL, HIGH);
  digitalWrite(ENA_GR, HIGH);
}

void Wasserwackeln() {
  digitalWrite(ENA_WL, LOW);
  digitalWrite(ENA_WR, LOW);

  // Motor links
  digitalWrite(DIR_WL, HIGH);

  // Motor rechts
  digitalWrite(DIR_WR, LOW);

  for (int i = 0; i <= 250; i++) {
    digitalWrite(PUL_WL, HIGH);
    digitalWrite(PUL_WR, HIGH);
    delayMicroseconds(1200);
    digitalWrite(PUL_WL, LOW);
    digitalWrite(PUL_WR, LOW);
    delayMicroseconds(1200);
  }

  delay(300);
  // Motor links
  digitalWrite(DIR_WL, LOW);

  // Motor rechts
  digitalWrite(DIR_WR, HIGH);

   for (int i = 0; i <= 250; i++) {
    digitalWrite(PUL_WL, HIGH);
    digitalWrite(PUL_WR, HIGH);
    delayMicroseconds(1200);
    digitalWrite(PUL_WL, LOW);
    digitalWrite(PUL_WR, LOW);
    delayMicroseconds(1200);
  }
}
void Graswackeln() {

  digitalWrite(ENA_GL, LOW);
  digitalWrite(ENA_GR, LOW);

   // Motor links
  digitalWrite(DIR_GL, HIGH);

  // Motor rechts
  digitalWrite(DIR_GR, LOW);

 for (int i = 0; i <= 250; i++) {
    digitalWrite(PUL_GL, HIGH);
    digitalWrite(PUL_GR, HIGH);
    delayMicroseconds(1200);
    digitalWrite(PUL_GL, LOW);
    digitalWrite(PUL_GR, LOW);
    delayMicroseconds(1200);
  }

  delay(300);
  // Motor links
  digitalWrite(DIR_GL, LOW);

  // Motor rechts
  digitalWrite(DIR_GR, HIGH);

   for (int i = 0; i <= 250; i++) {
    digitalWrite(PUL_GL, HIGH);
    digitalWrite(PUL_GR, HIGH);
    delayMicroseconds(1200);
    digitalWrite(PUL_GL, LOW);
    digitalWrite(PUL_GR, LOW);
    delayMicroseconds(1200);
  }

  }








