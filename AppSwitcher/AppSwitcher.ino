#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int modepin = 13;
int mode= HIGH;

void setup() 
{
    // set up the LCD's number of columns and rows:
    pinMode(modepin, INPUT);
    lcd.begin(16, 2);
    
    lcd.setRGB(255, 255, 255);
    
    // Print a message to the LCD.

    delay(1000);
}

void loop() 
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(millis()/1000);

    delay(100);
    mode=digitalRead(modepin);
    if(mode==LOW)
    {
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("hello, world!");
    }
    else
    {
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("This is part two");
    }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
