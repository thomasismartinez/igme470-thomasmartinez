/*
  2 button toggle

  Turns on and off a light emitting diode(LED) connected to digital pin 3 and 4,
  when pressing a pushbutton attached to pin 2.
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPinYellow = 3;    // the number of the LED pin
const int ledPinRed = 4;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinYellow, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinYellow, LOW);
    Serial.print("Red");
    
  } else {
    // turn LED off:
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinYellow, HIGH);
    Serial.print("Yellow");
  }
}
