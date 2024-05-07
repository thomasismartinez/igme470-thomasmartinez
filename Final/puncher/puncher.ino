#include <Arduino_LSM6DS3.h>
#include <Arduino_LSM6DS3.h>

const int threshold = 1000;   // threshold value to decide when the detected sound is a knock or not

// these variables will change:
int sensorReading = 0;  // variable to store the value read from the sensor pin

// accelerometer data
float ax, ay, az;

// gyro data
float gx, gy, gz;

// variables used by gesture detection
int timer;
bool twist;

// codes to communicate with processing
byte blankCode = 0;
byte bamCode = 1;
byte powCode = 2;
byte pewCode = 3;

void setup() {
  Serial.begin(9600);       // use the serial port

  // begin using IMU
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  timer = 0;
  twist = false;
}

void loop() {
  // get gyro and acc data
  getGyro();
  getAcc();

  // if glove accelerates and timer hasnt started, start gesture detection timer
  if (ax < -0.8 && timer == 0) {
    timer = 1;
  }
  // if the timer has run above 50 stop gesture detection
  else if (timer > 50) {
    timer = 0;
    twist = false;
  }
  // if timer is running iterate
  else if (timer > 0) {
    timer++;
  }

  // if glove twists before time threshold
  if (gx > 500 && timer > 0) {
    twist = true;
    Serial.println("TWIST");
  }

  //printAcc();
  //printGyro();
  //Serial.println(ax);
  //Serial.println(timer);

  // if glove has decelerated within the time threshold
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
    else {
      Serial.write(bamCode);
      Serial.println("forward");
      delay(1000);
    }

    // tell processing to show blank screen
    Serial.write(blankCode);
  }

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