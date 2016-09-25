#include "Driver.h"

Driver::Driver(DcMotor (&motors)[2])
  : motors_(motors)
{}

void Driver::Forward(int speed) {
  speed_ = speed;
  forward_ = true;
  
  for (const DcMotor motor : motors_)
    motor.Move(speed_, forward_);
}

void Driver::Reverse(int speed) {
  speed_ = speed;
  
  for (const DcMotor motor : motors_)
    motor.Move(speed_, !forward_);
}

void Driver::TurnRight() {
  //int i = 0;
  // for (const DcMotor motor : motors_) {
  //   if (i == 0) { i++;motor.Move(255/3, forward_);}
  //   else { motor.Move(255, forward_);}
  //   i++;
  // }
  motors_[0].Move(255, true);
  motors_[1].Stop();
  //motors_[1].Move(255, forward_);
  delay(3000);
}

void Driver::TurnLeft() {
  // int i = 0;
  // for (const DcMotor motor : motors_) {
  //   if (i % 0 == 0) { motor.Move(255, forward_);}
  //   else { motor.Move(255/3, forward_);}
  //   i++;
  // }
}

void Driver::Stop() {
  for (const DcMotor motor : motors_)
    motor.Stop();
}
