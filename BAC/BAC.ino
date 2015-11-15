#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;
const int analogPin = 0;
int diagpin = 13;
int state = 0;      // the current state of the output pin
int reading;
int inpin=5;// the current reading from the input pin
int previous = 1;    // the previous reading from the input pin
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers
int loopEngaged = 0;

void setup() 
{
  pinMode(diagpin, OUTPUT);
  pinMode(inpin, INPUT);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    
    lcd.print("BAC:");

    delay(1000);
}

void loop() 
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    int sensorReading = analogRead(analogPin);
        if (sensorReading > 750){
        int r,g,b;
        r = map(sensorReading,750,1024,0,255);
        g = map(sensorReading,750,1024,255,0);
        b = map(sensorReading,750,1024,255,0);
        lcd.setRGB(r, g, b);
        lcd.clear();
        unsigned int ppm = map(sensorReading, 750, 1024, 200 ,800);
        unsigned int bac = map (ppm, 200,800,10,50);
        //float BAC = ppm/2600;
        //int BAC = ppm;
        unsigned int BAC = ppm*100;
        unsigned int temp=BAC/26;
        lcd.setCursor(0, 0);
        lcd.print("Your BAC is:");
        lcd.setCursor(0,1);
        lcd.print(".");
        lcd.setCursor(1,1);
        lcd.print(temp);}
        //lcd.print(BAC);}
        else{
          lcd.clear();
          lcd.setRGB(255,255,255);
          lcd.print(
            "BAC is too low");
          lcd.setCursor(0,1);
          lcd.print("Drink some more!");
          
            //sensorReading);
        
        }

    delay(100);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
