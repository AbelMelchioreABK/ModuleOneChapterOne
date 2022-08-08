#pragma once
#include "Container.h"
#include <thread>

class BeeHive
{
	Container* container;
	std::thread thread;

	public:
		BeeHive(Container* container);
		void StartHoneyProduction();
		std::thread* GetThread();
};

