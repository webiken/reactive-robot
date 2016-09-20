#ifndef SROBOT_SENSORS_ULTRASONIC_H_
#define SROBOT_SENSORS_ULTRASONIC_H_

#include "Arduino.h"

class Ultrasonic {
 public:
  Ultrasonic(int pin);
  void DistanceMeasure(void);
  long microseconds_to_centimeters(void);
 private:
  int pin_;
  long duration_;
};

#endif // SROBOT_SENSORS_ULTRASONIC_H_
