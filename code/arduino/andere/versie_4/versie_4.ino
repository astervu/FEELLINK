int potPin = A5;           
int motorPin = 6;         
bool vorigeStatus = LOW;   

const int drempel = 800;   

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void trillertijd(int pin, int duur) {
  digitalWrite(pin, HIGH);
  delay(duur);
  digitalWrite(pin, LOW);
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.println(potValue);  


  if (potValue > drempel && vorigeStatus == LOW) {
    trillertijd(motorPin, 200);
    vorigeStatus = HIGH;
  }


  if (potValue <= drempel) {
    vorigeStatus = LOW;
  }

  delay(10);
}