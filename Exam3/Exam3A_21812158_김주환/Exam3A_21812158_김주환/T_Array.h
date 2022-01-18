/* T_Array.h */
#ifndef TA_H
#define TA_H
#include <iostream>
#include <iomanip>
using namespace std;

template<typename E>
class T_Array
{
public:
	T_Array(int capacity, string nm); // constructor
	~T_Array(); // destructor
	int size() { return num_elements; }
	bool empty() { return num_elements == 0; }
	string getName() { return name; }
	E& operator[](int index) { return t_array[index]; }
protected:
	E* t_array;
	int num_elements;
	int capacity;
	string name;
};
template<typename E>
T_Array<E>::T_Array(int new_capacity, string nm) { // constructor 
	t_array = (E*) new T[new_capacity];
	if (t_array == NULL) {
		cout << "Error in creation of dynamic array of size (" << new_capacity << ") !!" << endl;
		exit;
	}
	capacity = new_capacity;
	num_elements = 0;
	name = nm;
}
template<typename E>
T_Array<E>::~T_Array() { // destructor
	if (t_array != NULL)
		delete[] t_array;
}
#endif // !TA_H
