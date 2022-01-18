/* CompleteBinaryTree.h */
#ifndef CBT_H
#define CBT_H
#include "T_Array.h"

#define CBT_ROOT 1

template<typename E>
class CompleteBinaryTree : public T_Array<E>
{
public:
	CompleteBinaryTree(int capa, string nm);
	int add_at_end(E& elem);
	E& getEndElement() { return this->t_array[end]; }
	E& getRootElement() { return this->t_array[CBT_ROOT]; }
	int getEndIndex() { return end; }
	void removeCBTEnd();
	void printCBT();
	void printCBT_byLevel();
protected:
	void _printCBT_byLevel(int p, int level);
	int parentIndex(int index) { return index / 2; }
	int leftChildIndex(int index) { return index * 2; }
	int rightChildIndex(int index) { return (index * 2 + 1); }
	bool hasLeftChild(int index) { return ((index * 2) <= end); }
	bool hasRightChild(int index) { return ((index * 2 + 1) <= end); }
	int end;
};
template<typename E>
CompleteBinaryTree<E>::CompleteBinaryTree(int capa, string nm)
	:T_Array<E>(capa, nm)
{
	end = 0; // reset to empty
}
template<typename E>
void CompleteBinaryTree<E>::printCBT()
{
	if (end <= 0)
	{
		cout << this->getName() << " is empty now !!" << endl;
		return;
	}
	int count = 0;
	for (int i = 1; i <= end; i++)
	{
		cout << setw(3) << this->t_array[i] << endl;
		//if ((((count + 1) % 10) == 0) && (i != end))
		//fout << endl;
		count++;
	}
}
template<typename E>
void CompleteBinaryTree<E>::_printCBT_byLevel(int index, int level)
{
	int index_child;
	if (this->hasRightChild(index))
	{
		index_child = this->rightChildIndex(index);
		this->_printCBT_byLevel(index_child, level + 1);
	}
	for (int i = 0; i < level; i++)
		cout << "   ";
	// this->t_GA[index].fprint(fout);
	cout << this->t_array[index];
	cout << endl;
	if (this->hasLeftChild(index))
	{
		index_child = this->leftChildIndex(index);
		this->_cprintCBT_byLevel(index_child, level + 1);
	}
}
template<typename E>
void CompleteBinaryTree<E>::printCBT_byLevel()
{
	if (end <= 0)
	{
		cout << "CBT is EMPTY now !!" << endl;
		return;
	}
	_printCBT_byLevel(CBT_ROOT, 0);
}
template<typename E>
int CompleteBinaryTree<E>::add_at_end(E& elem)
{
	if (end >= this->capacity)
	{
		cout << this->getName() << " is FULL now !!" << endl;
		return end;
	}
	end++;
	this->t_array[end] = elem;
	return end;
}
template<typename E>
void CompleteBinaryTree<E>::removeCBTEnd()
{
	end--;
	this->num_elements--;
}

#endif // !CBT_H
