#include "Arduino.h"
#include <Servo.h>
#include <Wire.h>
#include <NewPing.h>
#include <stdlib.h>

class Car
{
  public:
    Car();
    void moveForward();
    void stopping();
    void turnLeft(int time);
    void turnRight(int time);
    int checkDistance();
    void moveServo();
    int checkSpace();
    int checkLeft();
    int checkRight();
  private:
    int _motor1Direction, _motor2Direction;
    int _motor1Speed, _motor2Speed;
    int _motor1Brake, _motor2Brake;
    int _trigPin;
    int _echoPin;
    int distance;
    //int time;
    Servo _servoMotor;
    
};


