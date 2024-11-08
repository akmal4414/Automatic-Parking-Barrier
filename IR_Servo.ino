#include <Servo.h>
Servo myServo;

// Pin Definitions
const int irSensorPin = 2;
const int greenLedPin = 3; // Green LED pin

int irState = 0;

// Servo positions
const int servoSebelumDetect = 0;   // Gate closed position
const int servoLepasDetect = 180;   // Gate open position

void setup() {
  myServo.attach(9); // Attach servo to pin 9
  pinMode(irSensorPin, INPUT);
  pinMode(greenLedPin, OUTPUT); // Set green LED pin as output

  // Initialize the servo and LED
  myServo.write(servoSebelumDetect);
  digitalWrite(greenLedPin, LOW);
  
  Serial.begin(115200);
}

void loop() {
  irState = digitalRead(irSensorPin); // Read IR sensor state

  if (irState == LOW) { // Object detected
    myServo.write(servoLepasDetect);   // Open the gate
    digitalWrite(greenLedPin, HIGH);   // Turn on the green LED
    Serial.println("Ada objek - Pagar Buka");
  } else { // No object detected
    myServo.write(servoSebelumDetect); // Close the gate
    digitalWrite(greenLedPin, LOW);    // Turn off the green LED
    Serial.println("Tiada objek - Pagar Tutup");
  }
  delay(100); // Small delay to avoid rapid switching
}
