int moistureSensorPin=A0;
int ledPin=8;
int buzzerPin=9;
int relayPin=7;
int threshold=500;

void setup(){
   pinMode(ledPin, OUTPUT);
   pinMode(buzzerPin, OUTPUT);
   pinMode(relayPin, OUTPUT);
   Serial.begin(9600);

}
 void loop (){
  int moistureValue= analogRead(moistureSensorPin);
  Serial.println(moistureValue);

  if (moistureValue < threshold){
    digitalWrite (ledPin, HIGH);
    digitalWrite (buzzerPin, HIGH);
    digitalWrite (relayPin, HIGH);
  }
  else {
      digitalWrite (ledPin, LOW);
    digitalWrite (buzzerPin, LOW);
    digitalWrite (relayPin, LOW);
  }
  delay(1000);  // wait for 1 second
 }
