import processing.serial.*;

import processing.sound.*;
SinOsc osc;

Serial myPort;

void setup()
{
  myPort = new Serial(this, "COM3", 9600);
  
  osc = new SinOsc(this);
  osc.play();
}

void draw() {
  while (myPort.available() > 0) {
    String inString = myPort.readStringUntil('\n');
    if (inString != null) {
      inString = trim(inString); // Remove any extra whitespace
      println(inString);
      int inValue = int(inString); // Convert the received string to an integer
      println(inValue);
      osc.freq(inValue);
    }
  }
}
  
