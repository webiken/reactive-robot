#ifndef SROBOT_DRIVER_H_
#define SROBOT_DRIVER_H_

#include <Adafruit_MotorShield.h>

class Driver {

  Adafruit_DCMotor* (&motor_1);
  Adafruit_DCMotor* (&motor_2);
  
 public:
  Driver(void);
  Driver(Adafruit_DCMotor* (&motor1), Adafruit_DCMotor* (&motor2));
  void Forward(int speed);
  void Reverse(int speed);
  void TurnRight();
  void TurnLeft(void);
  void Stop(void);
  void SetupDriver(void);
  
 private:

  int speed_;
  boolean forward_;
};

#endif // SROBOT_DRIVER_H_
