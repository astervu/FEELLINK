# Feellink code
## code alles wa tesamen

```cpp

#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);

int ButtonPin1= 2;
int ButtonPin2= 3;
int ButtonPin3= 4;
int ButtonPin4= 5;
int ButtonPin5= 6;
int ButtonPin6= 7;

int LedPin1 = A1;
int LedPin2 = 8;
int LedPin3 = 9;
int LedPin4 = 12;
int LedPin5 = 13;

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

    pinMode(LedPin1, OUTPUT);
    pinMode(LedPin2, OUTPUT);
    pinMode(LedPin3, OUTPUT);
    pinMode(LedPin4, OUTPUT);
    pinMode(LedPin5, OUTPUT);
}


void trillertijd(int pin, int duur) {
  digitalWrite(pin, HIGH);
  delay(duur);
  digitalWrite(pin, LOW);
}



void loop() {
    
    //digitalWrite(Triller, LOW);   //Startstand triller = low

//  code die enkel gebeurd als de switch werkt
    if(digitalRead(SwitchPin) == HIGH){
            

    // wanneer 5 emotieknoppen worden ingeduwd veranderd de staat ervan (toggle aan uit)
        if (digitalRead(ButtonPin1) == LOW) {  
            knop1 = !knop1; 
            trillertijd(Triller, 200);
            //trillertijd(Sololampje, 200);
            //B.println("Knop 1 is ingedrukt!");
            delay(200);
        } 

        if (digitalRead(ButtonPin2) == LOW) {  
            knop2 = !knop2;
            trillertijd(Triller, 200);
            //trillertijd(Sololampje, 200);
            //B.println("Knop 2 is ingedrukt!");
            delay(200);
        } 

        if (digitalRead(ButtonPin3) == LOW) {  
            knop3 = !knop3;
            trillertijd(Triller, 200);
            //trillertijd(Sololampje, 200);
            //B.println("Knop 3 is ingedrukt!");
            delay(200);
        } 
        
        if (digitalRead(ButtonPin4) == LOW) {  
            knop4 = !knop4;
            trillertijd(Triller, 200);
            //trillertijd(Sololampje, 200);
            //B.println("Knop 4 is ingedrukt!");
            delay(200);
        }    

        if (digitalRead(ButtonPin5) == LOW) {  
            knop5 = !knop5;
            trillertijd(Triller, 200);
            //trillertijd(Sololampje, 200);
            //B.println("Knop 5 is ingedrukt!");
            delay(200);
        }
    // wanneer de knoppen aan getoggled zijn dan moet hun lampje respectievelijk branden
        digitalWrite(LedPin1, knop1);
        digitalWrite(LedPin2, knop2);
        digitalWrite(LedPin3, knop3);
        digitalWrite(LedPin4, knop4);
        digitalWrite(LedPin5, knop5);
        

    // wanneer de verzend knop wordt ingeduwd worden de emoties die aan stonden doorgestuurd en worden ze terug afgezet

        if (digitalRead(ButtonPin6) == LOW) { 
            trillertijd(Triller, 500);
            
            //trillertijd(Sololampje, 100);
            //trillertijd(Sololampje, 100);

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
        digitalWrite(LedPin1, LOW);
        digitalWrite(LedPin2, LOW);
        digitalWrite(LedPin3, LOW);
        digitalWrite(LedPin4, LOW);
        digitalWrite(LedPin5, LOW);
        
        knop1 = false;
        knop2 = false;
        knop3 = false;
        knop4 = false;
        knop5 = false;

    }
}
```
## code geen feedback

```cpp


#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);

int ButtonPin1= 2;
int ButtonPin2= 3;
int ButtonPin3= 4;
int ButtonPin4= 5;
int ButtonPin5= 6;
int ButtonPin6= 7;


int SwitchPin = A3;


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


}



void loop() {

//  code die enkel gebeurd als de switch werkt
    if(digitalRead(SwitchPin) == HIGH){
            

    // wanneer 5 emotieknoppen worden ingeduwd veranderd de staat ervan (toggle aan uit)
        if (digitalRead(ButtonPin1) == LOW) {  
            knop1 = !knop1; 
            delay(200);
        } 

        if (digitalRead(ButtonPin2) == LOW) {  
            knop2 = !knop2;
            delay(200);
        } 

        if (digitalRead(ButtonPin3) == LOW) {  
            knop3 = !knop3;
            delay(200);
        } 
        
        if (digitalRead(ButtonPin4) == LOW) {  
            knop4 = !knop4;
            delay(200);
        }    

        if (digitalRead(ButtonPin5) == LOW) {  
            knop5 = !knop5;
            delay(200);
        }
    

    // wanneer de verzend knop wordt ingeduwd worden de emoties die aan stonden doorgestuurd en worden ze terug afgezet

        if (digitalRead(ButtonPin6) == LOW) { 
            

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

```



## code Sololedje + triller

```cpp


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



```


## code alle ledjes per emotieknop + triller
```cpp

#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);

int ButtonPin1= 2;
int ButtonPin2= 3;
int ButtonPin3= 4;
int ButtonPin4= 5;
int ButtonPin5= 6;
int ButtonPin6= 7;

int LedPin1 = A1;
int LedPin2 = 8;
int LedPin3 = 9;
int LedPin4 = 12;
int LedPin5 = 13;

int SwitchPin = A3;

const int Triller = A4;

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

    pinMode(LedPin1, OUTPUT);
    pinMode(LedPin2, OUTPUT);
    pinMode(LedPin3, OUTPUT);
    pinMode(LedPin4, OUTPUT);
    pinMode(LedPin5, OUTPUT);
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
            delay(200);
        } 

        if (digitalRead(ButtonPin2) == LOW) {  
            knop2 = !knop2;
            trillertijd(Triller, 200);
            delay(200);
        } 

        if (digitalRead(ButtonPin3) == LOW) {  
            knop3 = !knop3;
            trillertijd(Triller, 200);
            delay(200);
        } 
        
        if (digitalRead(ButtonPin4) == LOW) {  
            knop4 = !knop4;
            trillertijd(Triller, 200);
            delay(200);
        }    

        if (digitalRead(ButtonPin5) == LOW) {  
            knop5 = !knop5;
            trillertijd(Triller, 200);
            delay(200);
        }
    // wanneer de knoppen aan getoggled zijn dan moet hun lampje respectievelijk branden
        digitalWrite(LedPin1, knop1);
        digitalWrite(LedPin2, knop2);
        digitalWrite(LedPin3, knop3);
        digitalWrite(LedPin4, knop4);
        digitalWrite(LedPin5, knop5);
        

    // wanneer de verzend knop wordt ingeduwd worden de emoties die aan stonden doorgestuurd en worden ze terug afgezet

        if (digitalRead(ButtonPin6) == LOW) { 
            trillertijd(Triller, 500);
            

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
        digitalWrite(LedPin1, LOW);
        digitalWrite(LedPin2, LOW);
        digitalWrite(LedPin3, LOW);
        digitalWrite(LedPin4, LOW);
        digitalWrite(LedPin5, LOW);
        
        knop1 = false;
        knop2 = false;
        knop3 = false;
        knop4 = false;
        knop5 = false;

    }
}

```


## code 1 ledje (pinkt 1 maal bij emotieknop, 2 maal verzendknop

```cpp


#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);

int ButtonPin1= 2;
int ButtonPin2= 3;
int ButtonPin3= 4;
int ButtonPin4= 5;
int ButtonPin5= 6;
int ButtonPin6= 7;


int SwitchPin = A3;


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

    pinMode(Sololampje, OUTPUT);


}


void trillertijd(int pin, int duur) {
  digitalWrite(pin, HIGH);
  delay(duur);
  digitalWrite(pin, LOW);
}



void loop() {
    
    //digitalWrite(Triller, LOW);   //Startstand triller = low

//  code die enkel gebeurd als de switch werkt
    if(digitalRead(SwitchPin) == HIGH){
            

    // wanneer 5 emotieknoppen worden ingeduwd veranderd de staat ervan (toggle aan uit)
        if (digitalRead(ButtonPin1) == LOW) {  
            knop1 = !knop1; 
            trillertijd(Sololampje, 200);
            
            delay(200);
        } 

        if (digitalRead(ButtonPin2) == LOW) {  
            knop2 = !knop2;
            trillertijd(Sololampje, 200);
            delay(200);
        } 

        if (digitalRead(ButtonPin3) == LOW) {  
            knop3 = !knop3;
            trillertijd(Sololampje, 200);
            delay(200);
        } 
        
        if (digitalRead(ButtonPin4) == LOW) {  
            knop4 = !knop4;
            trillertijd(Sololampje, 200);
            delay(200);
        }    

        if (digitalRead(ButtonPin5) == LOW) {  
            knop5 = !knop5;
            trillertijd(Sololampje, 200);
            delay(200);
        }
    
        

    // wanneer de verzend knop wordt ingeduwd worden de emoties die aan stonden doorgestuurd en worden ze terug afgezet

        if (digitalRead(ButtonPin6) == LOW) { 
            
            trillertijd(Sololampje, 100);
            delay(100);
            trillertijd(Sololampje, 100);

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


```

## code triller bij emotieknop, langer trillern bij verzendknop

```cpp

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


}


void trillertijd(int pin, int duur) {
  digitalWrite(pin, HIGH);
  delay(duur);
  digitalWrite(pin, LOW);
}



void loop() {
    
    //digitalWrite(Triller, LOW);   //Startstand triller = low

//  code die enkel gebeurd als de switch werkt
    if(digitalRead(SwitchPin) == HIGH){
            

    // wanneer 5 emotieknoppen worden ingeduwd veranderd de staat ervan (toggle aan uit)
        if (digitalRead(ButtonPin1) == LOW) {  
            knop1 = !knop1; 
            trillertijd(Triller, 200);
            
            delay(200);
        } 

        if (digitalRead(ButtonPin2) == LOW) {  
            knop2 = !knop2;
            trillertijd(Triller, 200);
            delay(200);
        } 

        if (digitalRead(ButtonPin3) == LOW) {  
            knop3 = !knop3;
            trillertijd(Triller, 200);
            delay(200);
        } 
        
        if (digitalRead(ButtonPin4) == LOW) {  
            knop4 = !knop4;
            trillertijd(Triller, 200);
            delay(200);
        }    

        if (digitalRead(ButtonPin5) == LOW) {  
            knop5 = !knop5;
            trillertijd(Triller, 200);
            delay(200);
        }

        

    // wanneer de verzend knop wordt ingeduwd worden de emoties die aan stonden doorgestuurd en worden ze terug afgezet

        if (digitalRead(ButtonPin6) == LOW) { 
            trillertijd(Triller, 500);
            
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
```

## code versie 5 - on off switch - ledjes bij elke emotieknop

```cpp

#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);

int ButtonPin1= 2;
int ButtonPin2= 3;
int ButtonPin3= 4;
int ButtonPin4= 5;
int ButtonPin5= 6;
int ButtonPin6= 7;

int LedPin1 = A1;
int LedPin2 = 8;
int LedPin3 = 9;
int LedPin4 = 12;
int LedPin5 = 13;

int SwitchPin = A3;

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

    pinMode(LedPin1, OUTPUT);
    pinMode(LedPin2, OUTPUT);
    pinMode(LedPin3, OUTPUT);
    pinMode(LedPin4, OUTPUT);
    pinMode(LedPin5, OUTPUT);
}


void loop() {
//  code die enkel gebeurd als de switch werkt
    if(digitalRead(SwitchPin) == HIGH){
            

    // wanneer 5 emotieknoppen worden ingeduwd veranderd de staat ervan (toggle aan uit)
        if (digitalRead(ButtonPin1) == LOW) {  
            knop1 = !knop1; 
            //B.println("Knop 1 is ingedrukt!");
            delay(200);
        } 

        if (digitalRead(ButtonPin2) == LOW) {  
            knop2 = !knop2;
            //B.println("Knop 2 is ingedrukt!");
            delay(200);
        } 

        if (digitalRead(ButtonPin3) == LOW) {  
            knop3 = !knop3;
            //B.println("Knop 3 is ingedrukt!");
            delay(200);
        } 
        
        if (digitalRead(ButtonPin4) == LOW) {  
            knop4 = !knop4;
            //B.println("Knop 4 is ingedrukt!");
            delay(200);
        }    

        if (digitalRead(ButtonPin5) == LOW) {  
            knop5 = !knop5;
            //B.println("Knop 5 is ingedrukt!");
            delay(200);
        }
    // wanneer de knoppen aan getoggled zijn dan moet hun lampje respectievelijk branden
        digitalWrite(LedPin1, knop1);
        digitalWrite(LedPin2, knop2);
        digitalWrite(LedPin3, knop3);
        digitalWrite(LedPin4, knop4);
        digitalWrite(LedPin5, knop5);
        

    // wanneer de verzend knop wordt ingeduwd worden de emoties die aan stonden doorgestuurd en worden ze terug afgezet

        if (digitalRead(ButtonPin6) == LOW) {  
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
        digitalWrite(LedPin1, LOW);
        digitalWrite(LedPin2, LOW);
        digitalWrite(LedPin3, LOW);
        digitalWrite(LedPin4, LOW);
        digitalWrite(LedPin5, LOW);
        knop1 = false;
        knop2 = false;
        knop3 = false;
        knop4 = false;
        knop5 = false;

    }
}

```

![image](https://github.com/user-attachments/assets/059161e5-ec04-4d3d-a69c-846aad740aa5)


## code versie 4 (test of switch werkt)

```cpp

#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);

int ButtonPin1= 2;
int ButtonPin2= 3;
int ButtonPin3= 4;
int ButtonPin4= 5;
int ButtonPin5= 6;
int ButtonPin6= 7;

int LedPin1 = A1;
int LedPin2 = 8;
int LedPin3 = 9;
int LedPin4 = 12;
int LedPin5 = 13;

int SwitchPin = A3;

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

    pinMode(LedPin1, OUTPUT);
    pinMode(LedPin2, OUTPUT);
    pinMode(LedPin3, OUTPUT);
    pinMode(LedPin4, OUTPUT);
    pinMode(LedPin5, OUTPUT);
}


void loop() {
//  code die kijkt of de switch werkt
    if(digitalRead(SwitchPin) == HIGH){
        B.println("AAN");
        delay(200);
    }

// wanneer 5 emotieknoppen worden ingeduwd veranderd de staat ervan (toggle aan uit)
    if (digitalRead(ButtonPin1) == LOW) {  
        knop1 = !knop1; 
        //B.println("Knop 1 is ingedrukt!");
        delay(200);
    } 

    if (digitalRead(ButtonPin2) == LOW) {  
        knop2 = !knop2;
        //B.println("Knop 2 is ingedrukt!");
        delay(200);
    } 

    if (digitalRead(ButtonPin3) == LOW) {  
        knop3 = !knop3;
        //B.println("Knop 3 is ingedrukt!");
        delay(200);
    } 
    
    if (digitalRead(ButtonPin4) == LOW) {  
        knop4 = !knop4;
        //B.println("Knop 4 is ingedrukt!");
        delay(200);
    }    

    if (digitalRead(ButtonPin5) == LOW) {  
        knop5 = !knop5;
        //B.println("Knop 5 is ingedrukt!");
        delay(200);
    }
// wanneer de knoppen aan getoggled zijn dan moet hun lampje respectievelijk branden
    digitalWrite(LedPin1, knop1);
    digitalWrite(LedPin2, knop2);
    digitalWrite(LedPin3, knop3);
    digitalWrite(LedPin4, knop4);
    digitalWrite(LedPin5, knop5);
    

// wanneer de verzend knop wordt ingeduwd worden de emoties die aan stonden doorgestuurd en worden ze terug afgezet

    if (digitalRead(ButtonPin6) == LOW) {  
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

```

## code versie 3

```cpp

#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);

int ButtonPin1= 2;
int ButtonPin2= 3;
int ButtonPin3= 4;
int ButtonPin4= 5;
int ButtonPin5= 6;
int ButtonPin6= 7;

int LedPin1 = 1;
int LedPin2 = 8;
int LedPin3 = 9;
int LedPin4 = 12;
int LedPin5 = 13;

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

    pinMode(LedPin1, OUTPUT);
    pinMode(LedPin2, OUTPUT);
    pinMode(LedPin3, OUTPUT);
    pinMode(LedPin4, OUTPUT);
    pinMode(LedPin5, OUTPUT);
}


void loop() {

// wanneer 5 emotieknoppen worden ingeduwd veranderd de staat ervan (toggle aan uit)
    if (digitalRead(ButtonPin1) == LOW) {  
        knop1 = !knop1; 
        //B.println("Knop 1 is ingedrukt!");
        delay(200);
    } 

    if (digitalRead(ButtonPin2) == LOW) {  
        knop2 = !knop2;
        //B.println("Knop 2 is ingedrukt!");
        delay(200);
    } 

    if (digitalRead(ButtonPin3) == LOW) {  
        knop3 = !knop3;
        //B.println("Knop 3 is ingedrukt!");
        delay(200);
    } 
    
    if (digitalRead(ButtonPin4) == LOW) {  
        knop4 = !knop4;
        //B.println("Knop 4 is ingedrukt!");
        delay(200);
    }    

    if (digitalRead(ButtonPin5) == LOW) {  
        knop5 = !knop5;
        //B.println("Knop 5 is ingedrukt!");
        delay(200);
    }
// wanneer de knoppen aan getoggled zijn dan moet hun lampje respectievelijk branden
    digitalWrite(LedPin1, knop1);
    digitalWrite(LedPin2, knop2);
    digitalWrite(LedPin3, knop3);
    digitalWrite(LedPin4, knop4);
    digitalWrite(LedPin5, knop5);
    

// wanneer de verzend knop wordt ingeduwd worden de emoties die aan stonden doorgestuurd en worden ze terug afgezet

    if (digitalRead(ButtonPin6) == LOW) {  
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

```

![image](https://github.com/user-attachments/assets/0603b8f1-7da2-4674-908f-35684bef4c51)



## code versie 2

```cpp

#include<SoftwareSerial.h>

SoftwareSerial B(10, 11);

int ButtonPin1= 2;
int ButtonPin2= 3;
int ButtonPin3= 4;
int ButtonPin4= 5;
int ButtonPin5= 6;
int ButtonPin6= 7;

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

}


void loop() {


    if (digitalRead(ButtonPin1) == LOW) {  
        knop1 = !knop1; 
        //B.println("Knop 1 is ingedrukt!");
        delay(200);
    } 

    if (digitalRead(ButtonPin2) == LOW) {  
        knop2 = !knop2;
        //B.println("Knop 2 is ingedrukt!");
        delay(200);
    } 

    if (digitalRead(ButtonPin3) == LOW) {  
        knop3 = !knop3;
        //B.println("Knop 3 is ingedrukt!");
        delay(200);
    } 
    
    if (digitalRead(ButtonPin4) == LOW) {  
        knop4 = !knop4;
        //B.println("Knop 4 is ingedrukt!");
        delay(200);
    }    

    if (digitalRead(ButtonPin5) == LOW) {  
        knop5 = !knop5;
        //B.println("Knop 5 is ingedrukt!");
        delay(200);
    }

    if (digitalRead(ButtonPin6) == LOW) {  
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

```

![image](https://github.com/user-attachments/assets/be676976-23bc-4330-ac32-bebb3172485a)



## code versie 1 

```cpp

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

```

![image](https://github.com/user-attachments/assets/a9e4d760-9362-4c98-b8b4-e2c36ed57e69)

