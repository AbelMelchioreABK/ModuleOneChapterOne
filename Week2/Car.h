#pragma once
#include "Vehicle.h"
class Car : public Vehicle {
	public:
		Car() : Vehicle(0) {}
		Car(float speed) : Vehicle(speed, "") {}
		Car(std::string color) : Vehicle(0, color) {}
		Car(float speed, std::string color) : Vehicle(speed, color) {

		}
		~Car() {}

		void drive();
		void honk();
};

