#include "BeeHiveSimulation.h"

BeeHiveSimulation::BeeHiveSimulation(int hives, int farmers)
{
	container = new Container();

	for (int i = 0; i < hives; i++)
	{
		BeeHive *tempHive = new BeeHive(container);
		beeHives.push_back(tempHive);
	}

	for (int i = 0; i < farmers; i++)
	{
		Farmer* tempFarmer = new Farmer(container);
		honeyCollectors.push_back(tempFarmer);
	}
}

BeeHiveSimulation::~BeeHiveSimulation()
{
	
}

void BeeHiveSimulation::init()
{
	for (auto hive : beeHives)
	{
		hive->StartHoneyProduction();
	}

	for (auto farmer : honeyCollectors)
	{
		farmer->StartHoneyCollection();
	}

	for (auto hive : beeHives)
	{
		hive->GetThread()->join();
	}

	for (auto farmer : honeyCollectors)
	{
		farmer->GetThread()->join();
	}
}