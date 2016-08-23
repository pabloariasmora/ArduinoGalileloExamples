/*
 littleBits Arduino Module
 created by Ben Leduc-Mills for SparkFun https://learn.sparkfun.com/resources/62
 modified for littleBits by Linz Craig
 modified for littleBits by Matt Richard
 
 _Analog Pong_
 
   What is supposed to happen:
 * Play pong using two analog sensor modules as inputs.
 * This sketch will allow you to send 2 analog sensor values to a
   Processing sketch that is running a version of the game Pong.
   The Pong paddle positions move based on the sensor values.
   
   Important Note:
 * You will need to download Processing to run the Processing sketch.
   Processing can be downloaded here: https://processing.org/download/?processing
   
   Circuit:
 * littleBits slide dimmer on analog pin A0
 * littleBits slide dimmer on analog pin A1
 * Optional:
   Use four littBits wire modules to properly orient and space 
   the slide dimmers so two people can play comfortably
 
 This sketch includs the following commands:
 Serial.begin(baudrate);    baudrate = speed of serial communication
 Serial.read();             reads the incoming data from Serial port
 Serial.print();            sends data out the Serial port
 if(conditional){}          conditional = logical statement that evaluates to TRUE or FALSE
 analogRead(pin);           pin = an analog pin
*/


void setup() {
  Serial.begin(9600); //Establish rate of Serial communication
  establishContact(); //See function below
}

void loop() {
  if (Serial.available() > 0) { //If we've heard from Processing do the following

    // read the incoming byte from processing
    int inByte = Serial.read();
    // save the value from first analog sensor as variable leftPaddle
    int leftPaddle = analogRead(A0);
    // print out on Serial the value of leftPaddle (first sensor)
    Serial.print(leftPaddle, DEC);
    // print out on Serial a delimiter
    Serial.print(",");
    // save the value from second analog sensor as variable rightPaddle
    int rightPaddle = analogRead(A1);
    // print out on Serial the value of rightPaddle (second sensor)
    // but make sure you use Serial.println instead of Serial.print,
    // this is used by Processing to determine the end of our series of sensor values
    Serial.println(rightPaddle, DEC);
    // If you add additional sensors/buttons make sure you add delimiters
    // between the values and use Serial.println only for the last value
  }
}

void establishContact() {
  // when Arduino receives a Serial message from Processing
  while (Serial.available() <= 0) {
    // send a starting message
    Serial.println("hello");
    // then wait 300 milliseconds
    delay(300);
  }
}


