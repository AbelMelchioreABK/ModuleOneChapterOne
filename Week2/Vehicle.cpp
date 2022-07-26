#include "Vehicle.h"


Vehicle::Vehicle() : Vehicle(0) {}
Vehicle::Vehicle(float speed) : Vehicle(speed, "") {}
Vehicle::Vehicle(string color) : Vehicle(0, color) {}
Vehicle::Vehicle(float speed, string color) {
	this->speed = speed;
	this->color = color;
	this->distanceTraveled = 0.0f;
}
Vehicle::~Vehicle() {}
void Vehicle::speedUp(float speed) {
	this->speed += speed;
}
void Vehicle::slowDown(float speed) {
	this->speed -= speed;
	speed = max(0.0f, speed);
}
void Vehicle::stop() {
	this->speed = 0;
}

void Vehicle::setColor(string color) {
	this->color = color;
}
string Vehicle::getColor() {
	return color;
}

void Vehicle::setSpeed(float speed) {
	this->speed = speed;
}
float Vehicle::getSpeed() {
	return speed;
}

// should probably rename this function to reset distance traveled to keep in line with other name schemes
void Vehicle::resetOdometer() {
	distanceTraveled = 0;
}
float Vehicle::getDistanceTraveled() {
	return distanceTraveled;
}