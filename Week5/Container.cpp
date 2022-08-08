#include "Container.h"
#include <iostream>

Container::Container()
{
	hasHoney = false;
	totalHoney = 0;
	wastedHoney = 0;
}

Container::~Container()
{
}

void Container::InputHoney()
{
	std::cout << "attempting to input honey" << std::endl;
	lock.lock();
	std::cout << "Locking honey" << std::endl;
	std::cout << "Do we currently have honey? " << hasHoney << std::endl;
	if (!hasHoney)
	{
		hasHoney = true;
	}
	else
	{
		wastedHoney += 1;
	}
	totalHoney += 1;
	std::cout << "Total Honey: " << totalHoney << std::endl;
	std::cout << "Wasted Honey: " << wastedHoney << std::endl;

	lock.unlock();
}

bool Container::GetHoney()
{
	bool hadHoney = false;
	lock.lock();
	hadHoney = hasHoney;
	hasHoney = false;
	lock.unlock();
	return hadHoney;
}

int Container::TotalHoneyMade()
{
	return totalHoney;
}

int Container::TotalEffectiveHoney()
{
	return totalHoney - wastedHoney;
}

int Container::TotalWastedHoney()
{
	return wastedHoney;
}
