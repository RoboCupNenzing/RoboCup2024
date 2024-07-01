
int LED1L =30;
int LED2L =32;
int LED3L =34;
int LED4L =36;

int LED1R =22;
int LED2R =24;
int LED3R =26;
int LED4R =28;

void setup() {

pinMode(LED1L, OUTPUT);
pinMode(LED2L, OUTPUT);
pinMode(LED3L, OUTPUT);
pinMode(LED4L, OUTPUT);

pinMode(LED1R, OUTPUT);
pinMode(LED2R, OUTPUT);
pinMode(LED3R, OUTPUT);
pinMode(LED4R, OUTPUT);
}

void loop() {

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


