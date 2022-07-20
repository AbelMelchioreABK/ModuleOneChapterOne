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
void challengeFive();

int main()
{
	//challengeOne();
	//challengeTwo();
	//cout << "Your date was" << (challengeThree()?"" :"n't") << " a leap year." << endl;
	//challengeFour();
	challengeFive();
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

void challengeFive() {
	int data[30]{ 13, 20, 0, 25, 19, 28, 29, 8, 16, 10, 5, 2, 6, 7, 22, 4, 18, 21, 11, 3, 17, 9, 12, 26, 1, 14, 27, 24, 23, 15 };

	for (int i = 0; i < 30; i++) {
		switch (rand() % 4) {
			case 0:
				data[i] = data[i] * 5;
				break;
			case 1:
				data[i] = data[i] / 5;
				break;
			case 2:
				data[i] = data[i] + 5;
				break;
			case 3:
				data[i] = data[i] - 5;
				break;
		}
	}

	int largest = data[0];

	for(int i = 0; i < 30; i++) {
		if (data[i] > largest) {
			largest = data[i];
		}
	}

	cout << "The largest Number in this list: ";
	for (int i : data) {
		cout << i << " ";
	}
	cout << endl << " is " << largest << endl;

}


