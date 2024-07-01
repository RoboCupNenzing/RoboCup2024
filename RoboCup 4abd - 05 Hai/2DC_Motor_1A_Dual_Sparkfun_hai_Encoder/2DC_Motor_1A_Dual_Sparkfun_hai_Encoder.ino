/* Der Motor ist mit A01 und A02
   des Motor Drivers verbunden */

#define STBY 5  /* Pin mit dem die Verbindung zum Motor hergestellt bzw. unterbrochen wird */

//Motorsteuerung:
#define PWMA 4  // Pin für die Geschwindigkeit (Wert: 0 - 255)
#define AIN1 17  //(gruen) Pin1 für die Richtung (Vorwärts: HIGH, Rückwärts: LOW)
#define AIN2 16  //(gelb) Pin2 für die Richtung (Vorwärts: LOW, RÜckwärts: HIGH)

#define PWMB 0  // Pin für die Geschwindigkeit (Wert: 0 - 255)
#define BIN1 18  // Pin1 für die Richtung (Vorwärts: HIGH, Rückwärts: LOW)
#define BIN2 19  // Pin2 für die Richtung (Vorwärts: LOW, RÜckwärts: HIGH)

//Encoder
#define ENCODER_Pin_A 2
#define ENCODER_Pin_B 15
volatile long ENCODER_value_A = 0;
volatile long ENCODER_value_B = 0;


void setup()

{
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  //Motoren mit Strom versorgen
  digitalWrite (STBY, HIGH);

  //ENCODER
  pinMode (ENCODER_Pin_A, INPUT_PULLUP);
  pinMode (ENCODER_Pin_B, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCODER_Pin_A), ENCODER_A, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCODER_Pin_B), ENCODER_B, RISING);
  Serial.begin(9600);
}

void loop()
{

  MOVE_right(150, 500);
  Serial.println("Right");
  delay(5000);
  MOVE_left(150, 500);
  Serial.println("Left");
  delay(5000);

}

void MOVE_forward(int sp, int steps)
{

  digitalWrite (AIN1, HIGH);
  digitalWrite (AIN2, LOW);
  digitalWrite (BIN1, HIGH);
  digitalWrite (BIN2, LOW);

  analogWrite (PWMA, sp);
  analogWrite (PWMB, sp);

  while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps))
  {

  }

  Serial.print("Value A: ");
  Serial.println(ENCODER_value_A);
  Serial.print("Value B: ");
  Serial.println(ENCODER_value_B);

  STOP();
  CLEAR_VALUE();

}

void STOP()
{

  digitalWrite (AIN1, LOW);
  digitalWrite (AIN2, LOW);
  digitalWrite (BIN1, LOW);
  digitalWrite (BIN2, LOW);

  analogWrite (PWMA, 0);
  analogWrite (PWMB, 0);

}

void MOVE_backward(int sp, int steps)
{

  digitalWrite (AIN1, LOW);
  digitalWrite (AIN2, HIGH);
  digitalWrite (BIN1, LOW);
  digitalWrite (BIN2, HIGH);

  analogWrite (PWMA, sp);
  analogWrite (PWMB, sp);

  while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps))
  {

  }

  Serial.print("Value A: ");
  Serial.println(ENCODER_value_A);
  Serial.print("Value B: ");
  Serial.println(ENCODER_value_B);

  STOP();
  CLEAR_VALUE();
}

void TURN_right(int sp, int steps)
{

  digitalWrite (AIN1, HIGH);
  digitalWrite (AIN2, LOW);
  digitalWrite (BIN1, LOW);
  digitalWrite (BIN2, HIGH);

  analogWrite (PWMA, sp);
  analogWrite (PWMB, sp);

  Serial.print("Value A: ");
  Serial.println(ENCODER_value_A);
  Serial.print("Value B: ");
  Serial.println(ENCODER_value_B);

  while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps))
  {
  }
  STOP();
  CLEAR_VALUE();
}


void TURN_left(int sp, int steps)
{

  digitalWrite (AIN1, LOW);
  digitalWrite (AIN2, HIGH);
  digitalWrite (BIN1, HIGH);
  digitalWrite (BIN2, LOW);

  analogWrite (PWMA, sp);
  analogWrite (PWMB, sp);


  while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps))
  {

  }

  STOP();
  CLEAR_VALUE();
}


void MOVE_left(int sp, int steps)
{

  digitalWrite (AIN1, HIGH);
  digitalWrite (AIN2, LOW);
  digitalWrite (BIN1, HIGH);
  digitalWrite (BIN2, LOW);

  int sp_left = sp * 0.7;
  int sp_right = sp;

  analogWrite (PWMA, sp_left);
  analogWrite (PWMB, sp_right);

  while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps))
  {

  }

  Serial.print("Value A: ");
  Serial.println(ENCODER_value_A);
  Serial.print("Value B: ");
  Serial.println(ENCODER_value_B);

  STOP();
  CLEAR_VALUE();

}


void MOVE_right(int sp, int steps)
{

  digitalWrite (AIN1, HIGH);
  digitalWrite (AIN2, LOW);
  digitalWrite (BIN1, HIGH);
  digitalWrite (BIN2, LOW);

  int sp_left = sp;
  int sp_right = sp * 0.7;

  analogWrite (PWMA, sp_left);
  analogWrite (PWMB, sp_right);

  while ((ENCODER_value_A < steps) || (ENCODER_value_B < steps))
  {

  }

  Serial.print("Value A: ");
  Serial.println(ENCODER_value_A);
  Serial.print("Value B: ");
  Serial.println(ENCODER_value_B);

  STOP();
  CLEAR_VALUE();

}


void ENCODER_A()
{
  ENCODER_value_A ++;

}

void ENCODER_B()
{
  ENCODER_value_B ++;

}

void CLEAR_VALUE()
{
  ENCODER_value_A = 0;
  ENCODER_value_B = 0;
}
