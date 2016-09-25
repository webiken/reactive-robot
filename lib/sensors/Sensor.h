#ifndef SROBOT_SENSORS_BASE_H_
#define SROBOT_SENSORS_BASE_H_

/*
  Planning for good design. Agent library
  should be able to use more than one sensor.

  The agent's constructor will accept a vector
  of sensors.
*/
class Sensor
{
 public:
  Sensor(){};
  virtual float Sense() {return 0.0;};
};

#endif // SROBOT_SENSORS_BASE_H_
