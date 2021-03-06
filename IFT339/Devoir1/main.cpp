// Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Array.h"
#include <iostream>



int main()
{
	Array<int, 3> arrayOne;
	Array<int, 3> arrayTest;
	Array<int, 2> arrayTwo;
	Array<int, 5> arrayThree;

	Array<int, 3>::iterator it(arrayTest.begin());

	Array<int, 3>::const_iterator cit(arrayTest.cbegin());

	

	arrayOne.fill(2);
	arrayTest.fill(12);
	arrayTwo.fill(0);
	arrayThree.fill(6);

	cit++;
	std::cout << "iterator value:" << *it;
	std::cout << "const_iterator value:" << *cit;

	*it = 8;

	for (int i = 0; i < 3; ++i) {
		std::cout << arrayTest[i] << " ";
	}

	Array<int, 3> arrayFour;

	arrayFour = arrayThree.subset<3>(2);

	for (int i = 0; i < 3; ++i) {
		std::cout << arrayFour[i] << " ";
	}

	arrayFour.swap(arrayOne);

	for (int i = 0; i < 3; ++i) {
		std::cout << arrayFour[i] << " ";
	}

	arrayThree = arrayOne.fusion(arrayTwo);
    

	for (int i = 0; i < 5; ++i) {
		std::cout << arrayThree[i] << " ";
	}

	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
