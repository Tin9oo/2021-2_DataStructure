/** CmplxArray.h */
#ifndef CMPLXARRAY_H
#define CMPLXARRAY_H
#include <iostream>
#include "Cmplx.h"
using namespace std;
class CmplxArray {
public:
	CmplxArray(int size); // constructor
	CmplxArray(const CmplxArray& obj);
	~CmplxArray();
	int size() { return cmplxArrySize; }
	Cmplx &operator[](int);
	void print(ostream& fout);
	void sort();
private:
	Cmplx* pCA;
	int cmplxArrySize;
	bool isValidIndex(int indx);
};
#endif