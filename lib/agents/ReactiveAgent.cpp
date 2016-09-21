#include "ReactiveAgent.h"

ReactiveAgent::ReactiveAgent(UltraSonicSensor sensor, Driver driver) {
  sensor_ = sensor;
  driver_ = driver;
  a_ = .9;
  b_ = 5;
}

int ReactiveAgent::CalcSpeed(double distance) {
  return (int)(a_ * distance + b_);
}

void ReactiveAgent::SenseAndMove(void) {
  float distance = sensor.DistanceMeasure();
  while (distance > 100) {
    driver_.Foward(CalcSpeed(distance));
    delay(10000);
    distance = sensor.DistanceMeasure();
  }
  // we are 1 meter fro the wall
  // stop the car
  driver_.Stop();
}
void ReactiveAgent::React(void) {
  //stop the car
  driver_.Stop();
  // move 360 degrees
  for (int i = 0; i < 3; i++) {
    // move until 1meter from wall
    SenseAndMove();
    driver_.TurnRight(100);
    driver_.Stop();
  }
  
}
