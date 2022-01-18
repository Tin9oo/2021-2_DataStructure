#include <iostream>
#include "Mtrx.h"

int main()
{
	int n_row, n_col;
	double dA[3 * 3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double dB[3 * 3] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
	Mtrx mA("mA =", dA, 3, 3), mB("mB =", dB, 3, 3);
	cout << mA;
	cout << mB;
}