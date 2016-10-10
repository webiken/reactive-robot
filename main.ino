#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <utility/Adafruit_MS_PWMServoDriver.h>
#include <Sensor.h>
#include <UltraSonicSensor.h>
#include <ReactiveAgent.h>

long begin_ = millis();
long start_ = 2000;
int started_ = 0;
int count = 0;

UltraSonicSensor uSensor(10);
Sensor *sensors[] = {&uSensor};

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *motor_1 = AFMS.getMotor(2);
Adafruit_DCMotor *motor_2 = AFMS.getMotor(3);
Driver driver(motor_1, motor_2);

ReactiveAgent agent(sensors, driver);

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  
  motor_2->setSpeed(150);
  motor_2->run(FORWARD);
  motor_2->run(RELEASE);
  
  motor_1->setSpeed(150);
  motor_1->run(FORWARD);
  motor_1->run(RELEASE);
  
}

float distance_(){
  float distance1 = sensors[0]->Sense();
  delay(300);
  float distance2 = sensors[0]->Sense();
  if (distance1 < distance2) {
    distance2 = distance1;
  }
  return distance2;
}

void loop() {

  //driver.Forward(50);
  float distance = distance_();
  Serial.println(distance); 
  while (distance > 100.0) {
    distance = distance_();
  }
  Serial.print("close .. ");
  Serial.println(distance);  		  
  //driver.TurnRight(); 
  delay(1000);

}
