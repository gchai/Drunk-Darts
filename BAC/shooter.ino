int pin = 0;
volatile int state = LOW;
int pin2 = 1;
volatile int state2 = LOW;

void setup() {
    pinMode(pin, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(pin), blink, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pin2), blink, CHANGE);
}

void loop() {
    digitalWrite(pin, state);
    digitalWrite(pin, state2);
}

void blink() {
    state = !state;
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
