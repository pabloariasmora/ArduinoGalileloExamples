
// wiring setup (so we can easily reference certain pins)
int cols[8] = {6, 11, 10, 3, 17, 4, 8, 9};
int rows[8] = {2, 7, 19, 5, 13, 18, 12, 16};

//Define Input pins for Player
int button1 = 0;
int button2 = 1;
int button3 = A0;

byte col = 0;

int buttonSelection;
int button1Selection,button2Selection,button3Selection;

// A static integer matrix representing a player.
int playerpixels[8][8] = { \
  {1, 1, 1, 0, 0, 0, 0, 0}, \
  {1, 1, 1, 1, 0, 0, 0, 0}, \
  {1, 0, 0, 1, 0, 1, 1, 1}, \
  {1, 0, 0, 1, 0, 1, 1, 1}, \
  {1, 1, 1, 1, 0, 0, 0, 0}, \
  {1, 1, 1, 0, 0, 1, 1, 1}, \
  {1, 1, 0, 0, 0, 1, 1, 1}, \
  {1, 1, 0, 0, 0, 0, 0, 0} \
};

// A static integer matrix representing a computer.
int computerpixels[8][8] = { \
  {0, 1, 1, 0, 0, 0, 0, 0}, \
  {1, 1, 1, 1, 0, 0, 0, 0}, \
  {1, 0, 0, 1, 0, 1, 1, 1}, \
  {1, 0, 0, 0, 0, 1, 1, 1}, \
  {1, 0, 0, 0, 0, 0, 0, 0}, \
  {1, 0, 0, 1, 0, 1, 1, 1}, \
  {1, 1, 1, 1, 0, 1, 1, 1}, \
  {0, 1, 1, 0, 0, 0, 0, 0} \
};

// A static integer matrix representing a tie.
int ufacepixels[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 1, 1, 1, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 1, 0} \
};

// A static integer matrix representing a win.
int hfacepixels[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 1, 1, 1, 1, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0} \
};

// A static integer matrix representing a loss.
int sfacepixels[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 1, 1, 1, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0} \
};

// A static integer matrix representing a question mark.
int qpixels[8][8] = { \
  {0, 0, 1, 1, 1, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 1, 0, 0}, \
  {0, 1, 0, 0, 0, 1, 0, 0}, \
  {0, 0, 0, 0, 1, 0, 0, 0}, \
  {0, 0, 0, 1, 0, 0, 0, 0}, \
  {0, 0, 0, 1, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 1, 0, 0, 0, 0} \
};

// A static integer matrix representing a rock.
int rockpixels[8][8] = { \
  {1, 1, 1, 1, 1, 0, 0, 0}, \
  {1, 1, 0, 0, 0, 1, 0, 0}, \
  {1, 0, 1, 0, 0, 0, 1, 0}, \
  {1, 0, 0, 1, 1, 1, 1, 1}, \
  {1, 0, 0, 1, 0, 0, 0, 1}, \
  {0, 1, 0, 1, 0, 0, 0, 1}, \
  {0, 0, 1, 1, 0, 0, 0, 1}, \
  {0, 0, 0, 1, 1, 1, 1, 1} \
};

// A static integer matrix representing paper.
int paperpixels[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 1, 1, 1, 1, 1}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 1, 1, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 1, 1, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {1, 1, 1, 1, 1, 1, 0, 0} \
};

// A static integer matrix representing scissors.
int scissorspixels[8][8] = { \
  {0, 0, 1, 0, 1, 0, 0, 0}, \
  {0, 1, 1, 0, 1, 1, 0, 0}, \
  {0, 1, 1, 0, 1, 1, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 0, 0}, \
  {0, 0, 0, 1, 0, 0, 0, 0}, \
  {0, 0, 1, 1, 1, 0, 0, 0}, \
  {0, 1, 0, 1, 0, 1, 0, 0}, \
  {0, 1, 1, 0, 1, 1, 0, 0} \
};

// A static integer matrix representing scissors.
int paperpixels1[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 1, 1, 1, 1, 1}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 1, 1, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 1, 1, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {1, 1, 1, 1, 1, 1, 0, 0} \
};

// A static integer matrix representing one.
int onepixels[8][8] = { \
  {0, 0, 1, 1, 1, 0, 0, 0}, \
  {0, 1, 1, 1, 1, 0, 0, 0}, \
  {0, 1, 0, 1, 1, 0, 0, 0}, \
  {0, 0, 0, 1, 1, 0, 0, 0}, \
  {0, 0, 0, 1, 1, 0, 0, 0}, \
  {0, 0, 0, 1, 1, 0, 0, 0}, \
  {0, 0, 0, 1, 1, 0, 0, 0}, \
  {0, 0, 1, 1, 1, 1, 0, 0} \
};

// A static integer matrix representing two.
int twopixels[8][8] = { \
  {0, 0, 1, 1, 1, 1, 0, 0}, \
  {0, 1, 1, 0, 0, 1, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 0, 0, 1, 1, 0}, \
  {0, 0, 0, 1, 1, 1, 0, 0}, \
  {0, 0, 1, 1, 1, 0, 0, 0}, \
  {0, 1, 1, 0, 0, 0, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 1, 0} \
};

// A static integer matrix representing three.
int threepixels[8][8] = { \
  {0, 0, 1, 1, 1, 1, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 1, 0}, \
  {0, 1, 0, 0, 0, 1, 1, 0}, \
  {0, 0, 0, 1, 1, 1, 0, 0}, \
  {0, 0, 0, 1, 1, 1, 0, 0}, \
  {0, 1, 0, 0, 0, 1, 1, 0}, \
  {0, 1, 1, 1, 1, 1, 1, 0}, \
  {0, 0, 1, 1, 1, 1, 0, 0} \
};


// A static integer matrix representing go.
int gopixels[8][8] = { \
  {1, 1, 1, 1, 0, 1, 1, 1}, \
  {1, 0, 0, 0, 0, 1, 0, 1}, \
  {1, 0, 1, 1, 0, 1, 0, 1}, \
  {1, 0, 0, 1, 0, 1, 0, 1}, \
  {1, 1, 1, 1, 0, 1, 1, 1}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0} \
};

void clearScreen(){
  for (int thisPin =0; thisPin <8; thisPin++){
    digitalWrite(cols[thisPin], HIGH);
  }
}

void fillScreen() {
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    digitalWrite(cols[thisPin], LOW);    
    digitalWrite(rows[thisPin], HIGH);   
    delay(100);
  }
}

void setup() {
  // initialize the I/O pins as outputs
  // iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(cols[thisPin], OUTPUT);
    pinMode(rows[thisPin], OUTPUT);  
  }
  pinMode(button1, INPUT);     
  pinMode(button2, INPUT);     
  pinMode(button3, INPUT);
  randomSeed(100);  
  fillScreen();
  clearScreen();  
  Serial.begin(9600);  //Begin serial communcation
}
 
void drawColumn(int curPixels[8][8]){
  digitalWrite(cols[col], HIGH);  // Turn whole previous column off
  col++;
  Serial.print(col);
  Serial.println( " ccol");
  if (col == 8) {
    col = 0;
  }
  for (int row = 0; row < 8; row++) {
    if (curPixels[col][7 - row] == 1)
      digitalWrite(rows[row], HIGH);
    else
      digitalWrite(rows[row], LOW); // Turn off this led
  }
  digitalWrite(cols[col], LOW); // Turn whole column on at once (for equal lighting times)
}

void drawScreen(int curPixels[8][8]) {
  //Draw image on 8x8 24 times so less flicker
  for (int count=0; count <24; count++) {
    //Draw each column individually
    for (int curcol=0; curcol <8; curcol++) {
      Serial.print(curcol);
      Serial.println( " curcol");
      Serial.println("drawColumn\n");
      drawColumn(curPixels);
    }
    delay(1);
  }
}

void countdown()
{
  //Loop through 3-2-1
  drawScreen(threepixels);
  drawScreen(twopixels);
  drawScreen(onepixels);
  drawScreen(gopixels);
  clearScreen();
}

int computerThrow;
int randNumber;
int playerThrow;

void loop(){
  // display ? and wait for button press
  Serial.println("Wait for button press\n"); 

  buttonSelection=0;
  button1Selection=HIGH;
  button2Selection=HIGH;
  button3Selection=HIGH;
  do {
    drawScreen(qpixels);
    button1Selection=digitalRead(button1);
    button2Selection=digitalRead(button2);
    button3Selection=digitalRead(button3);
    if (button1Selection == LOW || button2Selection == LOW || button3Selection == LOW) {
      buttonSelection=1;
    }
  } while (buttonSelection ==0) ;

  int games =0;
  do {
    //Get Player Throw
    buttonSelection=0;
    button1Selection=HIGH;
    button2Selection=HIGH;
    button3Selection=HIGH;
    countdown();
    do {
      button1Selection=digitalRead(button1);
      button2Selection=digitalRead(button2);
      button3Selection=digitalRead(button3);
      if (button1Selection == LOW || button2Selection == LOW || button3Selection == LOW) {
        buttonSelection=1;
      }
    } while (buttonSelection ==0) ;

    drawScreen(playerpixels);
    delay(100);
    drawScreen(playerpixels);
    if (button1Selection == LOW) { 
      playerThrow=1;
      drawScreen(rockpixels);
      delay(100);
      drawScreen(rockpixels);
    }
    else if (button2Selection == LOW) { 
      playerThrow=2;
      drawScreen(paperpixels);
      delay(100);
      drawScreen(paperpixels);
    }
    else if (button3Selection == LOW) { 
      playerThrow=3;
      drawScreen(scissorspixels);
      delay(100);
      drawScreen(scissorspixels);
    }
    
    // Try to pick a random number and decide if the Computer is playing Paper, Rock, or Scissors.
    drawScreen(computerpixels);
    delay(100);
    drawScreen(computerpixels);
    randNumber = random(300);   
    if (randNumber < 100) {
      Serial.println("Computer = Rock\n");
      drawScreen(rockpixels);
      delay(100);
      drawScreen(rockpixels);
      computerThrow = 1;
    }
    else if (randNumber < 200) {
      Serial.println("Computer = Paper\n");
      drawScreen(paperpixels);
      delay(100);
      drawScreen(paperpixels);
      computerThrow = 2;
    }
    else {
      Serial.println("Computer = Scissors\n");
      drawScreen(scissorspixels);
      delay(100);
      drawScreen(scissorspixels);
      computerThrow = 3;
    }
    
    //Decide who won
    if ((computerThrow == 1 && playerThrow == 2) || (computerThrow == 2 && playerThrow == 3) || (computerThrow == 3 && playerThrow == 1)) {
      //Player won
      Serial.println("Player 1 = Won\n");
      drawScreen(hfacepixels);
      delay(100);
      drawScreen(hfacepixels);
      games++;
    }
    else if ((computerThrow == 1 && playerThrow == 3) || (computerThrow == 2 && playerThrow == 1) || (computerThrow == 3 && playerThrow == 2)) {
      //Compute won
      Serial.println("Player 2 = Won\n");
      drawScreen(sfacepixels);
      delay(100);
      drawScreen(sfacepixels);
      games++;
    }
    else {
      //Tie
      Serial.println("Tie\n");
      drawScreen(ufacepixels);
      delay(100);
      drawScreen(ufacepixels);
    }
    delay(100);
  } while (games <3);
}


