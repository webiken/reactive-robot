#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int pin){
  pin_ = pin;
}

/*Begin the detection and get the pulse back signal*/
void Ultrasonic::DistanceMeasure(void) {
  pinMode(pin_, OUTPUT);
  digitalWrite(pin_, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin_,LOW);
  pinMode(pin_,INPUT);
  duration_ = pulseIn(pin_,HIGH);
}

/*The measured distance from the range 0 to 400 Centimeters*/
long Ultrasonic::microseconds_to_centimeters(void){
  return duration_/29/2;
}

