
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

const char* boodschappen[] = {
  "De leerling is verdrietig!",
  "De leerling is boos!",
  "De leerling is blij!",
  "De leerling is verbaasd!",
  "De leerling is verward!",
  "De leerling heeft een vraag!"
};



void setup() {

    B.begin(9600);
    
    for (int i = 0; i < 6; i++) {
        pinMode(knopPinnen[i], INPUT_PULLUP);
        pinMode(ledPinnen[i], OUTPUT);
    }

    pinMode(ButtonPin7, INPUT_PULLUP);

    pinMode(SwitchPin, INPUT);
    pinMode(Triller, OUTPUT);
    pinMode(Sololampje, OUTPUT);

}


void trillertijd(int pin, int duur) {
  digitalWrite(pin, HIGH);
  delay(duur);
  digitalWrite(pin, LOW);
}



void loop() {
    

//  code die enkel gebeurd als de switch werkt
    //if(digitalRead(SwitchPin) == HIGH){
            

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


            for (int i = 0; i < 6; i++) {
                if (*knoppen[i] == true) {
                    B.print(boodschappen[i]);
                    B.print(" -----------> Knop ");
                    B.print(i + 1);
                    B.println(" is ingedrukt!");
                    *knoppen[i] = !*knoppen[i];
                }
            }


            B.println("Emoties verzonden!");
            delay(200);
        }
        
    }