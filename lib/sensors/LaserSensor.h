#ifndef SROBOT_SENSORS_BASE_H_

#define SROBOT_SENSORS_BASE_H_
#include "Sensor.h"

#endif // SROBOT_SENSORS_BASE_H_

#ifndef SROBOT_SENSORS_LASER_H_

#define SROBOT_SENSORS_LASER_H_

/*
  Planning for good design. Agent library
  should be able to use more than one sensor.

  The agent's constructor will accept a vector
  of sensors.
 */
class LaserSensor: public Sensor {
 public:
  /*
    
   */
  LaserSensor(){};
};

#endif // SROBOT_SENSORS_LASER_H_
