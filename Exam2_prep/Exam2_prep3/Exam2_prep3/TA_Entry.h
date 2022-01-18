/* TA_Entry.h */
#ifndef TA_ENTRY_H
#define TA_ENTRY_H
#include <iostream>
#include "T_Entry.h"
using namespace std;

enum SortingDirection { INCREASING, DECREASING };

template<typename K, typename V>
class TA_Entry
{
public:
	TA_Entry(int n, string nm); // constructor
	~TA_Entry(); // destructor
	int size() { return num_elements; }
	bool empty() { return num_elements == 0; }
	string getName() { return name; }
	void reserve(int new_capacity);
	void insert(int i, T_Entry<K, V> element);
	void selection_sort(SortingDirection sd); // Section 4에서 필요함
	void print();
	bool isValidIndex(int i);
	T_Entry<K, V>& operator[](int index) { return t_array[index]; }
protected:
	T_Entry<K, V>* t_array;
	int num_elements;
	int capacity;
	string name;
};
template<typename K, typename V>
TA_Entry<K, V>::TA_Entry(int n, string nm) {
	t_array = (T_Entry<K, V>*) new T_Entry<K, V>[n];
	if (t_array == NULL) {
		cout << "Error in creation of dynamic array of size (" << n << ") !!" << endl;
		exit;
	}
	capacity = n;
	num_elements = 0;
	name = nm;
}
template<typename K, typename V>
TA_Entry<K, V>::~TA_Entry() {
	if (t_array != NULL) delete[] t_array;
}
template<typename K, typename V>
void TA_Entry<K, V>::reserve(int new_capacity) {

}
template<typename K, typename V>
void TA_Entry<K, V>::insert(int i, T_Entry<K, V> element) {
	if (isValidIndex(i)) {
		for (int j = num_elements - 1; j >= i; j--)
			t_array[j + 1] = t_array[j]; //shift up elements in one position
		t_array[i] = element;
		num_elements++;
	}
}
template<typename K, typename V>
void TA_Entry<K, V>::selection_sort(SortingDirection sd) {
	
}
template<typename K, typename V>
void TA_Entry<K, V>::print() {
	int count = 0;
	while (count < num_elements)
	{
		t_array[count].T_Entry<K, V>::print();
		// cout << t_array[count] << " ";
		count++;
		if (count % 1 == 0)
			cout << endl;
	}
	cout << endl;
}
template<typename K, typename V>
bool TA_Entry<K, V>::isValidIndex(int i) {
	if ((i < 0) || (i > num_elements))
		return false;
	else
		return true;
}
#endif // !TA_ENTRY_H
