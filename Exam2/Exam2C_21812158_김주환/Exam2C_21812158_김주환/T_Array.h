/* Template class T_Array.h */
#ifndef T_Array_H
#define T_Array_H
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Time.h"
using namespace std;

enum SortingOrder { INCREASING, DECREASING };

template<typename T, typename K>
class T_Array {
public:
	// 생성자 & 소멸자
	T_Array(int n, string nm); // constructor
	~T_Array(); // destructor

	int size() { return num_elements; }
	bool empty() { return num_elements == 0; }
	string getName() { return name; } // 이름 반환
	void insert(int i, T element);
	int sequential_search(string keyName, K search_key); // search and return the index; -1 if not found
	void selection_sort(string keyName, SortingOrder sortOrder);

	void print(int elements_per_line); // 출력
	bool isValidIndex(int i); // 유효한 인덱스인지 판단
	T& operator[](int index) { return t_array[index]; } // 인덱싱 작업
private:
	T* t_array;
	int num_elements;
	int capacity;
	string name;
};

template<typename T, typename K>
T_Array<T, K>::T_Array(int new_capacity, string nm) { // constructor 
	t_array = (T*) new T[new_capacity];
	if (t_array == NULL) {
		cout << "Error in creation of dynamic array of size (" << new_capacity << ") !!" << endl;
		exit;
	}
	capacity = new_capacity;
	num_elements = 0;
	name = nm;
}
template<typename T, typename K>
T_Array<T, K>::~T_Array() { // destructor
	if (t_array != NULL) delete[] t_array;
}
template<typename T, typename K>
bool T_Array<T, K>::isValidIndex(int index) {
	if ((index < 0) || (index > num_elements))
		return false;
	else
		return true;
}
template<typename T, typename K>
void T_Array<T, K>::insert(int i, T new_element) {
	if (isValidIndex(i)) {
		for (int j = num_elements - 1; j >= i; j--)
			t_array[j + 1] = t_array[j]; //shift up elements in one position
		t_array[i] = new_element;
		num_elements++;
	}
}
template<typename T, typename K>
int T_Array<T, K>::sequential_search(string keyName, K search_key) {
	int index;
	K key;
	if (keyName == "ST_ID") { // student_ID
		for (int index = 0; index < num_elements; index++) {
			t_array[index].getKey(keyName, &key);
			if (key == search_key)
				return index;
		}
	}
	return -1;
}
template<typename T, typename K>
void T_Array<T, K>::selection_sort(string keyName, SortingOrder sortOrder) {
	int index_min, index_max; // index of the element with minimum value
	T tempElement;
	K minKey, maxKey, key;

	for (int i = 0; i < num_elements - 1; i++) {
		if (sortOrder == INCREASING) { // sorting in increasing (non_decreasing) order
			index_min = i;
			t_array[i].getKey(keyName, &key); // 키 반환
			minKey = (K)key;
			for (int j = i + 1; j < num_elements; j++) {
				t_array[j].getKey(keyName, &key);
				if ((K)key < minKey) {
					index_min = j;
					minKey = (K)key;
				}
			}
			if (index_min != i) { // if a smaller element is found, then swap
				tempElement = t_array[index_min];
				t_array[index_min] = t_array[i];
				t_array[i] = tempElement;
			}
		}
		else { // sorting in decreasing (non_increasing) order
			index_max = i;
			t_array[i].getKey(keyName, &key);
			maxKey = (K)key;
			for (int j = i + 1; j < num_elements; j++) {
				t_array[j].getKey(keyName, &key);
				if ((K)key > maxKey) {
					index_max = j;
					maxKey = (K)key;
				}
			}
			if (index_max != i) { // if a smaller element is found, then swap  
				tempElement = t_array[index_max];
				t_array[index_max] = t_array[i];
				t_array[i] = tempElement;
			}
		}
	} // end for
}
template<typename T, typename K>
void T_Array<T, K>::print(int elements_per_line)
{
	int count = 0;
	while (count < num_elements)
	{
		for (int i = 0; i < elements_per_line; i++)
		{
			cout << t_array[count] << " ";
			count++;
			if (count % elements_per_line == 0)
				cout << endl;
		}
	}
	cout << endl;
}
#endif