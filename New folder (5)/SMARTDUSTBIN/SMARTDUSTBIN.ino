  
#include <Servo.h> 
Servo myservo; 

  const int trigPinr = 9;
  const int echoPinr = 10; 
  long durationr;
  int distancer;
  int pos = 0;
  void setup() {
    
  myservo.attach(A0);  // attaches the servo on pin 9 to the servo object 
 
   
   pinMode(trigPinr, OUTPUT); 
  pinMode(echoPinr, INPUT);
  pinMode(8, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  delay(100);
}
void loop() {
  digitalWrite(8, HIGH);
  
  digitalWrite(11, LOW);
 
   
   digitalWrite(trigPinr, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinr, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinr, LOW);
  durationr = pulseIn(echoPinr, HIGH);
  distancer= durationr*0.034/2;
  Serial.print("Distancer: ");
  Serial.println(distancer);

   if( distancer <20) //IF ONLY CENTER DETECTED
     {
        
  for(pos = 0; pos <= 90; pos +=90) // goes from 0 degrees to 180 degrees 
  {  
     digitalWrite (11,HIGH);
        delay(1000);
        digitalWrite (11,LOW);   
     delay(1000);
         
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5000); 
     
  } 
     }
   if( distancer >25) //IF ONLY CENTER DETECTED
     {
  for(pos =90; pos>=90; pos-=90)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(2500);                       // waits 15ms for the servo to reach the position 
                       // waits 15ms for the servo to reach the position 
  } 
}
}
