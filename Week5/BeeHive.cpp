#include "BeeHive.h"

#include <iostream>
#include <random>

void GenerateHoney(Container* container);

BeeHive::BeeHive(Container* container)
{
	this->container = container;
}

void BeeHive::StartHoneyProduction()
{
	thread = std::thread(GenerateHoney, this->container);
}

void GenerateHoney(Container* container)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 10000); // distribution in range [1, 6]

	while (true)
	{
		int rngDelay = dist6(rng);
		int totalDelay = 5000 + rngDelay;
		std::cout << "Sleeping for " << totalDelay << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(totalDelay));
		container->InputHoney();
	}
}

std::thread* BeeHive::GetThread()
{
	return &thread;
}