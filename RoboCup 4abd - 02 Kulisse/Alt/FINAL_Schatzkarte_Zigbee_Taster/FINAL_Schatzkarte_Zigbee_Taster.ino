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
  #define PUL_R 6        //PWM
  #define ENA_R 4
 
//TOR - Motor links
  #define DIR_L 9
  #define PUL_L 10       //PWM
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
 
#define DELAYVAL 100    // Time (in milliseconds) to pause between pixels


void setup()
{
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
void loop()
 {
    //Set all pixel colors to "off"
    pixels.clear();
    
    
    
    tasterstatus = digitalRead(taster);

    if(tasterstatus == LOW)
    {
      Zigbee.print("1");
      Serial.println(1);
          //warten
          delay(25000);
  

      Zigbee.print("2");
      Serial.println(2);  
        TOR_AUF_ZU();
        delay(2000);

      // Code von LEDs bis zum Hai
            for (int i = 0; i <= 136; i++) {  // For each pixel...
        
            // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
            // Here we're using a moderately bright green color:
            pixels.setPixelColor(i, pixels.Color(0, 150, 150));
        
            pixels.show();  // Send the updated pixel colors to the hardware.
        
            delay(DELAYVAL);  // Pause before next pass through loop
          }

          //warten
          delay(20000);


  
      Zigbee.print("3");
      Serial.println(3);
      delay(3000);
          // Code LEDs - Hai bis zum Blitz
            for (int i = 137; i <= 173; i++) {  // For each pixel...
          
              // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
              // Here we're using a moderately bright green color:
              pixels.setPixelColor(i, pixels.Color(0, 150, 150));
          
              pixels.show();  // Send the updated pixel colors to the hardware.
          
              delay(DELAYVAL);  // Pause before next pass through loop
            }
          
          //warten
          delay(20000);

        Zigbee.print("4");
        Serial.println(4);
        //Code LEDs - Blitz bis Schatz
          for (int i = 174; i <= NUMPIXELS; i++) {  // For each pixel...
        
            // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
            // Here we're using a moderately bright green color:
            pixels.setPixelColor(i, pixels.Color(0, 150, 150));
        
            pixels.show();  // Send the updated pixel colors to the hardware.
        
            delay(DELAYVAL);  // Pause before next pass through loop
          }



    }
  
  

}
 
void TOR_AUF_ZU()
{
  //Tor öffnen
    
    digitalWrite(DIR_R, HIGH);
    digitalWrite(DIR_L, LOW);
   
    for(int i = 0; i <= 230; i++)
      {
      digitalWrite(PUL_R, HIGH);
      digitalWrite(PUL_L, HIGH);
      delayMicroseconds(1700);
      digitalWrite(PUL_R, LOW);
      digitalWrite(PUL_L, LOW);
      delayMicroseconds(1700);
      }
    delay(15000);       //15 Sek geöffnet
 
  //Tor schließen
   
    digitalWrite(DIR_R, LOW);
    digitalWrite(DIR_L, HIGH);
   
    for(int i = 0; i <= 250; i++)
      {
      digitalWrite(PUL_R, HIGH);
      digitalWrite(PUL_L, HIGH);
      delayMicroseconds(1700);
      digitalWrite(PUL_R, LOW);
      digitalWrite(PUL_L, LOW);
      delayMicroseconds(1700);
      }
}

void AnimationLEDs()
{

  // Code
}