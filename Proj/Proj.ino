// Anthony Zuluaga and Matt Carmichael 
// CS 362
// Project 
// 
// Program for Arduino for LED Circles

#include "Adafruit_NeoPixel.h"
 
#define PIN 6
#define NUM_PIXELS 24
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup()
{
  pixels.begin();
}
 
void loop()
{
  
  //threeColor();
  yellowLight();
  pixels.clear();
}

void blueLight()
{
  for(int i=0; i<NUM_PIXELS; i++)
  {
    //pixels.clear();
    pixels.setPixelColor(i, 0, 0, 255); 
    pixels.show();
    delay(100);   
  }
}

void redLight()
{
  for(int i=0; i<NUM_PIXELS; i++)
  {
    //pixels.clear();
    pixels.setPixelColor(i, 255, 0, 0); 
    pixels.show();
    delay(100);   
  }
}

void greenLight()
{
  for(int i=0; i<NUM_PIXELS; i++)
  {
    //pixels.clear();
    pixels.setPixelColor(i, 0, 255, 0); 
    pixels.show();
    delay(100);   
  }
}

void threeColor()
{
  for(int i = 0; i < NUM_PIXELS; i++)
  {
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(0,255,0));
    pixels.setPixelColor(23-i, pixels.Color(255,0,0));
    if (i<12)
    {
      pixels.setPixelColor(12+i, pixels.Color(0,0,255));
    } else
    {
      pixels.setPixelColor(i-12, pixels.Color(0,0,255));
    }
    pixels.show();
    delay(50);
  }
}

void yellowLight()
{
  for(int i=0; i<NUM_PIXELS; i++)
  {
    //pixels.clear();
    pixels.setPixelColor(i, pixels.Color((255-(i*10)), 200, (255-(i*10))));
    pixels.show();
    delay(100);   
  }
}



