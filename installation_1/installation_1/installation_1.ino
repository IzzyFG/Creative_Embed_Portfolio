#include <SPI.h>
#include <TFT_eSPI.h>    // Hardware-specific library
#include <cstdio>
#include<cstdlib>
#include <iostream>
#include "words_w_count.h"
TFT_eSPI tft = TFT_eSPI();

//https://electropeak.com/learn/absolute-beginners-guide-to-tft-lcd-displays-by-arduino/
void showmsgXY(const GFXfont *f, const char *msg)
{
  int16_t x1, y1;
  uint16_t wid, ht;  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(f);
  wid = tft.textWidth(msg, f->glyph->width);
  ht = tft.fontHeight();

  tft.setCursor((tft.getViewportWidth()-wid)/2, (tft.getViewportHeight()+(ht/2))/2 );
  tft.println(msg);

  delay(3000);
}

void setup()
{
  Serial.begin(9600);
  tft.begin();
  tft.setRotation(1);
}

//https://stackoverflow.com/questions/8684327/c-map-number-ranges
void loop(void)
{
  const GFXfont *fontList[] = {
    &FreeSerif11pt7b,
    &FreeSerif12pt7b,
    &FreeSerif13pt7b,
    &FreeSerif14pt7b,
    &FreeSerif15pt7b,
    &FreeSerif16pt7b,
    &FreeSerif17pt7b,
    &FreeSerif18pt7b,
    &FreeSerif19pt7b,
    &FreeSerif20pt7b,
    &FreeSerif21pt7b,
    &FreeSerif22pt7b,
    &FreeSerif23pt7b,
    &FreeSerif24pt7b,
    &FreeSerif25pt7b,
    &FreeSerif26pt7b,
    &FreeSerif27pt7b,
    &FreeSerif28pt7b,
    &FreeSerif29pt7b,
    &FreeSerif30pt7b,
  };
  srand((unsigned) time(NULL));

  tft.invertDisplay(true);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_CYAN);
  
  tft.setCursor(0, 50);
  tft.setTextWrap(true); // Wrap on width

  for (int i = 0; i<800; i++){
    int random = rand()%500;    
    const GFXfont *f = fontList[wordsFreq[random]];
    showmsgXY(f, wordsList[random]);
  }

  
}
