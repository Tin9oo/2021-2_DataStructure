/* MtrxArray.h */
#ifndef MA
#define MA
#include "Mtrx.h"
using namespace std;
class MtrxArray
{
	friend ostream& operator<<(ostream&, const MtrxArray&); // MtrxArray ���
public:
	MtrxArray(int array_size); // constructor
	~MtrxArray(); // destructor
	Mtrx& operator[](int); // �ε��� ������
private:
	Mtrx* pMtrx;
	int mtrxArraySize;
	bool isValidIndex(int index); // ��ȿ�� index ���� Ȯ��
};
#endif // !MA