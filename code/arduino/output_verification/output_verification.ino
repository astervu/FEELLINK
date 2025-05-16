#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);


const int Triller = A4;

int ledPinnen[] = {9, 12, A5, A1, A2, A3, 13};

void setup() {
  // put your setup code here, to run once:
  
  
  B.begin(9600);
  
  pinMode(Triller, OUTPUT);

  for (int i = 0; i < 7; i++) {
      pinMode(ledPinnen[i], OUTPUT);
  }


}

void trillertijd(int pin, int duur) {
  digitalWrite(pin, HIGH);
  delay(duur);
  digitalWrite(pin, LOW);
  delay(100);
}



void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 7; i++) {
      trillertijd(ledPinnen[i], 500);
      
  }

  trillertijd(Triller, 500);

  B.println("De HC05 component werkt!");


}
