#ifndef SROBOT_SENSORS_BASE_H_
#define SROBOT_SENSORS_BASE_H_
#include "Sensor.h"
#endif // SROBOT_SENSORS_BASE_H_

#ifndef SROBOT_SENSORS_ULTRASONIC_H_
#define SROBOT_SENSORS_ULTRASONIC_H_

#include "Arduino.h"

class UltraSonicSensor: public Sensor {
 public:
  /*
    Constructors
   */
  UltraSonicSensor(){};
  UltraSonicSensor(int pin){
    pin_ = pin;
  }
  /*
    Measure Distance
   */
  float DistanceMeasure(void);
 private:
  /*
    Class only suppports Metric
   */
  float microseconds_to_centimeters(void);
  int pin_;
  long duration_;
};

#endif // SROBOT_SENSORS_ULTRASONIC_H_
