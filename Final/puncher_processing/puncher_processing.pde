import processing.serial.*;
import ddf.minim.*;
 
Serial myPort;
Minim minim;
AudioPlayer player;
byte blankCode = 0;
byte bamCode = 1;
byte powCode = 2;
byte pewCode = 3;

PImage bamImg;
PImage powImg;
PImage pewImg;
PImage blankImg;
 
void setup()
{
  // In the next line, you'll need to change this based on your USB port name
  //String portName = Serial.list()[0];
  myPort = new Serial(this, "COM4", 9600);
  minim = new Minim(this);
 
  // Put in the name of your sound file below, and make sure it is in the same directory
  
  
  size(1130,800);
  bamImg = loadImage("bam.png");
  powImg = loadImage("pow.png");
  pewImg = loadImage("pew.png");
  blankImg = loadImage("blank.png");
  
  image(blankImg, 0, 0);
}

void draw() {
  while (myPort.available() > 0) {
    int inByte = myPort.read();
    if (inByte == blankCode) {
      image(blankImg,0,0);
    }
    else if (inByte == bamCode) {
      player = minim.loadFile("punch.wav");
      player.rewind();
      player.play();
      image(bamImg,0,0);
    }
    else if (inByte == powCode) {
      player = minim.loadFile("punch2.wav");
      player.rewind();
      player.play();
      image(powImg,0,0);
    }
    else if (inByte == pewCode) {
      player = minim.loadFile("tyrantrave.wav");
      player.rewind();
      player.play();
      image(pewImg,0,0);
    }
  }
}
