// Anthony Zuluaga and Matt Carmichael 
// CS 362
// Project 
// 
// Program for Arduino for LED Circles

#include "Adafruit_NeoPixel.h"
#include <TrueRandom.h>
 
#define PIN 6
#define PIN2 5
#define NUM_PIXELS 24
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUM_PIXELS, PIN2, NEO_GRB + NEO_KHZ800);
int rNum;       // r pixel value 0 - 255 
int gNum;       // g pixel value 0 - 255 
int bNum;       // b pixel value 0 - 255

void setup()
{
  pixels.begin();
  pixels2.begin();
}
 
void loop()
{
  
  //threeColor();
  //light();
  //flash();
  randomLight();
  delay(350);
  clearAll();
  delay(350);

}

void blue()
{
  delay(1000);
  for(int i=0; i<NUM_PIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 255));
    pixels2.show();   
  }
}

void green()
{
  delay(1000);
  for(int i=0; i<NUM_PIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
    pixels2.setPixelColor(i, pixels2.Color(0, 255, 0));
    pixels2.show();   
  }
}

void red()
{
  delay(1000);
  for(int i=0; i<NUM_PIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
    pixels2.setPixelColor(i, pixels2.Color(255, 0, 0));
    pixels2.show();   
  }
}



void threeColor()
{
  for(int i = 0; i < NUM_PIXELS; i++)
  {
    pixels.clear();
    pixels2.clear();
    pixels.setPixelColor(i, pixels.Color(0,255,0));
    pixels2.setPixelColor(i, pixels2.Color(0,255,0));
    pixels.setPixelColor(23-i, pixels.Color(255,0,0));
    pixels2.setPixelColor(23-i, pixels2.Color(255,0,0));
    if (i<12)
    {
      pixels.setPixelColor(12+i, pixels.Color(0,0,255));
      pixels2.setPixelColor(12+i, pixels2.Color(0,0,255));
    } else
    {
      pixels.setPixelColor(i-12, pixels.Color(0,0,255));
      pixels2.setPixelColor(i-12, pixels2.Color(0,0,255));
    }
    pixels.show();
    pixels2.show();
    delay(50);
  }
}

void randomLight()
{
  delay(1000);
  rNum = (TrueRandom.random(1,255));            // store random number from 1 to 255 into r value
  gNum = (TrueRandom.random(1,255));            // store random number from 1 to 255 into g value
  bNum = (TrueRandom.random(1,255));            // store random number from 1 to 255 into b value
  
  for(int i=0; i<NUM_PIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(rNum, gNum, bNum));
    pixels.show();
    pixels2.setPixelColor(i, pixels2.Color(rNum, gNum, bNum));
    pixels2.show();   
  }
}

void clearAll()
{
  pixels.clear();
  pixels2.clear();
}


