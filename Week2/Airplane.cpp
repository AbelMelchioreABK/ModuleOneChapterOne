#include "Airplane.h"
#include <iostream>

void Airplane::drive() {
	this->distanceTraveled += this->speed;
	std::cout << "We have FLEW " << this->speed << std::endl;
}

void Airplane::honk() {
	std::cout << "Squawk Squawk like a roadrunner" << std::endl;
}