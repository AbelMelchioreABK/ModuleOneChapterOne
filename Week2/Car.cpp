#include "Car.h"
#include <iostream>

void Car::drive() {
	this->distanceTraveled += this->speed;
	std::cout << "We have drove " << this->speed << std::endl;
}

void Car::honk() {
	std::cout << "Beep Beep like a roadrunner" << std::endl;
}