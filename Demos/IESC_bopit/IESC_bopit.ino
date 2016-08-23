// LCD RGB Backlight - into I2C below D7
// Rotary Angle Sensor(potentimeter) - into A0; used for "Spin it"
// Sound Sensor - into A1; used for "Clap", adjust variable threashold value for noisy rooms
// Touch Sensor - into A2; used for new game
// Button Sensor - inot A3; used for touch it
//
// Keep doing the action for Touch, Spin or Clap as the game may randomly choose the same action more than once

#include <Wire.h>   //does I2C
#include "rgb_lcd.h" //plug lcd into I2C below D7

//Servo groveServo; //create a object
rgb_lcd lcd;
// set background color of lcd any integer 0-255
int red= 255;
int green= 255;
int blue= 255;

int count;

int random_num;

String commands [3] = {"Touch it", "Spin it", "Clap"};  

 // digital input
  const int touchPin1=A2;
  const int touchPin2=A3;
  const int pinSound = A1;               // pin of Sound Sensor
  
  int thresholdValue = 700;                 // the threshold to turn on or off the LED
 
  //digital output
  const int ledPin1=3;
  const int ledPin2=4;
  
  int touchState1,touchState2;
  int touchState_1_old, touchState_2_old;
  
  const int potentiometer = A0;                    // rotary angle sensor connect to A0


void setup() {
    // put your setup code here, to run once:
    lcd.begin(16, 2);
    
    // input pins - digital read
    //pinMode(touchPin1,INPUT);
    pinMode(touchPin2,INPUT);
        
     
    //output pins - digital write, pwm
    //pinMode(ledPin1,OUTPUT);
    pinMode(ledPin2,OUTPUT);
    pinMode(potentiometer, INPUT);
    
    Serial.begin(115200);
    
    count = 0;
}

int poll (int seconds){
  int timer = 0; 
  int oldValue = analogRead(potentiometer);;
    while (timer < seconds * 1000){
      timer++;      
      
      touchState2=digitalRead(touchPin2); // read input from touch sensor 2
      int value = analogRead(potentiometer);
      int sensorValue = analogRead(pinSound);   //read the sensorValue on Analog 0
      
      if (touchState2 == 1){
        if (random_num == 0){
          return 1;
        }
        else{
         return 0;
        }
      }
      else if (abs(value - oldValue) > 20){
        if (random_num == 1){
          return 1;
        }
        else{
          return 0;
        }
      }
      else if(sensorValue>thresholdValue){
        if (random_num == 2){
          return 1;
        }
        else{
          return 0;
        }
      } 
    }
    return 0; 
}

void loop() {
   lcd.setRGB(0,0,0);
   lcd.clear();
   random_num = random(0,3); 
   //lcd.setCursor(0,1); 
   lcd.print(commands[random_num]);
   lcd.setCursor(0,2);
   lcd.print(count);
   
   int success = poll(5);
   
   if (success){
     lcd.setRGB(0, 255, 0); //green
     count++;
   }
   else if (!success){
     lcd.setRGB(255, 0, 0); //red
     lcd.clear();
     lcd.print("Game over");
     lcd.setCursor(0,2);
     lcd.print(count);
     
     while(true){
       if (digitalRead(touchPin1)) {
         lcd.clear();
         lcd.print("New game");
         lcd.setRGB(0,0,255);
         count = 0;
         delay (1000);
         break;
       }
     }
   }
   delay (2000);

}
