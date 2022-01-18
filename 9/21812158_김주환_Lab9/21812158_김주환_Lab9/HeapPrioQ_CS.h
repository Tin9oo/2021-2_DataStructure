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

	T_Entry<K, V>* insert(T_Entry<K, V>& elem); // 전달받은 element를 삽입, add_at_end()
	T_Entry<K, V>* removeHeapMin(); // 우선순위가 가장 높은 element 추출 후 반환
	T_Entry<K, V>* getHeapMin(); // 우선순위가 가장 높은 element 반환

	void fprint(ostream& fout);
	int size() { return this->end; }
private:
	int heapPriQ_capa; // Heap priority Queue의 capacity
	mutex cs_priQ; // priority queue의 운용에 사용되는 mutex
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
	index = this->add_at_end(elem); // last node에 element insert
	
	/* up-heap bubbling */
	while (index != CBT_ROOT) {
		parent_index = this->parentIndex(index); // parent index 저장
		if (this->t_array[index].getKey() >= this->t_array[parent_index].getKey())
			break;
		else { // child node의 우선순위가 parent node의 우선순위보다 높은 경우
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
	if (HPQ_size <= 0) { // element가 없다.
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
		this->t_array[CBT_ROOT] = this->t_array[this->end]; // last node element를 root node element로 이동
		this->end--;
		
		/* down-heap bubbling */
		while (this->hasLeftChild(index_p)) { // left child 존재
			index_c = this->leftChildIndex(index_p);
			index_rc = this->rightChildIndex(index_p);
			// right child가 있고 right child의 우선순위가 left child의 우선순위보다 높은 경우 아래의 조건문을 실행
			if (this->hasRightChild(index_p) && (this->t_array[index_c] > this->t_array[index_rc]))
				index_c = index_rc;
			t_p = this->t_array[index_p];
			t_c = this->t_array[index_c];
			if (t_p > t_c) { // child의 우선순위가 더 높다.
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