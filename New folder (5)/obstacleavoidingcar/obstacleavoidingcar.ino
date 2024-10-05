#include <ESP8266WiFi.h>

// Motor Driver Pins
const int IN1 = D1;
const int IN2 = D2;
const int IN3 = D3;
const int IN4 = D4;

// Ultrasonic Sensor Pins
const int trigPin = D5;
const int echoPin = D6;

// Variables
long duration;
int distance;

void setup() {
  // Motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(115200); // Initialize serial communication
}

void loop() {
  // Measure distance
  distance = getDistance();
  Serial.println(distance);

  if (distance < 50) {
    // If obstacle detected within 50 cm, stop and wait for 2 seconds
    stop();
    delay(2000);

    // Move backward for 1 second
    moveBackward();
    delay(1000);

    // Turn right for 500 ms
    turnRight();
    delay(500);
  } else {
    // If no obstacle, move forward
    moveForward();
  }

  delay(100);
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

int getDistance() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  return distance;
}
