#include <vector>

#include "UltraSonicSensor.h"
#include "LaserSensor.h"

using namespace std;

long distance_, begin_, wait_;

UltrasonicSensors sensor1(26);
// planning for the future
LaserSensor sensor2();

vector<Sensor*> sensors;
sensors.push_back(&sensor1);
sensors.push_back(&sensor2);

DcMotor motors[] = {DcMotor(7, 30, 31), DcMotor(8, 32, 33)};
Driver driver(motors);

// reactive agent where all
// the work is done
ReactiveAgent agent(sensors, driver);

// wait to start
begin_ = millis();
wait_ = 3000;

void setup() {
  Serial.begin(9600);
}

void loop() {
 // is it time to start
 if (millis() >= (begin_ + wait_)){
    agent.decide();
 }
}
