//Testprogramm Schatzkiste
//Perlen und Kelch

//LEDs Perlen
#define weiss1 39
#define weiss2 43
#define weiss3 41
#define weiss4 33
#define weiss5 35
#define weiss6 37
#define weiss7 51
#define weiss8 49
#define weiss9 47
#define weiss10 45
#define weiss11 53 
#define weiss12 34
#define weiss13 32
#define weiss14 36
#define weiss15 28
#define weiss16 30
#define weiss17 46
#define weiss18 42
#define weiss19 38
#define weiss20 44
#define weiss21 40



//LEDs Kelch
#define gruen1 13
#define gruen2 11
#define gruen3 9
#define gruen4 7

#define rot1 12
#define rot2 10
#define rot3 6
#define rot4 5

#define pause1 100
#define pause2 100

int Animation;

void setup() {

//LEDs Perlen
  pinMode(weiss1, OUTPUT);
  pinMode(weiss2, OUTPUT);
  pinMode(weiss3, OUTPUT);
  pinMode(weiss4, OUTPUT);
  pinMode(weiss5, OUTPUT);
  pinMode(weiss6, OUTPUT); 
  pinMode(weiss7, OUTPUT);
  pinMode(weiss8, OUTPUT);
  pinMode(weiss9, OUTPUT);
  pinMode(weiss10, OUTPUT);
  pinMode(weiss11, OUTPUT);
  pinMode(weiss12, OUTPUT);
  pinMode(weiss13, OUTPUT);
  pinMode(weiss14, OUTPUT);
  pinMode(weiss15, OUTPUT);
  pinMode(weiss16, OUTPUT);
  pinMode(weiss17, OUTPUT);
  pinMode(weiss18, OUTPUT);
  pinMode(weiss19, OUTPUT);
  pinMode(weiss20, OUTPUT);
  pinMode(weiss21, OUTPUT);


//LEDs Kelch
  pinMode (gruen1, OUTPUT);
  pinMode (gruen2, OUTPUT);
  pinMode (gruen3, OUTPUT);
  pinMode (gruen4, OUTPUT);
  pinMode (rot1, OUTPUT);
  pinMode (rot2, OUTPUT);
  pinMode (rot3, OUTPUT);
  pinMode (rot4, OUTPUT);



}

void loop() {
 
 PERLENein(75);
 KELCHein(150);
 KELCHaus();
 ANIMATION(50);
 KELCHblinken(300);
 KELCHaus();
 PERLENaus();
 ANIMATION(100);
 KELCHein(150); 
 ANIMATIONzwei(700);
 KELCHdimmen();
 KELCHdimmen();
 KELCHaus();
 PERLENaus();



}

void PERLENein(int pause)
{
  digitalWrite (weiss1, HIGH);
  delay(pause);
  digitalWrite (weiss2, HIGH);
  delay(pause);
  digitalWrite (weiss3, HIGH);
  delay(pause);
  digitalWrite (weiss4, HIGH);
  delay(pause);
  digitalWrite (weiss5, HIGH);
  delay(pause);
  digitalWrite (weiss6, HIGH);
  delay(pause);
  digitalWrite (weiss7, HIGH);
  delay(pause);
  digitalWrite (weiss8, HIGH);
  delay(pause);
  digitalWrite (weiss9, HIGH);
  delay(pause);
  digitalWrite (weiss10, HIGH);
  delay(pause);
  digitalWrite (weiss11, HIGH);
  delay(pause);
  digitalWrite (weiss12, HIGH);
  delay(pause);
  digitalWrite (weiss13, HIGH);
  delay(pause);
  digitalWrite (weiss14, HIGH);
  delay(pause);
  digitalWrite (weiss15, HIGH);
  delay(pause);
  digitalWrite (weiss16, HIGH);
  delay(pause1);
  digitalWrite (weiss17, HIGH);
  delay(pause);
  digitalWrite (weiss18, HIGH);
  delay(pause);
  digitalWrite (weiss19, HIGH);
  delay(pause);
  digitalWrite (weiss20, HIGH);
  delay(pause);
  digitalWrite (weiss21, HIGH);
  delay(pause);
}

void PERLENaus()
{

  digitalWrite (weiss1, LOW);
  digitalWrite (weiss2, LOW);
  digitalWrite (weiss3, LOW);
  digitalWrite (weiss4, LOW);
  digitalWrite (weiss5, LOW);
  digitalWrite (weiss6, LOW);
  digitalWrite (weiss7, LOW);
  digitalWrite (weiss8, LOW);
  digitalWrite (weiss9, LOW);
  digitalWrite (weiss10, LOW);
  digitalWrite (weiss11, LOW);
  digitalWrite (weiss12, LOW);
  digitalWrite (weiss13, LOW);
  digitalWrite (weiss14, LOW);
  digitalWrite (weiss15, LOW);
  digitalWrite (weiss16, LOW);
  digitalWrite (weiss17, LOW);
  digitalWrite (weiss18, LOW);
  digitalWrite (weiss19, LOW);
  digitalWrite (weiss20, LOW);
  digitalWrite (weiss21, LOW); 
}

void KELCHein(int pause)
{
  
 digitalWrite ( gruen1, HIGH);
 delay (pause);
 digitalWrite ( rot1, HIGH);
 delay (pause);
 digitalWrite ( gruen2, HIGH);
 delay (pause);
 digitalWrite ( rot2, HIGH);
 delay (pause);
 digitalWrite ( gruen3, HIGH);
 delay (pause);
 digitalWrite ( rot3, HIGH);
 delay (pause);
 digitalWrite ( gruen4, HIGH);
 delay (pause);
 digitalWrite ( rot4, HIGH);
 delay (pause);
}

void KELCHaus()
{
 digitalWrite (gruen1, LOW);
 digitalWrite (gruen2, LOW);
 digitalWrite (gruen3, LOW);
 digitalWrite (gruen4, LOW);
 digitalWrite (rot1, LOW);
 digitalWrite (rot2, LOW);
 digitalWrite (rot3, LOW);
 digitalWrite (rot4, LOW);
 
}

void KELCHblinken(int pause)
{
  digitalWrite (gruen1, HIGH);
  digitalWrite (gruen2, HIGH);
  digitalWrite (gruen3, HIGH);
  digitalWrite (gruen4, HIGH);
  delay (pause);
  digitalWrite (gruen1, LOW);
  digitalWrite (gruen2, LOW);
  digitalWrite (gruen3, LOW);
  digitalWrite (gruen4, LOW);
  delay (pause);
  digitalWrite (rot1,HIGH);
  digitalWrite (rot2,HIGH);
  digitalWrite (rot3,HIGH);
  digitalWrite (rot4,HIGH);
  delay (pause);
  digitalWrite (rot1,LOW);
  digitalWrite (rot2,LOW);
  digitalWrite (rot3,LOW);
  digitalWrite (rot4,LOW);
  delay (pause);
  digitalWrite (gruen1, HIGH);
  digitalWrite (gruen2, HIGH);
  digitalWrite (gruen3, HIGH);
  digitalWrite (gruen4, HIGH);
  delay (pause);
  digitalWrite (gruen1, LOW);
  digitalWrite (gruen2, LOW);
  digitalWrite (gruen3, LOW);
  digitalWrite (gruen4, LOW);
  delay (pause);
  digitalWrite (rot1,HIGH);
  digitalWrite (rot2,HIGH);
  digitalWrite (rot3,HIGH);
  digitalWrite (rot4,HIGH);
  delay (pause);
  digitalWrite (rot1,LOW);
  digitalWrite (rot2,LOW);
  digitalWrite (rot3,LOW);
  digitalWrite (rot4,LOW);
  delay (pause);


}

void KELCHdimmen()

{
  for(int i=0; i<=255; i=i+3)
  {
  analogWrite(gruen1, i);
  analogWrite(gruen2, i);
  analogWrite(gruen3, i);
  analogWrite(gruen4, i);
  analogWrite(rot1, 255-i);
  analogWrite(rot2, 255-i);
  analogWrite(rot3, 255-i);
  analogWrite(rot4, 255-i);

  delay (15);

  }

  for(int i=255; i>=0; i=i-3)
  {
  analogWrite(gruen1, i);
  analogWrite(gruen2, i);
  analogWrite(gruen3, i);
  analogWrite(gruen4, i);
  analogWrite(rot1, 255-i);
  analogWrite(rot2, 255-i);
  analogWrite(rot3, 255-i);
  analogWrite(rot4, 255-i);
  delay (15);
  }


  
  
}


void ANIMATION(int pause)
{
 digitalWrite (weiss1, HIGH);
 delay(pause);
 digitalWrite (weiss2, HIGH);
 delay(pause);
 digitalWrite (weiss3, HIGH);
 delay(pause);
 digitalWrite (weiss4, HIGH);
 digitalWrite (weiss1, LOW);
 delay(pause);
 digitalWrite (weiss5, HIGH);
 digitalWrite (weiss2, LOW);
 delay(pause);
 digitalWrite (weiss6, HIGH);
 digitalWrite (weiss3, LOW);
 delay(pause);
 digitalWrite (weiss7, HIGH);
 digitalWrite (weiss4, LOW);
 delay(pause);
 digitalWrite (weiss8, HIGH);
 digitalWrite (weiss5, LOW);
 delay(pause);
 digitalWrite (weiss9, HIGH);
 digitalWrite (weiss6, LOW);
 delay(pause);
 digitalWrite (weiss10, HIGH);
 digitalWrite (weiss7, LOW);
 delay(pause);
 digitalWrite (weiss11, HIGH);
 digitalWrite (weiss8, LOW);
 delay(pause);
 digitalWrite (weiss9, LOW);
 delay(pause);
 digitalWrite (weiss10, LOW);
 delay(pause);
 digitalWrite (weiss11, LOW);
 delay(pause);

 digitalWrite (weiss12, HIGH);
 delay(pause);
 digitalWrite (weiss13, HIGH);
 delay(pause);
 digitalWrite (weiss14, HIGH);
 delay(pause);
 digitalWrite (weiss15, HIGH);
 digitalWrite (weiss12, LOW);
 delay(pause);
 digitalWrite (weiss16, HIGH);
 digitalWrite (weiss13, LOW);
 delay(pause);
 digitalWrite (weiss17, HIGH);
 digitalWrite (weiss14, LOW);
 delay(pause);
 digitalWrite (weiss18, HIGH);
 digitalWrite (weiss15, LOW);
 delay(pause);
 digitalWrite (weiss19, HIGH);
 digitalWrite (weiss16, LOW);
 delay(pause);
 digitalWrite (weiss20, HIGH);
 digitalWrite (weiss17, LOW);
 delay(pause);
 digitalWrite (weiss21, HIGH);
 digitalWrite (weiss18, LOW);
 delay(pause);
 digitalWrite (weiss19, LOW);
 delay(pause);
 digitalWrite (weiss20, LOW);
 delay(pause);
 digitalWrite (weiss21, LOW);


}


void ANIMATIONzwei(int pause)

{
 digitalWrite (weiss1, HIGH);
 digitalWrite (weiss4, HIGH);
 digitalWrite (weiss7, HIGH);
 digitalWrite (weiss10, HIGH);
 digitalWrite (weiss13, HIGH);
 digitalWrite (weiss16, HIGH);
 digitalWrite (weiss19, HIGH);
 delay(pause);
 digitalWrite (weiss1, LOW);
 digitalWrite (weiss4, LOW);
 digitalWrite (weiss7, LOW);
 digitalWrite (weiss10, LOW);
 digitalWrite (weiss13, LOW);
 digitalWrite (weiss16, LOW);
 digitalWrite (weiss19, LOW);

 digitalWrite (weiss2, HIGH);
 digitalWrite (weiss5, HIGH);
 digitalWrite (weiss8, HIGH);
 digitalWrite (weiss11, HIGH);
 digitalWrite (weiss14, HIGH);
 digitalWrite (weiss17, HIGH);
 digitalWrite (weiss20, HIGH);
 delay(pause);
 digitalWrite (weiss2, LOW);
 digitalWrite (weiss5, LOW);
 digitalWrite (weiss8, LOW);
 digitalWrite (weiss11, LOW);
 digitalWrite (weiss14, LOW);
 digitalWrite (weiss17, LOW);
 digitalWrite (weiss20, LOW);

 digitalWrite (weiss3, HIGH);
 digitalWrite (weiss6, HIGH);
 digitalWrite (weiss9, HIGH);
 digitalWrite (weiss12, HIGH);
 digitalWrite (weiss15, HIGH);
 digitalWrite (weiss18, HIGH);
 digitalWrite (weiss21, HIGH);
 delay(pause);
 digitalWrite (weiss3, LOW);
 digitalWrite (weiss6, LOW);
 digitalWrite (weiss9, LOW);
 digitalWrite (weiss12, LOW);
 digitalWrite (weiss15, LOW);
 digitalWrite (weiss18, LOW);
 digitalWrite (weiss21, LOW);

 digitalWrite (weiss2, HIGH);
 digitalWrite (weiss5, HIGH);
 digitalWrite (weiss8, HIGH);
 digitalWrite (weiss11, HIGH);
 digitalWrite (weiss14, HIGH);
 digitalWrite (weiss17, HIGH);
 digitalWrite (weiss20, HIGH);
 delay(pause);
 digitalWrite (weiss2, LOW);
 digitalWrite (weiss5, LOW);
 digitalWrite (weiss8, LOW);
 digitalWrite (weiss11, LOW);
 digitalWrite (weiss14, LOW);
 digitalWrite (weiss17, LOW);
 digitalWrite (weiss20, LOW);

  digitalWrite (weiss1, HIGH);
 digitalWrite (weiss4, HIGH);
 digitalWrite (weiss7, HIGH);
 digitalWrite (weiss10, HIGH);
 digitalWrite (weiss13, HIGH);
 digitalWrite (weiss16, HIGH);
 digitalWrite (weiss19, HIGH);
 delay(pause);
 digitalWrite (weiss1, LOW);
 digitalWrite (weiss4, LOW);
 digitalWrite (weiss7, LOW);
 digitalWrite (weiss10, LOW);
 digitalWrite (weiss13, LOW);
 digitalWrite (weiss16, LOW);
 digitalWrite (weiss19, LOW);

}
