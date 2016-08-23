
void showGUI() {

  stroke(87, 36, 124);
  line(width/2, 0, width/2, height);

  textSize(16);
  pushStyle();
  fill(87, 36, 124);
  text("Player 1: " + playerOne, 100, 20); // player 1 score display
  text("Player 2: " + playerTwo, 600, 20);  // play 2 score display
  popStyle();
  
  if (oneWins == true) { //if player one wins
    textSize(48);
    image(pEnd, 0, 0, width, height); //display End Game Screen
    pushStyle();
    fill(87, 36, 124);
    text("Player 1 WINS!!!", width/2 - 175, 100);
    popStyle();
  }

  if (twoWins == true) { //if player two wins
    textSize(48);
    image(pEnd, 0, 0, width, height); //display End Game Screen
    pushStyle();
    fill(87, 36, 124);
    text("Player 2 WINS!!!", width/2 - 175, 100);
    popStyle();
  }
}

