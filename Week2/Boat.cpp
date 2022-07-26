#include "Boat.h"
#include <iostream>

void Boat::drive() {
	this->distanceTraveled += this->speed;
	cout << "We have SAILED " << this->speed << endl;
}

void Boat::honk() {
	cout << "Honk Honk but like a goose" << endl;
}