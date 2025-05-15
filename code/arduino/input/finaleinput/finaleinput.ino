#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);

int ButtonPin7 = 4;


int SwitchPin = A6;
const int Triller = A4;
const int Sololampje = 13;

bool knop1 = false;
bool knop2 = false;
bool knop3 = false;
bool knop4 = false;
bool knop5 = false;
bool knop6 = false;

int knopPinnen[] = {2, 3, 8, 5, 6, 7};  // ButtonPin1 t.e.m. ButtonPin6
int ledPinnen[] = {9, 12, A5, A1, A2, A3};
bool* knoppen[] = {&knop1, &knop2, &knop3, &knop4, &knop5, &knop6};


void setup() {

    B.begin(9600);
    
    for (int i = 0; i < 6; i++) {
        pinMode(knopPinnen[i], INPUT_PULLUP);
    }

    pinMode(ButtonPin7, INPUT_PULLUP);

    pinMode(SwitchPin, INPUT);
    pinMode(Triller, OUTPUT);
    pinMode(Sololampje, OUTPUT);

    for (int i = 0; i < 6; i++) {
        pinMode(ledPinnen[i], OUTPUT);
    }
}


void trillertijd(int pin, int duur) {
  digitalWrite(pin, HIGH);
  delay(duur);
  digitalWrite(pin, LOW);
}
