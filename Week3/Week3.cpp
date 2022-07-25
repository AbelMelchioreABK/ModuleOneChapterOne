// Week3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int a, b;
    std::cout << "Please insert two integers." << std::endl;
    std::cin >> a;
    std::cin >> b;

    int* ptrA = &a;
    int* ptrB = &b;

    std::cout << "ptrA is pointing to " << ptrA << " with the value at that location of " << * ptrA << std::endl;
    std::cout << "ptrB is pointing to " << ptrB << " with the value at that location of " << * ptrB << std::endl;
}
