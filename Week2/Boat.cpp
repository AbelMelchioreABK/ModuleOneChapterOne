#include "Boat.h"
#include <iostream>

void Boat::drive() {
	this->distanceTraveled += this->speed;
	std::cout << "We have SAILED " << this->speed << std::endl;
}

void Boat::honk() {
	std::cout << "Honk Honk but like a goose" << std::endl;
}