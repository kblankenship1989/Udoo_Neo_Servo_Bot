#include <Servo.h>

Servo servoLeft;
Servo servoRight;
char incoming = '';
int servoPinLeft = 10;
int servoPinRight = 9;
int driveDelay = 2000;
char options[] = "wasd";

void setup() {
  Serial.begin(1152000;
}

void loop() {
  if (Serial.available > 0){
    incoming = char(Serial.read());
    servosAttach();
    switch(incoming){
      case 'a':
      case 'A':
        turnLeft();
        break;
      case 'd':
      case 'D':
        turnRight();
        break;
      case 's':
      case 'S':
        reverse();
        break;
      case 'w':
      case 'W':
        forward();
        break;
      default:
        Serial.write(options[random(0,length(options))])
        break;
    }
    delay(driveDelay);
    stopRobot();
    servosDetach();
  }
}

void servosAttach(){
  servoLeft.attach(servoPinLeft);
  servoRight.attach(servoPinRight);
}

void servosDetach(){
  servoLeft.detach();
  servoRight.detach();
}

void forward() {
  servoLeft.write(0);
  servoRight.write(180);
}

void reverse() {
  servoLeft.write(180);
  servoRight.write(0);
}

void turnRight() {
  servoLeft.write(180);
  servoRight.write(180);
}

void turnLeft() {
  servoLeft.write(0);
  servoRight.write(0);
}

void stopRobot() {
  servoLeft.write(90);
  servoRight.write(90);
  servosDetach();
}
