#include <NewPing.h>

#define LEFT_TRIG_PIN 22
#define LEFT_ECHO_PIN 19
#define RIGHT_TRIG_PIN 23
#define RIGHT_ECHO_PIN 18

#define MAX_DISTANCE 200

#define maxTol = 100
#define minTol = 15

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



  if(leftSensorActivated) {
    if(rightDistance > minTol && rightDistance < maxTol) {
      Serial.println("Entra");
      counter++;
      rightSensorActivated = false;
      leftSensorActivated = false;
      Serial.println(counter);
    }
  }

  if(rightSensorActivated) {
    if(leftDistance > minTol && leftDistance < maxTol) {
      if(counter > 0) {
        Serial.println("Sale");
        counter--;
        rightSensorActivated = false;
        leftSensorActivated = false;
        Serial.println(counter);
      }
    }
  }

  if(!leftSensorActivated && !rightSensorActivated) {
    // Check if the left sensor is less than 10 cm away
    if (leftDistance > minTol && leftDistance < maxTol) {
      leftSensorActivated = true;
    }
    
    // Check if the right sensor is less than 10 cm away
    if (rightDistance > minTol && rightDistance < maxTol) {
      rightSensorActivated = true;
    }
  }

  // Wait for a short time before repeating the loop
  delay(100);
}
