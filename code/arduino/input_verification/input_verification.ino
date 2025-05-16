
int knopPinnen[] = {2, 3, 8, 5, 6, 7, 4};
int SwitchPin = A6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
        pinMode(knopPinnen[i], INPUT_PULLUP);
    }
  
  pinMode(SwitchPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 7; i++) {
    if (digitalRead(knopPinnen[i]) == LOW) {
        Serial.print("knop ");
        Serial.print(i+1);
        Serial.println(" is ingedrukt!");
        delay(100);

    }
  }
  if(digitalRead(SwitchPin) == HIGH){
    Serial.println("Switch staat aan!");
    delay(100);

  }
}
