#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int pin = 0;
volatile int state = LOW;
int pin2 = 1;
volatile int state2 = LOW;
int BAC = 0;

int score;

void setup() {
    Wire.begin(1);
    Serial.begin(9600);
    pinMode(pin, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(0), test1, FALLING);
    attachInterrupt(digitalPinToInterrupt(1), test2, FALLING);
    Wire.begin(1);
    Wire.onReceive(recieveEvent);
    //Serial.print(BAC);
    lcd.begin(16,2);
}

void recieveEvent(int bytes)
{
  BAC = Wire.read();
}

void loop() {
        //if (Serial.available() > 0) {
                // read the incoming byte:
                //BAC = Serial.read();
    Wire.onReceive(recieveEvent);
                // say what you got:
               // Serial.print("I received: ");
                //Serial.println(BAC, DEC);
      //  }
    lcd.setCursor(0,0);
    lcd.print(BAC);
    digitalWrite(pin, state);
    digitalWrite(pin, state2);
    Serial.print(BAC);
    
}

void test1() {
    score += 100*BAC;
    //Serial.println("1 HIT!");
    //digitalWrite(output2,LOW);
    //Serial.println(score);
    //delay(500);
}

void test2() {
    score += 200*BAC;
    //Serial.println("2 HIT!");
    //Serial.println(score);
    //delay(500);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
