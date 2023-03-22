#include <NewPing.h>

#define LEFT_TRIG_PIN 22
#define LEFT_ECHO_PIN 19
#define RIGHT_TRIG_PIN 23
#define RIGHT_ECHO_PIN 18

#define MAX_DISTANCE 200

NewPing leftSensor(LEFT_TRIG_PIN, LEFT_ECHO_PIN, MAX_DISTANCE);
NewPing rightSensor(RIGHT_TRIG_PIN, RIGHT_ECHO_PIN, MAX_DISTANCE);

bool increase = false;
int counter = 0;

bool leftSensorActivated = false;
bool rightSensorActivated = false;

void setup() {
  // Initialize the serial connection for debugging
  Serial.begin(9600);
}

void loop() {
  // Measure the distance from the left sensor
  int leftDistance = leftSensor.ping_cm();
  
  // Measure the distance from the right sensor
  int rightDistance = rightSensor.ping_cm();
  
  // Debugging output
  Serial.print("Left distance: ");
  Serial.print(leftDistance);
  Serial.print(" cm, right distance: ");
  Serial.print(rightDistance);
  Serial.println(" cm");
  
  // Check if the left sensor is less than 10 cm away
  if (leftDistance > 10 && leftDistance < 50) {
    leftSensorActivated = true;
  }
  
  // Check if the right sensor is less than 10 cm away
  if (rightDistance > 10 && rightDistance < 50) {
    rightSensorActivated = true;
  }
  
  // Wait until both sensors are activated
  if (leftSensorActivated && rightSensorActivated) {
    // Check if both sensors are less than 10 cm away
    if (leftDistance < 10 && rightDistance < 10) {
      increase = true;
    } else {
      increase = false;
    }
  }
  
  // Debugging output
  if (increase) {
    Serial.println("Increase");
    counter++;
  } else {
    Serial.println("Decrease");
    if(counter > 0) {
      counter--;
    }
  }
  Serial.println(counter);
  // Wait for a short time before repeating the loop
  delay(100);
}
