#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int delaytime = 200;

String msgs1[]= {"It is certain" , "It is decidedly" , "Without a" , "Yes definitely" , "You may" , "As I see", "Most likely", "Outlook good" , "Yes" , "Signs point to", "Reply hazy", "Ask again", "Better not", "Cannot predict","Concentrate","Don't count","My reply", "My sources","Outlook not","Very doubtful"};
String msgs2[] = {"","so","doubt","", "rely on it", "it, yes", "","","","yes", "try again", "later","tell you now","now","and ask again","on it", "is no" , "say no" , "so good" , "" };

void setup()
{
  lcd.begin(16, 2);
  randomSeed(analogRead(A0));
}

void loop()
{
  if(digitalRead(A2) == 1)
  {
    delay(10);
    if(digitalRead(A2) == 1)
    {
      lcd.setRGB(100, 100, 0);
     int randomNum = random(0, 20);
     lcd.clear();
     lcd.setCursor(1, 0);
     lcd.print(msgs1[randomNum]);
     lcd.setCursor(1, 1);
     lcd.print(msgs2[randomNum]);
     delay(3000);
    }
  }
  else
  {
    openning();
  }    
}

void openning()
{
  lcd.setRGB(25, 10, 25);
  lcd.setCursor(1, 0);
  lcd.print("STEM Rocks     ");
  lcd.setCursor(1, 1);
  lcd.print("Ask me +Press ");
  bouncing(15,1);
}

void bouncing(int x, int y)
{
    lcd.setCursor(x, y);
    lcd.write("O");
    delay(delaytime);
    lcd.setCursor(x, y);
    lcd.write(" ");
    delay(delaytime);
}
