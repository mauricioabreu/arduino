/*
HCSR-04 ultrasonic sensor.
Leds red and green 560 ohms.
Arduino UNO R3.
*/

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

const long g_distance = 4;

void setup() {
  	Serial.begin (9600);
  	pinMode(trigPin, OUTPUT);
  	pinMode(echoPin, INPUT);
  	pinMode(led, OUTPUT);
  	pinMode(led2, OUTPUT);
}

void loop() {
  	long duration, distance;
  	digitalWrite(trigPin, LOW);
	delayMicroseconds(2); 
  	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10); 
  	digitalWrite(trigPin, LOW);
  	duration = pulseIn(echoPin, HIGH);
  	distance = (duration/2) / 29.1;
  	turnLedByDistance(distance);
  	delay(500);
}

void turnLedByDistance(long distance) {
	if (distance < g_distance) {
		digitalWrite(led, HIGH);
		digitalWrite(led2, LOW);
	} else {
		digitalWrite(led, LOW);
		digitalWrite(led2, HIGH);
	}
}
