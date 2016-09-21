#ifndef SROBOT_AGENTS_REACTIVE_H_
#define SROBOT_AGENTS_REACTIVE_H_

#include "UltraSonicSensor.h"
#include "Driver.h"

class ReactiveAgent {
 public:
  ReactiveAgent(void);
  ReactiveAgent(UltraSonicSensor sensor, Driver driver);
  void React(void);
 private:
  UltraSonic sensor_;
  Driver driver_;
  
  /* these are part of the formula
  y = a_ * x + b;
  where y is the speed
  and x is the distance returned
  by sensor */
  double a_;
  double b_;

  /* used to calculate the formula above */
  int CalcSpeed(double distance);

  void SenseAndMove(void);
};

#endif // SROBOT_AGENTS_REACTIVE_H_

