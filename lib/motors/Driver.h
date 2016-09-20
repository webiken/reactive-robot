#ifndef SROBOT_MOTORS_DRIVER_H_
#define SROBOT_MOTORS_DRIVER_H_

#include "DcMotor.h"

class Driver {
  DcMotor (&motors_)[2];

 public:

  Driver(DcMotor (&motors)[2]);
  void Forward(int speed);
  void Reverse(int speed);
  void TurnRight(void);
  void TurnLeft(void);
  void Stop(void);
  
 private:

  int speed_;
  boolean forward_;
  
};

#endif // SROBOT_MOTORS_DRIVER_H_
