// Anthony Zuluaga, Matt Carmichael, Marcell Purham 
// CS 362
// Project 
// 
// Program for Arduino for LED Circles

#include "Adafruit_NeoPixel.h"
#include <TrueRandom.h>
 
#define PIN 6                 // Reserves Pin number 6 for the first LED ring's input
#define PIN2 5                // Reserves Pin number 5 for the second LED ring's input
#define NUM_PIXELS 24         // Defines a variable for the max number of LEDs inside each NeoPixel ring
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);      // initializes the first LED ring
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUM_PIXELS, PIN2, NEO_GRB + NEO_KHZ800);    // initializes the second LED ring
int rNum;                     // r pixel value 0 - 255 
int gNum;                     // g pixel value 0 - 255 
int bNum;                     // b pixel value 0 - 255

void setup()
{
  pixels.begin();              
  pixels2.begin();            
}
 
void loop()
{
  
  //threeColor();             // three leds circle around the whole ring overlapping each other
  //flash();                  // flashes a white light on and off
  randomLight();              // random light function that displays a random color to each LED ring
  delay(350);
  clearAll();                 // clears every LED ring of its lights
  delay(350);

}

void blue()
{
  delay(1000);
  for(int i=0; i<NUM_PIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));             // set the led to the color BLUE
    pixels.show();
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 255));           // set the led to the color BLUE
    pixels2.show();   
  }
}

void green()
{
  delay(1000);
  for(int i=0; i<NUM_PIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));             // set the led to the color GREEN
    pixels.show();
    pixels2.setPixelColor(i, pixels2.Color(0, 255, 0));           // set the led to the color GREEN
    pixels2.show();   
  }
}

void red()
{
  delay(1000);
  for(int i=0; i<NUM_PIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));             // set the led to the color RED
    pixels.show();
    pixels2.setPixelColor(i, pixels2.Color(255, 0, 0));           // set the led to the color RED
    pixels2.show();   
  }
}

void flash()
{
  clearAll();
  
  delay(1000);

  for(int i=0; i<NUM_PIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255, 255, 255));         // set the led to the color WHITE
    pixels.show();
    pixels2.setPixelColor(i, pixels2.Color(255, 255, 255));       // set the led to the color WHITE
    pixels2.show();   
  }

  delay(1000);
}

void threeColor()
{
  for(int i = 0; i < NUM_PIXELS; i++)
  {
    pixels.clear();
    pixels2.clear();
    pixels.setPixelColor(i, pixels.Color(0,255,0));               // set the led to the color GREEN for first ring
    pixels2.setPixelColor(i, pixels2.Color(0,255,0));             // set the led to the color GREEN for second ring
    pixels.setPixelColor(23-i, pixels.Color(255,0,0));            // set the led to the color RED for first ring
    pixels2.setPixelColor(23-i, pixels2.Color(255,0,0));          // set the led to the color RED for second ring
    if (i<12)
    {
      pixels.setPixelColor(12+i, pixels.Color(0,0,255));          // set the led to the color BLUE for first ring
      pixels2.setPixelColor(12+i, pixels2.Color(0,0,255));        // set the led to the color BLUE for second ring
    } else
    {
      pixels.setPixelColor(i-12, pixels.Color(0,0,255));          // set the led to the color BLUE for first ring
      pixels2.setPixelColor(i-12, pixels2.Color(0,0,255));        // set the led to the color BLUE for second ring
    }
    pixels.show();
    pixels2.show();
    delay(50);
  }
}

void randomLight()
{
  delay(1000);
  rNum = (TrueRandom.random(1,254));                              // store random number from 1 to 230 into r value
  gNum = (TrueRandom.random(1,254));                              // store random number from 1 to 255 into g value
  bNum = (TrueRandom.random(1,254));                              // store random number from 1 to 255 into b value
  
  for(int i=0; i<NUM_PIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(rNum, gNum, bNum));      // set the led to a random color
    pixels.show();
    pixels2.setPixelColor(i, pixels2.Color(rNum, gNum, bNum));    // set the led to a random color
    pixels2.show();   
  }
}

void clearAll()
{
  pixels.clear();                                                 // clear all the LEDs in the first ring
  pixels2.clear();                                                // clear all the LEDs in the second ring
}


