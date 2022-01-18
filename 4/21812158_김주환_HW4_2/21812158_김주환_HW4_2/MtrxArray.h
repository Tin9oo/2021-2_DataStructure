/** MtrxArray.h */
#ifndef MTRX_ARRAY_H
#define MTRX_ARRAY_H
#include <iostream>
#include "Mtrx.h"
using namespace std;
class Mtrx;
class MtrxArray
{
public:
	MtrxArray(int array_size); // constructor
	~MtrxArray(); // destructor
	Mtrx& operator[](int);
private:
	Mtrx* pMtrx;
	int mtrxArraySize;
	bool isValidIndex(int index);
};
#endif