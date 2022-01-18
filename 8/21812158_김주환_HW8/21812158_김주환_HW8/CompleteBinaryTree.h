/* CompleteBinaryTree.h */
#ifndef CBT_H
#define CBT_H
#include "TA_Entry.h"

#define CBT_ROOT 1

template<typename K>
class CompleteBinaryTree : public TA_Entry<K> {
public:
	CompleteBinaryTree(int capa, string nm);

	int add_at_end(K& elem);
	K& getEndElement() { return this->t_GA[end]; }
	K& getRootElement() { return this->t_GA[CBT_ROOT]; }
	int getEndIndex() { return end; }
	void removeCBTEnd();
	void fprintCBT(ofstream& fout);
	void fprintCBT_byLevel(ofstream& fout);
protected:
	void _fprintCBT_byLevel(ofstream& fout, int p, int level);
	int parentIndex(int index) { return index / 2; }
	int leftChildIndex(int index) { return index * 2; }
	int rightChildIndex(int index) { return index * 2 + 1; }
	bool hasLeftChild(int index) { return (index * 2) <= end; }
	bool hasRightChild(int index) { return (index * 2 + 1) <= end; }
	int end;
};

template<typename K>
CompleteBinaryTree<K>::CompleteBinaryTree(int capa, string nm)
	:TA_Entry<K>(capa, nm)
{
	end = 0; // reset to empty
}
template<typename K>
void CompleteBinaryTree<K>::fprintCBT(ofstream& fout)
{
	if (end <= 0)
	{
		fout << this->getName() << " is empty now !!" << endl;
		return;
	}
	int count = 0;
	for (int i = 1; i <= end; i++)
	{
		fout << setw(3) << this->t_GA[i] << endl;
		//if ((((count + 1) % 10) == 0) && (i != end))
		//fout << endl;
		count++;
	}
}
template<typename K>
void CompleteBinaryTree<K>::_fprintCBT_byLevel(ofstream& fout, int index, int level)
{
	int index_child;
	if (this->hasRightChild(index))
	{
		index_child = this->rightChildIndex(index);
		this->_fprintCBT_byLevel(fout, index_child, level + 1);
	}
	for (int i = 0; i < level; i++)
		fout << "   ";
	// this->t_GA[index].fprint(fout);
	fout << this->t_GA[index];
	fout << endl;
	if (this->hasLeftChild(index))
	{
		index_child = this->leftChildIndex(index);
		this->_fprintCBT_byLevel(fout, index_child, level + 1);
	}
}
template<typename K>
void CompleteBinaryTree<K>::fprintCBT_byLevel(ofstream& fout)
{
	if (end <= 0)
	{
		fout << "CBT is EMPTY now !!" << endl;
		return;
	}
	_fprintCBT_byLevel(fout, CBT_ROOT, 0);
}
template<typename K>
int CompleteBinaryTree<K>::add_at_end(K& elem)
{
	if (end >= this->capacity)
	{
		cout << this->getName() << " is FULL now !!" << endl;
		return end;
	}
	end++;
	this->t_GA[end] = elem;
	return end;
}
template<typename K>
void CompleteBinaryTree<K>::removeCBTEnd()
{
	end--;
	this->num_elements--;
}
#endif // !CBT_H
