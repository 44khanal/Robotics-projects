#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define SERVO_PIN 3
#define led1_pin 4
//#define led1_pin 4


MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance
Servo myServo;

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  SPI.begin();          // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522 card
  Serial.println("Place your card to the reader...");
  Serial.println();

  myServo.attach(SERVO_PIN);
  myServo.write(0); // Initial position of the servo
   
}

void loop() {
  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Show UID on serial monitor
  Serial.print("UID tag: ");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message: ");
  content.toUpperCase();
  if (content.substring(1) == "62 8C 60 51") // Change "YOUR_CARD_UID" to the UID of your card
  {
     
    Serial.println("Authorized access");
    myServo.write(90); // Rotate servo to 90 degrees
    delay(2000); // Keep the servo in position for 2 seconds
    myServo.write(0); // Return servo to initial position
  } else {
    digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(5000);                       // wait for a second
        digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);                       // wait for a second
//        digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
//        delay(5000);                       // wait for a second
//        digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
//        delay(1000);                       // wait for a second
                       
   //     digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
     //   delay(1000);                       // wait for a second
       // digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
       // delay(1000);
    Serial.println("Access denied");
  }

  delay(1000); // Add a delay to avoid spamming the RFID reader
}
