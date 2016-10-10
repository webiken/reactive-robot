#include "Driver.h"

Driver::Driver(Adafruit_DCMotor* (&motor1), Adafruit_DCMotor* (&motor2)) :
motor_1(motor1), motor_2(motor2){}


void Driver::Forward(int speed) {
  speed_ = speed;
  
  this->motor_2->setSpeed(speed);
  this->motor_2->run(FORWARD);
  //delay(100);
  this->motor_1->setSpeed(speed);
  this->motor_1->run(FORWARD);
  
}

void Driver::Reverse(int speed) {
  speed_ = speed;
  // for (Adafruit_DCMotor *motor : this->motors_) {
  //   motor->run(BACKWARD);
  //   motor->setSpeed(speed_);
  // }
  
}

void Driver::TurnRight() {
  int M1_in1pin = 11;
  int M2_in1pin = 4;
  this->motor_1->MC->setPin(M1_in1pin, HIGH);
  this->motor_2->MC->setPin(M2_in1pin, LOW);
  delay(2000);

  this->Stop();
}

void Driver::TurnLeft() {
  int M1_in1pin = 11;
  int M2_in1pin = 4;
  this->motor_1->MC->setPin(M1_in1pin, LOW);
  this->motor_2->MC->setPin(M2_in1pin, HIGH);
  delay(2000);

  this->Stop();
}

void Driver::Stop() {
  this->motor_1->run(RELEASE);
  this->motor_2->run(RELEASE);
}
