/* CompleteBinaryTree.h */
#ifndef COMPLETE_BINARY_TREE_H
#define COMPLETE_BINARY_TREE_H
#include "TA_Entry.h"
#include "T_Entry.h"

#define CBT_ROOT 1

template<typename K, typename V>
class CompleteBinaryTree : public TA_Entry<K, V> {
public:
	CompleteBinaryTree(int capa, string nm);

	int add_at_end(T_Entry<K, V>& elem); // CBT의 last node에 element 삽입

	T_Entry<K, V>& getEndElement() { return this->t_array[end]; } // last node 반환
	T_Entry<K, V>& getRootElement() { return this->t_array[CBT_ROOT]; } // root node 반환

	int getEndIndex() { return end; }
	void removeCBTEnd(); // last node element 제거

	void printCBT(ostream& fout);
	void printCBT_byLevel(ostream& fout);
protected:
	void _printCBT_byLevel(ostream& fout, int p, int level);

	int parentIndex(int index) { return index / 2; } // parent node index
	int leftChildIndex(int index) { return index * 2; } // left child node index
	int rightChildIndex(int index) { return (index * 2 + 1); } // right child node index

	bool hasLeftChild(int index) { return ((index * 2) <= end); } // left child node에 element가 있는지 확인
	bool hasRightChild(int index) { return ((index * 2 + 1) <= end); } // right child node에 element가 있는지 확인

	int end; // last node index
};
template<typename K, typename V>
CompleteBinaryTree<K, V>::CompleteBinaryTree(int capa, string nm)
	:TA_Entry<K, V>(capa + 1, nm) {
	end = 0; // reset to empty
}
template<typename K, typename V>
void CompleteBinaryTree<K, V>::printCBT(ostream& fout) {
	int cnt = 1;
	if (end <= 0) {
		fout << this->getName() << " is empty now !!" << endl;
		return;
	}
	int count = 0;
	for (int i = 1; i <= end; i++) {
		fout << setw(3) << this->t_array[i];
		if ((cnt++ % 5) == 0)
			fout << endl;
		//if ((((count + 1) % 10) == 0) && (i != end))
		//fout << endl;
		count++;
	}
}
template<typename K, typename V>
void CompleteBinaryTree<K, V>::_printCBT_byLevel(ostream& fout, int index, int level) {
	int index_child;
	if (hasRightChild(index)) {
		index_child = rightChildIndex(index);
		this->_printCBT_byLevel(fout, index_child, level + 1);
	}
	for (int i = 0; i < level; i++)
		fout << " ";
	this->t_array[index].fprint(fout);
	fout << endl;
	if (hasLeftChild(index)) {
		index_child = leftChildIndex(index);
		this->_printCBT_byLevel(fout, index_child, level + 1);
	}
}
template<typename K, typename V>
void CompleteBinaryTree<K, V>::printCBT_byLevel(ostream& fout) {
	if (end <= 0) {
		fout << "CBT is EMPTY now !!" << endl;
		return;
	}
	this->_printCBT_byLevel(fout, CBT_ROOT, 0);
}
template<typename K, typename V>
int CompleteBinaryTree<K, V>::add_at_end(T_Entry<K, V>& elem) {
	if (end >= this->capacity) {
		cout << this->getName() << " is FULL now !!" << endl;
		return -1;
	}
	end++;
	this->t_array[end] = elem;
	return end;
}
template<typename K, typename V>
void CompleteBinaryTree<K, V>::removeCBTEnd() {
	end--;
	this->num_elements--;
}
#endif