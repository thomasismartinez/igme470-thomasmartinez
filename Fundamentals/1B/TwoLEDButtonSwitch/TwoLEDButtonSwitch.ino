/*
  2 LED Toggle

  Switches between 2 leds on and off a light emitting diode(LED) connected to digital pins 3 and 4,
  when pressing a pushbutton attached to pin 2.

*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPinYellow = 3;    // the number of the LED pin
const int ledPinRed = 4;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int prevButtonState = 0;
bool on = false;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) { // check if the pushbutton is pressed.
    if (prevButtonState == LOW) { // if it was previously not pressed
      on = !on;
      digitalWrite(ledPin, on); // sace the previous button state
    }
  }

  prevButtonState = buttonState;
}
