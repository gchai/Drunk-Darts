int pin = 13;
volatile int int2=2;
volatile int int3=3;
int output2=4;
int output3=5;
volatile int state = LOW;

void setup() {
    pinMode(output2, OUTPUT);
    pinMode(output3, OUTPUT);
    pinMode(pin, OUTPUT);
    attachInterrupt(0, hit2, RISING);
    attachInterrupt(1, hit3, RISING);
    delay(500);
}

void loop() {
digitalWrite(pin,LOW);

}

void hit2() {
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}

void hit3() {
  
}

