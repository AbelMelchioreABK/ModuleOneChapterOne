#include "Airplane.h"
#include <iostream>

void Airplane::drive() {
	this->distanceTraveled += this->speed;
	cout << "We have FLEW " << this->speed << endl;
}

void Airplane::honk() {
	cout << "Squawk Squawk like a roadrunner" << endl;
}