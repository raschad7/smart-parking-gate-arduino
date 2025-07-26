#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo gateServo;

const int trigPin = 2;
const int echoPin = 3;
const int irPin1 = 4;

int carCount = 0; // Counter for cars that have entered
bool spot1Occupied = false;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin1, INPUT);

  gateServo.attach(9); // attach the servo on pin 9
  gateServo.write(0); // initial position of gate

  lcd.init(); // initialize the lcd
  lcd.backlight(); // turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("Parking System");
  Serial.println("Parking System Initialized");
  delay(2000);
  lcd.clear();
}

void loop() {
  long duration, distance;

  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  // Check parking spot occupancy
  spot1Occupied = digitalRead(irPin1) == LOW; // assuming LOW means occupied

  updateLCD();

  if (carCount >= 5 && spot1Occupied) {
    // If car count is 5 or more and spot 1 is occupied, parking is considered full
    lcd.setCursor(0, 1);
    lcd.print("Parking is Full");
    Serial.println("Parking Full. Gate not opening.");
  } else if (distance < 20 && !spot1Occupied) { // if a car is detected within 20 cm and spot 1 is not full
    Serial.println("Car detected");
    openGate();
    delay(3000); // wait for car to pass
    closeGate();
    carCount++; // Increase car count only when a car enters and spot was previously not occupied
    updateLCD();
  }

  delay(1000);
}

void openGate() {
  if (!spot1Occupied && carCount < 5) {
    gateServo.write(90); // open the gate
    Serial.println("Gate opened");
    delay(1000);
  }
}

void closeGate() {
  gateServo.write(0); // close the gate
  Serial.println("Gate closed");
  delay(1000);
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cars: ");
  lcd.print(carCount);
  lcd.setCursor(0, 1);
  lcd.print("Spot 1: ");
  lcd.print(spot1Occupied ? "Occupied" : "Empty");

  // Print to Serial Monitor
  Serial.print("Cars: ");
  Serial.println(carCount);
  Serial.print("Spot 1: ");
  Serial.println(spot1Occupied ? "Occupied" : "Empty");
