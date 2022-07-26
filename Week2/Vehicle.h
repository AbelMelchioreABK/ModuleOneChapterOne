#pragma once

#include <string>
#include <algorithm>

using namespace std;

class Vehicle
{
	protected:
		float speed;
		string color;
		float distanceTraveled;

	public:
		Vehicle();
		Vehicle(float speed);
		Vehicle(std::string color);
		Vehicle(float speed, std::string color);
		~Vehicle();
		virtual void drive() = 0;
		virtual void honk() = 0;
		void speedUp(float speed);
		void slowDown(float speed);
		void stop();
		void setColor(std::string color);
		string getColor();
		void setSpeed(float speed);
		float getSpeed();

		// should probably rename this function to reset distance traveled to keep in line with other name schemes
		void resetOdometer();
		float getDistanceTraveled();
};

