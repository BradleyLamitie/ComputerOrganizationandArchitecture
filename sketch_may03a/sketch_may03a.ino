/*
  Arduino Design Project

  Bradley Lamitie
 */

// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>             //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo  
               
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 boolean veritas = true;
 int count = 0;
 int angle = 0;    
 int potentio = A0;      // initialize the A0analog pin for potentiometer
 int seconds = 0;
 int minutes = 0;
 int hours = 24;
 String timeLeft = "";
void setup() {
  // set up the number of columns and rows on the LCD 
  lcd.begin(16, 2);
  Serial.begin(9600);
  // set up the switch pin as an input
  servo_test.attach(9);   // attach the signal pin of servo to pin9 of arduino

  // Print a message to the LCD.
  //lcd.print("Time Left:");
  lcd.print("CAIT SMELLS");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
}

void loop() {
 //  angle = analogRead(potentio);  // reading the potentiometer value between 0 and 1023 
 // angle = map(angle, 0, 1023, 0, 359);     // scaling the potentiometer value to angle value for servo between 0 and 180) 
 
  if(veritas){
    angle+=0;
    if (angle>=180){
      veritas = false;
    }
  }else{
    angle-=0;
    if(angle<=0){
      veritas = true;
    }
  }
  Serial.print(angle);
  servo_test.write(angle);                   //command to rotate the servo to the specified angle 
  delay(100);
  count+=1;
  if(count%10 ==0){
    if(seconds==0){
        if(minutes==0){
           if(hours==0){
              lcd.clear();
            timeLeft = "TIMES UP!!!!!"   ;  
            lcd.setCursor(0,1);
            lcd.print(timeLeft);       
           }else{
            hours--;
           minutes = 60;
           }
        }else{
          minutes--;
          seconds = 60;
        }
    }else{
          seconds--;
  
       lcd.clear();
       timeLeft ="LIKE DOG BUNS";
          //  timeLeft = String(hours) + " :" + String(minutes) + " :" + String(seconds);
            lcd.setCursor(0,0);
           // lcd.print("Time Left:");
             lcd.print(" brad smells like poo");

            lcd.setCursor(0,1);
            //lcd.print(timeLeft);  
  
    }
  } 

}
  


