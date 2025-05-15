#include<SoftwareSerial.h>

int switchPin = 3;
int motorPin = 6;
bool vorigeStatus = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void trillertijd(int pin, int duur) {
  digitalWrite(pin, HIGH);
  delay(duur);
  digitalWrite(pin, LOW);
}

void loop() {
  bool huidigeStatus = digitalRead(switchPin);


  if (huidigeStatus == HIGH && vorigeStatus == LOW) {
    trillertijd(motorPin, 200);
  }

  vorigeStatus = huidigeStatus;

  delay(10); 
}