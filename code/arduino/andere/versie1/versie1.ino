#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);

int ButtonPin1= 2;
int ButtonPin2= 3;

void setup() {

  B.begin(9600);
  pinMode(ButtonPin1, INPUT_PULLUP);
  pinMode(ButtonPin2, INPUT_PULLUP);

}


void loop() {
    
    if (digitalRead(ButtonPin1) == LOW) {  
        
        B.println("Knop 1 is ingedrukt!");
        delay(200);
    }    
    if (digitalRead(ButtonPin2) == LOW) {  
        
        B.println("Knop 2 is ingedrukt!");
        delay(200);
    }
    
}