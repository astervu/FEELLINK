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



void loop() {
    

//  code die enkel gebeurd als de switch werkt
    if(digitalRead(SwitchPin) == HIGH){
            

    // wanneer 5 emotieknoppen worden ingeduwd veranderd de staat ervan (toggle aan uit)
        
        for (int i = 0; i < 6; i++) {
            if (digitalRead(knopPinnen[i]) == LOW) {
                *knoppen[i] = !*knoppen[i];
                trillertijd(Triller, 200);
                //trillertijd(Sololampje, 200);
                delay(200);
            }

    // wanneer de knoppen aan getoggled zijn dan moet hun lampje respectievelijk branden
            digitalWrite(ledPinnen[i], *knoppen[i]);
        }
        

    // wanneer de verzend knop wordt ingeduwd worden de emoties die aan stonden doorgestuurd en worden ze terug afgezet

        if (digitalRead(ButtonPin7) == LOW) { 
            trillertijd(Triller, 500);
            
            //trillertijd(Sololampje, 100);
            //trillertijd(Sololampje, 100);

            if (*knoppen[0] == true){
                B.println("De leerling is verdrietig! -----------> Knop 1 is ingedrukt!");
                *knoppen[0] = !*knoppen[0];
            }
            if (*knoppen[1] == true){
                B.println("De leerling is boos! -----------> Knop 2 is ingedrukt!");
                *knoppen[1] = !*knoppen[1];
            }
            if (*knoppen[2] == true){
                B.println("De leerling is blij! -----------> Knop 3 is ingedrukt!");
                *knoppen[2] = !*knoppen[2];
            }
            if (*knoppen[3] == true){
                B.println("De leerling is verbaasd! -----------> Knop 4 is ingedrukt!");
                *knoppen[3] = !*knoppen[3];
            }
            if (*knoppen[4] == true){
                B.println("De leerling is verward! -----------> Knop 5 is ingedrukt!");
                *knoppen[4] = !*knoppen[4];
            }

            if (*knoppen[5] == true){
                B.println("De leerling heeft een vraag! -----------> Knop 6 is ingedrukt!");
                *knoppen[5] = !*knoppen[5];

            }

            B.println("Emoties verzonden!");
            delay(200);
        }
        
    }

    if(digitalRead(SwitchPin) == LOW){
        for (int i = 0; i < 6; i++) {
                digitalWrite(ledPinnen[i], LOW);
                *knoppen[i] = false;
            }
        

    }
 }
