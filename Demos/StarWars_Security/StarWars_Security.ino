// LCD RGB Backlight - into I2C below D7
// Touch sensor - into A0
// Buzzer - into D3
// 
// touch sensor triggers alarm playing star wars

// demo of Starter kit V2.0 - Grove - Light Sensor
// when the value of light sensor ledd than a certain value
// led will on, you can set this certain value via change thresholdvalue
// such as when you cover light sensor with your hand, you'll find led on

//#include <Wire.h>
#include <Servo.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

const int pinLight = A0;
const int pinButton = A1;
const int pinLed = 7;
const int pinServo = 6;

int speakerPin = 3;                  // Grove Buzzer connect to D3

int thresholdvalue=400;                 //the threshold to turn on or off the LED

int length = 17; // the number of notes
char notes[] = "cgfdeCgfdeCgfdec "; // a space represents a rest
int beats[] = { 4, 4, 1, 1, 1, 4, 4, 1, 1, 1, 4, 4, 1, 1, 1, 4, 8}; //1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2, 4 };
int tempo = 150;
boolean securityOn = true;
boolean isPress = false;
int myLoop = 0;
Servo groveServo;

void playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
        digitalWrite(speakerPin, HIGH);
        delayMicroseconds(tone);
        digitalWrite(speakerPin, LOW);
        delayMicroseconds(tone);
    }
}

void playNote(char note, int duration) {
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
    int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

    // play the tone corresponding to the note name
    for (int i = 0; i < 8; i++) {
        if (names[i] == note) {
            playTone(tones[i], duration);
        }
    }
}

void setup()
{
    pinMode(pinButton, INPUT);
    pinMode(pinLed, OUTPUT);             //set the LED on Digital 12 as an OUTPUT
    groveServo.attach(pinServo);
    pinMode(speakerPin, OUTPUT);
    lcd.begin(16,2);
    lcd.setRGB(0,0,0);
    lcd.print("Security: ON");
}

void loop()
{
    
    int sensorValue = analogRead(pinLight);    //the light sensor is attached to analog 0
    if(digitalRead(pinButton) && !isPress) 
    {
      isPress = true;
      securityOn = !securityOn;
      lcd.clear();
      lcd.print("Security:");
      if(securityOn) {
       lcd.print("ON");
      }
     else {
      lcd.print("OFF");
     }
    }
    if(!digitalRead(pinButton)) {
       isPress = false; 
    }
    if(securityOn){
        if(!isDark())
        {
          
            digitalWrite(pinLed, HIGH);
            for (int i = 0; i < length; i++) 
            {
                setRed();
                groveServo.write(random(0,100));
                if (notes[i] == ' ')
                {
                    delay(beats[i] * tempo); // rest
                }
                else
                {
                    playNote(notes[i], beats[i] * tempo);
                }
        
                // pause between notes
                delay(tempo / 2);
                if(isDark())
                {
                  break;
                }
            }        
        }
        else
        {
            setGreen();
            digitalWrite(pinLed, LOW);
        }
    }
}

boolean isDark() 
{
    int sensorValue = analogRead(pinLight);
    if(sensorValue < thresholdvalue)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

void setRed()
{
  if (myLoop == 0){                           
                lcd.setRGB(255, 0, 0);
                myLoop = 1;
  } else {
                lcd.setRGB(255, random(0,100), random(0,100));
                myLoop = 0;
  } 
}

void setGreen()
{
   lcd.setRGB(0,255,0); 
}



