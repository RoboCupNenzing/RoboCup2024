//Testprogramm Schatzkiste Kelch

#define gruen1 13
#define gruen2 11
#define gruen3 9
#define gruen4 7

#define rot1 12
#define rot2 10
#define rot3 6
#define rot4 5

#define pause2 300

void setup() {

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
 
 digitalWrite ( gruen1, HIGH);
 delay (pause2);
 digitalWrite ( gruen2, HIGH);
 delay (pause2);
 digitalWrite ( gruen3, HIGH);
 delay (pause2);
 digitalWrite ( gruen4, HIGH);
 delay (pause2);
 digitalWrite ( rot1, HIGH);
 delay (pause2);
 digitalWrite ( rot2, HIGH);
 delay (pause2);
 digitalWrite ( rot3, HIGH);
 delay (pause2);
 digitalWrite ( rot4, HIGH);
 delay (pause2);
 
 digitalWrite (gruen1, LOW);
 digitalWrite (gruen2, LOW);
 digitalWrite (gruen3, LOW);
 digitalWrite (gruen4, LOW);
 digitalWrite (rot1, LOW);
 digitalWrite (rot2, LOW);
 digitalWrite (rot3, LOW);
 digitalWrite (rot4, LOW);
 delay (pause2);
}
