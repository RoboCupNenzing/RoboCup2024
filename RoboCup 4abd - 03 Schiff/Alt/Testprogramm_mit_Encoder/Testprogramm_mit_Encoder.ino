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
#define fire 24

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

  //Feuer
  pinMode(fire, OUTPUT);

  //Interrupt-Pins für Encoder
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), ENCODER_A, RISING); 
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_B), ENCODER_B, RISING); 
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_C), ENCODER_C, RISING); 
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_D), ENCODER_D, RISING); 

  //Serielle Schnittstelle für Debugging
  Serial.begin(9600);
}

void loop() {

  delay(3000);


  MOVE_steps(200, 2000);
  Serial.print("A: ");
  Serial.println(ENCODER_value_A); 
  Serial.print("B: ");
  Serial.println(ENCODER_value_B); 
  Serial.print("C: ");
  Serial.println(ENCODER_value_C);
  Serial.print("D: "); 
  Serial.println(ENCODER_value_D); 
  CLEAR_VALUE();

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


void MOVE_steps(int speed, int steps) {
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
  while(ENCODER_value_A<2000)
  {

  }
  STOP(1000);
}


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

void STOP(int time) {
  // Motor A und B aus
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