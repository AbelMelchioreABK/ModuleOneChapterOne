#pragma once
#include "Vehicle.h"
class Airplane : public Vehicle {
public:
	Airplane() : Vehicle(0) {}
	Airplane(float speed) : Vehicle(speed, "") {}
	Airplane(std::string color) : Vehicle(0, color) {}
	Airplane(float speed, std::string color) : Vehicle(speed, color) {

	}
	~Airplane() {}

	void drive();
	void honk();
};

