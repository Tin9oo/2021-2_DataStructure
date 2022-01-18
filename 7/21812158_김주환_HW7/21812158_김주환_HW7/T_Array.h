/* Template class T_Array.h */
#ifndef T_Array_H
#define T_Array_H
#include <iostream>
#include <iomanip>
#include "Time.h"
using namespace std;

enum SortingOrder { INCREASING, DECREASING };

template<typename T>
class T_Array {
public:
	T_Array(int n, string nm); // constructor
	~T_Array(); // destructor
	string getName() { return name; }
	void reserve(int new_capacity);
	void insert(int i, T element);
	void remove(int i);
	T& at(int i);
	void set(int i, T& element);
	void shuffle();
	void selection_sort(SortingOrder sortOrder = INCREASING);
	void quick_sort(SortingOrder sortOrder = INCREASING);
	void fprint(ofstream& fout, int elements_per_line);
	bool isValidIndex(int i);
	T& operator[](int index) { return t_array[index]; }
private:
	T* t_array;
	int num_elements;
	int capacity;
	string name;
};

template<typename T>
T_Array<T>::T_Array(int new_capacity, string nm) { // constructor 
	t_array = (T*) new T[new_capacity];
	if (t_array == NULL) {
		cout << "Error in creation of dynamic array of size (" << new_capacity << ") !!" << endl;
		exit;
	}
	capacity = new_capacity;
	num_elements = 0;
	name = nm;
}
template<typename T>
T_Array<T>::~T_Array() { // destructor
	if (t_array != NULL)
		delete[] t_array;
}
template<typename T>
bool T_Array<T>::isValidIndex(int index) {
	if ((index < 0) || (index > num_elements))
		return false;
	else
		return true;
}
template<typename T>
void T_Array<T>::reserve(int new_capacity) {
	if (capacity >= new_capacity)
		return; // already big enough
	T* t_newGA = (T*) new T[new_capacity];
	if (t_newGA == NULL)
	{
		cout << "Error in creation of dynamic array of size (" << new_capacity << ") !!" << endl;
		exit;
	}
	cout << this->getName() << " expands capacity to " << setw(3)
		<< new_capacity << endl;
	for (int i = 0; i < num_elements; i++)
		t_newGA[i] = t_array[i];
	delete[] t_array;
	t_array = t_newGA;
	capacity = new_capacity;
}
template<typename T>
void T_Array<T>::insert(int i, T new_element) {
	if (num_elements >= capacity) // full ?
	{
		int new_capa;
		new_capa = ((2 * capacity) > 1) ? 2 * capacity : 1;
		reserve(new_capa);
	}
	if (isValidIndex(i))
	{
		for (int j = num_elements - 1; j >= i; j--)
			t_array[j + 1] = t_array[j]; //shift up elements in one position
		t_array[i] = new_element;
		num_elements++;
	}
}
template<typename T>
void T_Array<T>::remove(int i) {
	if (isValidIndex(i))
	{
		for (int j = i + 1; j < num_elements; j++)
			t_array[j - 1] = t_array[j]; //shift down elements in one position
		num_elements--;
	}
	if (num_elements < (capacity / 2))
	{
		int new_capacity = capacity / 2;
		T* t_newGA = (T*) new T[new_capacity];
		if (t_newGA == NULL)
		{
			return; // new memory allocation failed.
			// Just return without modification.
		}
		cout << this->getName()
			<< " reduces capacity to " << setw(3)
			<< new_capacity << endl;
		for (int i = 0; i < num_elements; i++)
			t_newGA[i] = t_array[i];
		delete[] t_array;
		t_array = t_newGA;
		capacity = new_capacity;
	}
}
template<typename T>
T& T_Array<T>::at(int i) {
	if (isValidIndex(i))
		return t_array[i];
}
template<typename T>
void T_Array<T>::set(int i, T& element) {
	if (isValidIndex(i))
		t_array[i] = element;
}
template<typename T>
void T_Array<T>::shuffle() {
	srand(time(0));
	int index1, index2;
	int rand_1, rand_2;
	T temp;
	for (int i = 0; i < num_elements; i++) {
		rand_1 = rand();
		rand_2 = rand();
		index1 = ((rand_1 << 15) | rand_2) % num_elements;
		rand_1 = rand();
		rand_2 = rand();
		index2 = ((rand_1 << 15) | rand_2) % num_elements;
		temp = t_array[index1];
		t_array[index1] = t_array[index2];
		t_array[index2] = temp;
	}
}
template<typename T>
void T_Array<T>::selection_sort(SortingOrder sortOrder) {
	int index_min, index_max; // index of the element with minimum value
	T minValue; // minimum value
	T maxValue;
	for (int i = 0; i < num_elements - 1; i++)
	{
		if (sortOrder == INCREASING) { // sorting in increasing (non_decreasing) order
			index_min = i;
			minValue = t_array[i];
			for (int j = i + 1; j < num_elements; j++)
			{
				if (t_array[j] < minValue) // T must provide operator<() overloading !!
				{
					index_min = j;
					minValue = t_array[j];
				}
			}
			if (index_min != i) // if a smaller element is found, then swap
			{
				/* minValue is t_array[min] */
				t_array[index_min] = t_array[i];
				t_array[i] = minValue;
			}
		}
		else { // sorting in decreasing (non_increasing) order
			index_max = i;
			maxValue = t_array[i];
			for (int j = i + 1; j < num_elements; j++)
			{
				if (t_array[j] > maxValue) // T must provide operator>() overloading !!
				{
					index_max = j;
					maxValue = t_array[j];
				}
			}
			if (index_max != i) // if a smaller element is found, then swap
			{
				/* maxValue is t_array[max] */
				t_array[index_max] = t_array[i];
				t_array[i] = maxValue;
			}
		}
	} // end for
}
template<typename T>
int _partition(T* array, int size, int left, int right, int pivotIndex, 
	SortingOrder sortOrder=INCREASING) {
	T pivotValue, temp; // pivot value
	int newPI; // new pivot index
	/* place the pivot element at right-position */
	pivotValue = array[pivotIndex];
	array[pivotIndex] = array[right];
	array[right] = pivotValue; // Move pivot to array[right]
	newPI = left; // newPI is the index that points the position
	// where pivot element will be finally re-located
	for (int i = left; i <= (right - 1); i++) {
		if (sortOrder == INCREASING) // sorting in increasing order
		{
			if (array[i] <= pivotValue) // T must provide operator<=() overloading !!
			{
				temp = array[i];
				array[i] = array[newPI];
				array[newPI] = temp;
				newPI = newPI + 1;
				// note: all elements in left of index newPI are equal or smaller than pivot_value
			}
		}
		else // sorting in decreasing (non_increasing) order
		{
			if (array[i] > pivotValue) // T must provide operator>() overloading !!
			{
				temp = array[i];
				array[i] = array[newPI];
				array[newPI] = temp;
				newPI = newPI + 1;
				// note: all elements in left of index newPI are greater than pivot_value
			}
		}
	} // end for
	// swap array[newPI] and array[right]; Move pivot element to its final place
	temp = array[newPI];
	array[newPI] = array[right];
	array[right] = temp;
	return newPI;
}
template<typename T>
void _quick_sort(T* array, int size, int left, int right, 
	SortingOrder sortOrder=INCREASING) {
	int pI, newPI; // pivot index
	if (left >= right)
	{
		return;
	}
	else
	{//select a pI (pivotIndex) in the range left ¡Â pI ¡Â right
		pI = (left + right) / 2;
	}
	newPI = _partition(array, size, left, right, pI, sortOrder);
	if (left < (newPI - 1)) {
		_quick_sort(array, size, left, newPI - 1, sortOrder);
		// recursively sort elements on the left of pivotNewIndex
	}
	if ((newPI + 1) < right) {
		_quick_sort(array, size, newPI + 1, right, sortOrder);
		// recursively sort elements on the right of pivotNewIndex
	}
}
template<typename T>
void T_Array<T>::quick_sort(SortingOrder sortOrder) {
	int pI, newPI; // pivot index
	_quick_sort(this->t_array, num_elements, 0, num_elements - 1, sortOrder);
}
template<typename T>
void T_Array<T>::fprint(ofstream& fout, int elements_per_line)
{
	int count = 0;
	while (count < num_elements)
	{
		for (int i = 0; i < elements_per_line; i++)
		{
			fout << t_array[count] << " ";
			count++;
			if (count % elements_per_line == 0)
				fout << endl;
		}
	}
	fout << endl;
}
#endif