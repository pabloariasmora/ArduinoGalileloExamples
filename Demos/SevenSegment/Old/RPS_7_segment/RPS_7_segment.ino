/*
7 Segment LED RPS
 This code was adapted from original made by Riley Porter
 And further adapted from the 7 Segment LED Module 2
 
 Changes:
  > Made some modifications for a common-anode 7 segment (as used on this workshop).  
  > Changed #define to const due to error/fail on galileo.
  > Cleaned up typo on some code
  > Added 2nd 7 segment logic and RPS logic
*/

//Define Output pins A1-G1 for 1st 7 Segment
const int A1 = 5;
const int B1 = 6;
const int C1 = 0;
const int D1 = 1;
const int E1 = 2;
const int F1 = 3;
const int G1 = 4;

//Define Output pins A2-G2 for 2nd 7 Segment
const int A2 = 12;
const int B2 = 13;
const int C2 = 7;
const int D2 = 8;
const int E2 = 9;
const int F2 = 10;
const int G2 = 11;

//Define Input pins for 1st Player
int button1Rock = A3;
int button1Paper = A4;
int button1Scissors = A5;

//Define Input pins for 2nd Player
int button2Rock = A2;
int button2Paper = A1;
int button2Scissors = A0;

//Define some other stuff.
long randNumber = 0;
int needPlayerThrow = 0;
int computerScore = 0;
int playerScore = 0;
int computerThrow = 0;
int playerThrow = 0;

void clr11()
{
  //Clears the 1st LED
  digitalWrite(A1, HIGH);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(E1, HIGH);
  digitalWrite(F1, HIGH);
  digitalWrite(G1, HIGH);

}

void char_A1()
{
  //Displays A on 1st LED
  digitalWrite(D1, HIGH);
  digitalWrite(E1, LOW);
  digitalWrite(F1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
}

void char_B1()
{
  //Displays B on 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, LOW);
  digitalWrite(F1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, LOW);
}

void char_C1()
{
  //Displays C on 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, LOW);
  digitalWrite(F1, LOW);
  digitalWrite(G1, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, HIGH);
}

void char_D1()
{
  //Displays D on 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, LOW);
  digitalWrite(F1, HIGH);
  digitalWrite(G1, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
}

void char_E1()
{
  //Displays E on 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, LOW);
  digitalWrite(F1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, HIGH);
}

void char_F1()
{
  //Displays F on 1st LED
  digitalWrite(D1, HIGH);
  digitalWrite(E1, LOW);
  digitalWrite(F1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, HIGH);
}


void one1()
{
  //Displays 1 on 1st LED
  digitalWrite(D1, HIGH);
  digitalWrite(E1, HIGH);
  digitalWrite(F1, HIGH);
  digitalWrite(G1, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
}

void two1()
{
  //Displays 2 on 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, LOW);
  digitalWrite(F1, HIGH);
  digitalWrite(G1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, HIGH);
}

void three1()
{
  //Displays 3 on 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, HIGH);
  digitalWrite(F1, HIGH);
  digitalWrite(G1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
}

void four1()
{
  //Displays 4 on 1st LED
  digitalWrite(D1, HIGH);
  digitalWrite(E1, HIGH);
  digitalWrite(F1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
}

void five1()
{
  //Displays 5 on 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, HIGH);
  digitalWrite(F1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, LOW);
}

void six1()
{
  //Displays 6 on 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, LOW);
  digitalWrite(F1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, LOW);
}

void seven1()
{
  //Displays 7 on 1st LED
  digitalWrite(D1, HIGH);
  digitalWrite(E1, HIGH);
  digitalWrite(F1, HIGH);
  digitalWrite(G1, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
}

void eight1()
{
  //Displays 8 on 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, LOW);
  digitalWrite(F1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
}

void nine1()
{
  //Displays 9 on 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, HIGH);
  digitalWrite(F1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
}

void zero1()
{
  //Displays 0 on 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, LOW);
  digitalWrite(F1, LOW);
  digitalWrite(G1, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
}

void clr2()
{
  //Clears the 2nd LED
  digitalWrite(A2, HIGH);
  digitalWrite(B2, HIGH);
  digitalWrite(C2, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(E2, HIGH);
  digitalWrite(F2, HIGH);
  digitalWrite(G2, HIGH);

}

void char_A2()
{
  //Displays A on the 2nd LED
  digitalWrite(D2, HIGH);
  digitalWrite(E2, LOW);
  digitalWrite(F2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(C2, LOW);
}

void char_B2()
{
  //Displays B on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, LOW);
  digitalWrite(F2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(B2, HIGH);
  digitalWrite(C2, LOW);
}

void char_C2()
{
  //Displays C on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, LOW);
  digitalWrite(F2, LOW);
  digitalWrite(G2, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(B2, HIGH);
  digitalWrite(C2, HIGH);
}

void char_D2()
{
  //Displays D on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, LOW);
  digitalWrite(F2, HIGH);
  digitalWrite(G2, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(B2, LOW);
  digitalWrite(C2, LOW);
}

void char_E2()
{
  //Displays E on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, LOW);
  digitalWrite(F2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B2, HIGH);
  digitalWrite(C2, HIGH);
}

void char_F2()
{
  //Displays F on the 2nd LED
  digitalWrite(D2, HIGH);
  digitalWrite(E2, LOW);
  digitalWrite(F2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B2, HIGH);
  digitalWrite(C2, HIGH);
}


void one2()
{
  //Displays 1 on the 2nd LED
  digitalWrite(D2, HIGH);
  digitalWrite(E2, HIGH);
  digitalWrite(F2, HIGH);
  digitalWrite(G2, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(B2, LOW);
  digitalWrite(C2, LOW);
}

void two2()
{
  //Displays 2 on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, LOW);
  digitalWrite(F2, HIGH);
  digitalWrite(G2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(C2, HIGH);
}

void three2()
{
  //Displays 3 on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, HIGH);
  digitalWrite(F2, HIGH);
  digitalWrite(G2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(C2, LOW);
}

void four2()
{
  //Displays 4 on the 2nd LED
  digitalWrite(D2, HIGH);
  digitalWrite(E2, HIGH);
  digitalWrite(F2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(B2, LOW);
  digitalWrite(C2, LOW);
}

void five2()
{
  //Displays 5 on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, HIGH);
  digitalWrite(F2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B2, HIGH);
  digitalWrite(C2, LOW);
}

void six2()
{
  //Displays 6 on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, LOW);
  digitalWrite(F2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B2, HIGH);
  digitalWrite(C2, LOW);
}

void seven2()
{
  //Displays 7 on the 2nd LED
  digitalWrite(D2, HIGH);
  digitalWrite(E2, HIGH);
  digitalWrite(F2, HIGH);
  digitalWrite(G2, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(C2, LOW);
}

void eight2()
{
  //Displays 8 on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, LOW);
  digitalWrite(F2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(C2, LOW);
}

void nine2()
{
  //Displays 9 on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, HIGH);
  digitalWrite(F2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(C2, LOW);
}

void zero2()
{
  //Displays 0 on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, LOW);
  digitalWrite(F2, LOW);
  digitalWrite(G2, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(C2, LOW);
}

void dash1()
{
  //Displays - on the 1st LED
  digitalWrite(D1, HIGH);
  digitalWrite(E1, HIGH);
  digitalWrite(F1, HIGH);
  digitalWrite(G1, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, HIGH);
}

void dash2()
{
  //Displays - on the 2nd LED
  digitalWrite(D2, HIGH);
  digitalWrite(E2, HIGH);
  digitalWrite(F2, HIGH);
  digitalWrite(G2, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(B2, HIGH);
  digitalWrite(C2, HIGH);
}

void rock1()
{
  //Displays r on the 1st LED
  digitalWrite(D1, HIGH);
  digitalWrite(E1, LOW);
  digitalWrite(F1, LOW);
  digitalWrite(G1, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, HIGH);
}

void rock2()
{
  //Displays r on the 2nd LED
  digitalWrite(D2, HIGH);
  digitalWrite(E2, LOW);
  digitalWrite(F2, LOW);
  digitalWrite(G2, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(B2, HIGH);
  digitalWrite(C2, HIGH);
}

void paper1()
{
  //Displays P on the 1st LED
  digitalWrite(D1, HIGH);
  digitalWrite(E1, LOW);
  digitalWrite(F1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, HIGH);
}

void paper2()
{
  //Displays P on the 2nd LED
  digitalWrite(D2, HIGH);
  digitalWrite(E2, LOW);
  digitalWrite(F2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(C2, HIGH);
}

void scissor1()
{
  //Displays S on the 1st LED
  digitalWrite(D1, LOW);
  digitalWrite(E1, HIGH);
  digitalWrite(F1, LOW);
  digitalWrite(G1, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, LOW);
}

void scissor2()
{
  //Displays S on the 2nd LED
  digitalWrite(D2, LOW);
  digitalWrite(E2, HIGH);
  digitalWrite(F2, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B2, HIGH);
  digitalWrite(C2, LOW);
}

void Blink_C1()
{
  //Blink C on the 1st LED 3 times
  for(int count = 0; count <3; count++) {
    char_C1();
    delay(1000);
    clr1();
    delay(1000);
  }
}

void Blink_one1()
{
  //Blink 1 on the 1st LED 3 times
  for(int count = 0; count <3; count++) {
    char_one1();
    delay(1000);
    clr1();
    delay(1000);
  }
}

void Blink_two1()
{
  //Blink 2 on the 1st LED 3 times
  for(int count = 0; count <3; count++) {
    char_two1();
    delay(1000);
    clr1();
    delay(1000);
  }
}

void Blink_dash1()
{
  //Blink - on the 1st LED 3 times
  for(int count = 0; count <3; count++) {
    dash1();
    delay(1000);
    clr1();
    delay(1000);
  }
}

void LoopDisplay()
{
  //Loop through all Chars and Numbers
  char_A1();
  char_A2();
  delay(1000);
  char_B1();
  char_B2();
  delay(1000);
  char_C1();
  char_C2();
  delay(1000);
  char_D1();
  char_D2();
  delay(1000);
  char_E1();
  char_E2();
  delay(1000);
  char_F1();
  char_F2();
  delay(1000);
  one1();
  one2();
  delay(1000);
  two1();
  two2();
  delay(1000);
  three1();
  three2();
  delay(1000);
  four1();
  four2();
  delay(1000);
  five1();
  five2();
  delay(1000);
  six1();
  six2();
  delay(1000);
  seven1();
  seven2();
  delay(1000);
  eight1();
  eight2();
  delay(1000);
  nine1();
  nine2();
  delay(1000);
  zero1();
  zero2();
  delay(1000);
  dash1();
  dash2();
  delay(1000);
  rock1();
  rock2();
  delay(1000);
  paper1();
  paper2();
  delay(1000);
  scissor1();
  scissor2();
  delay(1000);
}

void Countdown()
{
  //Loop through 3-2-1
  three1();
  three2();
  delay(1000);
  two1();
  two2();
  delay(1000);
  one1();
  one2();
  delay(1000);
  clr1();
  clr2();
}

void setup()
{
  //Setup our pins
  pinMode(A1, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(F1, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(F2, OUTPUT);
  pinMode(G2, OUTPUT);
//Disabled since digital pins 0 and 1 will be used for output  Serial.begin(9600);  //Begin serial communcation
  pinMode(button1Rock, INPUT);     
  pinMode(button1Paper, INPUT);     
  pinMode(button1Scissors, INPUT);     
  pinMode(button2Rock, INPUT);     
  pinMode(button2Paper, INPUT);     
  pinMode(button2Scissors, INPUT);   

  randomSeed(100);  
  
  LoopDisplay();
  Countdown();
  Blink_C1();
  Blink_one1();
  Blink_two1();
  Blink_dash1();
}

void loop()
{
  needPlayerThrow = 0;
  Countdown();
  // Try to pick a random number and decide if the Arduino is playing Paper, Rock, or Scissors.
  randNumber = random(300);   
  if (randNumber < 100) {
    computerThrow = 1;
  }
  else if (randNumber < 200) {
    computerThrow = 2;
  }
  else {
    computerThrow = 3;
  }
  do {
    // Set the Player's play of Rock, Paper, or Scissors.
    if (digitalRead(button1Rock) == HIGH) {
      playerThrow = 1;
      needPlayerThrow = 1;
    }
    else if (digitalRead(button1Paper) == HIGH) {
      playerThrow = 2;
      needPlayerThrow = 1;
    }
    else if (digitalRead(button1Scissors) == HIGH) {
      playerThrow = 3;
      needPlayerThrow = 1;
    }
 
    if (playerThrow != 0) {
      //Scrolling Display Player one's throw
      clr2();
      char_one1();
      delay(500);
      char_one2();
      char_equal1();
      delay(500);
      char_equal2();
      delay(500);
      if (playerThrow == 1) {
        rock1();
        delay(500);
        rock2();
      }
      else if (playerThrow == 2) {
        paper1();
        delay(500);
        paper2();
      }
      else {
        scissors(1);
        delay(500);
        scissors(2);
      }
      clr1();

      //Scrolling Display Computer/Player two's throw
      clr2();
      char_C1();
      delay(500);
      char_C2();
      char_equal1();
      delay(500);
      char_equal2();
      delay(500);
      if (computerThrow == 1) {
        rock1();
        delay(500);
        rock2();
      }
      else if (computerThrow == 2) {
        paper1();
        delay(500);
        paper2();
      }
      else {
        scissor1();
        delay(500);
        scissor2();
      }
      clr1();

      // Decide who won and adjust the score.
      if ((computerThrow == 1 && playerThrow == 2) || (computerThrow == 2 && playerThrow == 3) || (computerThrow == 3 && playerThrow == 1)) {
        //Player won
        Blink_one1();
        playerScore = playerScore + 1;
      }
      else if ((computerThrow == 1 && playerThrow == 3) || (computerThrow == 2 && playerThrow == 1) || (computerThrow == 3 && playerThrow == 2)) {
        //Compute won
        Blink_C1();
        computerScore = computerScore + 1;
      }
      else {
        //Tie
        Blink_dash1();
      }
    }
  } while ( needPlayerThrow == 0);
 }
