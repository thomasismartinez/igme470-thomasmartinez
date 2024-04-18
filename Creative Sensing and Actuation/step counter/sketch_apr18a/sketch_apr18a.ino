const int knockSensor = A0;  // the piezo is connected to analog pin 0
const int threshold = 100;   // threshold value to decide when the detected sound is a knock or not

// these variables will change:
int sensorReading = 0;  // variable to store the value read from the sensor pin

int steps = 0;

// 7-seg pins
int a=7; 
int b=6; 
int c=5; 
int d=11; 
int e=10; 
int f=8; 
int g=9; 
int dp=4; 

void setup() {
  Serial.begin(9600);       // use the serial port

// setup 7-seg pins
  int i;
    for(i=4;i<=11;i++)
  
    pinMode(i,OUTPUT);
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);
  //Serial.println(sensorReading);

  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    // toggle the status of the ledPin:
    //ledState = !ledState;

    // update the LED pin itself:
    //digitalWrite(ledPin, ledState);
    steps = steps + 1;
    updateDisplay(steps);
    Serial.print("Step taken, TOTAL STEPS: ");
    Serial.println(steps);

    //send the string "Knock!" back to the computer, followed by newline
    //Serial.println("Knock!");
    delay(400);
    
  }
  delay(100);  // delay to avoid overloading the serial port buffer
}

// set display to current step count
void updateDisplay(int count) {
  clearDisplay();
  switch (count) {
  case 0:
    display0();
    break;
  case 1:
    display1();
    break;
  case 2:
    display2();
    break;
  case 3:
    display3();
    break;
  case 4:
    display4();
    break;
  case 5:
    display5();
    break;
  case 6:
    display6();
    break;
  case 7:
    display7();
    break;
  case 8:
    display8();
    break;
  case 9:
    display9();
    break;
  default:
    display0();
    break;
}
}

//display number 1
void display1(void) 
{
  
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
} 
//display number2
void
  display2(void) 
{
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);

    digitalWrite(g,HIGH);
  digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
}
  
// display number3
void display3(void) 
{ 
    digitalWrite(a,HIGH);

    digitalWrite(b,HIGH);
    
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);

    digitalWrite(g,HIGH);
} 
// display number4
void display4(void) 
{
  
    digitalWrite(f,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);

  digitalWrite(c,HIGH);
  
} 
// display number5
void display5(void)
  
{ 
    digitalWrite(a,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);

  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
} 
// display number6
void
  display6(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(f,HIGH);

    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
  
    digitalWrite(e,HIGH);  
} 
// display number7
void display7(void)
  
{   
   digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
}
  
// display number8
void display8(void) 
{ 
    digitalWrite(a,HIGH);

    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);

    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
  digitalWrite(f,HIGH);
  
} 
void clearDisplay(void) 
{ 
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);

    digitalWrite(g,LOW);
  digitalWrite(c,LOW);
    digitalWrite(d,LOW);  

    digitalWrite(e,LOW);  
  digitalWrite(f,LOW);  
} 
void display9(void)
  
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);

  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
  digitalWrite(f,HIGH);
  
} 
void display0(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);

  digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);
  
  digitalWrite(f,HIGH);  
} 
