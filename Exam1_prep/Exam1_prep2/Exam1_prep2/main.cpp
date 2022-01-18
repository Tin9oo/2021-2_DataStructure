#include <iostream>
#include "Mtrx.h"
using namespace std;

int main()
{
	int n_row, n_col;
	double dA[3 * 3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double dB[3 * 3] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
	Mtrx mA("mA =", dA, 3, 3), mB("mB =", dB, 3, 3);
	cout << mA;
	cout << mB;
	Mtrx mC = mA + mB;
	mC.set_name("mC = mA + mB =");
	Mtrx mD = mA - mB;
	mD.set_name("mD = mA - mB =");
	Mtrx mE = mA * mB;
	mE.set_name("mE = mA * mB =");
	cout << mC;
	cout << mD;
	cout << mE;

	return 0;
}