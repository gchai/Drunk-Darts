#include <Wire.h>
#include "rgb_lcd.h"
//rgb_lcd.h library by Seeed Studios
//Source: https://github.com/Seeed-Studio/Grove_LCD_RGB_Backlight

rgb_lcd lcd;
//initializing the lcd

int modepin = 13;
//This is the input that will tell the arduino which "mode" it will be in.
int mode= HIGH;
//Default pinmode is high
const int BACpin = 0;
unsigned int finalbac;
unsigned int score;

void setup() 
{
    
    Serial.begin(9600);
    pinMode(modepin, INPUT);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // set color of LCD
    lcd.setRGB(255, 255, 255);
    attachInterrupt(digitalPinToInterrupt(2), test1, RISING);
    attachInterrupt(digitalPinToInterrupt(3), test2, RISING);
    delay(1000);
}

void loop() 
{
    lcd.setCursor(0, 1);
    delay(100);
    mode=digitalRead(modepin);
    if(mode==LOW)
      {
        int sensorReading = analogRead(BACpin);
        if (sensorReading > 750)
          {
            int r,g,b;
            lcd.setRGB(255, 0, 0);
            lcd.clear();
            unsigned int ppm = map(sensorReading, 750, 1024, 200 ,800);
            unsigned int bac = map (ppm, 200,800,10,50);
            unsigned int BAC = ppm*100;
            unsigned int temp=BAC/26;
            lcd.setCursor(0, 0);
            lcd.print("BAC:");
            lcd.setCursor(5,0);
            lcd.print(".");
            lcd.setCursor(6,0);
            lcd.print(temp);
            finalbac=temp;
          }
        else
          {
            lcd.clear();
            lcd.setRGB(255,255,255);
            lcd.setCursor(0,0);
            lcd.print("BAC is too low!");
            delay(1000);
            lcd.setCursor(0,1);
            lcd.print("Drink Some More!");
            delay(1000);        
          }
      }
    else
      {
        lcd.setCursor(0,0);
        lcd.clear();
        lcd.print("Your BAC is .");
        lcd.setCursor(13,0);
        lcd.print(finalbac);
        lcd.setCursor(0,1);
        lcd.setRGB(255,255,255);
        lcd.print("Start! Score:");
        lcd.setCursor(13,1);
        lcd.print(score);
        Serial.println(score);
      }
}

void test1() {
    int tempvalue = map(finalbac,0,800,1,5);
    score += 100*tempvalue;
    Serial.println("HIT!!");
}

void test2() {
    int tempvalue = map(finalbac,0,800,1,5);
    score += 200*tempvalue;
        Serial.println("BULLSEYE!!");
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
