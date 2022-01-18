#ifndef MA
#define MA
#include "Mtrx.h"
class MtrxArray
{
public:
	MtrxArray(int array_size, int n_row, int n_col); // constructor
	~MtrxArray(); // destructor
	Mtrx& operator[](int);
private:
	Mtrx* pMtrx;
	int mtrxArraySize;
	bool isValidIndex(int index);
};
#endif // !MA
