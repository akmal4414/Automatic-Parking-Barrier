#include <Servo.h>
Servo myServo;

const int trigPin = 2;    //ultrasonic sensor 
const int echoPin = 4;    //ultrasonic sensor 
const int greenLedPin = 3; 

const int servoSebelumDetect = 0;   
const int servoLepasDetect = 180;   

long duration;
int distance;

void setup() {
  myServo.attach(9); //servo pin 9
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLedPin, OUTPUT); 

  myServo.write(servoSebelumDetect);
  digitalWrite(greenLedPin, LOW);
  
  Serial.begin(115200);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= 30) { 
    myServo.write(servoLepasDetect);  
    digitalWrite(greenLedPin, HIGH);   
    Serial.println("Ada objek - Pagar Buka");
  } else { 
    myServo.write(servoSebelumDetect); 
    digitalWrite(greenLedPin, LOW);    
    Serial.println("Tiada objek - Pagar Tutup");
  }
  delay(100); 
}
