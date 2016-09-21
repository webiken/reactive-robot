#include "UltraSonicSensor.h"
#include "ReactiveAgent.h"

UltraSonicSensor sensor(26);
// planning for the future
LaserSensor sensor2();

DcMotor motors[] = {DcMotor(7, 30, 31), DcMotor(8, 32, 33)};
Driver driver(motors);

// reactive agent where all
// the work is done
ReactiveAgent agent(sensor, driver);

// wait to start
long begin_ = millis();
long wait_ = 3000;
  
void setup() {
  Serial.begin(9600);
}

void loop() {
 // is it time to start
 if (millis() >= (begin_ + wait_)){
   agent.React();
   begin_ = millis();
 }
}
