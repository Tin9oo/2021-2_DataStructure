/* MtrxArray.cpp */
#include <iostream>
#include "MtrxArray.h"
using namespace std;

ostream& operator<<(ostream& fout, const MtrxArray& m) {
	for (int i = 0; i < m.mtrxArraySize; i++)
		fout << m.pMtrx[i];

	return fout;
}
MtrxArray::MtrxArray(int array_size) { // constructor
	mtrxArraySize = array_size;
	pMtrx = new Mtrx[array_size];
}
MtrxArray::~MtrxArray() { // destructor
	//cout << "MtrxArray :: destructor" << endl;
	if (pMtrx != NULL)
		delete[] pMtrx;
}
Mtrx& MtrxArray::operator[](int index) {
	if (isValidIndex(index))
		return pMtrx[index];
	else {
		cout << "ERROR: Subscript out of range.₩n";
		exit(0);
	}
}
bool MtrxArray::isValidIndex(int index) {
	if (index < 0 || index >= mtrxArraySize)
		return false;
	else
		return true;
}
