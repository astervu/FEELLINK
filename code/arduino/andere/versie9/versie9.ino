#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);

int ButtonPin1= 2;
int ButtonPin2= 3;
int ButtonPin3= 4;
int ButtonPin4= 5;
int ButtonPin5= 6;
int ButtonPin6= 7;


int SwitchPin = A3;

const int Triller = A4;
const int Sololampje = A5;

bool knop1 = false;
bool knop2 = false;
bool knop3 = false;
bool knop4 = false;
bool knop5 = false;



void setup() {

    B.begin(9600);
    pinMode(ButtonPin1, INPUT_PULLUP);
    pinMode(ButtonPin2, INPUT_PULLUP);
    pinMode(ButtonPin3, INPUT_PULLUP);
    pinMode(ButtonPin4, INPUT_PULLUP);
    pinMode(ButtonPin5, INPUT_PULLUP);
    pinMode(ButtonPin6, INPUT_PULLUP);

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
    if(digitalRead(SwitchPin) == HIGH){
            

    // wanneer 5 emotieknoppen worden ingeduwd veranderd de staat ervan (toggle aan uit)
        if (digitalRead(ButtonPin1) == LOW) {  
            knop1 = !knop1; 
            trillertijd(Triller, 200);
            trillertijd(Sololampje, 200);

            delay(200);
        } 

        if (digitalRead(ButtonPin2) == LOW) {  
            knop2 = !knop2;
            trillertijd(Triller, 200);
            trillertijd(Sololampje, 200);
            delay(200);
        } 

        if (digitalRead(ButtonPin3) == LOW) {  
            knop3 = !knop3;
            trillertijd(Triller, 200);
            trillertijd(Sololampje, 200);
            delay(200);
        } 
        
        if (digitalRead(ButtonPin4) == LOW) {  
            knop4 = !knop4;
            trillertijd(Triller, 200);
            trillertijd(Sololampje, 200);
            delay(200);
        }    

        if (digitalRead(ButtonPin5) == LOW) {  
            knop5 = !knop5;
            trillertijd(Triller, 200);
            trillertijd(Sololampje, 200);
            delay(200);
        }
    

    // wanneer de verzend knop wordt ingeduwd worden de emoties die aan stonden doorgestuurd en worden ze terug afgezet

        if (digitalRead(ButtonPin6) == LOW) { 
            
            digitalWrite(Triller, HIGH);
            digitalWrite(Sololampje, HIGH);

            delay(100);

            digitalWrite(Sololampje, LOW);

            delay(100);
            
            digitalWrite(Sololampje, HIGH);
            delay(100);
            digitalWrite(Sololampje, LOW);

            delay(200);
            digitalWrite(Triller, LOW);


            if (knop1 == true){
                B.println("Knop 1 is ingedrukt!");
                knop1 = !knop1;
            }
            if (knop2 == true){
                B.println("Knop 2 is ingedrukt!");
                knop2 = !knop2;
            }
            if (knop3 == true){
                B.println("Knop 3 is ingedrukt!");
                knop3 = !knop3;
            }
            if (knop4 == true){
                B.println("Knop 4 is ingedrukt!");
                knop4 = !knop4;
            }
            if (knop5 == true){
                B.println("Knop 5 is ingedrukt!");
                knop5 = !knop5;

            }
            
            B.println("Emoties verzonden!");
            delay(200);
        }
        
    }

    if(digitalRead(SwitchPin) == LOW){
        
        knop1 = false;
        knop2 = false;
        knop3 = false;
        knop4 = false;
        knop5 = false;

    }
}

