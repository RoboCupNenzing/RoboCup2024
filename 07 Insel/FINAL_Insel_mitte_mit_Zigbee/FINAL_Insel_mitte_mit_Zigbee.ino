//FINAL Mittlere INSEL mit Zigbee

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

  //Serielle Kommunikation
  Serial.begin(9600);
  Serial1.begin(9600);

  //Motoren
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

  //Motoren aktivieren
  digitalWrite(ENA_WL, HIGH);
  digitalWrite(ENA_WR, HIGH);
  digitalWrite(ENA_GL, HIGH);
  digitalWrite(ENA_GR, HIGH);
}

void loop() {

  // ------------- Szene 1 -------------
  ZigbeeAbfragen("1");
  Serial.println(1);

  Grasauf();

  // ------------- Szene 2 -------------
  ZigbeeAbfragen("2");
  Serial.println(2);

  Grasab();
  Wasserauf();

  // ------------- Szene 3 -------------
  ZigbeeAbfragen("3");
  Serial.println(3);

  // ------------- Szene 4 -------------
  ZigbeeAbfragen("4");
  Serial.println(4);

  Wasserab();
  Grasauf();

  // ------------- RESET -------------
  ZigbeeAbfragen("5");
  Serial.println(5);


  Grasab();
}

void Wasserauf() {

  // Motoren aktivieren
  digitalWrite(ENA_WL, LOW);
  digitalWrite(ENA_WR, LOW);

  // Motor links Richtung einstellen
  digitalWrite(DIR_WL, LOW);
  // Motoren rechts Richtung einstellen
  digitalWrite(DIR_WR, LOW);

  // 900 Steps 
  for (int i = 0; i <= 900; i++) {
    digitalWrite(PUL_WL, HIGH);
    digitalWrite(PUL_WR, HIGH);
    delayMicroseconds(1200);
    digitalWrite(PUL_WL, LOW);
    digitalWrite(PUL_WR, LOW);
    delayMicroseconds(1200);
  }

  //Motoren deaktivieren
  digitalWrite(ENA_WL, HIGH);
  digitalWrite(ENA_WR, HIGH);
}

void Wasserab() {
  // Motoren aktivieren
  digitalWrite(ENA_WL, LOW);
  digitalWrite(ENA_WR, LOW);

  // Motoren links Richtung einstellen
  digitalWrite(DIR_WL, HIGH);

  // Motoren rechts Richtung einstellen
  digitalWrite(DIR_WR, HIGH);

  // 900 Steps 
  for (int i = 0; i <= 900; i++) {
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
   // Motoren aktivieren
  digitalWrite(ENA_GL, LOW);
  digitalWrite(ENA_GR, LOW);

  // Motoren links Richtung einstellen
  digitalWrite(DIR_GL, LOW);

  // Motoren rechts Richtung einstellen
  digitalWrite(DIR_GR, LOW);

  // 950 Steps 
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
   // Motoren aktivieren
  digitalWrite(ENA_GL, LOW);
  digitalWrite(ENA_GR, LOW);

  // Motor links Richtung einstellen
  digitalWrite(DIR_GL, HIGH);

  // Motor rechts Richtung einstellen
  digitalWrite(DIR_GR, HIGH);

  // 950 Steps 
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

// Auf eine Zahl von ZigBee warten
void ZigbeeAbfragen(String Zahl) {
  while (1) {
    String readString;
    String Daten;
    while (Serial1.available()) {
      delay(1);
      if (Serial1.available() > 0) {
        char c = Serial1.read();
        if (isControl(c)) {
          break;
        }
        readString += c;
      }
    }
    Daten = readString;

    // Falls die Zahl empfangen wird wird Schleife verlassen
    if (Daten == Zahl) {
      break;
    }
  }
}
