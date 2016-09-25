#include "DcMotor.h"

DcMotor::DcMotor(void) {}

DcMotor::DcMotor(int speed_pin, int ctrl_pin1, int ctrl_pin2) {
  speed_pin_ = speed_pin;
  ctrl_pin1_ = ctrl_pin1; 
  ctrl_pin2_ = ctrl_pin2;

  pinMode(speed_pin_, OUTPUT);
  pinMode(ctrl_pin1_, OUTPUT);
  pinMode(ctrl_pin2, OUTPUT);

  digitalWrite(ctrl_pin1_, LOW);
  digitalWrite(ctrl_pin2_, HIGH);
}

void DcMotor::Move(int speed, boolean high) const {
  analogWrite(speed_pin_, speed);

  digitalWrite(ctrl_pin1_, LOW);
  digitalWrite(ctrl_pin2_, HIGH);
}

void DcMotor::Stop() const {
  analogWrite(speed_pin_, 0);
  digitalWrite(ctrl_pin1_, LOW);
  digitalWrite(ctrl_pin2_, LOW);
}
