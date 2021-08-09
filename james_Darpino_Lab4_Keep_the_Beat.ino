//hourglass
const int switchPin = 9;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 2000;
 
 
 
 
 
 //sound and lights
int tonePin = 8;
int blueLED = 4;
int greenLED = 5;
int yellowLED = 6;
int redLED = 7;





//servo
#include <Servo.h>
Servo myServo;
int angle = 0;



void setup() {
  //hourglass
  for(int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(9, INPUT);
  Serial.begin(9600);
  
  //sound lights
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  //servo
  myServo.attach(10);
  Serial.begin(9600);
}
 
  //plays harry potter theme song
void midi() {
  
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, LOW);
    
     tone(tonePin, 493, 284);
     
     
    digitalWrite(blueLED, HIGH);
   
     
    delay(315);
    delay(17);
    digitalWrite(blueLED, LOW);
    
    
    tone(tonePin, 659, 426);
    
    digitalWrite(redLED, HIGH);
    
    delay(474);
    delay(25);
    digitalWrite(redLED, LOW);
    
    
    tone(tonePin, 783, 141);
    digitalWrite(greenLED, HIGH);
    
    
    
    delay(157);
    delay(9);
    digitalWrite(greenLED, LOW);
    
    
    tone(tonePin, 739, 284);
    digitalWrite(blueLED, HIGH);
    
    delay(315);
    delay(17);
    digitalWrite(blueLED, LOW);
    
    
    
    tone(tonePin, 659, 569);
    digitalWrite(yellowLED, HIGH);
    
    delay(632);
    delay(34);
    digitalWrite(yellowLED, LOW);
    
    
    
    tone(tonePin, 987, 284);
    digitalWrite(blueLED, HIGH);
    
    delay(315);
    delay(17);
    digitalWrite(blueLED, LOW);
    
    
    tone(tonePin, 880, 854);
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(blueLED, HIGH);
    
    delay(949);
    delay(50);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, LOW);
    
    tone(tonePin, 739, 854);
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(blueLED, HIGH);
    delay(949);
    delay(50);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, LOW);
    
    tone(tonePin, 659, 426);
    digitalWrite(redLED, HIGH);
    
    delay(474);
    delay(25);
    digitalWrite(redLED, LOW);
    
    tone(tonePin, 783, 141);
    digitalWrite(greenLED, HIGH);
    
    delay(157);
    delay(9);
    digitalWrite(greenLED, LOW);
    
    tone(tonePin, 739, 284);
    digitalWrite(blueLED, HIGH);
    
    delay(315);
    delay(17);
    digitalWrite(blueLED, LOW);
    tone(tonePin, 622, 569);
    digitalWrite(yellowLED, HIGH);
    
    delay(632);
    delay(34);
    digitalWrite(yellowLED, LOW);
    
    tone(tonePin, 698, 284);
    digitalWrite(blueLED, HIGH);
    
    delay(315);
    delay(17);
    digitalWrite(blueLED, LOW);
    
    tone(tonePin, 493, 854);
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(blueLED, HIGH);
    delay(949);
    delay(717);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, LOW);
    
    tone(tonePin, 493, 284);
    digitalWrite(blueLED, HIGH);
    delay(315);
    delay(17);
    digitalWrite(blueLED, LOW);
    
    tone(tonePin, 659, 426);
    digitalWrite(redLED, HIGH);
    
    delay(474);
    delay(25);
    digitalWrite(redLED, LOW);
    
    
    
    tone(tonePin, 783, 141);
    digitalWrite(greenLED, HIGH);
    
    delay(157);
    delay(9);
    digitalWrite(greenLED, LOW);
    
    
    tone(tonePin, 739, 284);
    digitalWrite(blueLED, HIGH);
    
    delay(315);
    delay(17);
    digitalWrite(blueLED, LOW);
    
    tone(tonePin, 659, 569);
    digitalWrite(yellowLED, HIGH);
    
    delay(632);
    delay(34);
    digitalWrite(yellowLED, LOW);
    
    tone(tonePin, 987, 284);
    digitalWrite(blueLED, HIGH);
    
    delay(315);
    delay(17);
    digitalWrite(blueLED, LOW);
    
    tone(tonePin, 1174, 569);
    digitalWrite(yellowLED, HIGH);
    
    delay(632);
    delay(34);
    digitalWrite(yellowLED, LOW);
    
    
    tone(tonePin, 1108, 284);
    digitalWrite(blueLED, HIGH);
    
    delay(315);
    delay(17);
    digitalWrite(blueLED, LOW);
    
    
    tone(tonePin, 1046, 569);
    digitalWrite(yellowLED, HIGH);
    
    delay(632);
    delay(34);
    digitalWrite(yellowLED, LOW);
    
    tone(tonePin, 830, 284);
    delay(315);
    delay(17);
    tone(tonePin, 1046, 426);
    digitalWrite(redLED, HIGH);
    
    delay(474);
    delay(25);
    digitalWrite(redLED, LOW);
    
  
    tone(tonePin, 987, 141);
    digitalWrite(greenLED, HIGH);
    
    delay(157);
    delay(9);
    digitalWrite(greenLED, LOW);
    
    tone(tonePin, 932, 284);
    digitalWrite(blueLED, HIGH);
    
    delay(315);
    delay(17);
    digitalWrite(blueLED, LOW);
    
    tone(tonePin, 466, 569);
    digitalWrite(yellowLED, HIGH);
    
    delay(632);
    delay(34);
    digitalWrite(yellowLED, LOW);
    
    
    tone(tonePin, 783, 284);
    digitalWrite(blueLED, HIGH);
    
    delay(315);
    digitalWrite(blueLED, LOW);
    
    tone(tonePin, 493, 854);
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(blueLED, HIGH);
    
    delay(949);
    delay(717);
    
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, LOW);
  
}
void loop() {
  //hourglass
  unsigned long currentTime = millis();
 
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
   
    digitalWrite(led, HIGH);
    led++;
    delay(500);
    digitalWrite(blueLED, LOW);
    delay(500);
    digitalWrite(greenLED, LOW);
    delay(500);
    digitalWrite(yellowLED, LOW);
    delay(500);
    digitalWrite(redLED, LOW);
    
    if(led == 8){
    // Sound... Play midi
    midi();
    
    //spin servo
     for (angle = 0; angle < 180; angle += 10) { 
          myServo.write(angle);
          delay(15);
 }
     for (angle = 180; angle > 0; angle -= 10) {
  
        myServo.write(angle);
        delay(15);
 }
        delay(50000000000);
    }
    
  }
 
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
 
  if(switchState != prevSwitchState){
    for(int x = 2; x < 8; x++){
      digitalWrite(x, LOW);
    }
   
    led = 2;
    previousTime = currentTime;
  
  }
 
  prevSwitchState = switchState;
  
  
}