#include <iostream>
#include <vector>

#include "UltrasonicSensor.h"
#include "LaserSensor.h"

using namespace std;



long distance_, begin_, wait_;

UltrasonicSensors sensor1(26);
LaserSensor sensor2();


DcMotor motors[] = {DcMotor(7, 30, 31), DcMotor(8, 32, 33)};
Driver driver(motors, sensor);

// reactive agent where all
// the work is done
ReactiveAgent agent(driver);


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
