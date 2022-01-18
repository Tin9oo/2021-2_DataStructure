/** CmplxArray.cpp */
#include "CmplxArray.h"
#include "Cmplx.h"
CmplxArray::CmplxArray(int size) // constructor
{
	cmplxArrySize = size;
	this->pCA = new Cmplx[size];
	for (int i = 0; i < size; i++) {
		this->pCA[i].real = 0.0;
		this->pCA[i].imag = 0.0;
	}
}
CmplxArray::CmplxArray(const CmplxArray& obj) // constructor
{
	cmplxArrySize = obj.cmplxArrySize;
	this->pCA = new Cmplx[cmplxArrySize];
	for (int i = 0; i < cmplxArrySize; i++) {
		this->pCA[i] = obj.pCA[i]; // *(pCA+i) = obj.pCA[i];
	}
}
CmplxArray::~CmplxArray() // destructor
{
	if (cmplxArrySize > 0)
		delete[] pCA;
}
bool CmplxArray::isValidIndex(int indx)
{
	if (indx < 0 || indx >= cmplxArrySize)
	{
		cout << "ERROR: the given index is out of range.₩n";
		exit(0);
	}
	else
		return true;
}
Cmplx& CmplxArray::operator [](int indx)
{
	if (isValidIndex(indx))
		return pCA[indx];
}
void CmplxArray::print(ostream& fout)
{
	for (int i = 0; i < cmplxArrySize; i++)
	{
		fout << pCA[i] << endl;
	}
}