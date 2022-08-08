#include "Farmer.h"
#include <iostream>

void CollectHoney(Container* container);

Farmer::Farmer(Container* container)
{
	this->container = container;
}

void Farmer::StartHoneyCollection()
{
	thread = std::thread(CollectHoney, this->container);
}

void CollectHoney(Container* container)
{
	while (true)
	{
		int totalDelay = 2000;
		std::this_thread::sleep_for(std::chrono::milliseconds(totalDelay));
		bool hadHoney = container->GetHoney();
		
		if (hadHoney)
		{
			std::cout << "We had honey!" << std::endl;
		}
		else
		{
			std::cout << "We didn't have honey :(" << std::endl;
		}
	}
}

std::thread* Farmer::GetThread()
{
	return &thread;
}