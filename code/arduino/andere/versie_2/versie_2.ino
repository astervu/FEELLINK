#include<SoftwareSerial.h>




int LedPin1 = 4; 
int PotPin = 5;
int potVal= 0;


void setup() {

    Serial.begin(9600);

    pinMode(LedPin1, OUTPUT);
}



void loop() {
    
    potVal = analogRead(PotPin);

if (potVal >= 1023) {
    digitalWrite(LedPin1, HIGH);
  } else {
    digitalWrite(LedPin1, LOW);
  }

    
}
