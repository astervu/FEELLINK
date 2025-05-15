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
