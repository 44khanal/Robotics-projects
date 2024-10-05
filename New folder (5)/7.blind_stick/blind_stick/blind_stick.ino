 const int BUZZER = 4;  

   const int trigPinr = 2;
  const int echoPinr = 3; 
  long durationr;
  int distancer;
  void setup() {
   
   pinMode(trigPinr, OUTPUT); 
  pinMode(echoPinr, INPUT); 
   pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  delay(2000);
}
void loop() {
  
   digitalWrite(trigPinr, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinr, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinr, LOW);
  durationr = pulseIn(echoPinr, HIGH);
  distancer= durationr*0.034/2;
  Serial.print("Distancer: ");
  Serial.println(distancer);

     if( distancer<40) //IF ONLY CENTER DETECTED
     {
       Serial.println("obstacle- near");
        digitalWrite (BUZZER,HIGH);
     }
        if( distancer>45) //IF ONLY CENTER DETECTED
     {
       Serial.println("obstacle- far");
          digitalWrite (BUZZER,LOW);
       
       
     }
}
