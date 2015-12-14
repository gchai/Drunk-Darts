int output2 = 4; 
int output3 = 5;
int x = 0;  // variable to be updated by the interrupt
int ledpin = 13;

void setup() {
  //enable interrupt 0 (pin 2) which is connected to a button
  //jump to the increment function on falling edge
  pinMode(ledpin,OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);  
  attachInterrupt(0, out2, FALLING);
  attachInterrupt(1, out3, FALLING);
  digitalWrite(output2, LOW);
  digitalWrite(output3, LOW);
  Serial.begin(9600);  //turn on serial communication
}

void loop() {
  digitalWrite(output2, LOW);
  digitalWrite(output3, LOW);
  digitalWrite(ledpin, LOW);
  delay(1000); //pretend to be doing something useful
  Serial.println(x, DEC); //print x to serial monitor
}

// Interrupt service routine for interrupt 0
void out2() {
    x++;
    digitalWrite(output2, HIGH);
    digitalWrite(ledpin, HIGH);
    Serial.println("2 HIT!");
    delay(500);
    //digitalWrite(output2,LOW);
}

void out3() {
    x++;
    digitalWrite(output3, HIGH);
    digitalWrite(ledpin, HIGH);
    Serial.println("3 HIT!");
    delay(500);
    //digitalWrite(output3,LOW);
}
