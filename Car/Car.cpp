#include "Arduino.h"
#include <Servo.h>
#include <Wire.h>
#include <NewPing.h>
#include <stdlib.h>

#include "Car.h"

Car::Car()
{
    
    _motor1Direction = 12, _motor2Direction = 13;
    _motor1Speed = 3, _motor2Speed = 11;
    _motor1Brake = 9, _motor2Brake = 8;
    _trigPin = 6;
    _echoPin = 5;
    
    _servoMotor.attach(4);

    pinMode(_motor1Direction, OUTPUT);
    pinMode(_motor2Direction, OUTPUT);
    pinMode(_motor1Speed, OUTPUT);
    pinMode(_motor2Speed, OUTPUT);
    pinMode(_motor1Brake, OUTPUT);
    pinMode(_motor2Brake, OUTPUT);
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}

void Car::reverse(int speed){
    Serial.println("Moving backwards");
    
    analogWrite(_motor1Speed, speed);
    analogWrite(_motor2Speed, speed);
    digitalWrite(_motor1Brake, LOW);
    digitalWrite(_motor2Brake, LOW);
    digitalWrite(_motor1Direction, LOW);
    digitalWrite(_motor2Direction, LOW);
}

void Car::moveForward(int speed){
    Serial.println("Moving forward");

    Serial.println(speed);
    analogWrite(_motor1Speed, speed);
    analogWrite(_motor2Speed, speed);
    digitalWrite(_motor1Brake, LOW);
    digitalWrite(_motor2Brake, LOW);
    digitalWrite(_motor1Direction, HIGH);
    digitalWrite(_motor2Direction, HIGH);
}

void Car::stopping(){
    
    Serial.println("Stopping");
    analogWrite(_motor1Speed, 0);
    analogWrite(_motor2Speed, 0);
    digitalWrite(_motor1Brake, HIGH);
    digitalWrite(_motor2Brake, HIGH);    
    delay(200);
 }

void Car::turnLeft(int time){
    Serial.println("Turning right");

    delay(50);
    analogWrite(_motor1Speed, 255);
    analogWrite(_motor2Speed, 255);
    digitalWrite(_motor1Brake, LOW);
    digitalWrite(_motor2Brake, LOW);
    digitalWrite(_motor1Direction, HIGH);
    digitalWrite(_motor2Direction, LOW);
    delay(time); // turn 90 degrees

    digitalWrite(_motor1Brake, HIGH);    
    digitalWrite(_motor2Brake,HIGH);
  }

void Car::turnRight(int time){

    Serial.println("Turning left");
    delay(50);
    digitalWrite(_motor1Brake, LOW);
    digitalWrite(_motor2Brake, LOW);
    digitalWrite(_motor1Direction, LOW);
    digitalWrite(_motor2Direction, HIGH);
    analogWrite(_motor1Speed, 255);
    analogWrite(_motor2Speed, 255);
    
    
    delay(time); // turn 90 degrees

    digitalWrite(_motor1Brake, HIGH);    
    digitalWrite(_motor2Brake,HIGH);
}

int Car::checkLeft(){

  for(int i = 0; i < 123; i++){
      _servoMotor.write(i);
      delay(20);
  }
  
  delay(100);
  NewPing sonar(_trigPin, _echoPin, 100);
  distance = sonar.ping_cm(); 
  delay(10);
  if(distance == 0){
    distance = 250;
  }
  return distance;
}

int Car::checkRight(){
   for(int i = 0; i < 123; i++){
      _servoMotor.write(i);
      
      Serial.println(i);
      delay(20);
  }
  delay(100);
  NewPing sonar(_trigPin, _echoPin, 100);
  distance = sonar.ping_cm(); 
  delay(10);
  if(distance == 0){
    distance = 250;
  }
  return distance; 
}

int Car::checkSpace(){
  //loop though the two options for where the motor need to look (left/right)
  //checks the distance at each
  //saves this value to a variable/array
  //------------------EXTRA - take an average over three reads
  // compares the two values
  //returns the direction of the shortest
}

//this function will turn the servo motor to the possision sent into it
void Car::moveServo(){
    //_servoMotor.write();
}

//this function will return the distance between the ultrasound(eyes) and the nearest object 
int Car::checkDistance(){
  NewPing sonar(_trigPin, _echoPin, 100);
  distance = sonar.ping_cm(); 
  delay(10);
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance == 0){
    distance = 250;
  }
  return distance;
}
