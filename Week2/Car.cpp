#include "Car.h"
#include <iostream>

void Car::drive() {
	this->distanceTraveled += this->speed;
	cout << "We have drove " << this->speed << endl;
}

void Car::honk() {
	cout << "Beep Beep like a roadrunner" << endl;
}