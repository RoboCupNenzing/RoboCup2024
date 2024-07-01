int Magnet =A14;
int LED =32;

void setup() {
  // put your setup code here, to run once:
pinMode(Magnet, OUTPUT);
pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Magnet, HIGH);
digitalWrite(LED, HIGH);
delay(1000);
digitalWrite(Magnet, LOW);
digitalWrite(LED, LOW);
delay(1000);


}