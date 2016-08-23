/*
Module 2 : 7 Segment LED
 This code was adapted from original made by Riley Porter
 
 Changes:
  > Made some modifications for a common-anode 7 segment (as used on this workshop).  
  > Changed #define to const due to error/fail on galileo.
  > Cleaned up typo on some code
*/

//Define Output pins A-G for 1st 7 Segment
const int led1_A = 5;
const int led1_B = 6;
const int led1_C = 0;
const int led1_D = 1;
const int led1_E = 2;
const int led1_F = 3;
const int led1_G = 4;

//Define Output pins A-G for 2nd 7 Segment
const int led2_A = 12;
const int led2_B = 13;
const int led2_C = 7;
const int led2_D = 8;
const int led2_E = 9;
const int led2_F = 10;
const int led2_G = 11;

//Define Input pins for 1st Player
int button1Rock = A3;
int button1Paper = A4;
int button1Scissors = A5;

//Define Input pins for 2nd Player
int button2Rock = A0;
int button2Paper = A1;
int button2Scissors = A2;

//Define some other stuff.
long randNumber = 0;
int player1 = 0;
int player2 = 0;
int computerScore = 0;
int playerScore = 0;
int computerThrow = 0;
int playerThrow = 0;

void clr1()
{
  //Clears the 1st LED
  digitalWrite(led1_A, HIGH);
  digitalWrite(led1_B, HIGH);
  digitalWrite(led1_C, HIGH);
  digitalWrite(led1_D, HIGH);
  digitalWrite(led1_E, HIGH);
  digitalWrite(led1_F, HIGH);
  digitalWrite(led1_G, HIGH);
  //Serial.println("clear 1st 7 Segment\n");
}

void clr2()
{
  //Clears the 2nd LED
  digitalWrite(led2_A, HIGH);
  digitalWrite(led2_B, HIGH);
  digitalWrite(led2_C, HIGH);
  digitalWrite(led2_D, HIGH);
  digitalWrite(led2_E, HIGH);
  digitalWrite(led2_F, HIGH);
  digitalWrite(led2_G, HIGH);
  //Serial.println("clear 2nd 7 Segment\n");
}

void char_A1()
{
  //Displays A on 1st 7 Segment
  digitalWrite(led1_D, HIGH);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, LOW);
  //Serial.println("A on 1st 7 Segment\n");
}

void char_A2()
{
  //Displays A on 2nd 7 Segment
  digitalWrite(led2_D, HIGH);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, LOW);
  //Serial.println("A on 2nd 7 Segment\n");
}

void char_B1()
{
  //Displays B on 1st 7 Segment
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, HIGH);
  digitalWrite(led1_B, HIGH);
  digitalWrite(led1_C, LOW);
  //Serial.println("B on 1st 7 Segment\n");
}

void char_B2()
{
  //Displays B on 2nd 7 Segment
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, HIGH);
  digitalWrite(led2_B, HIGH);
  digitalWrite(led2_C, LOW);
  //Serial.println("B on 2nd 7 Segment\n");
}

void char_C1()
{
  //Displays C on 1st 7 Segment
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, HIGH);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, HIGH);
  digitalWrite(led1_C, HIGH);
  //Serial.println("C on 1st 7 Segment\n");
}

void char_C2()
{
  //Displays C on 2nd 7 Segment
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, HIGH);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, HIGH);
  digitalWrite(led2_C, HIGH);
  //Serial.println("C on 2nd 7 Segment\n");
}

void char_D1()
{
  //Displays D on 1st 7 Segment
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, HIGH);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, HIGH);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, LOW);
  //Serial.println("D on 1st 7 Segment\n");
}

void char_D2()
{
  //Displays D on 2nd 7 Segment
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, HIGH);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, HIGH);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, LOW);
  //Serial.println("D on 2nd 7 Segment\n");
}

void char_E1()
{
  //Displays E on 1st 7 Segment
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, HIGH);
  digitalWrite(led1_C, HIGH);
  //Serial.println("E on 1st 7 Segment\n");
}

void char_E2()
{
  //Displays E on 2nd 7 Segment
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, HIGH);
  digitalWrite(led2_C, HIGH);
  //Serial.println("E on 2nd 7 Segment\n");
}

void char_F1()
{
  //Displays F on 1st 7 Segment
  digitalWrite(led1_D, HIGH);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, HIGH);
  digitalWrite(led1_C, HIGH);
  //Serial.println("F on 1st 7 Segment\n");
}

void char_F2()
{
  //Displays F on 2nd 7 Segment
  digitalWrite(led2_D, HIGH);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, HIGH);
  digitalWrite(led2_C, HIGH);
  //Serial.println("F on 2nd 7 Segment\n");
}

void one1()
{
  //Displays 1 on 1st 7 Segment
  digitalWrite(led1_D, HIGH);
  digitalWrite(led1_E, HIGH);
  digitalWrite(led1_F, HIGH);
  digitalWrite(led1_G, HIGH);
  digitalWrite(led1_A, HIGH);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, LOW);
  //Serial.println("1 on 1st 7 Segment\n");
}

void one2()
{
  //Displays 1 on 2nd 7 Segment
  digitalWrite(led2_D, HIGH);
  digitalWrite(led2_E, HIGH);
  digitalWrite(led2_F, HIGH);
  digitalWrite(led2_G, HIGH);
  digitalWrite(led2_A, HIGH);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, LOW);
  //Serial.println("1 on 2nd 7 Segment\n");
}

void two1()
{
  //Displays 2 on 1st 7 Segment
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, HIGH);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, HIGH);
  //Serial.println("2 on 1st 7 Segment\n");
}

void two2()
{
  //Displays 2 on 2nd 7 Segment
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, HIGH);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, HIGH);
  //Serial.println("2 on 2nd 7 Segment\n");
}

void three1()
{
  //Displays 3 on 1st 7 Segment
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, HIGH);
  digitalWrite(led1_F, HIGH);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, LOW);
  //Serial.println("3 on 1st 7 Segment\n");
}

void three2()
{
  //Displays 3 on 2nd 7 Segment
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, HIGH);
  digitalWrite(led2_F, HIGH);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, LOW);
  //Serial.println("3 on 2nd 7 Segment\n");
}

void four1()
{
  //Displays 4 on 1st 7 Segment
  digitalWrite(led1_D, HIGH);
  digitalWrite(led1_E, HIGH);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, HIGH);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, LOW);
  //Serial.println("4 on 1st 7 Segment\n");
}

void four2()
{
  //Displays 4 on 2nd 7 Segment
  digitalWrite(led2_D, HIGH);
  digitalWrite(led2_E, HIGH);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, HIGH);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, LOW);
  //Serial.println("4 on 2nd 7 Segment\n");
}

void five1()
{
  //Displays 5 on 1st 7 Segment
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, HIGH);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, HIGH);
  digitalWrite(led1_C, LOW);
  //Serial.println("5 on 1st 7 Segment\n");
}

void five2()
{
  //Displays 5 on 2nd 7 Segment
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, HIGH);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, HIGH);
  digitalWrite(led2_C, LOW);
  //Serial.println("5 on 2nd 7 Segment\n");
}

void six1()
{
  //Displays 6 on 1st 7 Segment
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, HIGH);
  digitalWrite(led1_C, LOW);
  //Serial.println("6 on 1st 7 Segment\n");
}

void six2()
{
  //Displays 6 on 2nd 7 Segment
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, HIGH);
  digitalWrite(led2_C, LOW);
  //Serial.println("6 on 2nd 7 Segment\n");
}

void seven1()
{
  //Displays 7 on 1st 7 Segment
  digitalWrite(led1_D, HIGH);
  digitalWrite(led1_E, HIGH);
  digitalWrite(led1_F, HIGH);
  digitalWrite(led1_G, HIGH);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, LOW);
  //Serial.println("7 on 1st 7 Segment\n");
}

void seven2()
{
  //Displays 7 on 2nd 7 Segment
  digitalWrite(led2_D, HIGH);
  digitalWrite(led2_E, HIGH);
  digitalWrite(led2_F, HIGH);
  digitalWrite(led2_G, HIGH);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, LOW);
  //Serial.println("7 on 2nd 7 Segment\n");
}

void eight1()
{
  //Displays 8 on 1st 7 Segment
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, LOW);
  //Serial.println("8 on 1st 7 Segment\n");
}

void eight2()
{
  //Displays 8 on 2nd 7 Segment
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, LOW);
  //Serial.println("8 on 2nd 7 Segment\n");
}

void nine1()
{
  //Displays 9 on 1st 7 Segment
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, HIGH);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, LOW);
  //Serial.println("9 on 1st 7 Segment\n");
}

void nine2()
{
  //Displays 9 on 2nd 7 Segment
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, HIGH);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, LOW);
  //Serial.println("9 on 2nd 7 Segment\n");
}

void zero1()
{
  //Displays 0 on 1st 7 Segment
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, HIGH);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, LOW);
  //Serial.println("0 on 1st 7 Segment\n");
}

void zero2()
{
  //Displays 0 on 2nd 7 Segment
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, HIGH);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, LOW);
  //Serial.println("0 on 2nd 7 Segment\n");
}

void dash1()
{
  //Displays - on the 1st LED
  digitalWrite(led1_D, HIGH);
  digitalWrite(led1_E, HIGH);
  digitalWrite(led1_F, HIGH);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, HIGH);
  digitalWrite(led1_B, HIGH);
  digitalWrite(led1_C, HIGH);
  //Serial.println("- on 1st 7 Segment\n");
}

void dash2()
{
  //Displays - on the 2nd LED
  digitalWrite(led2_D, HIGH);
  digitalWrite(led2_E, HIGH);
  digitalWrite(led2_F, HIGH);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, HIGH);
  digitalWrite(led2_B, HIGH);
  digitalWrite(led2_C, HIGH);
  //Serial.println("- on 2nd 7 Segment\n");
}

void rock1()
{
  //Displays r on the 1st LED
  digitalWrite(led1_D, HIGH);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, HIGH);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, HIGH);
  digitalWrite(led1_B, HIGH);
  digitalWrite(led1_C, HIGH);
  //Serial.println("r on 1st 7 Segment\n");
}

void rock2()
{
  //Displays r on the 2nd LED
  digitalWrite(led2_D, HIGH);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, HIGH);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, HIGH);
  digitalWrite(led2_B, HIGH);
  digitalWrite(led2_C, HIGH);
  //Serial.println("r on 2nd 7 Segment\n");
}

void paper1()
{
  //Displays P on the 1st LED
  digitalWrite(led1_D, HIGH);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, HIGH);
  //Serial.println("P on 1st 7 Segment\n");
}

void paper2()
{
  //Displays P on the 2nd LED
  digitalWrite(led2_D, HIGH);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, HIGH);
  //Serial.println("P on 2nd 7 Segment\n");
}

void scissor1()
{
  //Displays S on the 1st LED
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, HIGH);
  digitalWrite(led1_F, LOW);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, HIGH);
  digitalWrite(led1_C, LOW);
  //Serial.println("S on 1st 7 Segment\n");
}

void scissor2()
{
  //Displays S on the 2nd LED
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, HIGH);
  digitalWrite(led2_F, LOW);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, HIGH);
  digitalWrite(led2_C, LOW);
  //Serial.println("S on 2nd 7 Segment\n");
}

void equal1()
{
  //Displays S on the 1st LED
  digitalWrite(led1_D, LOW);
  digitalWrite(led1_E, HIGH);
  digitalWrite(led1_F, HIGH);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, HIGH);
  digitalWrite(led1_B, HIGH);
  digitalWrite(led1_C, HIGH);
  //Serial.println("= on 1st 7 Segment\n");
}

void equal2()
{
  //Displays S on the 2nd LED
  digitalWrite(led2_D, LOW);
  digitalWrite(led2_E, HIGH);
  digitalWrite(led2_F, HIGH);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, HIGH);
  digitalWrite(led2_B, HIGH);
  digitalWrite(led2_C, HIGH);
  //Serial.println("= on 2nd 7 Segment\n");
}

void question1()
{
  //Displays ? on the 1st LED
  digitalWrite(led1_D, HIGH);
  digitalWrite(led1_E, LOW);
  digitalWrite(led1_F, HIGH);
  digitalWrite(led1_G, LOW);
  digitalWrite(led1_A, LOW);
  digitalWrite(led1_B, LOW);
  digitalWrite(led1_C, HIGH);
  //Serial.println("? on 1st 7 Segment\n");
}

void question2()
{
  //Displays ? on the 2nd LED
  digitalWrite(led2_D, HIGH);
  digitalWrite(led2_E, LOW);
  digitalWrite(led2_F, HIGH);
  digitalWrite(led2_G, LOW);
  digitalWrite(led2_A, LOW);
  digitalWrite(led2_B, LOW);
  digitalWrite(led2_C, HIGH);
  //Serial.println("? on 2nd 7 Segment\n");
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

void Blink_C2()
{
  //Blink C on the 2nd LED 3 times
  for(int count = 0; count <3; count++) {
    char_C2();
    delay(1000);
    clr2();
    delay(1000);
  }
}

void Blink_one1()
{
  //Blink 1 on the 1st LED 3 times
  for(int count = 0; count <3; count++) {
    one1();
    delay(1000);
    clr1();
    delay(1000);
  }
}

void Blink_one2()
{
  //Blink 1 on the 2nd LED 3 times
  for(int count = 0; count <3; count++) {
    one2();
    delay(1000);
    clr2();
    delay(1000);
  }
}

void Blink_two1()
{
  //Blink 2 on the 1st LED 3 times
  for(int count = 0; count <3; count++) {
    two1();
    delay(1000);
    clr1();
    delay(1000);
  }
}

void Blink_two2()
{
  //Blink 2 on the 2nd LED 3 times
  for(int count = 0; count <3; count++) {
    two2();
    delay(1000);
    clr2();
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

void Blink_dash2()
{
  //Blink - on the 2nd LED 3 times
  for(int count = 0; count <3; count++) {
    dash2();
    delay(1000);
    clr2();
    delay(1000);
  }
}

void LoopDisplay()
{
  //Loop through all Chars and Numbers
  zero1();
  zero2();
  delay(100);
  one1();
  one2();
  delay(100);
  two1();
  two2();
  delay(100);
  three1();
  three2();
  delay(100);
  four1();
  four2();
  delay(100);
  five1();
  five2();
  delay(100);
  six1();
  six2();
  delay(100);
  seven1();
  seven2();
  delay(100);
  eight1();
  eight2();
  delay(100);
  nine1();
  nine2();
  delay(100);
  rock1();
  rock2();
  delay(100);
  paper1();
  paper2();
  delay(100);
  scissor1();
  scissor2();
  delay(100);
  equal1();
  equal2();
  delay(100);
  question1();
  question2();
  delay(100);
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
  delay(1000);
}

void setup()
{
  //Setup our pins
  pinMode(led1_A, OUTPUT);
  pinMode(led1_B, OUTPUT);
  pinMode(led1_C, OUTPUT);
  pinMode(led1_D, OUTPUT);
  pinMode(led1_E, OUTPUT);
  pinMode(led1_F, OUTPUT);
  pinMode(led1_G, OUTPUT);
  pinMode(led2_A, OUTPUT);
  pinMode(led2_B, OUTPUT);
  pinMode(led2_C, OUTPUT);
  pinMode(led2_D, OUTPUT);
  pinMode(led2_E, OUTPUT);
  pinMode(led2_F, OUTPUT);
  pinMode(led2_G, OUTPUT);
  pinMode(button1Rock, INPUT);     
  pinMode(button1Paper, INPUT);     
  pinMode(button1Scissors, INPUT);
  pinMode(button2Rock, INPUT);     
  pinMode(button2Paper, INPUT);     
  pinMode(button2Scissors, INPUT);
  Serial.begin(9600);  //Begin serial communcation
  
  randomSeed(100);  

  LoopDisplay();
  player1 = 0;
  player2 = 0;
  Serial.println("Press Player one rock button for one player\n");
  Serial.println("Press Player one paper button for two player\n");
  do {
    if (digitalRead(button1Rock) == LOW) {
      Serial.println("one player\n");
      player1 = 1;
    }
    else if (digitalRead(button1Paper) == LOW) {
      Serial.println("Player2 = Paper\n");
      player2 = 1;
    }
  } while ( (player1 == 0) && (player2 ==0) );
}

void loop()
{
  Serial.println("Starting loop\n");
  playerThrow = 0;
  computerThrow = 0;
  Countdown();

  if ( player2 == 1 ) {
    // Set the Player 2's play of Rock, Paper, or Scissors.
    do {
      if (digitalRead(button2Rock) == LOW) {
        Serial.println("Player2 = Rock\n");
        computerThrow = 1;
      }
      else if (digitalRead(button2Paper) == LOW) {
        Serial.println("Player2 = Paper\n");
        computerThrow = 2;
        }
      else if (digitalRead(button2Scissors) == LOW) {
        Serial.println("Player2 = Scissors\n");
        computerThrow = 3;
      }
    } while ( computerThrow == 0 );
  }
  else {
    // Try to pick a random number and decide if the Computer is playing Paper, Rock, or Scissors.
    randNumber = random(300);   
    if (randNumber < 100) {
      Serial.println("Computer = Rock\n");
      computerThrow = 1;
    }
    else if (randNumber < 200) {
      Serial.println("Computer = Paper\n");
      computerThrow = 2;
    }
    else {
      Serial.println("Computer = Scissors\n");
      computerThrow = 3;
    }
  }
  do {
    // Set the Player 1's throw of Rock, Paper, or Scissors.
    if (digitalRead(button1Rock) == LOW) {
      Serial.println("Player1 = Rock\n");
      playerThrow = 1;
    }
    else if (digitalRead(button1Paper) == LOW) {
      Serial.println("Player1 = Paper\n");
      playerThrow = 2;
    }
    else if (digitalRead(button1Scissors) == LOW) {
      Serial.println("Player1 = Scissors\n");
      playerThrow = 3;
    }
  } while ( playerThrow == 0);
  if (player2 == 0) {
    //Scrolling Display Player one's throw
    clr2();
    one1();
    delay(1000);
    one2();
    equal1();
    delay(1000);
    equal2();
    if (playerThrow == 1) {
      rock1();
      delay(1000);
      rock2();
    }
    else if (playerThrow == 2) {
      paper1();
      delay(1000);
      paper2();
    }
    else {
      scissor1();
      delay(1000);
      scissor2();
    }
    clr1();
    delay(1000);

    //Scrolling Display Computer/Player two's throw
    clr2();
    char_C1();
    delay(1000);
    char_C2();
    equal1();
    delay(1000);
    equal2();
    if (computerThrow == 1) {
      rock1();
      delay(1000);
      rock2();
    }
    else if (computerThrow == 2) {
      paper1();
      delay(1000);
      paper2();
    }
    else {
      scissor1();
      delay(1000);
      scissor2();
    }
    clr1();
    delay(1000);
    clr2();
  }
  else {
    //Displap Player 1 throw
    if (playerThrow == 1) {
      rock1();
    }
    else if (playerThrow == 2) {
      paper1();
    }
    else {
      scissor1();
    }
    //Display Player 2 throw
    if (computerThrow == 1) {
      rock2();
    }
    else if (computerThrow == 2) {
      paper2();
    }
    else {
      scissor2();
    }
    delay(1500);
    clr2();
  }
  // Decide who won and adjust the score.
  if ((computerThrow == 1 && playerThrow == 2) || (computerThrow == 2 && playerThrow == 3) || (computerThrow == 3 && playerThrow == 1)) {
    //Player won
    Serial.println("Player 1 = Won\n");
    Blink_one1();
    playerScore = playerScore + 1;
  }
  else if ((computerThrow == 1 && playerThrow == 3) || (computerThrow == 2 && playerThrow == 1) || (computerThrow == 3 && playerThrow == 2)) {
    if (player2 == 0) {
      //Compute won
      Serial.println("Computer = Won\n");
      Blink_C1();
    }
    else {
      //Compute won
      Serial.println("Player 2 = Won\n");
      Blink_two1();
    }
    computerScore = computerScore + 1;
  }
  else {
    //Tie
    Serial.println("Tie\n");
    Blink_dash1();
  }
}
