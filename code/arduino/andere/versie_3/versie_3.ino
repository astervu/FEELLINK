#include<SoftwareSerial.h>




int LedPin1 = 4; 
int SwitchPin = 3;



void setup() {

    Serial.begin(9600);


    pinMode(SwitchPin, INPUT);
    pinMode(LedPin1, OUTPUT);
}



void loop() {
    

    if(digitalRead(SwitchPin) == HIGH){
        digitalWrite(LedPin1, HIGH);

    }
    
    if(digitalRead(SwitchPin) == LOW){
        digitalWrite(LedPin1, LOW);
 
    }
}