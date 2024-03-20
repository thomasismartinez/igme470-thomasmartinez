/*
  Augmented Vinyl Record Cover

  Switch within record cover activates a buzzer that plays a short tune

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - switch attached to pin 2 from +5V
  - 220K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  by Thomas Martinez
*/

int melody[] = {
  82, 82, 165, 82, 82, 147, 82, 82, 
  131, 82, 82, 117, 82, 82, 123, 131,
  82, 82, 165, 82, 82, 147, 82, 82,
  131, 82, 82, 117,
};

int durations[] = {
  8, 8, 8, 8, 8, 8, 8, 8, 
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 2
};

// constants won't change. They're used here to set pin numbers:
const int switchPin = 2;  // the number of the pushbutton pin
const int buzzer = 13;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int lastButtonState = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(buzzer, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(switchPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(switchPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState != lastButtonState && buttonState == HIGH) {
    // play tune
    playDoom();
  }

  lastButtonState = buttonState;
}

// borrowed code
// https://github.com/hibit-dev/buzzer/blob/master/src/games/doom/doom.ino

void playDoom() {
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(buzzer, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(buzzer);
  }
}
