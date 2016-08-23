
// wiring setup (so we can easily reference certain pins)
int cols[8] = {6, 11, 10, 3, 17, 4, 8, 9};
int rows[8] = {2, 7, 19, 5, 13, 18, 12, 16};

byte col = 0;

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
    drawScreen(hpixels);
}


