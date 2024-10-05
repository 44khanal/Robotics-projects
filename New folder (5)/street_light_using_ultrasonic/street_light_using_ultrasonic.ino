
   #include <Servo.h>
    Servo myservo;
    int pos = 0;
   const int trigPinr1 = 4;
  const int echoPinr1 = 3; 
  const int trigPinr2 = 6;
  const int echoPinr2 = 5; 
  const int trigPinr3 =11;
  const int echoPinr3 = 12; 
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
 pinMode(7, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT); 
  Serial.begin(115200);
  delay(100);
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
       Serial.println("object on 1");
        digitalWrite (8,HIGH);
         
     }
 if( distancer1 >11 ) 
     {
       Serial.println(" no object on 1");
      digitalWrite (8,LOW);
     }
 if( distancer2 <10)  
     {
       Serial.println("object on 2");
        digitalWrite (9,HIGH);    
     }  
      if( distancer2 >11)  
     {
       Serial.println("no object on 2");
        digitalWrite (9,LOW);     
     } 
            
    if( distancer3 <10)  
     {
       Serial.println("object on 3");
        digitalWrite (10,HIGH); 
          
     }  
      if( distancer3 >11)  
     {
       Serial.println("no object on 3");
        digitalWrite (10,LOW);
          
     } 
if( distancer3 <10 && distancer1 <10 && distancer2 <10 )  
     {
       Serial.println("BUZZZZZZZEEEERRRRRRR ON");
        digitalWrite (7,HIGH); 
          
     }  
      if( distancer3 >11)  
     {
       Serial.println("BUUUUZZZZZEEEEERRRR OFF ");
        digitalWrite (7,LOW);
          
     } 
     
}
