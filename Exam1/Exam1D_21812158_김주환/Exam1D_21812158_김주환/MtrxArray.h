/* MtrxArray.h */
#ifndef MA
#define MA
#include "Mtrx.h"
using namespace std;
class MtrxArray
{
	friend ostream& operator<<(ostream&, const MtrxArray&); // MtrxArray 출력
public:
	MtrxArray(int array_size); // constructor
	~MtrxArray(); // destructor
	Mtrx& operator[](int); // 인덱스 연산자
private:
	Mtrx* pMtrx;
	int mtrxArraySize;
	bool isValidIndex(int index); // 유효한 index 인지 확인
};
#endif // !MA