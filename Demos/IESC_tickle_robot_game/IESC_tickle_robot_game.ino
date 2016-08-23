  /*
  Find the Robot's tickle spot
   By: 
   Sruti Chigullapalli 
   Shammi Jayaraj
   Romana Flores
   Oliver Chen
   Dustin Bryers
   10/27/2014. 
 
  Objective: Blink led based on touch sensor 

 Digital Input: touch sensor 
 Digital Output: LED blinking rapidly
 LCD prints: "Ha  ha" "Stop tickling me"
 
 
  */
 
  #include <Wire.h>   //does I2C
  #include "rgb_lcd.h" //plug lcd into I2C below D7
  
  const int playingGame=0; // Change 0 to 1 to unlock hidden game
  
  // digital input
  const int touchPin1=A2;
  const int touchPin2=A3;

 
  //digital output
  const int ledPin1=3;
  const int ledPin2=4;

  //use pwm pins 3,5,6,9,10,11
  int buzzerPin=6;
    
  
  //Servo groveServo; //create a object
  rgb_lcd lcd;
  // set background color of lcd any integer 0-255
  int red= 255;
  int green= 255;
  int blue= 255;
  
  /* 
  // useful commands for lcd
  lcd.begin(numCols,numRows);// set up the LCD's number of columns and rows
  lcd.home();// go to (0,0)
  lcd.setCursor(thisRow,thisCol);// set the cursor position
  lcd.write(thisLetter);// print the letter
  lcd.setRGB(red, green, blue);//set color
  lcd.leftToRight();// go left for the next letter
  lcd.rightToLeft();// go right for the next letter
  */
  
  char dtaUart[15];
  char dtaLen = 0;
  
  
  const int debug=1;  //print data to serial monitor

int touchState1,touchState2;
int touchState_1_old, touchState_2_old;

  //Define game stuff
  int tickleCount = 0;
  int firstRPS = 0;
  long randNumber = 0;
  int computerThrow = 0;
  int playerThrow = 0;
  int computerScore = 0;
  int playerScore = 0;
  int playerState1, playerState2;
  
  void setup() {
    // put your setup code here, to run once:
    
  // input pins - digital read
  pinMode(touchPin1,INPUT);
  pinMode(touchPin2,INPUT);
      
   
  //output pins - digital write, pwm
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);

  pinMode(buzzerPin,OUTPUT);
    
  // RPS game
  randomSeed(100);
    
  lcd.begin(16, 2);
  lcd.print("Ready");
  lcd.setCursor(0,1);
  lcd.print("Ready");
  Serial.begin(115200);
  }
  
  void loop() {
    // turn led on using button or touch
        
         touchState1=digitalRead(touchPin1); // read input from touch sensor 1
         touchState2=digitalRead(touchPin2); // read input from touch sensor 2

         // introduce Rock Paper Scissors logic
         computerThrow = 0;
         playerThrow = 0;
         if (tickleCount > 3 && playingGame ==1) {
           if (firstRPS==0) {
             lcd.clear();
             lcd.print("Rock Paper");
             lcd.setCursor(0,1);
             lcd.print("Scissor Unlocked");
             lcd.setRGB(0, 0, 255); //green
             delay(1000);
             firstRPS=1;
             playerScore=0;
             computerScore=0;
           }

           lcd.clear();
           lcd.print("3");
           lcd.setRGB(0, 0, 255); //green
           delay(500);
           lcd.clear();
           lcd.print("3 - 2");
           lcd.setRGB(0, 0, 255); //green
           delay(500);
           lcd.clear();
           lcd.print("3 - 2 - 1");
           lcd.setRGB(0, 0, 255); //green
           delay(500);
           lcd.clear();
           lcd.print("3 - 2 - 1: throw");
           lcd.setRGB(0, 0, 255); //green
           do {
             // Set the Player 1's throw of Rock, Paper, or Scissors.
             playerState1=digitalRead(touchPin1); // read input from touch sensor 1
             playerState2=digitalRead(touchPin2); // read input from touch sensor 2

             if (playerState1 == 1 && playerState2 == 0) {
               Serial.println("Player1 = Rock\n");
               lcd.clear();
               lcd.print("Player = Rock");
               playerThrow = 1;
             }
             else if (playerState1 == 0 && playerState2 == 1) {
               Serial.println("Player1 = Paper\n");
               lcd.clear();
               lcd.print("Player = Paper");
               playerThrow = 2;
             }
             else if (playerState1 == 1 && playerState2 == 1) {
               Serial.println("Player1 = Scissors\n");
               lcd.clear();
               lcd.print("Player = Scissors");
               playerThrow = 3;
             }
           } while ( playerThrow == 0);
           // Pick random number for Computer throw
           randNumber = random(300);   
           if (randNumber < 100) {
             Serial.println("Robot = Rock\n");
             lcd.setCursor(0,1);
             lcd.print("Robot = Rock");
             computerThrow = 1;
           }
           else if (randNumber < 200) {
             Serial.println("Robot = Paper\n");
             lcd.setCursor(0,1);
             lcd.print("Robot = Paper");
             computerThrow = 2;
           }
           else {
             Serial.println("Robot = Scissors\n");
             lcd.setCursor(0,1);
             lcd.print("Robot = Scissors");
             computerThrow = 3;
           }
           delay(1000);
           // Decide who won and adjust the score.
           if ((computerThrow == 1 && playerThrow == 2) || (computerThrow == 2 && playerThrow == 3) || (computerThrow == 3 && playerThrow == 1)) {
             //Player won
             Serial.println("You won\n");
            lcd.clear();
            lcd.print("You Win");
            lcd.setRGB(0, 255, 0); //GREEN
             playerScore = playerScore + 1;
           }
           else if ((computerThrow == 1 && playerThrow == 3) || (computerThrow == 2 && playerThrow == 1) || (computerThrow == 3 && playerThrow == 2)) {
            Serial.println("I won\n");
            lcd.clear();
            lcd.print("You Lose");
            lcd.setRGB(255, 255, 0); 
            computerScore = computerScore + 1;
           }
           else {
             //Tie
             Serial.println("Tie\n");
             lcd.clear();
             lcd.print("We Tie");
           }
           delay(1000);
           if (computerScore >= 3 || playerScore >= 3) {
             firstRPS=0;
             tickleCount=0;
             lcd.clear();
             lcd.print("Tickle Me Again");
             lcd.setRGB(0, 0, 255); //green
             delay(1000);
           }
         }
         else if (touchState1==1 && touchState2==0){
             digitalWrite(ledPin1,HIGH);           
             digitalWrite(ledPin2,LOW); 
             lcd.clear();
             lcd.print("HA HA");
             lcd.setRGB(0, 0, 255); //green
             tickleCount=tickleCount+1;
           }
           else if (touchState1==0 && touchState2==1){
             digitalWrite(ledPin1,LOW);
             digitalWrite(ledPin2,HIGH);
             lcd.clear();
             lcd.print("HA HA");
             lcd.setRGB(0, 0, 255); //blue
             tickleCount=tickleCount+1;
           }
           else if (touchState1==1 && touchState2==1){
             digitalWrite(ledPin1,HIGH);
             digitalWrite(ledPin2,HIGH);
             lcd.clear();
             lcd.print("STOP Tickling me");
             lcd.setRGB(0, 255, 0); //GREEN
             tickleCount=tickleCount+1;
           }
           else if (touchState1==0 && touchState2==0){
             digitalWrite(ledPin1,LOW);
             digitalWrite(ledPin2,LOW);
             lcd.clear();
             lcd.print("I feel nothing");
             lcd.setRGB(255, 255, 0); 
          }
          delay(200);

          if (debug==1){
            //Serial.println("button state 1= "+String(buttonState1)+";  button state 2= "+String(buttonState2));
            Serial.println("touch state 1"+String(touchState1)+";  touch state 2= "+String(touchState2));
          }  
  
 /*
  if (touchState==1 && touchState!= touchStateOld){
  //write to LCD
  lcd.clear();
  lcd.print("LED is ON");
   lcd.setRGB(0, 255, 0); //green
  }
  else if(touchState==0 && touchState!= touchStateOld && buttonState==0){ 
  lcd.clear();
  lcd.print("LED is OFF"); 
  lcd.setRGB(255, 0, 50); //pink
  }
  else if (buttonState==1 && buttonState!= buttonStateOld){
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print("LED blinks"); 
  lcd.setRGB(red, green, blue); //white
  }
  else if (buttonState==0 && buttonState!= buttonStateOld && touchState==0){
   lcd.clear();
   lcd.setCursor(2,1);
   lcd.print("LED is OFF"); 
   lcd.setRGB(red, green, blue); //white
  }
   else if (buttonState==1 && touchState==1)
   {lcd.clear(); 
   lcd.print("Temp=");
  lcd.print(temperature);
  lcd.print(" oC");
    lcd.setRGB(0, 0, 255); //blue display
   }
  if (debug==1){
    Serial.println(temperature);
  }
 
 buttonState_1_old=buttonState1;
 buttonState_2_old=buttonState2;
 */
 touchState_1_old=touchState1;
 touchState_2_old=touchState2;
  }
