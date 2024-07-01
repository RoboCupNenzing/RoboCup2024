// Testprogramm Schiff


//Motor A
#define PWMA 8   // Geschwindigkeit Motor A (ein Wert zwischen 0 und 255)
#define AIN1 9   // Richtung
#define AIN2 10  // Richtung

//Motor B
#define PWMB 13  // Geschwindigkeit Motor B (ein Wert zwischen 0 und 255)
#define BIN1 11  // Richtung
#define BIN2 12  // Richtung

//Motor C
#define PWMC 2  // Geschwindigkeit Motor C (ein Wert zwischen 0 und 255)
#define CIN1 3  // Richtung
#define CIN2 4  // Richtung

//Motor D
#define PWMD 7  // Geschwindigkeit Motor D (ein Wert zwischen 0 und 255)
#define DIN1 5  // Richtung
#define DIN2 6  // Richtung

//Feuer
#define fire 42

//Encoder-Pins für die Motoren A-D
#define ENCODER_PIN_A 18
#define ENCODER_PIN_B 19
#define ENCODER_PIN_C 20
#define ENCODER_PIN_D 21

// Variable für den Encoder-Wert
volatile long ENCODER_value_A = 0;
volatile long ENCODER_value_B = 0;
volatile long ENCODER_value_C = 0;
volatile long ENCODER_value_D = 0;


int LED1L = 30;
int LED2L = 32;
int LED3L = 34;
int LED4L = 36;

int LED1R = 22;
int LED2R = 24;
int LED3R = 26;
int LED4R = 28;


int Magnet = A14;


void setup() {

  // PinMode für Motor A
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  // PinMode für Motor B
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  // PinMode für Motor C
  pinMode(PWMC, OUTPUT);
  pinMode(CIN1, OUTPUT);
  pinMode(CIN2, OUTPUT);

  // PinMode für Motor D
  pinMode(PWMD, OUTPUT);
  pinMode(DIN1, OUTPUT);
  pinMode(DIN2, OUTPUT);

  // PinMode für Encoder.Pins
  pinMode(ENCODER_PIN_A, INPUT_PULLUP);
  pinMode(ENCODER_PIN_B, INPUT_PULLUP);
  pinMode(ENCODER_PIN_C, INPUT_PULLUP);
  pinMode(ENCODER_PIN_D, INPUT_PULLUP);

  // PinMode für Kanonen
  pinMode(LED1L, OUTPUT);
  pinMode(LED2L, OUTPUT);
  pinMode(LED3L, OUTPUT);
  pinMode(LED4L, OUTPUT);

  pinMode(LED1R, OUTPUT);
  pinMode(LED2R, OUTPUT);
  pinMode(LED3R, OUTPUT);
  pinMode(LED4R, OUTPUT);

  //Magnet
  pinMode(Magnet, OUTPUT);
  pinMode(A13, OUTPUT);
  analogWrite(A13, 0);

  //Feuer
  pinMode(fire, OUTPUT);
  digitalWrite(fire, LOW);
  

  //Interrupt-Pins für Encoder
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), ENCODER_A, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_B), ENCODER_B, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_C), ENCODER_C, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_D), ENCODER_D, RISING);

  //Serielle Schnittstelle
  Serial.begin(9600);
  Serial3.begin(9600);
  
  //Magnet einschalten
  Magnet_an();
  
  
}

void loop() {

  Serial.println("Start");
  ZigbeeAbfragen("1");
  Serial.println(1);
  
  
  ZigbeeAbfragen("2");
  Serial.println(2);
  
    delay(2000);
    //Schiff fährt los
    MOVE_forward_steps(200, 750);
    
    //Fahne runter
    Magnet_aus();
    delay(1000);
    
    //Schiff fährt weiter
    MOVE_left_steps(200, 150);
    MOVE_forward_steps(200, 900);
    MOVE_left_steps(200, 120);

    //Hai erkannt
    Kanonnenfeuern();
    delay(1000);

    //Schiff fährt weiter
    MOVE_right_steps(200, 120);
    MOVE_forward_steps(200, 700);

    //Gewitter
    digitalWrite(fire, LOW);
    delay(6000);
    digitalWrite(fire, HIGH);




  delay(100000000);

  /*
  Serial.print("A: ");
  Serial.println(ENCODER_value_A); 
  Serial.print("B: ");
  Serial.println(ENCODER_value_B); 
  Serial.print("C: ");
  Serial.println(ENCODER_value_C);
  Serial.print("D: "); 
  Serial.println(ENCODER_value_D); 
  CLEAR_VALUE();
  */

  delay(1000000000);
  // MOVE_forward(150, 2000);
  // STOP(1000);
  // TURN_right(200, 1200);
  // STOP(2000);
  // MOVE_backward(150, 2000);
  // STOP(1000);
  // TURN_left(200, 1200);
  // STOP(2000);
  // digitalWrite(fire, HIGH);
  // delay(2000);
  // digitalWrite(fire, LOW);
  // delay(5000);
}


void MOVE_forward_steps(int speed, int steps) {
  // Motoren 
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(CIN1, LOW);
  digitalWrite(CIN2, HIGH);
  digitalWrite(DIN1, LOW);
  digitalWrite(DIN2, HIGH);
  // Geschwindigkeit:
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
  analogWrite(PWMC, speed);
  analogWrite(PWMD, speed);
  while (ENCODER_value_A < steps) {
    // Serial.println(ENCODER_value_A);
  }
  STOP(1000);
  CLEAR_VALUE();
}


void MOVE_left_steps(int speed, int steps) {
  // Motoren 
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(CIN1, HIGH);
  digitalWrite(CIN2, LOW);
  digitalWrite(DIN1, LOW);
  digitalWrite(DIN2, HIGH);
  // Geschwindigkeit:
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
  analogWrite(PWMC, speed);
  analogWrite(PWMD, speed);
  while (ENCODER_value_A < steps) {
    // Serial.println(ENCODER_value_A);
  }
  STOP(1000);
  CLEAR_VALUE();
}


void MOVE_right_steps(int speed, int steps) {
  // Motor C und D
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(CIN1, LOW);
  digitalWrite(CIN2, HIGH);
  digitalWrite(DIN1, HIGH);
  digitalWrite(DIN2, LOW);
  // Geschwindigkeit:
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
  analogWrite(PWMC, speed);
  analogWrite(PWMD, speed);
  while (ENCODER_value_C < steps) {
    // Serial.println(ENCODER_value_A);
  }
  STOP(1000);
  CLEAR_VALUE();
}

/*
void MOVE_forward(int speed, int time) {
  // Motor A und B
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(CIN1, LOW);
  digitalWrite(CIN2, HIGH);
  digitalWrite(DIN1, LOW);
  digitalWrite(DIN2, HIGH);
  // Geschwindigkeit:
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
  analogWrite(PWMC, speed);
  analogWrite(PWMD, speed);

  delay(time);
}

void MOVE_backward(int speed, int time) {
  // Motor A und B
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(CIN1, HIGH);
  digitalWrite(CIN2, LOW);
  digitalWrite(DIN1, HIGH);
  digitalWrite(DIN2, LOW);
  // Geschwindigkeit:
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
  analogWrite(PWMC, speed);
  analogWrite(PWMD, speed);

  delay(time);
}

void TURN_left(int speed, int time) {
  // Motor A und B
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(CIN1, HIGH);
  digitalWrite(CIN2, LOW);
  digitalWrite(DIN1, LOW);
  digitalWrite(DIN2, HIGH);
  // Geschwindigkeit:
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
  analogWrite(PWMC, speed);
  analogWrite(PWMD, speed);

  delay(time);
}

void TURN_right(int speed, int time) {
  // Motor A und B
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(CIN1, LOW);
  digitalWrite(CIN2, HIGH);
  digitalWrite(DIN1, HIGH);
  digitalWrite(DIN2, LOW);
  // Geschwindigkeit:
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
  analogWrite(PWMC, speed);
  analogWrite(PWMD, speed);

  delay(time);
}

*/

void STOP(int time) {
  // Motoren ABCD
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(CIN1, LOW);
  digitalWrite(CIN2, LOW);
  digitalWrite(DIN1, LOW);
  digitalWrite(DIN2, LOW);
  // Geschwindigkeit:
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  analogWrite(PWMC, 0);
  analogWrite(PWMD, 0);

  delay(time);
}

void ENCODER_A() {

  ENCODER_value_A++;
}

void ENCODER_B() {

  ENCODER_value_B++;
}

void ENCODER_C() {

  ENCODER_value_C++;
}

void ENCODER_D() {

  ENCODER_value_D++;
}

void CLEAR_VALUE() {

  ENCODER_value_A = 0;
  ENCODER_value_B = 0;
  ENCODER_value_C = 0;
  ENCODER_value_D = 0;
}

void Kanonnenfeuern()
{
digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, HIGH);
digitalWrite(LED2R, LOW);
delay(130);
digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, HIGH);
digitalWrite(LED3R, LOW);
delay(80);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, LOW);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(150);

digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, LOW);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED2R, HIGH);
digitalWrite(LED4R, HIGH);
digitalWrite(LED3R, LOW);
delay(90);
digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, LOW);
delay(170);
digitalWrite(LED1R, LOW);
digitalWrite(LED3R, LOW);
digitalWrite(LED4R, LOW);
delay(80);

digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, HIGH);
digitalWrite(LED2R, LOW);
delay(130);
digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, HIGH);
digitalWrite(LED3R, LOW);
delay(80);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, LOW);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(150);

digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, LOW);
delay(60);
digitalWrite(LED1R, LOW);
digitalWrite(LED2R, HIGH);
digitalWrite(LED4R, HIGH);
digitalWrite(LED3R, LOW);
delay(120);
digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, LOW);
delay(70);
digitalWrite(LED1R, LOW);
digitalWrite(LED3R, LOW);
digitalWrite(LED4R, LOW);
delay(130);

digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, HIGH);
digitalWrite(LED2R, LOW);
delay(130);
digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, HIGH);
digitalWrite(LED3R, LOW);
delay(80);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, LOW);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(150);

digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, LOW);
delay(120);
digitalWrite(LED1R, LOW);
digitalWrite(LED2R, HIGH);
digitalWrite(LED4R, HIGH);
digitalWrite(LED3R, LOW);
delay(50);
digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, LOW);
delay(80);
digitalWrite(LED1R, LOW);
digitalWrite(LED3R, LOW);
digitalWrite(LED4R, LOW);
delay(170);

digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, HIGH);
digitalWrite(LED2R, LOW);
delay(130);
digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, HIGH);
digitalWrite(LED3R, LOW);
delay(80);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, LOW);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(150);

digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, LOW);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED2R, HIGH);
digitalWrite(LED4R, HIGH);
digitalWrite(LED3R, LOW);
delay(90);
digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, LOW);
delay(170);
digitalWrite(LED1R, LOW);
digitalWrite(LED3R, LOW);
digitalWrite(LED4R, LOW);
delay(80);

digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, HIGH);
digitalWrite(LED2R, LOW);
delay(130);
digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, HIGH);
digitalWrite(LED3R, LOW);
delay(80);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, LOW);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(150);

digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, LOW);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED2R, HIGH);
digitalWrite(LED4R, HIGH);
digitalWrite(LED3R, LOW);
delay(90);
digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, LOW);
delay(170);
digitalWrite(LED1R, LOW);
digitalWrite(LED3R, LOW);
digitalWrite(LED4R, LOW);
delay(80);

digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, HIGH);
digitalWrite(LED2R, LOW);
delay(130);
digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, HIGH);
digitalWrite(LED3R, LOW);
delay(80);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, LOW);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(150);

digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, LOW);
delay(60);
digitalWrite(LED1R, LOW);
digitalWrite(LED2R, HIGH);
digitalWrite(LED4R, HIGH);
digitalWrite(LED3R, LOW);
delay(120);
digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, LOW);
delay(70);
digitalWrite(LED1R, LOW);
digitalWrite(LED3R, LOW);
digitalWrite(LED4R, LOW);
delay(130);

digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, HIGH);
digitalWrite(LED2R, LOW);
delay(130);
digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, HIGH);
digitalWrite(LED3R, LOW);
delay(80);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, LOW);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(150);

digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, LOW);
delay(120);
digitalWrite(LED1R, LOW);
digitalWrite(LED2R, HIGH);
digitalWrite(LED4R, HIGH);
digitalWrite(LED3R, LOW);
delay(50);
digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, LOW);
delay(80);
digitalWrite(LED1R, LOW);
digitalWrite(LED3R, LOW);
digitalWrite(LED4R, LOW);
delay(170);

digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, HIGH);
digitalWrite(LED2R, LOW);
delay(130);
digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, HIGH);
digitalWrite(LED3R, LOW);
delay(80);
digitalWrite(LED1R, LOW);
digitalWrite(LED4R, LOW);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, HIGH);
delay(150);

digitalWrite(LED1R, HIGH);
digitalWrite(LED2R, LOW);
delay(100);
digitalWrite(LED1R, LOW);
digitalWrite(LED2R, HIGH);
digitalWrite(LED4R, HIGH);
digitalWrite(LED3R, LOW);
delay(90);
digitalWrite(LED1R, HIGH);
digitalWrite(LED3R, HIGH);
digitalWrite(LED2R, LOW);
delay(170);
digitalWrite(LED1R, LOW);
digitalWrite(LED3R, LOW);
digitalWrite(LED4R, LOW);
delay(80);

}

void Magnet_an()
{
digitalWrite(Magnet, HIGH);

}

void Magnet_aus()
{
  digitalWrite(Magnet, LOW);
}


void ZigbeeAbfragen(String Zahl)
{
  while (1)
  {
    String readString;
    String Daten;
    while (Serial3.available())
    {
      delay(1);
      if (Serial3.available() > 0)
      {
        char c = Serial3.read();
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