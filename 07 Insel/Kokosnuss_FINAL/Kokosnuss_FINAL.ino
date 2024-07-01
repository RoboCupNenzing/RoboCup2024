// Programm Kokosnuss

#define IN1 6
#define IN2 7
#define Laser 4

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(Laser, INPUT_PULLUP);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  Serial.begin(9600);
}

void loop() {

  delay(1000);
  Serial.println(digitalRead(4));

  if (digitalRead(4) == 1) 
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
}
