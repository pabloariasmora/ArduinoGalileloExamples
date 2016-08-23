/*
 littleBits Arduino Module
 created by Ben Leduc-Mills for SparkFun https://learn.sparkfun.com/resources/62
 modified for littleBits by Linz Craig
 modified for littleBits by Matt Richard
 
 _Analog Pong_
 
   What is supposed to happen:
 * Play pong using two analog sensor modules as inputs.
 * This sketch will allow you to read 2 analog sensor values from a
   littleBits Arduino Module, and use the values to control paddles
   in a game of two player Pong.
   
   Important Note:
 * You will need to download Processing to run the Processing sketch.
   Processing can be downloaded here: https://processing.org/download/?processing
   
   Circuit:
 * littleBits slide dimmer on analog pin A0
 * littleBits slide dimmer on analog pin A1
 * Optional:
   Use four littBits wire modules to properly orient and space 
   the slide dimmers so two people can play comfortably
 
*/

import processing.serial.*; //import serial library

// *** begin MODIFY THESE VARIABLES ***
int points_to_win = 2; // number of points it takes to win the game
// use these two variables to flip the values of your sensors if your
// orientation is causing the paddle to move in the wrong direction
boolean flip_left_sensor_value = false; // setting to true flips the left sensor value
boolean flip_right_sensor_value = false; // setting to true flips the right sensor value
// *** end MODIFY THESE VARIABLES ***


// *** begin DO NOT MODIFY THESE VARIABLES ***
Serial myPort;
PFont myFont; //init font for text
int lf = 10; //linefeed in ASCII
Paddle leftPaddle, rightPaddle; //paddle objects
Ball pong; //ball object
int padWidth = 15;
int padHeight = 60;
int leftPaddlePos = 0;
int rightPaddlePos = 0;
int distWall = 15; //paddle distance from wall
float lpp; //scaled left paddle position
float rpp; //scaled right paddle position
int playerOne = 0; //player 1 score (left paddle)
int playerTwo = 0; //player 2 score (right paddle)
boolean oneWins = false;
boolean twoWins = false;
boolean firstContact = false; // Whether we've heard from the microcontroller
PImage pStart; //PImage object for Start Screen
PImage pEnd; //PImage object for End Screen
boolean started = false; //boolean to keep track of whether we have started game
int timePlayed = 0; //added to create timer
// *** begin DO NOT MODIFY THESE VARIABLES ***

void setup() {
  // set size of Game Window
  size(1000, 600); 

  // load "game start" and "game over" image
  pStart = loadImage("Pong_Start.png");
  pEnd = loadImage("Pong_End.png");
  // create a font for GUI
  myFont = createFont("FFScala", 16);
  textFont(myFont);

  // initialize rectangle and ellipse drawing from center of shape
  rectMode(CENTER);
  ellipseMode(CENTER);

  // initialize the Serial Port that will be recieving data from the littleBits Arduino Module
  // display all serial ports in text window
  println(Serial.list()); // use this to determine which serial port is your littleBits Arduino
  // count, starting with 0, the serial ports until you reach your littleBits Arduino
  // place that number in the command below
  // EXAMPLE: myPort = new Serial(this, Serial.list()[ your serial port number ], 9600);
  myPort = new Serial(this, Serial.list()[3], 9600);
  myPort.bufferUntil('\n');

  // initialize left and right paddle
  leftPaddle = new Paddle(padWidth, padHeight, distWall, leftPaddlePos);
  rightPaddle = new Paddle(padWidth, padHeight, width - distWall, rightPaddlePos);
  // initialize the pong ball
  pong = new Ball (15, width/2, height/2, 8, 2, 1, 1);
}

void draw() {
  // make the background littleBits white
  background(247);
  // display and update the ball
  pong.display(); 
  pong.update();// updates location and points, spurs game over screen
  // display the left and right paddle
  leftPaddle.display(lpp);
  rightPaddle.display(rpp);
  //shows scores, etc. (see GUI tab)
  showGUI();
  
  // show "start game" image
  if (started == false) {
    image(pStart, 0, 0, width, height); //start
    println("Start");
  }
  //increment game timer
  timePlayed ++;
  //make ball faster as game goes on
  pong.bRadius = pong.bRadius + (timePlayed * .001);
  
}

void serialEvent(Serial myPort) {

  String myString = myPort.readStringUntil('\n');
  // if you got any bytes other than the linefeed:
  if (myString != null) {

    myString = trim(myString);

    // if you haven't heard from the microncontroller yet, listen:
    if (firstContact == false) {
      if (myString.equals("hello")) { 
        myPort.clear();          // clear the serial port buffer
        firstContact = true;     // you've had first contact from the microcontroller
        myPort.write('A');       // ask for more
        println("contact");
      }
    } 
    // if you have heard from the microcontroller, proceed:
    else {
      // split the string at the commas
      // and convert the sections into integers:
      int sensors[] = int(split(myString, ','));
      //add parsing sensor into array code here

      // print out the values you got:
      for (int sensorNum = 0; sensorNum < sensors.length; sensorNum++) {
        println("Sensor " + sensorNum + ": " + sensors[sensorNum]);
      }

      if (sensors.length > 1) {

        leftPaddlePos = sensors[0];
        rightPaddlePos = sensors[1];

        lpp = (float)leftPaddlePos;
        rpp = (float)rightPaddlePos;

        // check to see if sensor values need to be flipped
        // then map their values to the paddle positions
        // left sensor/paddle
        if ( flip_left_sensor_value == false ) {
          lpp = map(lpp, 0, 1023, 1, height);
        } 
        else if ( flip_left_sensor_value == true ) {
          lpp = map(lpp, 1023, 0, 1, height);
        }
        // right sensor/paddle
        if ( flip_right_sensor_value == false ) {
          rpp = map(rpp, 0, 1023, 1, height);
        } 
        else if ( flip_right_sensor_value == true ) {
          rpp = map(rpp, 1023, 0, 1, height);
        }

        // Other sensors can be used to control the paddles
        // Here are a few sensors with their corresponding mappings
        // to use these sensors, simply copy and paste the below code
        // where the it is called for directly above.
        // Make sure to keep consistent with the lpp and rpp

        // lpp sensors
        //map(lpp, 500, 900, 1, height);  //photocell, this will need to be adjusted for each new location
        //map(lpp, 200, 1023, 1, height); //force sensor
        //map(lpp, 150, 275, 1, height);  //flex sensor

        // rpp sensors
        //map(rpp, 500, 900, 1, height);  //photocell, this will need to be adjusted for each new location
        //map(rpp, 200, 1023, 1, height); //force sensor
        //map(rpp, 150, 275, 1, height);  //flex sensor
      }
      // when you've parsed the data you have, ask for more:
      myPort.write("A");
    }
  }
}

void keyPressed() {
  if (started == true) {   //added for Start Screen
    pong.keyPressed();
  }                        //added for Start Screen
  if (started == false) {  //added for Start Screen
    started = true;        //added for Start Screen
  }                        //added for Start Screen
}

