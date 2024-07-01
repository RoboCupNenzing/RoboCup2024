int weiss1 = 5;
int weiss2 = 6;
int weiss3 = 7;
int weiss4 = 8;
int weiss5 = 9;
int weiss6 = 10;
int weiss7 = 11;
int weiss8 = 12;
int weiss9 = 13;

int pause = 500;
int pause1 = 1000;

void setup() {
pinMode (weiss1, OUTPUT);
pinMode (weiss2, OUTPUT);
pinMode (weiss3, OUTPUT);
pinMode (weiss4, OUTPUT);
pinMode (weiss5, OUTPUT);
pinMode (weiss6, OUTPUT);
pinMode (weiss7, OUTPUT);
pinMode (weiss8, OUTPUT);
pinMode (weiss9, OUTPUT);



}

void loop() {
  //alle nacheinander ein
digitalWrite(weiss1, HIGH);
delay(pause);
digitalWrite(weiss2, HIGH);
delay(pause);
digitalWrite(weiss3, HIGH);
delay(pause);
digitalWrite(weiss4, HIGH);
delay(pause);
digitalWrite(weiss5, HIGH);
delay(pause);
digitalWrite(weiss6, HIGH);
delay(pause);
digitalWrite(weiss7, HIGH);
delay(pause);
digitalWrite(weiss8, HIGH);
delay(pause);
digitalWrite(weiss9, HIGH);
delay(pause1);
//alle nacheinander aus
digitalWrite(weiss1, LOW);
delay(pause);
digitalWrite(weiss2, LOW);
delay(pause);
digitalWrite(weiss3, LOW);
delay(pause);
digitalWrite(weiss4, LOW);
delay(pause);
digitalWrite(weiss5, LOW);
delay(pause);
digitalWrite(weiss6, LOW);
delay(pause);
digitalWrite(weiss7, LOW);
delay(pause);
digitalWrite(weiss8, LOW);
delay(pause);
digitalWrite(weiss9, LOW);
delay(pause1);
//immer das zweite ein und aus
digitalWrite (weiss1, HIGH);
delay (pause);
digitalWrite (weiss3, HIGH);
delay (pause);
digitalWrite (weiss5, HIGH);
delay (pause);
digitalWrite (weiss7, HIGH);
delay (pause);
digitalWrite (weiss9, HIGH);
delay(pause1);

digitalWrite (weiss2, HIGH);
digitalWrite (weiss1, LOW);
delay (pause);
digitalWrite (weiss4, HIGH);
digitalWrite (weiss3, LOW);
delay (pause);
digitalWrite (weiss6, HIGH);
digitalWrite (weiss5, LOW);
delay (pause);
digitalWrite (weiss8, HIGH);
digitalWrite (weiss7, LOW);
delay (pause);
digitalWrite (weiss9, LOW);
delay(pause1);










}
