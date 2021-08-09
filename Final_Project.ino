#include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 5, 4, 3, 2); 


int pushButtonLeft = 7; 
int pushButtonRight = 13; 
int pushButtonTop = 6;
int pushButtonBottom = 8;

int buttonStateLeft = 0; 
int buttonStateRight = 0; 
int buttonStateTop = 0;
int buttonStateBottom = 0;

int prevButtonStateLeft;
int prevButtonStateRight;
int prevButtonStateTop;
int prevButtonStateBottom;

int contrast = 20;

int cursorVertical = 0;
int cursorHorizontal = 0;

char rowOne[] = "000000";
char rowTwo[] = "000000";

char symbols[] = { '=', '+', '-', '*', '&', '@', ' '};

char temp1;
char temp2;

int tempSpot1 = 0;
int tempSpot2 = 0;


char hiddenTop[] = {'+','*','&','@','-','='};
char hiddenBottom[] = {'@','-','=','&','*','+'};

int randNumber;

int i = 5;
int j = 0;

int screenState = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(9, OUTPUT);
  pinMode(pushButtonLeft, INPUT);
  pinMode(pushButtonRight, INPUT);
  pinMode(pushButtonTop, INPUT);
  pinMode(pushButtonBottom, INPUT);
  analogWrite(9, contrast);
  // randomSeed() will then shuffle the random function
  randomSeed(analogRead(0));
  
}

//gets the menu screen that reads the game title
void getStartMenu(){
  if(buttonStateLeft == LOW || buttonStateRight == LOW){
        lcd.print("Card Match");
        delay(50);
        lcd.clear();
     }
     
     //check if button is pressed, HIGH means it's pressed
     // check to see if both buttons are pressed, if they are clear the lcd screen and go to next screen
     //prevent from holding down a button 
    if(buttonStateBottom != prevButtonStateBottom && buttonStateRight != prevButtonStateRight){
     if (buttonStateBottom == HIGH && buttonStateRight == HIGH) {
        screenState++;
        lcd.clear();
        
      }//prevent holding down of buttons

     prevButtonStateRight = buttonStateRight;
     prevButtonStateBottom = buttonStateBottom;
    } 
    
    
}


//goes to game screen 
   void gameScreen(){
    
      lcd.print(rowOne); 
      lcd.setCursor(cursorHorizontal,cursorVertical);
      lcd.blink();
      
 
      lcd.setCursor(0,1);
      lcd.print(rowTwo);
      lcd.setCursor(cursorHorizontal,cursorVertical);
      delay(50);
      lcd.clear();
     
   
  //moves the cursor to the left
  if(buttonStateLeft != prevButtonStateLeft){
    if(buttonStateLeft == HIGH && buttonStateRight == LOW){
     cursorHorizontal = cursorHorizontal - 1;
      
      
    }
    prevButtonStateLeft = buttonStateLeft;
  }
  //moves cursor to the right
    if(buttonStateRight != prevButtonStateRight){
    if(buttonStateLeft == LOW && buttonStateRight == HIGH){
     cursorHorizontal = cursorHorizontal + 1;
      
    
      
      
    }
    prevButtonStateRight = buttonStateRight;
  }
    
    //moves the cursor up 
       if(buttonStateTop != prevButtonStateTop){
    if(buttonStateBottom == LOW && buttonStateTop == HIGH){
     cursorVertical = cursorVertical + 1;
      
    
      
      
    }
    prevButtonStateTop = buttonStateTop;
  }
  
  //States vertical bounds for the cursor
    if(cursorVertical > 1){
      cursorVertical = 1;
    }
    
  //States vertical bounds for the cursor
    if(cursorVertical < 0){
      cursorVertical = 0;
    }
  //States Horizontal bounds for the cursor
    if(cursorHorizontal == 6){
      cursorHorizontal = 5;
    }
  //States Horizontal bounds for the cursor
    if(cursorHorizontal == -1){
      cursorHorizontal = 0;
    }
    
   
  //check if button is pressed, HIGH means it's pressed
  // check to see if both buttons are pressed, if they are set the array of either rowOne or rowTwo to a random symbol 
  //prevent from holding down a button 
     if (buttonStateLeft == HIGH && buttonStateRight == HIGH) {
      
        if(cursorVertical == 0){
         delay(1000);
           // print a random number from 0 to 5
          randNumber = random(0, i);
          Serial.println(randNumber);
          rowOne[cursorHorizontal] = hiddenTop[randNumber];
          tempSpot1 = cursorHorizontal; //temp spot for top row first chosen 
         
        }
       
       
        if(cursorVertical == 1) {
          delay(1000);
           // print a random number from 0 to 5
          randNumber = random(0, i);
          rowTwo[cursorHorizontal] = hiddenBottom[randNumber];
          
          tempSpot2 = cursorHorizontal; // temp spot for bot row first chosen
       
        }
          
         if(temp1 == NULL){ // if temp 1 has no val random num from 0 - 5
            temp1 = hiddenTop[randNumber];
            Serial.print("temp1: ");
            Serial.println(temp1);
            
            
          }else if (temp1 != NULL){
            temp2 = hiddenBottom[randNumber];
            Serial.print("temp2: ");
            Serial.println(temp2);
          
          }
          
          if(temp1 == temp2){
            if(cursorVertical == 1){ //if cursor is on second row and if temp 1 is  = to temp 2, set temps back to blank as 1 point
               rowTwo[cursorHorizontal] = symbols[6]; 
               rowOne[tempSpot1] = symbols[6];
               temp1 = NULL;
               temp2 = NULL;
               
              // tempSpot1 = 0;
              // tempSpot2 = 0;
            }
            if(cursorVertical == 0){//if cursor is on first row and if temp 1 is  = to temp 2, set temps back to blank as 1 point
              rowTwo[tempSpot2] = symbols[6]; 
               rowOne[cursorHorizontal] = symbols[6];
               temp1 = NULL;
               temp2 = NULL;
               
               // tempSpot1 = 0;
                //tempSpot2 = 0;
            }
          }
          
          if(temp1 != temp2 && temp2 != NULL){
            
            if(cursorVertical == 1){ //if cursor is on second row and if temp 1 is not = to temp 2, set temps back to 0 as reset
          rowTwo[cursorHorizontal] = '0'; 
            rowOne[tempSpot1] = '0';
               temp1 = NULL;
               temp2 = NULL;
              // tempSpot1 = 0;
               // tempSpot2 = 0;
            }
            //if cursor is on first row and if temp 1 is not = to temp 2, set temps back to 0 as reset
            if(cursorVertical == 0){
             
              rowTwo[tempSpot2] = '0'; 
               rowOne[cursorHorizontal] = '0';
               temp1 = NULL;
               temp2 = NULL;
                //tempSpot1 = 0;
               // tempSpot2 = 0;
            }
          }
          //ends game
          if(rowOne[1] == symbols[6] && rowTwo[5] == symbols[6]){
            lcd.clear();
            screenState++;
            
          }            
        }
        prevButtonStateLeft = buttonStateLeft;
         prevButtonStateRight = buttonStateRight;
    
     if(buttonStateBottom != prevButtonStateBottom){
    if(buttonStateBottom == HIGH && buttonStateTop == LOW){
     cursorVertical = cursorVertical - 1;
      
    
      
      
    }
    prevButtonStateBottom = buttonStateBottom;
  }
  
 
  
}

 void gameOver(){
    
      lcd.print("You Won!"); 
      
 }
 

void loop() {
      
  //read state of pushbutton value
  buttonStateLeft = digitalRead(pushButtonLeft);
  buttonStateRight = digitalRead(pushButtonRight);
  buttonStateTop = digitalRead(pushButtonTop);
  buttonStateBottom = digitalRead(pushButtonBottom);
   
   //gets Welcome Screen
   if(screenState == 0) {
    getStartMenu();
    
   }
  
 //gets game screen
  if (screenState == 1){
   gameScreen();
   
  }
  
  if (screenState == 2){
  gameOver();
   
  }
}
