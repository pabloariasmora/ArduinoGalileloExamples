
// wiring setup (so we can easily reference certain pins)
int cols[8] = {6, 11, 10, 3, 17, 4, 8, 9};
int rows[8] = {2, 7, 19, 5, 13, 18, 12, 16};

//Define Input pins for Player
int button1 = 0;
int button2 = 1;
int button3 = A0;

byte col = 0;

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

// A static integer matrix representing a smile.
int hpixels[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 1, 1, 1, 1, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0} \
};

// A static integer matrix representing a frown.
int spixels[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 1, 1, 1, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0} \
};

//Space Invader animation 1
int sipixels1[8][8] = { \
  {1, 0, 1, 0, 1, 0, 1, 0}, \
  {1, 0, 1, 1, 1, 0, 1, 0}, \
  {1, 1, 1, 1, 1, 1, 1, 0}, \
  {1, 1, 0, 1, 0, 1, 1, 0}, \
  {0, 1, 1, 1, 1, 1, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 0, 0}, \
  {0, 1, 0, 0, 0, 1, 0, 0}, \
  {1, 0, 0, 0, 0, 0, 1, 0} \
};

//Space Invader animation 2
int sipixels2[8][8] = { \
  {0, 0, 0, 1, 0, 1, 0, 0}, \
  {0, 0, 0, 1, 1, 1, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 1, 1}, \
  {0, 1, 1, 0, 1, 0, 1, 1}, \
  {0, 1, 1, 1, 1, 1, 1, 1}, \
  {0, 1, 0, 1, 1, 1, 0, 1}, \
  {0, 0, 1, 0, 0, 0, 1, 0}, \
  {0, 0, 1, 1, 0, 1, 1, 0} \
};

//Space Invader animation 3
int sipixels3[8][8] = { \
  {0, 0, 1, 0, 1, 0, 1, 0}, \
  {0, 0, 1, 0, 1, 1, 1, 0}, \
  {0, 0, 1, 1, 1, 1, 1, 1}, \
  {0, 0, 1, 1, 0, 1, 0, 1}, \
  {0, 0, 0, 1, 1, 1, 1, 1}, \
  {0, 0, 0, 1, 1, 1, 1, 1}, \
  {0, 0, 0, 1, 0, 0, 0, 1}, \
  {0, 0, 1, 0, 0, 0, 0, 0} \
};

//Space Invader animation 4
int sipixels4[8][8] = { \
  {0, 0, 0, 0, 0, 1, 0, 1}, \
  {0, 0, 0, 0, 0, 1, 1, 1}, \
  {0, 0, 0, 0, 1, 1, 1, 1}, \
  {0, 0, 0, 1, 1, 0, 1, 0}, \
  {0, 0, 0, 1, 1, 1, 1, 1}, \
  {0, 0, 0, 1, 0, 1, 1, 1}, \
  {0, 0, 0, 0, 1, 0, 0, 0}, \
  {0, 0, 0, 0, 1, 1, 0, 0} \
};

//Space Invader animation 5
int sipixels5[8][8] = { \
  {0, 0, 0, 0, 1, 0, 1, 0}, \
  {0, 0, 0, 0, 1, 0, 1, 1}, \
  {0, 0, 0, 0, 1, 1, 1, 1}, \
  {0, 0, 0, 0, 1, 1, 0, 1}, \
  {0, 0, 0, 0, 0, 1, 1, 1}, \
  {0, 0, 0, 0, 0, 1, 1, 1}, \
  {0, 0, 0, 0, 0, 1, 0, 0}, \
  {0, 0, 0, 0, 1, 0, 0, 0} \
};

//Space Invader animation 6
int sipixels6[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 1}, \
  {0, 0, 0, 0, 0, 0, 0, 1}, \
  {0, 0, 0, 0, 0, 0, 1, 1}, \
  {0, 0, 0, 0, 0, 1, 1, 0}, \
  {0, 0, 0, 0, 0, 1, 1, 1}, \
  {0, 0, 0, 0, 0, 1, 0, 1}, \
  {0, 0, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 0, 0, 0, 1, 1} \
};

//Space Invader animation 7
int sipixels7[8][8] = { \
  {0, 0, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 0, 0, 0, 1, 1}, \
  {0, 0, 0, 0, 0, 0, 1, 1}, \
  {0, 0, 0, 0, 0, 0, 0, 1}, \
  {0, 0, 0, 0, 0, 0, 0, 1}, \
  {0, 0, 0, 0, 0, 0, 0, 1}, \
  {0, 0, 0, 0, 0, 0, 1, 0} \
};

//Space Invader animation 8
int sipixels8[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 1}, \
  {0, 0, 0, 0, 0, 0, 0, 1}, \
  {0, 0, 0, 0, 0, 0, 0, 1}, \
  {0, 0, 0, 0, 0, 0, 0, 1}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 1} \
};

//Pacman animation 1
int pmpixels1[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 1, 1, 0, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 0, 0}, \
  {1, 1, 1, 1, 1, 1, 1, 0}, \
  {1, 1, 1, 1, 1, 1, 1, 0}, \
  {1, 1, 1, 1, 1, 1, 1, 0}, \
  {0, 1, 1, 1, 1, 1, 0, 0}, \
  {0, 0, 1, 1, 1, 0, 0, 0} \
};

//Pacman animation 2
int pmpixels2[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 1, 1, 0, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 0, 0}, \
  {1, 1, 1, 1, 1, 1, 1, 0}, \
  {1, 1, 1, 1, 0, 0, 0, 0}, \
  {1, 1, 1, 1, 1, 1, 1, 0}, \
  {0, 1, 1, 1, 1, 1, 0, 0}, \
  {0, 0, 1, 1, 1, 0, 0, 0} \
};

//Pacman animation 3
int pmpixels3[8][8] = { \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 1, 1, 0, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 0, 0}, \
  {1, 1, 1, 1, 1, 0, 0, 0}, \
  {1, 1, 1, 1, 0, 0, 0, 0}, \
  {1, 1, 1, 1, 1, 0, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 0, 0}, \
  {0, 0, 1, 1, 1, 0, 0, 0} \
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
  //Draw image on 8x8 8 times so less flicker
  for (int count=0; count <8; count++) {
    //Draw each column individually
    for (int curcol=0; curcol <8; curcol++) {
      Serial.print(curcol);
      Serial.println( " curcol");
      Serial.println("drawColumn\n"); 
      drawColumn(curPixels);
    }
  }
}
int buttonSelection;
int button1Selection,button2Selection,button3Selection;
void loop(){
    buttonSelection=0;
    do {
      drawScreen(qpixels);
      button1Selection=digitalRead(button1);
      button2Selection=digitalRead(button2);
      button3Selection=digitalRead(button3);
      if (button1Selection == LOW) { 
        drawScreen(hpixels);
        drawScreen(spixels);
        drawScreen(hpixels);
        drawScreen(spixels);
        drawScreen(hpixels);
        drawScreen(spixels);
        drawScreen(hpixels);
        drawScreen(spixels);
        buttonSelection=1;
      }
      else if (button2Selection == LOW) { 
        drawScreen(sipixels1);
        drawScreen(sipixels2);
        drawScreen(sipixels3);
        drawScreen(sipixels4);
        drawScreen(sipixels5);
        drawScreen(sipixels6);
        drawScreen(sipixels7);
        drawScreen(sipixels8);
        buttonSelection=1;
      }
      else if (button3Selection == LOW) { 
        drawScreen(pmpixels1);
        drawScreen(pmpixels2);
        drawScreen(pmpixels3);
        drawScreen(pmpixels2);
        drawScreen(pmpixels1);
        drawScreen(pmpixels2);
        drawScreen(pmpixels3);
        drawScreen(pmpixels2);
        drawScreen(pmpixels1);
        buttonSelection=1;
     }
    } while (buttonSelection ==0);
}


