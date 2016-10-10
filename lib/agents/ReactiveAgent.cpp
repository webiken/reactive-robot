#include "ReactiveAgent.h"

ReactiveAgent::ReactiveAgent(Sensor* (&sensors)[1], Driver (&driver)) :
  sensors_(sensors), driver_(driver) {
 
  a_ = 4.9;
  b_ = 30;
  count = 0;
  distance_ = 0.0;
  turning_ = 0;
}

int ReactiveAgent::CalcSpeed(double distance) {
  
  int max_ = 170;
  
  int speed_ = (int)(a_ * distance + b_);
  if (speed_ <= max_) { return speed_;}

  return max_;
}

void ReactiveAgent::SenseAndMove(void) {
  
  distance_ = sensors_[0]->Sense();
  while (distance_ > 50.0) {
    delay(100);
    distance_ = sensors_[0]->Sense();
    this->driver_.Forward(this->CalcSpeed(distance_));
    delay(100);
  }
  if (distance_ <= 50.0) {
    this->driver_.TurnRight();
  }
  
}

void ReactiveAgent::React(void) {
  SenseAndMove();
}
