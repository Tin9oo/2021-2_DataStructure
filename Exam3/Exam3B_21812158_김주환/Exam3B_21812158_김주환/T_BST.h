/* T_BST.h */
#ifndef T_BST_H
#define T_BST_H
#include "T_BSTN.h"
template<typename E>
class T_BST
{
public:
	T_BST(string nm) : // constructor
		_root(NULL), num_entry(0), name(nm) {} // constructor
	string getName() { return name; }
	int size() const { return num_entry; }
	bool empty() const { return num_entry == 0; }
	T_BSTN<E>* getRoot() { return _root; }
	T_BSTN<E>** getRootAddr() { return &_root; }
	T_BSTN<E>* eraseBSTN(T_BSTN<E>** pp);
	void insertInOrder(const E entry);
	void insertAndRebalance(E e);
	void print_with_Depth();
	void print_inOrder();
protected:
	T_BSTN<E>* _insertInOrder(T_BSTN<E>** p, T_BSTN<E>* parenPos, const E e);
	T_BSTN<E>* _insertAndRebalance(T_BSTN<E>** ppTN, T_BSTN<E>* pPr, E e);
	T_BSTN<E>* _rotate_LL(T_BSTN<E>* pCurSubRoot);
	T_BSTN<E>* _rotate_RR(T_BSTN<E>* pCurSubRoot);
	T_BSTN<E>* _rotate_RL(T_BSTN<E>* pCurSubRoot);
	T_BSTN<E>* _rotate_LR(T_BSTN<E>* pCurSubRoot);
	int _getHeight(T_BSTN<E>* pTN);
	int _getHeightDiff(T_BSTN<E>* pTN);
	T_BSTN<E>* _reBalance(T_BSTN<E>** ppTN);
	void _print_with_Depth(T_BSTN<E>* pTN, int depth);
	void _print_inOrder(T_BSTN<E>* pTN);
private:
	T_BSTN<E>* _root; // pointer to the root
	int num_entry; // number of tree nodes
	string name;
}; // end of class T_BST
template<typename E>
T_BSTN<E>* T_BST<E>::_insertInOrder(T_BSTN<E>** pp,
	T_BSTN<E>* parenPos, const E e)
{
	T_BSTN<E>* newPos, ** pChildPos;
	T_BSTN<E>* pos;
	E ent;

	if (pp == NULL) // 구성이 제대로 안됨
	{
		cout << "Error in creation of BinarySearchTree :";
		cout << " address of the pointer to the Root Node is NULL !!₩n";
		exit;
	}
	pos = *pp;
	if (pos == NULL) // 트리가 비어있다.
	{
		pos = new T_BSTN<E>(e);
		if (parenPos == NULL) // 부모가 없다 => root
		{
			_root = pos; // initialize the root node
		}
		pos->setpPr(parenPos);
		*pp = pos; // 위에서 동적할당한 노드의 주소
		num_entry++; // increment the number of elements
		return pos;
	}
	ent = pos->getEntry();
	if (e < ent)
	{
		pChildPos = pos->getppLc();
		newPos = _insertInOrder(pChildPos, pos, e);
		if (newPos != NULL)
			pos->setpLc(newPos);
		return NULL; // only the leaf child is set correctly, while the intermediate node is skipped
	}
	else if (e >= ent)
	{
		pChildPos = pos->getppRc();
		newPos = _insertInOrder(pChildPos, pos, e);
		if (newPos != NULL)
			pos->setpRc(newPos);
		return NULL; // only the leaf child is set correctly, while the intermediate node is skipped
	}
}
template<typename E>
void T_BST<E>::insertInOrder(const E e)
{
	_insertInOrder(&_root, NULL, e);
}
template<typename E>
void T_BST<E>::_print_inOrder(T_BSTN<E>* pTN)
{
	T_BSTN<E>* pRc, * pLc;
	if ((pLc = pTN->getpLc()) != NULL)
		_print_inOrder(pLc);
	cout << pTN->getEntry() << " ";
	if ((pRc = pTN->getpRc()) != NULL)
		_print_inOrder(pRc);
}
template<typename E>
void T_BST<E>::print_inOrder()
{
	T_BSTN<E>* root = getRoot();
	if (num_entry == 0)
	{
		cout << getName() << " is empty now !!" << endl;
		return;
	}
	_print_inOrder(root);
}
template<typename E>
void T_BST<E>::_print_with_Depth(T_BSTN<E>* pTN, int depth)
{
	T_BSTN<E>* pRc, * pLc;
	if ((pRc = pTN->getpRc()) != NULL)
		_print_with_Depth(pRc, depth + 1);
	for (int i = 0; i < depth; i++)
	{
		cout << "    ";
	}
	cout << pTN->getEntry() << endl;
	if ((pLc = pTN->getpLc()) != NULL)
		_print_with_Depth(pLc, depth + 1);
}
template<typename E>
void T_BST<E>::print_with_Depth()
{
	T_BSTN<E>* root = getRoot();
	if (num_entry == 0)
	{
		cout << getName() << " is empty now !!" << endl;
		return;
	}
	_print_with_Depth(root, 0);
}
template<typename E>
T_BSTN<E>* T_BST<E>::eraseBSTN(T_BSTN<E>** pptoBeErased)
// remove BSTN considering balance of the BST
{
	T_BSTN<E>* newSubRoot, * temp, * w, * wlc;
	T_BSTN<E>* toBeErased;
	toBeErased = *pptoBeErased;
	if (toBeErased == NULL)
		return NULL;
	if ((toBeErased->getpLc() == NULL) && (toBeErased->getpRc() == NULL))
		// no child
	{
		newSubRoot = NULL;
	}
	else if ((toBeErased->getpLc() != NULL) && (toBeErased->getpRc() == NULL))
		// only left child
	{
		newSubRoot = toBeErased->getpLc();
		newSubRoot->setpPr(toBeErased->getpPr());
	}
	else if ((toBeErased->getpLc() == NULL) && (toBeErased->getpRc() != NULL))
		// only right child
	{
		newSubRoot = toBeErased->getpRc();
		newSubRoot->setpPr(toBeErased->getpPr());
	}
	else
	{ /* tree node to be deleted has both left child and right child */
		int heightDiff = _getHeightDiff(toBeErased);
		T_BSTN<E>* parDel = toBeErased->getpPr();
		T_BSTN<E>* lChild = toBeErased->getpLc();
		T_BSTN<E>* rChild = toBeErased->getpRc();
		T_BSTN<E>* ioSs = NULL, * rcIoSs, * parIoSs;
		T_BSTN<E>* ioPd = NULL, * lcIoPd, * parIoPd;
		if (heightDiff > 0)
			// left subtree is higher, so put the ioPd in the place of the erased node
		{
			ioPd = _maxBSTN(lChild); // in-order predecessor (ioPd)
			lcIoPd = ioPd->getpLc();
			parIoPd = ioPd->getpPr();
			newSubRoot = ioPd;
			if (ioPd->getpPr() != toBeErased)
			{
				newSubRoot->setpLc(lChild);
				parIoPd->setpRc(lcIoPd);
				if (lcIoPd != NULL)
					lcIoPd->setpPr(parIoPd);
			}
			newSubRoot->setpRc(rChild);
			newSubRoot->setpPr(toBeErased->getpPr());
		}
		else
			// right subtree is higher, so put the ioSs in the place of the erased node
		{
			ioSs = _minBSTN(rChild); // in-order successor (ioSs)
			rcIoSs = ioSs->getpRc();
			parIoSs = ioSs->getpPr();
			newSubRoot = ioSs;
			if (ioSs->getpPr() != toBeErased)
			{
				newSubRoot->setpRc(rChild);
				parIoSs->setpLc(rcIoSs);
				if (rcIoSs != NULL)
					rcIoSs->setpPr(parIoSs);
			}
			newSubRoot->setpLc(lChild);
			newSubRoot->setpPr(toBeErased->getpPr());
		}
		if (lChild != ioPd)
			lChild->setpPr(newSubRoot);
		if (rChild != ioSs)
			rChild->setpPr(newSubRoot);
	}
	if (toBeErased == _root)
		_root = newSubRoot;
	num_entry--; // decrement the number of entries in the BST
	free(toBeErased);
	*pptoBeErased = newSubRoot;
	return newSubRoot;
}
template<typename E>
int T_BST<E>::_getHeight(T_BSTN<E>* pTN)
{
	int height = 0;
	int height_Lc, height_Rc;
	if (pTN != NULL)
	{
		height_Lc = _getHeight(pTN->getpLc());
		height_Rc = _getHeight(pTN->getpRc());
		if (height_Lc > height_Rc)
			height = 1 + height_Lc;
		else
			height = 1 + height_Rc;
	}
	return height;
}
template<typename E>
int T_BST<E>::
_getHeightDiff(T_BSTN<E>* pTN)
{
	int heightDiff = 0;
	if (pTN == NULL)
		return 0;
	heightDiff = _getHeight(pTN->getpLc())
		- _getHeight(pTN->getpRc());
	return heightDiff;
}
template<typename E>
T_BSTN<E>* T_BST<E>::_rotate_LL(T_BSTN<E>* pCurSubRoot)
{
	T_BSTN<E>* pNewSubRoot, * pBR, * pCurParent;
	pCurParent = pCurSubRoot->getpPr(); // 현재 서브루트의 부모를 현재부모로 설정
	pNewSubRoot = pCurSubRoot->getpLc(); // 현재 서브루트의 왼쪽 자식을 새로운 서브루트로 설정
	pBR = pNewSubRoot->getpRc(); // 새로운 서브루트의 오른쪽 자식을 BR로 설정
	pCurSubRoot->setpLc(pBR); // 현재 서브루트의 왼쪽 자식을 BR로 설정
	if (pBR != NULL)
		pBR->setpPr(pCurSubRoot); // BR의 부모를 현재 서브루트로 설정
	pNewSubRoot->setpRc(pCurSubRoot); // 새로운 서브루트의 오른쪽 자식을 현재 서브루트로 설정
	pNewSubRoot->setpPr(pCurParent); // 새로운 서브루트의 부모를 현재 부모로 설정
	pCurSubRoot->setpPr(pNewSubRoot); // 현재 서브루트의 부모를 새로운 서브루트로 설정
	return pNewSubRoot; // 새로운 서브루트 반환
}
template<typename E>
T_BSTN<E>* T_BST<E>::_rotate_RR(T_BSTN<E>* pCurSubRoot)
{
	T_BSTN<E>* pNewSubRoot, * pBL, * pCurParent;
	pCurParent = pCurSubRoot->getpPr(); // 현재 서브루트의 부모를 현재 부모로 설정
	pNewSubRoot = pCurSubRoot->getpRc(); // 현재 서브루트의 오른쪽 자식을 새로운 서브루트로 설정
	pBL = pNewSubRoot->getpLc();// 새로운 서브루트의 왼쪽 자식을 BL로 설정
	pCurSubRoot->setpRc(pBL);// 현재 서브루트의 오른쪽 자식을 BR로 설정
	if (pBL != NULL)
		pBL->setpPr(pCurSubRoot);// BL의 부모를 현재 서브루트로 설정
	pNewSubRoot->setpLc(pCurSubRoot);// 새로운 서브루트의 왼쪽 자식을 현재 서브루트로 설정
	pNewSubRoot->setpPr(pCurParent);// 새로운 서브루트의 부모를 현재 부모로 설정
	pCurSubRoot->setpPr(pNewSubRoot); // 현재 서브루트의 부모를 새로운 서브루트로 설정
	return pNewSubRoot;// 새로운 서브루트 반환
}
template<typename E>
T_BSTN<E>* T_BST<E>::_rotate_LR(T_BSTN<E>* pCurSubRoot)
{
	T_BSTN<E>* pSubRoot, * pNewSubRoot, * pCurParent;
	T_BSTN<E>* pA, * pB, * pC, * pBL, * pBR;
	pC = pCurSubRoot; // 현재 서브루트
	pCurParent = pCurSubRoot->getpPr(); // 현재부모
	pA = pC->getpLc(); // A를 C의 왼쪽 자식으로 설정
	pB = pA->getpRc(); // B를 A의 오른쪽 자식으로 설정
	pBL = pB->getpLc(); // BL을 B의 왼쪽 자식으로 설정
	pBR = pB->getpRc(); // BR을 B의 오른쪽 자식으로 설정
	pSubRoot = _rotate_RR(pA); // A 기준 rotateRR을 해서 서브루트 반환
	pCurSubRoot->setpLc(pSubRoot); // 현재 서브루트의 왼쪽 자식을 서브루트로 설정
	pNewSubRoot = _rotate_LL(pC); // C 기준 rotateLL을 해서 서브루트 반환
	pNewSubRoot->setpPr(pCurParent); // 새로운 서브루트의 부모를 현재 부모로 설정
	pA->setpPr(pNewSubRoot); // A의 부모를 새로운 서브루트로 설정
	pC->setpPr(pNewSubRoot); // C의 부모를 새로운 서브루트로 설정
	if (pBL != NULL)
		pBL->setpPr(pA); // BL의 부모를 A로 설정
	if (pBR != NULL)
		pBR->setpPr(pC); // BR의 부모를 C로 설정
	return pNewSubRoot; // 새로운 서브루트 반환
}
template<typename E>
T_BSTN<E>* T_BST<E>::_rotate_RL(T_BSTN<E>* pCurSubRoot)
{
	T_BSTN<E>* pSubRoot, * pNewSubRoot, * pCurParent;
	T_BSTN<E>* pA, * pB, * pC, * pBL, * pBR;
	pA = pCurSubRoot; // 현재 서브루트
	pCurParent = pCurSubRoot->getpPr(); // 현재 부모
	pC = pA->getpRc(); // C를 A의 오른쪽 자식으로 설정
	pB = pC->getpLc(); // B를 C의 왼쪽 자식으로 설정
	pBL = pB->getpLc(); // BL을 B의 왼쪽 자식으로 설정
	pBR = pB->getpRc(); // BR을 B의 오른쪽 자식으로 설정
	pSubRoot = _rotate_LL(pC); // C 기준 rotateLL을 통해 서브루트 반환
	pCurSubRoot->setpRc(pSubRoot); // 현재 서브루트의 오른쪽 자식을 서브루트로 설정
	pNewSubRoot = _rotate_RR(pA); // A 기준 rotateRR을 통해 새로운 서브루트로 반환
	pNewSubRoot->setpPr(pCurParent); // 새로운 서브루트의 부모를 현재 부모로 설정
	pA->setpPr(pNewSubRoot); // A의 부모를 새로운 서브루트로 설정
	pC->setpPr(pNewSubRoot); // C의 부모를 새로운 서브루트로 설정
	if (pBL != NULL)
		pBL->setpPr(pA); // BL의 부모를 A로 설정
	if (pBR != NULL)
		pBR->setpPr(pC); // BR의 부모를 C로 설정
	return pNewSubRoot; // 새로운 서브루트 반환
}
template<typename E>
T_BSTN<E>* T_BST<E>::_reBalance(T_BSTN<E>** ppTN)
{
	int heightDiff = 0;
	heightDiff = _getHeightDiff(*ppTN);
	if (heightDiff > 1) // left subtree is higher
	{
		if (_getHeightDiff((*ppTN)->getpLc()) > 0)
			*ppTN = _rotate_LL(*ppTN);
		else
			*ppTN = _rotate_LR(*ppTN);
	}
	else if (heightDiff < -1) // right subtree is higher
	{
		if (_getHeightDiff((*ppTN)->getpRc()) < 0)
			*ppTN = _rotate_RR(*ppTN);
		else
			*ppTN = _rotate_RL(*ppTN);
	}
	return *ppTN;
}
template<typename E>
void T_BST<E>::insertAndRebalance(E e)
{
	_insertAndRebalance(&_root, NULL, e);
}
template<typename E>
T_BSTN<E>* T_BST<E>::_insertAndRebalance(T_BSTN<E>** ppTN,
	T_BSTN<E>* pPr, E e)
{
	T_BSTN<E>* pTN, ** ppLc, ** ppRc;
	if (*ppTN == NULL) // attach a new tree node at the currently external node
	{
		pTN = new T_BSTN<E>(e);
		*ppTN = pTN;
		if (pPr != NULL) // if not root
			pTN->setpPr(pPr);
		(*ppTN)->setpLc(NULL);
		(*ppTN)->setpRc(NULL);
		num_entry++;
		return *ppTN;
	}
	E bstn_entry;
	bstn_entry = (*ppTN)->getEntry();
	if (e < bstn_entry) // T_Entry<K, V> must provide ‘<’ operator overloading !!
	{
		ppLc = (*ppTN)->getppLc();
		pTN = _insertAndRebalance(ppLc, *ppTN, e);
		if (ppTN != NULL)
		{
			(*ppTN)->setpLc(pTN);
			*ppTN = _reBalance(ppTN);
		}
	}
	else // entry >= bstn_entry
	{
		ppRc = (*ppTN)->getppRc();
		pTN = _insertAndRebalance(ppRc, *ppTN, e);
		if (ppTN != NULL)
		{
			(*ppTN)->setpRc(pTN);
			*ppTN = _reBalance(ppTN);
		}
	}
	return *ppTN;
}
#endif // !T_BST_H