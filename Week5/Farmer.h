#pragma once
#include "Container.h"
#include <thread>

class Farmer
{
	Container* container;
	std::thread thread;

	public:
		Farmer(Container* container);
		void StartHoneyCollection();
		std::thread* GetThread();
};

