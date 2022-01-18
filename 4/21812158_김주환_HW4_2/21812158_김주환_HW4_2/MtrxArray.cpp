/* MtrxArray.cpp */
#include "MtrxArray.h"
#include "Mtrx.h"
MtrxArray::MtrxArray(int arraySize) { // constructor
	mtrxArraySize = arraySize;
	pMtrx = new Mtrx[arraySize];
}
MtrxArray::~MtrxArray() {
	//cout << "MtrxArray :: destructor" << endl;
	if (pMtrx != NULL)
		delete[] pMtrx;
}
void subError() {
	cout << "ERROR: Subscript out of range.₩n";
	exit(0);
}
bool MtrxArray::isValidIndex(int index) {
	if (index < 0 || index >= mtrxArraySize)
		return false;
	else
		return true;
}
Mtrx& MtrxArray::operator [](int sub) {
	if (isValidIndex(sub))
		return pMtrx[sub];
	else
		subError();
}
