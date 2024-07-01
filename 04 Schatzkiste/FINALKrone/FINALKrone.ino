//Testprogramm Schatzkiste Krone

int red1 = 13;
int green1 = 12;
int blue1 = 11;
int red2 = 10;
int green2 = 9;
int blue2 = 8;
int red3 = 7;
int green3 = 6;
int blue3 = 5;
int red4 = 4;
int green4 = 3;
int blue4 = 2;
int red5 = 44;
int green5 = 45;
int blue5 = 46;

int pause = 5;


void setup() {


  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(blue3, OUTPUT);
  pinMode(red4, OUTPUT);
  pinMode(green4, OUTPUT);
  pinMode(blue4, OUTPUT);
  pinMode(red5, OUTPUT);
  pinMode(green5, OUTPUT);
  pinMode(blue5, OUTPUT);


  aus();
}

void loop() {

  Farbenwechsel();
  Uebergang();
  Farbverlauf();
}

void blinken() {

  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(red4, HIGH);
  digitalWrite(red5, HIGH);

  delay(200);

  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(red3, LOW);
  digitalWrite(red4, LOW);
  digitalWrite(red5, LOW);

  delay(200);

  digitalWrite(green1, HIGH);
  digitalWrite(green2, HIGH);
  digitalWrite(green3, HIGH);
  digitalWrite(green4, HIGH);
  digitalWrite(green5, HIGH);

  delay(200);

  digitalWrite(green1, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(green4, LOW);
  digitalWrite(green5, LOW);

  delay(200);

  digitalWrite(blue1, HIGH);
  digitalWrite(blue2, HIGH);
  digitalWrite(blue3, HIGH);
  digitalWrite(blue4, HIGH);
  digitalWrite(blue5, HIGH);

  delay(200);

  digitalWrite(blue1, LOW);
  digitalWrite(blue2, LOW);
  digitalWrite(blue3, LOW);
  digitalWrite(blue4, LOW);
  digitalWrite(blue5, LOW);

  delay(200);
}

void Farbenwechsel() {

  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, i);
    analogWrite(red2, i);
    analogWrite(red3, i);
    analogWrite(red4, i);
    analogWrite(red5, i);
    analogWrite(green1, 0);
    analogWrite(green2, 0);
    analogWrite(green3, 0);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }

  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 0);
    analogWrite(green2, 0);
    analogWrite(green3, 0);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, i);
    analogWrite(blue2, i);
    analogWrite(blue3, i);
    analogWrite(blue4, i);
    analogWrite(blue5, i);
    delay(pause);
  }

  for (int i = 255; i > 0; i=i-3) {
    analogWrite(red1, i);
    analogWrite(red2, i);
    analogWrite(red3, i);
    analogWrite(red4, i);
    analogWrite(red5, i);
    analogWrite(green1, 0);
    analogWrite(green2, 0);
    analogWrite(green3, 0);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, 255);
    analogWrite(blue2, 255);
    analogWrite(blue3, 255);
    analogWrite(blue4, 255);
    analogWrite(blue5, 255);
    delay(pause);
  }

  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 0);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, i);
    analogWrite(green2, i);
    analogWrite(green3, i);
    analogWrite(green4, i);
    analogWrite(green5, i);
    analogWrite(blue1, 255);
    analogWrite(blue2, 255);
    analogWrite(blue3, 255);
    analogWrite(blue4, 255);
    analogWrite(blue5, 255);
    delay(pause);
  }

  for (int i = 255; i > 0; i=i-3) {
    analogWrite(red1, 0);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, i);
    analogWrite(blue2, i);
    analogWrite(blue3, i);
    analogWrite(blue4, i);
    analogWrite(blue5, i);
    delay(pause);
  }

  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, i);
    analogWrite(red2, i);
    analogWrite(red3, i);
    analogWrite(red4, i);
    analogWrite(red5, i);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }



  for (int i = 255; i > 0; i=i-3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, i);
    analogWrite(green2, i);
    analogWrite(green3, i);
    analogWrite(green4, i);
    analogWrite(green5, i);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }

  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, i);
    analogWrite(green2, i);
    analogWrite(green3, i);
    analogWrite(green4, i);
    analogWrite(green5, i);
    analogWrite(blue1, i);
    analogWrite(blue2, i);
    analogWrite(blue3, i);
    analogWrite(blue4, i);
    analogWrite(blue5, i);
    delay(pause);
  }
  for (int i = 255; i > 0; i=i-3) {
    analogWrite(red1, i);
    analogWrite(red2, i);
    analogWrite(red3, i);
    analogWrite(red4, i);
    analogWrite(red5, i);
    analogWrite(green1, i);
    analogWrite(green2, i);
    analogWrite(green3, i);
    analogWrite(green4, i);
    analogWrite(green5, i);
    analogWrite(blue1, i);
    analogWrite(blue2, i);
    analogWrite(blue3, i);
    analogWrite(blue4, i);
    analogWrite(blue5, i);
    delay(pause);
  }
}

void aus() {
  //alle LEDs ausschalten
  digitalWrite(red1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(blue1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(blue2, LOW);
  digitalWrite(red3, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(blue3, LOW);
  digitalWrite(red4, LOW);
  digitalWrite(green4, LOW);
  digitalWrite(blue4, LOW);
  digitalWrite(red5, LOW);
  digitalWrite(green5, LOW);
  digitalWrite(blue5, LOW);
}

void Uebergang() {
  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, i);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, 0);
    analogWrite(green2, 0);
    analogWrite(green3, 0);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }

  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, i);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, 0);
    analogWrite(green2, 0);
    analogWrite(green3, 0);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, i);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, i);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, i);
    analogWrite(green2, 0);
    analogWrite(green3, 0);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, 255);
    analogWrite(blue2, i);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }

  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, i);
    analogWrite(red5, 0);
    analogWrite(green1, 255);
    analogWrite(green2, i);
    analogWrite(green3, 0);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, 255);
    analogWrite(blue2, 255);
    analogWrite(blue3, i);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }

  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, i);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, i);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, 255);
    analogWrite(blue2, 255);
    analogWrite(blue3, 255);
    analogWrite(blue4, i);
    analogWrite(blue5, 0);
    delay(pause);
  }

  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, i);
    analogWrite(green5, 0);
    analogWrite(blue1, 255);
    analogWrite(blue2, 255);
    analogWrite(blue3, 255);
    analogWrite(blue4, 255);
    analogWrite(blue5, i);
    delay(pause);
  }
  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, i);
    analogWrite(blue1, 255);
    analogWrite(blue2, 255);
    analogWrite(blue3, 255);
    analogWrite(blue4, 255);
    analogWrite(blue5, 255);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, i);
    analogWrite(blue2, 255);
    analogWrite(blue3, 255);
    analogWrite(blue4, 255);
    analogWrite(blue5, 255);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, i);
    analogWrite(blue3, 255);
    analogWrite(blue4, 255);
    analogWrite(blue5, 255);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, i);
    analogWrite(blue4, 255);
    analogWrite(blue5, 255);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, i);
    analogWrite(blue5, 255);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, i);
    delay(pause);
  }
  delay(1000);

  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, i);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 0);
    analogWrite(red2, i);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 0);
    analogWrite(red2, 0);
    analogWrite(red3, i);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 0);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, i);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 0);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, i);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  delay(1000);
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 0);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, i);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 0);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, 0);
    analogWrite(green2, i);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 0);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, 0);
    analogWrite(green2, 0);
    analogWrite(green3, i);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 0);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, 0);
    analogWrite(green2, 0);
    analogWrite(green3, 0);
    analogWrite(green4, i);
    analogWrite(green5, 255);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 225; i > 0; i=i-3) {
    analogWrite(red1, 0);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, 0);
    analogWrite(green2, 0);
    analogWrite(green3, 0);
    analogWrite(green4, 0);
    analogWrite(green5, i);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
}
void Farbverlauf() {
  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, i);
    analogWrite(red2, 0);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, 0);
    analogWrite(green2, 0);
    analogWrite(green3, 0);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, i);
    analogWrite(red3, 0);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, i);
    analogWrite(green2, 0);
    analogWrite(green3, 0);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, 0);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, i);
    analogWrite(red4, 0);
    analogWrite(red5, 0);
    analogWrite(green1, 255);
    analogWrite(green2, i);
    analogWrite(green3, 0);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, i);
    analogWrite(blue2, 0);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, i);
    analogWrite(red5, 0);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, i);
    analogWrite(green4, 0);
    analogWrite(green5, 0);
    analogWrite(blue1, 255);
    analogWrite(blue2, i);
    analogWrite(blue3, 0);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, i);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, i);
    analogWrite(green5, 0);
    analogWrite(blue1, 255);
    analogWrite(blue2, 255);
    analogWrite(blue3, i);
    analogWrite(blue4, 0);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, i);
    analogWrite(blue1, 255);
    analogWrite(blue2, 255);
    analogWrite(blue3, 255);
    analogWrite(blue4, i);
    analogWrite(blue5, 0);
    delay(pause);
  }
  for (int i = 0; i < 255; i=i+3) {
    analogWrite(red1, 255);
    analogWrite(red2, 255);
    analogWrite(red3, 255);
    analogWrite(red4, 255);
    analogWrite(red5, 255);
    analogWrite(green1, 255);
    analogWrite(green2, 255);
    analogWrite(green3, 255);
    analogWrite(green4, 255);
    analogWrite(green5, 255);
    analogWrite(blue1, 255);
    analogWrite(blue2, 255);
    analogWrite(blue3, 255);
    analogWrite(blue4, 255);
    analogWrite(blue5, i);
    delay(pause);
  }
  delay(1000);
}