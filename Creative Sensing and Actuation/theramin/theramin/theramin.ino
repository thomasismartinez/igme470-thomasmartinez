
// 
// Ultrasonic Sensor code from:
// https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
//

const int trigPin = 9;  
const int echoPin = 10; 

const int buzzer = 13;

float duration, distance, buzzerFreq, percentage, hrz;  

const int maxDistance = 30;
const int maxHrz = 1000; 
const int minHrz = 100;

void setup() {
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  

  duration = pulseIn(echoPin, HIGH); 

  distance = (duration*.0343)/2;  

  // scale distance to hrz
  buzzerFreq = distance;

  if (distance > maxDistance) {
    distance = maxDistance;
  }
  else {
    percentage = distance / 30;
    hrz = (percentage * (maxHrz - minHrz)) + minHrz;
  }

  // play tone
  tone(buzzer, hrz, 50);

  Serial.print("Distance: ");  
	Serial.print(distance);
  Serial.print(", Hrz: ");  
	Serial.println(hrz);  
	delay(50); 
}
