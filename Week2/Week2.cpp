// Week2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
void challengeOne();
void challengeTwo();
bool challengeThree();
void challengeFour();

int main()
{
	//challengeOne();
	//challengeTwo();
	//cout << "Your date was" << (challengeThree()?"" :"n't") << " a leap year." << endl;
	challengeFour();
}

void challengeOne() {
	cout << "Insert 3 number to be summed" << endl;
	int one, two, three;
	cin >> one;
	cin >> two;
	cin >> three;

	int sum = one + two + three;
	cout << one << " + " << two << " + " << three << " = " << sum << endl;

	float average = sum / 3.0f;
	cout << sum << " / " << "3" << " = " << average << endl;
}

void challengeTwo() {
	cout << "Insert a number to be cubed" << endl;
	int toCube;
	cin >> toCube;
	cout << toCube << "^3 = " << pow(toCube, 3) << endl;
}

bool challengeThree() {
	cout << "Input a year you'd like to check" << endl;
	int year;
	cin >> year;

	if (year % 400 == 0) {
		return true;
	}
	if (year % 100 == 0) {
		return false;
	}
	if (year % 4 == 0) {
		return true;
	}
	return false;
}

void challengeFour() {
	cout << "insert a positive number" << endl;
	int positiveNumber;
	cin >> positiveNumber;

	if (cin.fail()) {
		cout << "You didn't enter a number. Dying." << endl;
	}

	if (positiveNumber <= 0) {
		cout << "number provided not positive. dying." << endl;
		return;
	}

	vector<int> vec;

	for (int i = 1; i <= positiveNumber; i++) {
		if (positiveNumber % i == 0) {
			vec.push_back(i);
		}
	}

	cout << "The factors of " << positiveNumber << " are ";
	for (int i : vec) {
		cout << i << ' ';
	}
	cout << endl;
}
