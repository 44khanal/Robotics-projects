
   #include <Servo.h>
    Servo myservo;
    int pos = 0;
   const int trigPinr1 = 3;
  const int echoPinr1 = 2; 
  const int trigPinr2 = 5;
  const int echoPinr2 = 4; 
  const int trigPinr3 = 7;
  const int echoPinr3 = 6; 
  long durationr1;
  int distancer1;
  long durationr2;
  int distancer2;
  long durationr3;
  int distancer3;
  void setup() {
   myservo.attach(A0); 
   pinMode(trigPinr1, OUTPUT); 
  pinMode(echoPinr1, INPUT); 
   pinMode(trigPinr2, OUTPUT); 
  pinMode(echoPinr2, INPUT); 
  pinMode(trigPinr3, OUTPUT); 
  pinMode(echoPinr3, INPUT);
 pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
  Serial.begin(115200);
  delay(500);
}
void loop() {
  
   digitalWrite(trigPinr1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinr1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinr1, LOW);
  durationr1 = pulseIn(echoPinr1, HIGH);
  distancer1= durationr1*0.034/2;
  Serial.print("Distancer1: ");
  Serial.println(distancer1);

  digitalWrite(trigPinr2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinr2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinr2, LOW);
  durationr2 = pulseIn(echoPinr2, HIGH);
  distancer2= durationr2*0.034/2;
  Serial.print("Distancer2: ");
  Serial.println(distancer2);

  digitalWrite(trigPinr3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinr3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinr3, LOW);
  durationr3 = pulseIn(echoPinr3, HIGH);
  distancer3= durationr3*0.034/2;
  Serial.print("Distancer3: ");
  Serial.println(distancer3);

   if( distancer1 <10 ) 
     {
       Serial.println("parked on 1");
        digitalWrite (8,HIGH);
         digitalWrite (9,LOW);
     }
 if( distancer1 >11 ) 
     {
       Serial.println("empty on 1");
        digitalWrite (9,HIGH);
      digitalWrite (8,LOW);
     }
 if( distancer2 <10)  
     {
       Serial.println("parked on 2");
        digitalWrite (10,HIGH); 
          digitalWrite (11,LOW);
     }  
      if( distancer2 >11)  
     {
       Serial.println("empty on 2");
        digitalWrite (11,HIGH);
          digitalWrite (10,LOW);
     } 
if( distancer3 <6) 
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
   if( distancer3 >11) //IF ONLY CENTER DETECTED
     {
  for(pos =90; pos>=90; pos-=90)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(2500);                       // waits 15ms for the servo to reach the position 
                       // waits 15ms for the servo to reach the position 
  } 
}
}
