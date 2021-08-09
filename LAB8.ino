const int switchPin = 9;
 
unsigned long previousTime = 0;
 
int switchState = 0;
int prevSwitchState = 0;
 
int led = 2;
 
long interval = 3000;
 
void setup() {
  for(int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
 
  pinMode(9, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  unsigned long currentTime = millis();
 
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
   
    digitalWrite(led, HIGH);
    led++;
   
    if(led == 7){
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