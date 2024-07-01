// Programm Kokosnuss

#define IN1 6
#define IN2 7

void setup() {
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);

}

void loop() {
digitalWrite (IN1, HIGH);
digitalWrite (IN2, LOW);
delay (10000);
digitalWrite (IN1, LOW);
digitalWrite (IN2, LOW);
delay(2000);
}
