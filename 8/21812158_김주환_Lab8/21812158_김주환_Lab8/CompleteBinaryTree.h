/* CompleteBinaryTree.h */
#ifndef CBT_H
#define CBT_H
#include "TA_Entry.h"
#include "T_Entry.h"

#define CBT_ROOT 1

template<typename K, typename V>
class CompleteBinaryTree : public TA_Entry<K, V> {
public:
	CompleteBinaryTree(int capa, string nm);

	int add_at_end(T_Entry<K, V>& elem);
	T_Entry<K, V>& getEndElement() { return this->t_GA[end]; }
	T_Entry<K, V>& getRootElement() { return this->t_GA[CBT_ROOT]; }
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

template<typename K, typename V>
CompleteBinaryTree<K, V>::CompleteBinaryTree(int capa, string nm)
	:TA_Entry<K, V>(capa, nm)
{
	end = 0; // reset to empty
}
template<typename K, typename V>
void CompleteBinaryTree<K, V>::fprintCBT(ofstream& fout)
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
template<typename K, typename V>
void CompleteBinaryTree<K, V>::_fprintCBT_byLevel(ofstream& fout, int index, int level)
{
	int index_child;
	if (this->hasRightChild(index))
	{
		index_child = this->rightChildIndex(index);
		this->_fprintCBT_byLevel(fout, index_child, level + 1);
	}
	for (int i = 0; i < level; i++)
		fout << "   ";
	this->t_GA[index].fprint(fout);
	fout << endl;
	if (this->hasLeftChild(index))
	{
		index_child = this->leftChildIndex(index);
		this->_fprintCBT_byLevel(fout, index_child, level + 1);
	}
}
template<typename K, typename V>
void CompleteBinaryTree<K, V>::fprintCBT_byLevel(ofstream& fout)
{
	if (end <= 0)
	{
		fout << "CBT is EMPTY now !!" << endl;
		return;
	}
	_fprintCBT_byLevel(fout, CBT_ROOT, 0);
}
template<typename K, typename V>
int CompleteBinaryTree<K, V>::add_at_end(T_Entry<K, V>& elem)
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
template<typename K, typename V>
void CompleteBinaryTree<K, V>::removeCBTEnd()
{
	end--;
	this->num_elements--;
}
#endif // !CBT_H
