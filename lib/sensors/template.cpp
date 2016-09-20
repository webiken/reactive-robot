#include <iostream>
#include <vector>

#include "UltrasonicSensor.h"
#include "LaserSensor.h"

using namespace std;



int main ()
{
    long distance_, begin_, wait_;

    UltrasonicSensor sensor1;
    LaserSensor sensor2;


    vector<Sensor*> vect;
    vect.push_back(&sensor1);
    vect.push_back(&sensor2);
      
    vect[0]->identify();
    vect[1]->identify();
    return 0;
}
