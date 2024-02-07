/*
  6 state finite state

  Button switches between three LEDs. Reducing light on photocell inverts which lights are turned on.
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;
const int ledPinRed = 5;
const int ledPinYellow = 4;
const int ledPinBlue = 3;
const int photocellInPin = A0;

// variables will change:
int prevButtonState = 0;
int buttonState = 0;  // variable for reading the pushbutton status
int lightState = 0;
int sensorValue = 0;

bool LEDINV = true;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinYellow, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // read serial analog photocell input
  sensorValue = analogRead(photocellInPin);

  if (sensorValue < 200) {
    LEDINV = false;
  }
  else {
    LEDINV = true;
  }

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    if (prevButtonState == LOW) {
      switch (lightState) {
        case 0: // all lights off
          updateLED(LEDINV,!LEDINV,!LEDINV);
          lightState++;
          break;
        case 1: // red on
          updateLED(!LEDINV,LEDINV,!LEDINV);
          lightState++;
          break;
        case 2: // yellow on
          updateLED(!LEDINV,!LEDINV,LEDINV);
          lightState++;
          break;
        default: // blue on
          updateLED(!LEDINV,!LEDINV,!LEDINV);
          lightState = 0;
          break;
      }
      Serial.println(sensorValue);
    }
  }
  prevButtonState = buttonState;
}

void updateLED(int R,int Y,int B) {
  digitalWrite(ledPinRed, R);
  digitalWrite(ledPinYellow, Y);
  digitalWrite(ledPinBlue, B);
}