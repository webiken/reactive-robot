#ifndef SROBOT_MOTORS_DCMOTOR_H_
#define SROBOT_MOTORS_DCMOTOR_H_

#include "Arduino.h"

class DcMotor {
 public:
  DcMotor(void);
  DcMotor(int speed_pin, int ctrl_pin1, int ctrl_pin2);
  void Move(int speed, boolean high) const;
  void Stop(void) const;
 private:
  int speed_pin_;
  int ctrl_pin1_;
  int ctrl_pin2_;
};

#endif  // SROBOT_MOTORS_DCMOTOR_H_
