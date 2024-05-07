
// 
// Ultrasonic Sensor code from:
// https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
//

const int trigPin = 9;  
const int echoPin = 10; 

float duration, distance, percentage, output;  

const int maxDistance = 30;

void setup() {
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  

  duration = pulseIn(echoPin, HIGH); 

  distance = (duration*.0343)/2;

  if (distance > maxDistance) {
    distance = maxDistance;
  }
  else {
    percentage = distance / maxDistance;
    output = (percentage * 1000) + 100;
  }

  int add = (int)output;
  Serial.println(add);

  //Serial.print("Duration: ");  
	//Serial.print(duration);
  //Serial.print("\tDistance: ");  
	//Serial.print(distance);
  //Serial.print("\tAdd: ");  
	//Serial.println(add);
	delay(50); 
}
