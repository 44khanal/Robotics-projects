#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define button pins
const int button1 = 2;  // Connected to digital pin D2
const int button2 = 3;  // Connected to digital pin D3
const int button3 = 4;  // Connected to digital pin D4 (End voting and display results)

// Variables to store vote counts
int count1 = 0;
int count2 = 0;

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Initialize button pins as inputs
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  // Display initial message
  lcd.setCursor(0, 0);
  lcd.print("Choose Candidate");
}

void loop() {
  // Check for button presses and update counts
  if (digitalRead(button1) == HIGH) {
    waitForRelease(button1);
    displayMessage();
    while (digitalRead(button1) == LOW && digitalRead(button2) == LOW);
    if (digitalRead(button1) == HIGH) {
      count1++;
      waitForRelease(button1);
    }
    displayPressButton();
  } else if (digitalRead(button2) == HIGH) {
    waitForRelease(button2);
    displayMessage();
    while (digitalRead(button1) == LOW && digitalRead(button2) == LOW);
    if (digitalRead(button2) == HIGH) {
      count2++;
      waitForRelease(button2);
    }
    displayPressButton();
  } else if (digitalRead(button3) == HIGH) {
    // Display final counts
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Results:");
    lcd.setCursor(0, 1);
    lcd.print("C1:");
    lcd.print(count1);
    lcd.print(" C2:");
    lcd.print(count2);
    // Halt for 10 seconds before restarting
    delay(10000);
    resetVoting();
  }
}

void displayMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Congratulations, You Voted");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Choose C1, C2");
  delay(1000);  // Debounce delay
}

void displayPressButton() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press button");
}

void waitForRelease(int buttonPin) {
  while (digitalRead(buttonPin) == HIGH);
  delay(50); // Debounce delay
}

void resetVoting() {
  count1 = 0;
  count2 = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press button");
}
