void loop() {
    

//  code die enkel gebeurd als de switch werkt
    if(digitalRead(SwitchPin) == HIGH){
            

    // wanneer 5 emotieknoppen worden ingeduwd veranderd de staat ervan (toggle aan uit)
        if (digitalRead(ButtonPin1) == LOW) {  
            knop1 = !knop1; 
            trillertijd(Triller, 200);
            //trillertijd(Sololampje, 200);
            delay(200);
        } 

        if (digitalRead(ButtonPin2) == LOW) {  
            knop2 = !knop2;
            trillertijd(Triller, 200);
            //trillertijd(Sololampje, 200);
            delay(200);
        } 

        if (digitalRead(ButtonPin3) == LOW) {  
            knop3 = !knop3;
            trillertijd(Triller, 200);
            //trillertijd(Sololampje, 200);
            delay(200);
        } 
        
        if (digitalRead(ButtonPin4) == LOW) {  
            knop4 = !knop4;
            trillertijd(Triller, 200);
            //trillertijd(Sololampje, 200);
            delay(200);
        }    

        if (digitalRead(ButtonPin5) == LOW) {  
            knop5 = !knop5;
            trillertijd(Triller, 200);
            //trillertijd(Sololampje, 200);
            delay(200);
        }

        if (digitalRead(ButtonPin6) == LOW) {  
            knop6 = !knop6;
            trillertijd(Triller, 200);
            //trillertijd(Sololampje, 200);
            
            delay(200);
        }

    // wanneer de knoppen aan getoggled zijn dan moet hun lampje respectievelijk branden
        digitalWrite(LedPin1, knop1);
        digitalWrite(LedPin2, knop2);
        digitalWrite(LedPin3, knop3);
        digitalWrite(LedPin4, knop4);
        digitalWrite(LedPin5, knop5);
        digitalWrite(LedPin6, knop6);
        

    // wanneer de verzend knop wordt ingeduwd worden de emoties die aan stonden doorgestuurd en worden ze terug afgezet

        if (digitalRead(ButtonPin7) == LOW) { 
            trillertijd(Triller, 500);
            
            //trillertijd(Sololampje, 100);
            //trillertijd(Sololampje, 100);

            if (knop1 == true){
                B.println("De leerling is verdrietig! -----------> Knop 1 is ingedrukt!");
                knop1 = !knop1;
            }
            if (knop2 == true){
                B.println("De leerling is boos! -----------> Knop 2 is ingedrukt!");
                knop2 = !knop2;
            }
            if (knop3 == true){
                B.println("De leerling is blij! -----------> Knop 3 is ingedrukt!");
                knop3 = !knop3;
            }
            if (knop4 == true){
                B.println("De leerling is verbaasd! -----------> Knop 4 is ingedrukt!");
                knop4 = !knop4;
            }
            if (knop5 == true){
                B.println("De leerling is verward! -----------> Knop 5 is ingedrukt!");
                knop5 = !knop5;

            }

            if (knop6 == true){
                B.println("De leerling heeft een vraag! -----------> Knop 6 is ingedrukt!");
                knop6 = !knop6;

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
         digitalWrite(LedPin5, LOW);
        
         knop1 = false;
         knop2 = false;
         knop3 = false;
         knop4 = false;
         knop5 = false;
         knop6 = false;

     }
 }