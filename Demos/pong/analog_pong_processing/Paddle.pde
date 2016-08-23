//class for paddles

class Paddle {

  float pWidth;
  float pHeight;
  float yPos;
  float xPos;

  Paddle(float ipWidth, float ipHeight, float ixPos, float iyPos) {

    pWidth = ipWidth;
    pHeight = ipHeight;
    xPos = ixPos;
    yPos = iyPos;
  }

  void display(float yPos) {
    pushStyle();
    fill(87, 36, 124);// or littleBits white(247)
    rect(xPos, yPos, pWidth, pHeight);
    popStyle();
  }
}

