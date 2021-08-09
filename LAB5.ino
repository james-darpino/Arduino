#include <Servo.h>
Servo myServo;

int angle = 0;

void setup() {
  myServo.attach(10);
  
  Serial.begin(9600);
  
}

void loop() {
 for (angle = 0; angle < 180; angle += 10) { 
  myServo.write(angle);
  delay(15);
 }
 for (angle = 180; angle > 0; angle -= 10) {
  
  myServo.write(angle);
  delay(15);
 }
 delay(5000);
}
