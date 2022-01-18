/* T_BSTN.h */
#ifndef T_BSTN_H
#define T_BSTN_H
#include <iostream>
#include <iomanip>
using namespace std;
template<typename E>
class T_BSTN // binary search tree node
{
public:
	T_BSTN() : entry(), pPr(NULL), pLc(NULL), pRc(NULL) { } // default constructor
	T_BSTN(E e) : entry(e), pPr(NULL), pLc(NULL), pRc(NULL) { } // constructor
	E& getEntry() { return entry; }
	void setEntry(E e) { entry = e; }
	T_BSTN<E>* getpPr() { return pPr; }
	T_BSTN<E>* getpLc() { return pLc; }
	T_BSTN<E>* getpRc() { return pRc; }
	T_BSTN<E>** getppLc() { return &pLc; }
	T_BSTN<E>** getppRc() { return &pRc; }
	void setpPr(T_BSTN<E>* pTN) { pPr = pTN; }
	void setpLc(T_BSTN<E>* pTN) { pLc = pTN; }
	void setpRc(T_BSTN<E>* pTN) { pRc = pTN; }
	E& operator*() { return entry; }
private:
	E entry; // element value
	T_BSTN<E>* pPr; // parent
	T_BSTN<E>* pLc; // left child
	T_BSTN<E>* pRc; // right child
};
#endif // !T_BSTN_H