//Programm GESTELL FINAL


//Motoren
#define DIR_A 2
#define PUL_A 3  //PWM
#define ENA_A 1

#define DIR_B 5
#define PUL_B 6  //PWM
#define ENA_B 4

#define DIR_C 9
#define PUL_C 10  //PWM
#define ENA_C 8

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

//Pin für die Blitze
#define PIN_rechts 27
#define PIN_links 25
#define PIN_mitte 23

//Anzahl der Neopixel
#define NUMPIXELS_rechts 28
#define NUMPIXELS_links 36
#define NUMPIXELS_mitte 20

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel Blitz_rechts(NUMPIXELS_rechts, PIN_rechts, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Blitz_links(NUMPIXELS_links, PIN_links, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel Blitz_mitte(NUMPIXELS_mitte, PIN_mitte, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 15  // Time (in milliseconds) to pause between pixels


#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

void setup() {

  //Serielle Kommunikation
  Serial.begin(9600);
  Serial3.begin(9600);

  //Motoren
  pinMode(DIR_A, OUTPUT);
  pinMode(PUL_A, OUTPUT);
  pinMode(ENA_A, OUTPUT);
  pinMode(DIR_B, OUTPUT);
  pinMode(PUL_B, OUTPUT);
  pinMode(ENA_B, OUTPUT);
  pinMode(DIR_C, OUTPUT);
  pinMode(PUL_C, OUTPUT);
  pinMode(ENA_C, OUTPUT);

  // Motoren deaktivieren
  digitalWrite(ENA_A, HIGH);
  digitalWrite(ENA_B, HIGH);
  digitalWrite(ENA_C, HIGH);


  Blitz_links.begin();   // INITIALIZE NeoPixel strip object (REQUIRED)
  Blitz_rechts.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  Blitz_mitte.begin();   // INITIALIZE NeoPixel strip object (REQUIRED)

  Blitz_links.clear();   // Set all pixel colors to 'off'
  Blitz_rechts.clear();  // Set all pixel colors to 'off'
  Blitz_mitte.clear();   // Set all pixel colors to 'off'

  Blitz_links.show();
  Blitz_rechts.show();
  Blitz_mitte.show();
  //ganzes Programm Blitze

//Testprogramm Blitze
 
}

void loop() {

  ZigbeeAbfragen("1");  //nichts passiert
  Serial.println(1);

  ZigbeeAbfragen("2");  //nichts passiert
  Serial.println(2);

  ZigbeeAbfragen("3");
  Serial.println(3);

  // Motoren Aktivieren
  digitalWrite(ENA_A, LOW);
  digitalWrite(ENA_B, LOW);
  digitalWrite(ENA_C, LOW);

  Drehung_links(2100);

  delay(1000);

  //Blitze erscheinen


  Gewitter();

  

  ZigbeeAbfragen("4");
  Serial.println(4);

  Drehung_links(3300);

  //Motoren deaktivieren
  digitalWrite(ENA_A, HIGH);
  digitalWrite(ENA_B, HIGH);
  digitalWrite(ENA_C, HIGH);

  ZigbeeAbfragen("5");
  Serial.println(5);
}


void Blitz_rechts_zeigen(int sp) {
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i <= NUMPIXELS_rechts; i++) {  // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    Blitz_rechts.setPixelColor(i, Blitz_rechts.Color(255, 100, 0));

    Blitz_rechts.show();  // Send the updated pixel colors to the hardware.

    delay(sp);  // Pause before next pass through loop
  }
  Blitz_rechts.clear();
  Blitz_rechts.show();
}

void Blitz_links_zeigen(int sp) {
  for (int i = 0; i <= NUMPIXELS_links; i++) {  // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    Blitz_links.setPixelColor(i, Blitz_links.Color(255, 100, 0));

    Blitz_links.show();  // Send the updated pixel colors to the hardware.

    delay(sp);  // Pause before next pass through loop
  }
  Blitz_links.clear();
  Blitz_links.show();
}

void Blitz_mitte_zeigen(int sp) {
  for (int i = 0; i <= NUMPIXELS_mitte; i++) {  // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    Blitz_mitte.setPixelColor(i, Blitz_mitte.Color(200, 100, 0));

    Blitz_mitte.show();  // Send the updated pixel colors to the hardware.

    delay(sp);  // Pause before next pass through loop
  }
  Blitz_mitte.clear();
  Blitz_mitte.show();
}

void Gewitter()
{
  Blitz_rechts_zeigen(8);
  Blitz_mitte_zeigen(11);
  Blitz_links_zeigen(9);
  Blitz_mitte_zeigen(10);
  Blitz_rechts_zeigen(12);
  Blitz_rechts_zeigen(7);
  Blitz_links_zeigen(12);
  Blitz_mitte_zeigen(8);
  Blitz_links_zeigen(10);
  Blitz_rechts_zeigen(9);
  Blitz_rechts_zeigen(12);
  Blitz_links_zeigen(7);
  Blitz_mitte_zeigen(11);
  Blitz_links_zeigen(8);
  Blitz_rechts_zeigen(12);
}


void Drehung_links(int steps) {
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, LOW);
  digitalWrite(DIR_C, LOW);

  for (int i = 0; i < steps; i++) {
    digitalWrite(PUL_A, HIGH);
    digitalWrite(PUL_B, HIGH);
    digitalWrite(PUL_C, HIGH);
    delayMicroseconds(1200);
    digitalWrite(PUL_A, LOW);
    digitalWrite(PUL_B, LOW);
    digitalWrite(PUL_C, LOW);
    delayMicroseconds(1200);
  }
}


void ZigbeeAbfragen(String Zahl) {
  while (1) {
    String readString;
    String Daten;
    while (Serial3.available()) {
      delay(1);
      if (Serial3.available() > 0) {
        char c = Serial3.read();
        if (isControl(c)) {
          break;
        }
        readString += c;
      }
    }
    Daten = readString;

    if (Daten == Zahl) {
      break;
    }
  }
}
