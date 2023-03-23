 #include <NewPing.h>

#define LEFT_TRIG_PIN 22
#define LEFT_ECHO_PIN 19
#define RIGHT_TRIG_PIN 23
#define RIGHT_ECHO_PIN 18

#define MAX_DISTANCE 200

#define maxTol 100
#define minTol 15

//=====  DEBUG ======
void printDistances();
void printStage();
//=====  UTILS ======
bool isSensorActivated();
void reset();
//====== LED ======
void setupLed();

NewPing leftSensor(LEFT_TRIG_PIN, LEFT_ECHO_PIN, MAX_DISTANCE);
NewPing rightSensor(RIGHT_TRIG_PIN, RIGHT_ECHO_PIN, MAX_DISTANCE);

int counter = 0;
bool leftSensorActivated = false;
bool rightSensorActivated = false;
int stage = 0;

void setup() {
  Serial.begin(9600);
  setupLed();
}

void loop() {
  int leftDistance = leftSensor.ping_cm();
  int rightDistance = rightSensor.ping_cm();
  bool isLeftSensorActivated = isSensorActivated(leftDistance);
  bool isRightSensorActivated = isSensorActivated(rightDistance);
  
  printDistances(leftDistance, rightDistance);

  switch (stage) {
    case 0:
      if(!leftSensorActivated && !rightSensorActivated) {
        if (isLeftSensorActivated) {
          leftSensorActivated = true;
          stage = 1;
          break;
        }
        
        if (isRightSensorActivated) {
          rightSensorActivated = true;
          stage = 1;
          break;
        }
      }
    case 1:
      if(leftSensorActivated && !rightSensorActivated || rightSensorActivated && !leftSensorActivated) {
        if(isLeftSensorActivated && isRightSensorActivated){
          stage = 2;
          break;
        } else {
          reset();
          break;
        }
      }
    case 2:
      if(leftSensorActivated && isRightSensorActivated || rightSensorActivated && isLeftSensorActivated) {
        stage = 3;
        break;
      } 
      else if(isLeftSensorActivated && isRightSensorActivated) {
        stage = 2;
        break;
      }
    case 3:
      if(leftSensorActivated) {
        counter++;
        Serial.println("ENTRA =====>>>>>");
        reset();
        break;
      }
      if(rightSensorActivated) {
        if(counter > 0) {
          counter--;
          Serial.println("<<<<===== SALE");
          reset();
          break;
        }
      }
    default:
      break;
  }

  printStage();

  delay(100);
}
