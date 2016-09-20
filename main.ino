#include "Ultrasonic.h"
#include "Driver.h"

DcMotor motors[] = {DcMotor(7, 30, 31), DcMotor(8, 32, 33)};
Driver driver(motors);

Ultrasonic ultrasonic(26);
long distance;

void setup() {
     Serial.begin(9600);
}

void loop() {
  ultrasonic.DistanceMeasure();
  distance = ultrasonic.microseconds_to_centimeters();
  Serial.println("The distance is ");
  Serial.println(" inch");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
  driver.Forward(200);
}
