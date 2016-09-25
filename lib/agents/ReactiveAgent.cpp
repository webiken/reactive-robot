#include "ReactiveAgent.h"

ReactiveAgent::ReactiveAgent(Sensor* (&sensors)[1], Driver (&driver)) :
  sensors_(sensors), driver_(driver) {
  
  a_ = 1.5;
  b_ = 5;
  
}

int ReactiveAgent::CalcSpeed(double distance) {
  int max_ = 255;
  
  int speed_ = (int)(a_ * distance + b_);
  if (speed_ <= 255) { return speed_;}

  return max_;
}

void ReactiveAgent::SenseAndMove(void) {
  driver_.Forward(255);
  // for (Sensor* sensor : sensors_) {
  //   float distance = sensor->Sense();
  //   while (distance > 80.0) {
  //     //driver_.Forward(CalcSpeed(distance));
  //     distance = sensor->Sense();
  //   }
  //   // we are 1 meter from the wall
  //   // stop the car
  //   driver_.Stop();
  // }
  delay(4000);
}
void ReactiveAgent::React(void) {
  //stop the car
  //driver_.Stop();
  
  // move in U shape 
  for (int i = 0; i < 3; i++) {
    // move until 1 meter from wall
    SenseAndMove();
    driver_.TurnRight();
    driver_.Stop();
  }
  
}
