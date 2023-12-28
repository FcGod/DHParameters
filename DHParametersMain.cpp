#include <iostream>
#include "DHMatrix.h"

int main()
{
	Matrix T1, T2, T3, T4, T5, T6, result;

	//Make Transformed Matrices

	T1 = DH::CreateMatrix(780, 0, 410, 90); //d, theta, r, alpha
	T2 = DH::CreateMatrix(0, -90, 1075, 0);
	T3 = DH::CreateMatrix(0, 0, 165, -90);
	T4 = DH::CreateMatrix(1056, 0, 0, 90);
	T5 = DH::CreateMatrix(0, 0, 0, -90);
	T6 = DH::CreateMatrix(250, 90, 0, 0);

	result = DH::calculateFinal(T1, T2, T3, T4, T5, T6);
}
