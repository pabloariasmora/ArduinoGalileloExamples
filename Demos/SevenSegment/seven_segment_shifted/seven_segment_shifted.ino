/*
Module 2 : 7 Segment LED
 This code was adapted from original made by Riley Porter
 
 Changes:
  > Made some modifications for a common-anode 7 segment (as used on this workshop).  
  > Changed #define to const due to error/fail on galileo.
  > Cleaned up typo on some code
  > Pins shifted to pins 0-6 to allow for 2nd LED ins 7-13
*/

const int A = 5;
const int B = 6;
const int C = 0;
const int D = 1;
const int E = 2;
const int F = 3;
const int G = 4;

void clr()
{
  //Clears the LED
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

}

void char_A()
{
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
}

void char_B()
{
  //Displays B
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
}

void char_C()
{
  //Displays C
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void char_D()
{
  //Displays D
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
}

void char_E()
{
  //Displays E
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void char_F()
{
  //Displays F
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}


void one()
{
  //Displays 1
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
}

void two()
{
  //Displays 2
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
}

void three()
{
  //Displays 3
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
}

void four()
{
  //Displays 4
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
}

void five()
{
  //Displays 5
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
}

void six()
{
  //Displays 6
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
}

void seven()
{
  //Displays 7
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
}

void eight()
{
  //Displays 8
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
}

void nine()
{
  //Displays 9
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
}

void zero()
{
  //Displays 0
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
}

void LoopDisplay()
{
  //Loop through all Chars and Numbers
 
  char_A();
  Serial.println("A\n");
  delay(1000);
  char_B();
  Serial.println("B\n");
  delay(1000);
  char_C();
  Serial.println("C\n");
  delay(1000);
  char_D();
  Serial.println("D\n");
  delay(1000);
  char_E();
  Serial.println("E\n");
  delay(1000);
  char_F();
  Serial.println("F\n");
  delay(1000);
  one();
  Serial.println("1\n");
  delay(1000);
  two();
  Serial.println("2\n");
  delay(1000);
  three();
  Serial.println("3\n");
  delay(1000);
  four();
  Serial.println("4\n");
  delay(1000);
  five();
  Serial.println("5\n");
  delay(1000);
  six();
  Serial.println("6\n");
  delay(1000);
  seven();
  Serial.println("7\n");
  delay(1000);
  eight();
  Serial.println("8\n");
  delay(1000);
  nine();
  Serial.println("9\n");
  delay(1000);
  zero();
  Serial.println("0\n");
  delay(1000);

}

void setup()
{
  //Setup our pins
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  Serial.begin(9600);  //Begin serial communcation
}

void loop()
{
  Serial.println("Starting\n");
  LoopDisplay();
 }
