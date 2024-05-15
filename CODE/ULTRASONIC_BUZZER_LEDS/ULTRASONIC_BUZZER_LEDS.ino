/*/----------------------------------------
*THIS IS JUST AN EXAMPLE CODE*
**IT NEEDS TO BE REDEFINED ACCORDING TO YOUR NEEDS**
**ITS FUNCTION IS TO MEASURE DISTANCE AND LIGHT UP LEDS ACCORDING TO THE DISTANCE MEASURED BY THE ULTRASONIC SENSOR AND WHEN THE DISTACE IS VERY CLOSE (I.E. 1 CM), THE BUZZER GIVES A BEEP SOUND**
***ALSO IT INITIATES A SERIAL COMMUNICATION BETWEEN THE ARDUINO BLUETOOTH MODULE AND THE USER'S PHONE***
****OPERATING SCENARIO

CREDITS TO: /* Arduino tutorial - Buzzer / Piezo Speaker
   More info and circuit: http://www.ardumotive.com/how-to-use-a-buzzer-en.html
   Dev: Michalis Vasilakis // Date: 9/6/2015 // www.ardumotive.com
----------------------------------------/*/
#include <NewPing.h>                    //ULTRASONIC LIBRARY
#include <SoftwareSerial.h>             //BLUETOOTH LIBRARY

// Define pins for ultrasonic sensor and LED outputs
const int trigPin = 2;
const int echoPin = 3;
const int led1 = 4;
const int led2 = 5;
const int led3 = 6;

// Define variables for the distance and duration of the ultrasonic sensor signal
long duration;
int distance;

const int buzzer = 9; //buzzer to arduino pin 9

void setup() {
  // Initialize the serial communication and LED pins
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}

void loop() {

  // Send a brief signal to the ultrasonic sensor to trigger it
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the ultrasonic sensor signal and calculate the distance in centimeters
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Use select case branching to light the appropriate LED(s) based on the distance
  switch (distance) {
    case 0 ... 10:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      break;
    case 11 ... 20:
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      break;
    case 21 ... 30:
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      break;
  }

  //BUZZER CODE
  if distance == 1
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
  Serial.println("ROBOT IS VERY CLOSE TO OBSTACLE!!");
  // Wait for a brief period before taking another distance measurement
  delay(100);
}