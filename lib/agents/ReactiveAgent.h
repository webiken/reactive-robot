#ifndef SROBOT_AGENTS_REACTIVE_H_
#define SROBOT_AGENTS_REACTIVE_H_

#include "UltraSonicSensor.h"
#include "Driver.h"

class ReactiveAgent {
  Sensor* (&sensors_)[1];
  Driver (&driver_);

 public:
  
  ReactiveAgent(void);
  ReactiveAgent(Sensor* (&sensors)[1], Driver (&driver));
  void React(void);

  void SenseAndMove(void);
 private:
  
  /* these are part of the formula
  y = a_ * x + b;
  where y is the speed
  and x is the distance returned
  by sensor */
  double a_;
  double b_;

  /* used to calculate the formula above */
  int CalcSpeed(double distance);

  
};

#endif // SROBOT_AGENTS_REACTIVE_H_

