#pragma once
#include <mutex>

class Container
{
	std::mutex lock;
	bool hasHoney;
	int totalHoney;
	int wastedHoney;

	public:
		Container();
		~Container();
		void InputHoney();
		bool GetHoney();

		int TotalHoneyMade();
		int TotalEffectiveHoney();
		int TotalWastedHoney();
};

