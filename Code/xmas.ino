/* Arduino 256 RGB LEDs Matrix Animation Frame
   Using WS2812B 32*8 LED Strip matrix
   https://www.amazon.de/-/nl/gp/product/B07KT1H481/ref=ppx_yo_dt_b_asin_title_o06_s01?ie=UTF8&psc=1

   Sprites created using LEDMatrixStudio
   www.freshney.org // paul@freshney.org
   https://sourceforge.net/projects/led-matrix-studio/   

  Sprites created by Barremans
  https://github.com/barremans/Xmas_Pullover
*/
#define SKETCH_VERSION "4.0.1"
/*
 * changelog:
 * less code
 * all function and data stored in the sprite header
 * sprite animation controlled by the function RUNMATRIX
 * Thanks to johnwasser and guix for making the code smaller
 * 
 */

#include <avr/pgmspace.h>  // Needed to store stuff in Flash using PROGMEM
#include "FastLED.h"       // Fastled library to control the LEDs
#include "xmas.h"          // this holds the xmass sprite

// How many leds are connected?
#define NUM_LEDS 256

// Define the Data Pin
const byte DATA_PIN = RX;  // Connected to the data pin of the first LED strip


// Define the array of leds
CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); // Init of the Fastled library
  FastLED.setBrightness(50);
  FastLED.clear();
}

void loop()
{
  RUNMATRIX();  //Runs the the choosen sprite  
}

void RUNMATRIX()
{
  // Frame 1-77
  FastLED.clear();

  for (byte frame = 0; frame < sizeof(Xitems) / sizeof(Xitems[0]); frame++)
  {
    const long int * ptr = Xitems[frame];
    
    for (long i = 0; i < NUM_LEDS; i++)
    {
      // Each pixel is a 'long' (a.k.a. 'dword')
      leds[i] = ptr[i];
    }
    
    FastLED.show();
    delay(400);
  }
}
