#ifndef SROBOT_AGENTS_REACTIVE_H_
#define SROBOT_AGENTS_REACTIVE_H_

#include "Driver.h"
#include "UltraSonicSensor.h"

class ReactiveAgent {
  Sensor* (&sensors_)[1];
  Driver (&driver_);

 public:

  ReactiveAgent(void);
  ReactiveAgent(Sensor* (&sensors)[1], Driver (&driver));
  void React(void);

  void SenseAndMove(void);
  void SetupDriver(void);
 private:

  /* these are part of the formula
  y = a_ * x + b;
  where y is the speed
  and x is the distance returned
  by sensor */
  double a_;
  double b_;
  int count;
  /* used to calculate the formula above */
  int CalcSpeed(double distance);
  float distance_;
  int turning_;
};


#endif // SROBOT_AGENTS_REACTIVE_H_

