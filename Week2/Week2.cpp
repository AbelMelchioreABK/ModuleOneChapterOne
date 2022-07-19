// Week2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void challengeOne();
void challengeTwo();


int main()
{
	//challengeOne();
	challengeTwo();
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