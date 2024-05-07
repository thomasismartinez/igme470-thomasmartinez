#include <Arduino_LSM6DS3.h>
#include <Arduino_LSM6DS3.h>

const int knockSensor = A0;  // the piezo is connected to analog pin 0
const int threshold = 1000;   // threshold value to decide when the detected sound is a knock or not

// these variables will change:
int sensorReading = 0;  // variable to store the value read from the sensor pin

// accelerometer data
float ax, ay, az;

// gyro data
float gx, gy, gz;

int timer;
bool twist;

// code to communicate with processing
byte blankCode = 0;
byte bamCode = 1;
byte powCode = 2;
byte pewCode = 3;

void setup() {
  Serial.begin(9600);       // use the serial port

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  timer = 0;
  twist = false;
}

void loop() {
  getGyro();
  getAcc();

  if (ax < -0.8 && timer == 0) {
    timer = 1;
  }
  else if (timer > 50) {
    timer = 0;
    twist = false;
  }
  else if (timer > 0) {
    timer++;
    printGyro();
  }

  if (gx > 500 && timer > 0) {
    twist = true;
    Serial.println("TWIST");
  }

  //printAcc();
  //printGyro();
  //Serial.println(ax);
  //Serial.println(timer);

  if (ax > 0.5 && timer > 0) {
    // print "punch"
    Serial.println("punch");

    // write to serial for processing based on gyro information
    if (twist == true) {
      Serial.write(powCode);
      Serial.println("twist");
      delay(1000);
    }
    else if (gy < -300) {
      Serial.write(pewCode);
      Serial.println("uppercut");
      delay(4000);
    }
    //else if (gx > 500) {
    //  Serial.write(powCode);
    //  Serial.println("twist");
    //  delay(1000);
    //}
    else {
      Serial.write(bamCode);
      Serial.println("forward");
      delay(1000);
    }

    //send the string "Knock!" back to the computer, followed by newline
    //Serial.println("Knock!");
    Serial.write(blankCode);
  }

  // if the sensor reading is greater than the threshold:
  //if (sensorReading >= threshold) {
  //  // print "punch"
  //  Serial.println("punch");
//
  //  // get gyro and acceleration data from arduino
  //  getGyro();
  //  getAcc();
//
  //  // write to serial for processing
  //  if (gy < -100) {
  //    Serial.write(powCode);
  //  }
  //  else {
  //    Serial.write(bamCode);
  //  }
//
  //  //send the string "Knock!" back to the computer, followed by newline
  //  //Serial.println("Knock!");
  //  delay(10000);
  //  
  //}
  delay(10);  // delay to avoid overloading the serial port buffer
}

void getAcc() {
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(ax, ay, az);
  }
}

void printAcc() {
  //Serial.print("Acceleration: ");
  Serial.print(ax);
  Serial.print(' ');
  Serial.print(ay);
  Serial.print(' ');
  Serial.println(az);
}

void getGyro() {
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(gx, gy, gz);
  }
}

void printGyro() {
  //Serial.print("Gyroscope: ");
  Serial.print(gx);
  Serial.print(' ');
  Serial.print(gy);
  Serial.print(' ');
  Serial.println(gz);
}