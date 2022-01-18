/* TA_CirQ.h */
#ifndef TA_C_H
#define TA_C_H
#include <mutex>
#include "T_Array.h"
template<typename E>
class TA_CirQ : public T_Array<E>
{
private:
	int front; // index of queue_front
	int back; // index of queue_back
	mutex mtx_cirQ;
public:
	TA_CirQ(int capacity, string nm); // constructor
	~TA_CirQ() {} //destructor
	E* dequeue(); // return the element at top of stack
	E* enqueue(E& element); // pop the data block at top of the stack
	bool isEmpty() { return (this->num_elements == 0); }
	bool isFull() { return (this->num_elements >= this->capacity); }
	int size() { return this->num_elements; }
	void fprint(ostream& fout, int elements_per_line);
};
template<typename E>
TA_CirQ<E>::TA_CirQ(int cap, string nm)
	:T_Array(cap, nm)
	// initialization section in constructor
{
	front = back = 0;
}
template<typename E>
E* TA_CirQ<E>::dequeue()
// dequeue the data at front of the queue
{
	if (isEmpty())
		return NULL;
	else
	{
		E* pE;
		pE = &t_array[front];
		front++;
		num_elements--;
		if (front >= capacity)
			front = front % capacity;
		return pE;
	}
}
template<typename E>
E* TA_CirQ<E>::enqueue(E& element)
// push into the stack
{
	if (isFull())
	{
		cout << "Queue is Full !\n";
		return NULL;
	}
	E* pE;
	t_array[back] = element;
	pE = &t_array[back];
	back++;
	if (back >= capacity)
		back = back % capacity;
	num_elements++;
	return pE;
}
template<typename E>
void TA_CirQ<E>::fprint(ostream& fout, int elements_per_line)
{
	int count = 0;
	int index;
	if (num_elements <= 0)
	{
		fout << endl << this->getName() << " is Empty now !" << endl;
	}
	CirItor p; // circular Iterator
	for (p = begin(); p != end(); ++p)
	{
		count++;
		fout << setw(5) << *p;
		if ((count % elements_per_line) == 0)
			fout << endl << " ";
	}
}
#endif // !TA_C_H
