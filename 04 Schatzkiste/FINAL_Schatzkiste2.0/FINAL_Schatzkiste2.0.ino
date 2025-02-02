// PIN für LED-Streifen
#define Beleuchtung 45

// IN1 und IN 2: Motor rechts
#define IN1 53
#define IN2 51

// IN1 und IN 2: Motor links
#define IN3 49
#define IN4 47

//PINs für Ultraschall-Sensor
#define Trigger 41
#define Echo 39

long Entfernung = 0;


void setup() {
  
  // Serielle Kommunikation mit Computer
  Serial.begin(9600);

  //PinMode für alle Pins
  pinMode(Beleuchtung, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);

  // Alle Motoren ausschalten
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {

  delay(50);
  // Sender kurz ausschalten um Störungen des Signal zu vermeiden
  digitalWrite(Trigger, LOW);
  delay(5);

  // Signal für 10 Micrsekunden senden, danach wieder ausschalten
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  // pulseIn -> Zeit messen, bis das Signal zurückkommt
  long Zeit = pulseIn(Echo, HIGH);

  // Entfernung in cm berechnen
  // Zeit/2 -> nur eine Strecke
  Entfernung = (Zeit / 2) * 0.03432;
  delay(100);
  Serial.println(Entfernung);
  
  if (Entfernung < 30) {
    delay(15000);
    digitalWrite(Beleuchtung, HIGH);
    Deckelauf();

    Beleuchtungblinken(60);
    
    digitalWrite(Beleuchtung, HIGH);
    Deckelzu();
  
    digitalWrite(Beleuchtung, LOW);
  }
  
}

void Deckelauf() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(8000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Beleuchtungblinken(int Anzahl) {
 for(int i = 0; i<Anzahl; i++)
 {
  digitalWrite(Beleuchtung, HIGH);
  delay(200);
  digitalWrite(Beleuchtung, LOW);
  delay(200);
 }

}

void Deckelzu() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(8000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


