#include "UltraSonicSensor.h"

/*
  Begin the detection and get the pulse back signal
*/
float Ultrasonic::DistanceMeasure(void) {
  pinMode(pin_, OUTPUT);
  digitalWrite(pin_, LOW);
  
  delayMicroseconds(2);
  digitalWrite(pin_, HIGH);
  delayMicroseconds(5);

  digitalWrite(pin_,LOW);
  pinMode(pin_,INPUT);
  duration_ = pulseIn(pin_,HIGH);
  return microseconds_to_centimeters(duration_);
}

/*
  The measured distance from the range 0 to 400 Centimeters.
  
  We devide by 29 which is the speed of sound in cm,
  then devide by 2 since the sound echos and travels back
*/
float Ultrasonic::microseconds_to_centimeters(float duration){
  return duration/29/2;
}

