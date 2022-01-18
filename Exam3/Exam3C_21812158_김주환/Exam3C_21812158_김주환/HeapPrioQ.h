/* HeapPrioQ.h */
#ifndef HPQ_H
#define HPQ_H
#include "CompleteBinaryTree.h"

template<typename E>
class HeapPrioQueue : public CompleteBinaryTree<E>
{
public:
	HeapPrioQueue(int capa, string nm);
	~HeapPrioQueue();
	bool isEmpty() { return size() == 0; }
	bool isFull() { return size() == this->capacity; }
	int insert(E& elem);
	E* removeHeapMin();
	E* getHeapMin();
	void fprint(ofstream& fout);
	int size() { return this->end; }
};
template<typename E>
HeapPrioQueue<E>::HeapPrioQueue(int capa, string nm)
	:CompleteBinaryTree<E>(capa, nm)
{ }
template<typename E>
HeapPrioQueue<E>::~HeapPrioQueue()
{ }
template<typename E>
void HeapPrioQueue<E>::fprint(ofstream& fout)
{
	if (size() <= 0)
	{
		fout << "HeapPriorityQueue is Empty !!" << endl;
		return;
	}
	else
		CompleteBinaryTree::printCBT(fout);
}
template<typename E>
int HeapPrioQueue<E>::insert(E& elem)
{
	int index, parent_index;
	E temp;
	if (isFull())
	{
		cout << this->getName() << " is Full !!" << endl;
		return size();
	}
	index = this->add_at_end(elem);
	/* up-heap bubbling */
	while (index != CBT_ROOT)
	{
		parent_index = this->parentIndex(index);
		if (this->t_array[index] > this->t_array[parent_index])
			break;
		else
		{
			temp = this->t_array[index];
			this->t_array[index] = this->t_array[parent_index];
			this->t_array[parent_index] = temp;
			index = parent_index;
		}
	}
	return size();
}
template<typename E>
E* HeapPrioQueue<E>::getHeapMin()
{
	E* pMinElem;
	if (size() <= 0)
	{
		return NULL;
	}
	pMinElem = (E*) new E;
	*pMinElem = this->getRootElement();
	return pMinElem;
}
template<typename E>
E* HeapPrioQueue<E>::removeHeapMin()
{
	int index_p, index_c, index_rc;
	E* pMinElem;
	E temp, t_p, t_c;
	int HPQ_size = size();
	if (HPQ_size <= 0)
	{
		return NULL;
	}
	pMinElem = (E*) new E;
	*pMinElem = this->getRootElement();
	if (HPQ_size == 1)
		this->removeCBTEnd();
	else {
		index_p = CBT_ROOT;
		this->t_array[CBT_ROOT] = this->t_array[this->end];
		this->end--;
		/* down-heap bubbling */
		while (this->hasLeftChild(index_p))
		{
			index_c = this->leftChildIndex(index_p);
			index_rc = this->rightChildIndex(index_p);
			if (this->hasRightChild(index_p) && (this->t_array[index_c] > this->t_array[index_rc]))
				index_c = index_rc;
			t_p = this->t_array[index_p];
			t_c = this->t_array[index_c];
			if (t_p > t_c)
			{
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
	return pMinElem;
}

#endif // !HPQ_H
