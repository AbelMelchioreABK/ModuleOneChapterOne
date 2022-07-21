#pragma once
#include "Vehicle.h"
class Boat : public Vehicle {

	public:
		Boat() : Vehicle(0) {}
		Boat(float speed) : Vehicle(speed, "") {}
		Boat(std::string color) : Vehicle(0, color) {}
		Boat(float speed, std::string color) : Vehicle(speed, color) {

		}
		~Boat() {}

		void drive();
		void honk();
};

