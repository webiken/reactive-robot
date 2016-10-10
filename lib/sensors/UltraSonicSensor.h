#ifndef SROBOT_SENSORS_ULTRASONIC_H_
#define SROBOT_SENSORS_ULTRASONIC_H_

#include "Arduino.h"
#include "Sensor.h"

class UltraSonicSensor: public Sensor {
 public:
  /* Constructors */
  UltraSonicSensor(){};
  UltraSonicSensor(int sigPin){
    sigPin_ = sigPin;
    
  };
  
  /* override base class' method */
  virtual float Sense();
  
 private:
  /*
    Measure Distance
   */
  float DistanceMeasure(void);
  /*
    Class only suppports Metric
   */
  float microseconds_to_centimeters(float duration);
  int sigPin_;
  int high_;
  int low_;
  float duration_;
};

#endif // SROBOT_SENSORS_ULTRASONIC_H_
