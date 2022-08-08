#pragma once
#include "BeeHive.h"
#include "Farmer.h"
#include "Container.h"
#include "vector"

class BeeHiveSimulation
{
	std::vector<BeeHive*> beeHives;
	std::vector<Farmer*> honeyCollectors;
	Container* container;

	public:
		BeeHiveSimulation(int hives, int farmers);
		~BeeHiveSimulation();

		void init();
};

