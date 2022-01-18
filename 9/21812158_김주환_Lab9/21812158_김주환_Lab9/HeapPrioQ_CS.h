/* HeapPrioQ.h */
#ifndef HEAP_PRIO_QUEUE_H
#define HEAP_PRIO_QUEUE_H
#include <mutex>
#include "CompleteBinaryTree.h"
using namespace std;

template<typename K, typename V>
class HeapPrioQ_CS : public CompleteBinaryTree<K, V> {
public:
	HeapPrioQ_CS(int capa, string nm);
	~HeapPrioQ_CS();

	bool isEmpty() { return (this->end <= 0); }
	bool isFull() { return (this->end >= this->heapPriQ_capa); }

	T_Entry<K, V>* insert(T_Entry<K, V>& elem); // ���޹��� element�� ����, add_at_end()
	T_Entry<K, V>* removeHeapMin(); // �켱������ ���� ���� element ���� �� ��ȯ
	T_Entry<K, V>* getHeapMin(); // �켱������ ���� ���� element ��ȯ

	void fprint(ostream& fout);
	int size() { return this->end; }
private:
	int heapPriQ_capa; // Heap priority Queue�� capacity
	mutex cs_priQ; // priority queue�� ��뿡 ���Ǵ� mutex
};
template<typename K, typename V>
HeapPrioQ_CS<K, V>::HeapPrioQ_CS(int capa, string nm)
	:CompleteBinaryTree<K, V>(capa, nm) {
	heapPriQ_capa = capa;
}
template<typename K, typename V>
HeapPrioQ_CS<K, V>::~HeapPrioQ_CS()
{ }
template<typename K, typename V>
T_Entry<K, V>* HeapPrioQ_CS<K, V>::insert(T_Entry<K, V>& elem) {
	int index, parent_index;
	T_Entry<K, V> temp;
	if (isFull()) {
		cout << "HeapPrioQ is Full !!" << endl;
			return NULL;
	}

	cs_priQ.lock();
	index = this->add_at_end(elem); // last node�� element insert
	
	/* up-heap bubbling */
	while (index != CBT_ROOT) {
		parent_index = this->parentIndex(index); // parent index ����
		if (this->t_array[index].getKey() >= this->t_array[parent_index].getKey())
			break;
		else { // child node�� �켱������ parent node�� �켱�������� ���� ���
			temp = this->t_array[index];
			this->t_array[index] = this->t_array[parent_index];
			this->t_array[parent_index] = temp;
			index = parent_index;
		}
	}
	cs_priQ.unlock();
	T_Entry<K, V>* pRoot = &(this->t_array[CBT_ROOT]);
	return pRoot;
}
template<typename K, typename V>
T_Entry<K, V>* HeapPrioQ_CS<K, V>::removeHeapMin() {
	int index_p, index_c, index_rc;
	T_Entry<K, V>* pMinElem;
	T_Entry<K, V> temp, t_p, t_c;
	int HPQ_size = size();
	if (HPQ_size <= 0) { // element�� ����.
		return NULL;
	}
	cs_priQ.lock();
	pMinElem = (T_Entry<K, V>*) new T_Entry<K, V>;
	*pMinElem = this->getRootElement(); // root node element
	if (HPQ_size == 1) {
		this->removeCBTEnd();
	}
	else {
		index_p = CBT_ROOT;
		this->t_array[CBT_ROOT] = this->t_array[this->end]; // last node element�� root node element�� �̵�
		this->end--;
		
		/* down-heap bubbling */
		while (this->hasLeftChild(index_p)) { // left child ����
			index_c = this->leftChildIndex(index_p);
			index_rc = this->rightChildIndex(index_p);
			// right child�� �ְ� right child�� �켱������ left child�� �켱�������� ���� ��� �Ʒ��� ���ǹ��� ����
			if (this->hasRightChild(index_p) && (this->t_array[index_c] > this->t_array[index_rc]))
				index_c = index_rc;
			t_p = this->t_array[index_p];
			t_c = this->t_array[index_c];
			if (t_p > t_c) { // child�� �켱������ �� ����.
				//swap(index_u, index_c);
				temp = this->t_array[index_p];
				this->t_array[index_p] = this->t_array[index_c];
				this->t_array[index_c] = temp;
				index_p = index_c;
			}
			else
				break;
		} // end while
	}
	cs_priQ.unlock();
	return pMinElem;
}
template<typename K, typename V>
T_Entry<K, V>* HeapPrioQ_CS<K, V>::getHeapMin() {
	T_Entry<K, V>* pMinElem;
	if (this->end <= 0) {
		return NULL;
	}
	pMinElem = (T_Entry<K, V>*) new T_Entry<K, V>;
	*pMinElem = this->getRootElement();
	return pMinElem;
}
template<typename K, typename V>
void HeapPrioQ_CS<K, V>::fprint(ostream& fout) {
	if (size() <= 0) {
		fout << "HeapPriorityQueue is Empty !!" << endl;
		return;
	}
	else
		CompleteBinaryTree<K, V>::printCBT(fout);

}
#endif