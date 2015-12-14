#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int modepin = 13;
int mode= HIGH;
const int BACpin = 0;
unsigned int finalbac;
unsigned int score;

void setup() 
{
    // set up the LCD's number of columns and rows:
    Serial.begin(9600);
    pinMode(modepin, INPUT);
    lcd.begin(16, 2);
    
    lcd.setRGB(255, 255, 255);
    
    // Print a message to the LCD.
    attachInterrupt(digitalPinToInterrupt(2), test1, RISING);
    attachInterrupt(digitalPinToInterrupt(3), test2, RISING);
    delay(1000);
}

void loop() 
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    //lcd.print(millis()/1000);

    delay(100);
    mode=digitalRead(modepin);
    if(mode==LOW)
    {
    int sensorReading = analogRead(BACpin);
        if (sensorReading > 750){
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
        else{
        lcd.clear();
        lcd.setRGB(255,255,255);
        lcd.setCursor(0,0);
        lcd.print("BAC is too low!");
        delay(1000);
        lcd.setCursor(0,1);
        lcd.print("Drink Some More!");
        delay(1000);
        //lcd.setCursor(0,1);
          //lcd.print("Drink some more!");
          
            //sensorReading);
        
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
    Serial.println("YAY");
}

void test2() {
    int tempvalue = map(finalbac,0,800,1,5);
    score += 200*tempvalue;
        Serial.println("YAY");
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
