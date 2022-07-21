#pragma once

#include <string>
#include <algorithm>

class Vehicle
{
	protected:
		float speed;
		std::string color;
		float distanceTraveled;

	public:
		Vehicle() : Vehicle(0) {}
		Vehicle(float speed) : Vehicle(speed, "") {}
		Vehicle(std::string color) : Vehicle(0, color) {}
		Vehicle(float speed, std::string color) {
			this->speed = speed;
			this->color = color;
			this->distanceTraveled = 0.0f;
		}
		~Vehicle() {}
		virtual void drive() = 0;
		virtual void honk() = 0;
		void speedUp(float speed) {
			this->speed += speed;
		}
		void slowDown(float speed) {
			this->speed -= speed;
			speed = std::max(0.0f, speed);
		}
		void stop() {
			this->speed = 0;
		}

		void setColor(std::string color) {
			this->color = color;
		}
		std::string getColor() {
			return color;
		}

		void setSpeed(float speed) {
			this->speed = speed;
		}
		float getSpeed() {
			return speed;
		}

		void resetOdometer() {
			distanceTraveled = 0;
		}
		float getDistanceTraveled() {
			return distanceTraveled;
		}
};

