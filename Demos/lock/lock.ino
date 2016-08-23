// LCD RGB Backlight - plug into I2C below D7
// Rotary angle sensor(dial) - plug into A0
// Buzzer - plug into D3

// Turn dial until lock is picked

#include <Wire.h>   //does I2C
#include "rgb_lcd.h" //plug lcd into I2C below D7
 
const int potentiometer = A0;                    // rotary angle sensor connect to A0
int speakerPin = 3;                  // Grove Buzzer connect to D3
//const int pinLed    =  ;                        // pin of led define here
  //digital output
  const int ledPin1=3;
  const int ledPin2=4;
 
  long value1 = random(10,1014); 
  
 int lowerBound = value1 - 20;
int upperBound = value1 + 20;
 
int lowerFARBound = value1 - 300;
  int upperFARBound = value1 + 300;
 
  //Servo groveServo; //create a object
  rgb_lcd lcd;
  // set background color of lcd any integer 0-255
  int red= 255;
  int green= 255;
  int blue= 255;
 
 
void setup()
{
    Serial.begin(9600);                         // set the serial communication frequency at 9600 bits per sec
    pinMode(potentiometer, INPUT);
     //output pins - digital write, pwm
    pinMode(ledPin1,OUTPUT);
    pinMode(ledPin2,OUTPUT);   
  lcd.begin(16, 2);
  lcd.print("Ready");
  lcd.setCursor(0,1);
  lcd.print("Ready");
}
 
void loop()
{
    int value = analogRead(potentiometer);
    lcd.print(value);
    delay(200); 
    lcd.clear();
    if(value < lowerFARBound || value > upperFARBound){
     lcd.setRGB(0, 0, 255);
}   else {
   lcd.setRGB(255, 255, 0);
}
    if(value >= lowerBound && value <= upperBound){
      Serial.println("success");
      lcd.setRGB(255, 0, 0); //green
      lcd.print("\nLock Picked!");
      delay(1000);                  // waits for a second     
      digitalWrite(speakerPin, HIGH);   // sets the LED on
      delayMicroseconds(3000);
      digitalWrite(speakerPin, LOW);
      value1 = random(10,1014);
      lowerBound = value1 - 20;
     upperBound = value1 + 20;
      lowerFARBound = value1 - 300;
      upperFARBound = value1 + 300;
      Serial.println(value1);                      // pirnt the value on the serial monitor screen
    }
    else{
     digitalWrite(speakerPin, LOW);    // sets the LED off
    }
}
