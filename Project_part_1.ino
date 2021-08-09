#include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 5, 4, 3, 2); 


int pushButtonLeft = 7; 
int pushButtonRight = 13; 


int buttonStateLeft = 0; 
int buttonStateRight = 0; 

int contrast = 20;

int prevButtonStateLeft;
int prevButtonStateRight;

int cursor = 0;
char charByteOne[] = "00000000";
char charByteTwo[] = "00000000";

long binarySum;

int multiple = 1;


int i = 0;
int j = 0;


int l = 7;
int m = 7;
int k = 0;

int byteOneResult;
int byteTwoResult;

String stringByteOne(charByteOne);
String stringByteTwo(charByteTwo);

long longByteOne = stringByteOne.toInt();
long longByteTwo = stringByteTwo.toInt();






int screenState = 0;
//9 is contrast

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(9, OUTPUT);
  pinMode(pushButtonLeft, INPUT);
  pinMode(pushButtonRight, INPUT);
  analogWrite(9, contrast);
  
  
  
  
  

}
void getWelcome(){
  if(buttonStateLeft == LOW || buttonStateRight == LOW){
        lcd.print("Welcome User");
        delay(50);
        lcd.clear();
     }
     
     //check if button is pressed, HIGH means it's pressed
     // check to see if both buttons are pressed, if they are clear the lcd screen
     //prevent from holding down a button 
    if(buttonStateLeft != prevButtonStateLeft && buttonStateRight != prevButtonStateRight){
     if (buttonStateLeft == HIGH && buttonStateRight == HIGH) {
        screenState++;
        lcd.clear();
        
      }//prevent holding down of buttons
     prevButtonStateLeft = buttonStateLeft;
     prevButtonStateRight = buttonStateRight;
    }
}

void getContrast(){
      //if nothing is pressed keep display on loop
    if(buttonStateLeft == LOW || buttonStateRight == LOW){
      analogWrite(9, contrast);
      lcd.print("Contrast Setting");
      lcd.setCursor(0,1);
      lcd.print("Left - Right +");
      delay(50);
      lcd.clear();
     }
 
  // check to see if left button is pressed if so, decrement contrast by 5 each press
  if(buttonStateLeft != prevButtonStateLeft){
    if(buttonStateLeft == HIGH && buttonStateRight == LOW){
      contrast-=5;
      analogWrite(9, contrast);
      
      
      
    } 
    //prevent holding down of buttons
  prevButtonStateLeft = buttonStateLeft;
  }
  
  
  // check to see if Right button is pressed if so, increment contrast by 5 each press
   if(buttonStateRight != prevButtonStateRight){
    if(buttonStateLeft == LOW && buttonStateRight == HIGH){
      contrast+=5;
      analogWrite(9, contrast);
      
      
    } //prevent holding down of buttons
    prevButtonStateRight = buttonStateRight;
    } 
}
   
   void getByteOne(){
    if(buttonStateLeft == LOW || buttonStateRight == LOW){
     
      lcd.print(charByteOne);
      lcd.setCursor(cursor,0);
      lcd.blink();
      delay(50);
      lcd.clear();
    }
   
   
  //shifts cursor over by one every time the right button is pressed
  if(buttonStateRight != prevButtonStateRight){
    if(buttonStateLeft == LOW && buttonStateRight == HIGH){
     cursor = cursor + 1;
      if(cursor == 8){
        screenState++;
        
        
        
        //convert char to string
        String stringByteOne(charByteOne);
      
        
        
        //convert string to long
       longByteOne = stringByteOne.toInt();
      
        cursor = 0;
      }
      
      
    }
    prevButtonStateRight = buttonStateRight;
  }
    
    
  if(buttonStateLeft != prevButtonStateLeft){
    if(buttonStateLeft == HIGH && buttonStateRight == LOW){
      //maps cursor to a certain letter of the string and flips it from 0 to 1
     if(cursor >= i){
     charByteOne[cursor] = '1';
     
     i++;
      
     }
     
    }
    prevButtonStateLeft = buttonStateLeft;
  }
  
  
}

void getByteTwo(){
  if(buttonStateLeft == LOW || buttonStateRight == LOW){
     
      lcd.print(charByteTwo);
      lcd.setCursor(cursor,0);
      lcd.blink();
      delay(50);
      lcd.clear();
      
    }
    
  //shifts cursor over by one every time the right button is pressed
  if(buttonStateRight != prevButtonStateRight){
    if(buttonStateLeft == LOW && buttonStateRight == HIGH){
     cursor = cursor + 1;
      if(cursor == 8){
        screenState++;
        
        
       //convert char to string
        String stringByteTwo(charByteTwo);
      
       
        
        //convert string to long
       longByteTwo = stringByteTwo.toInt();
      
      //calculate sum
      binarySum = longByteOne + longByteTwo;
      
        
      }
      
      
    }
    prevButtonStateRight = buttonStateRight;
  }
    
    
  if(buttonStateLeft != prevButtonStateLeft){
    if(buttonStateLeft == HIGH && buttonStateRight == LOW){
      //maps cursor to a certain letter of the string and flips it from 0 to 1
     if(cursor >= j){
     charByteTwo[cursor] = '1';
     
     j++;
      
     }
     
    }
    prevButtonStateLeft = buttonStateLeft;
  }
}

void getSolution(){
  /*
  if(l >= 0){
    stringByteOne[l] = stringByteOne[l] % 2
    if()
    l--;
  }
  */
  if(buttonStateLeft == LOW || buttonStateRight == LOW){
    lcd.noBlink();
    lcd.setCursor(0,0);
    lcd.print("Solution");
    delay(100);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(binarySum);
  
  }
  
  
  //check if button is pressed, HIGH means it's pressed
  // check to see if both buttons are pressed, if they are clear the lcd screen
  //prevent from holding down a button 
     if (buttonStateLeft == HIGH && buttonStateRight == HIGH) {
        screenState++;
        lcd.clear();
        }
         prevButtonStateLeft = buttonStateLeft;
          prevButtonStateRight = buttonStateRight;
  
   
   }

   
void loop() {
  
  //read state of pushbutton value
  buttonStateLeft = digitalRead(pushButtonLeft);
  buttonStateRight = digitalRead(pushButtonRight);
 // Serial.print("Screen State: ");
  // Serial.println(screenState);
   
   
   //Welcome Screen
   if(screenState == 0) {
    getWelcome();
    
   }
  

  

 //Binary Byte
  if (screenState == 1){
   getByteOne();
   
  }
  
  
  if(screenState == 2){
    getByteTwo();
   
   
  }
  
  
  if(screenState == 3){
   getSolution();
  
  }
  
  //contrast
  if(screenState == 4){
    
    getContrast();
  
  }

  
}



  
  
