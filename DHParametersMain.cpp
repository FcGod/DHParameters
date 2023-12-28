#include <iostream>
#include "DHMatrix.h"

int main()
{
	/* initialize random seed: */
	srand(static_cast<unsigned>(time(0)));

	Matrix T1, T2, T3, T4, T5, T6, result, test1, test2;

	//Make Transformed Matrices

	T1 = DH::CreateMatrix(780, 0, 410, 90); //d, theta, r, alpha
	T2 = DH::CreateMatrix(0, -90, 1075, 0);
	T3 = DH::CreateMatrix(0, 0, 165, -90);
	T4 = DH::CreateMatrix(1056, 0, 0, 90);
	T5 = DH::CreateMatrix(0, 0, 0, -90);
	T6 = DH::CreateMatrix(250, 90, 0, 0);
	/*
	DH::printMatrix(T1);
	DH::printMatrix(T2);
	DH::printMatrix(T4);
	DH::printMatrix(T3);
	DH::printMatrix(T5);
	DH::printMatrix(T6);
	
	test1 = DH::fill();
	test2 = DH::fill();
	DH::printMatrix(test1);
	DH::printMatrix(test2);
	result = test1 * test2;
	DH::printMatrix(result);
	*/

	result = DH::calculateFinal(T1, T2, T3, T4, T5, T6);
}
