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
}

void loop() {
 // is it time to start
 if (millis() > (begin_+wait_)){
    
    //driver.Forward(200);
    //delay(5000);
    //driver.TurnRight();

    motors[0].Move(255, true);
    motors[1].Move(255, true);
    delay(3000);

    // turn right
    // right motor slower turns right
    // takes about 3 seconds to do a 90 degree turn
    analogWrite(E1, 255/3);
    analogWrite(E2, 255);

    motors[0].Move(255, true);
    motors[1].Move(255, true);
    delay(3000);
 }
 
}
