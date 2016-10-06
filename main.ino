#define E1 2  // Enable Pin for motor 1
#define E2 5  // Enable Pin for motor 2

#include "Sensor.h"
#include "UltraSonicSensor.h"
#include "ReactiveAgent.h"

DcMotor motors[] = {DcMotor(2, 3, 4), DcMotor(5, 6, 7)};
UltraSonicSensor uSensor(8);

Sensor *sensors[] = {&uSensor};
Driver driver(motors);

// reactive agent where all
// the work is done
ReactiveAgent agent(sensors, driver);

// wait to start
long begin_ = millis();
long wait_ = 1100;
  
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  
}

void loop() {
 // is it time to start
 analogWrite(2, 150);
 
}
