//Programm SCHATZKARTE FINAL

//Serielle Kommunikation
#include <SoftwareSerial.h>
#define rxPin 2
#define txPin 3

SoftwareSerial Zigbee(rxPin, txPin);

//Tastsensor
#define taster 13
bool tasterstatus = HIGH;

//TOR - Motor rechts
#define DIR_R 5
#define PUL_R 6  //PWM
#define ENA_R 4

//TOR - Motor links
#define DIR_L 9
#define PUL_L 10  //PWM
#define ENA_L 8

//Neopixel
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

//LED Pin
#define PIN 12

#define NUMPIXELS 211  // Anzahl Neopixel

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 75  // Time (in milliseconds) to pause between pixels


void setup() {
  // Kommunikation mit ZigBee
  Zigbee.begin(9600);
  Serial.begin(9600);

  //Taster
  pinMode(taster, INPUT_PULLUP);


  //TOR
  pinMode(DIR_R, OUTPUT);
  pinMode(PUL_R, OUTPUT);
  pinMode(ENA_R, OUTPUT);

  pinMode(DIR_L, OUTPUT);
  pinMode(PUL_L, OUTPUT);
  pinMode(ENA_L, OUTPUT);

  digitalWrite(ENA_R, LOW);
  digitalWrite(ENA_L, LOW);



  //Neopixel
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
}
void loop() {
  //Set all pixel colors to "off"
  pixels.clear();
  pixels.show();




  tasterstatus = digitalRead(taster);

  if (tasterstatus == LOW) {
    delay(1000);

    // ------------- Abschnitt 1 ----------------
    Zigbee.print("1");

    Serial.println(1);

    //warten
    delay(23000);  // NOCH ANPASSEN
    Zigbee.print("A");
    delay(17000);

    // ------------- Abschnitt 2 ----------------
    Zigbee.print("2");
    Serial.println(2);

    TOR_AUF();
    LED_bis_Hai();  // Code für LED-Streifen bis zum Hai
    TOR_ZU();


    //warten
    delay(10000);  // NOCH ANPASSEN

    // ------------- Abschnitt 3 ----------------
    Zigbee.print("3");
    Serial.println(3);
    delay(3000);

    LED_bis_Blitz();

    //warten
    delay(10000);  // NOCH ANPASSEN

    LED_bis_Schatz();

    delay(4500);

    // ------------- Abschnitt 4 ----------------
    Zigbee.print("4");
    Serial.println(4);
    


    delay(25000);
    Zigbee.print("B");
    Serial.println("B");

    delay(17000);
    Zigbee.print("C");
    Serial.println("C");



    AnimationLEDs(70);

    // ------------- RESET ----------------
    Zigbee.print("5");
    Serial.println("5");
  }
}

void LED_bis_Hai() {
  // Code LEDs - bis zum Hai
  for (int i = 0; i <= 136; i++) {  // For-Schleife für die Pixel

    pixels.setPixelColor(i, pixels.Color(0, 150, 150));  // LED-Streifen auf Position i mit Farbe versehen
    pixels.show();                                       // LED Streifen aktualisieren
    delay(DELAYVAL);                                     // Pause vor nächster LED
  }
}

void LED_bis_Blitz() {
  // Code LEDs - Hai bis zum Blitz
  for (int i = 137; i <= 173; i++) {  // For-Schleife für die Pixel

    pixels.setPixelColor(i, pixels.Color(0, 150, 150));  // LED-Streifen auf Position i mit Farbe versehen
    pixels.show();                                       // LED Streifen aktualisieren
    delay(DELAYVAL);                                     // Pause vor nächster LED
  }
}

void LED_bis_Schatz() {
  // Code LEDs - Blitz bis zum Schatz
  for (int i = 174; i <= NUMPIXELS; i++) {  // For-Schleife für die Pixel

    pixels.setPixelColor(i, pixels.Color(0, 150, 150));  // LED-Streifen auf Position i mit Farbe versehen
    pixels.show();                                       // LED Streifen aktualisieren
    delay(DELAYVAL);                                     // Pause vor nächster LED
  }
}

void TOR_AUF() {
  //Tor öffnen

  digitalWrite(DIR_R, HIGH);
  digitalWrite(DIR_L, LOW);

  for (int i = 0; i <= 230; i++) {
    digitalWrite(PUL_R, HIGH);
    digitalWrite(PUL_L, HIGH);
    delayMicroseconds(1700);
    digitalWrite(PUL_R, LOW);
    digitalWrite(PUL_L, LOW);
    delayMicroseconds(1700);
  }
}

void TOR_ZU() {

  //Tor schließen

  digitalWrite(DIR_R, LOW);
  digitalWrite(DIR_L, HIGH);

  for (int i = 0; i <= 250; i++) {
    digitalWrite(PUL_R, HIGH);
    digitalWrite(PUL_L, HIGH);
    delayMicroseconds(1700);
    digitalWrite(PUL_R, LOW);
    digitalWrite(PUL_L, LOW);
    delayMicroseconds(1700);
  }
}


void AnimationLEDs(int repeats) {

  // Code


  for(int a=0; a<repeats; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      pixels.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<pixels.numPixels(); c += 3) {
        pixels.setPixelColor(c, 0, 150, 150); // Set pixel 'c' to value 'color'
      }
      pixels.show(); // Update strip with new contents
      delay(100);  // Pause for a moment
    }
  }
}
