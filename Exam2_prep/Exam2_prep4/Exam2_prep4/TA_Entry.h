/* TA_Entry.h */
#ifndef TA_ENTRY_H
#define TA_ENTRY_H
#include <iostream>
#include <iomanip>
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

	// Quick sorting
	int partition(SortingDirection sd, int left, int right, int pivotIndex);
	void _quick_sort(SortingDirection sd, int left, int right);
	void quick_sort(SortingDirection sd);

	// Merge sorting
	void _merge_sort(SortingDirection sd, T_Entry<K, V>* tmp_array, int left, int right);
	void merge_sort(SortingDirection sd);
	
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
	if (capacity >= new_capacity)
		return; // already big enough
	T_Entry* t_newGA = (T_Entry*) new T_Entry[new_capacity];
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
	int index_min, index_max; // index of the element with minimum value
	T_Entry<K, V> tempElement;
	K minKey, maxKey, key;

	for (int i = 0; i < num_elements - 1; i++) {
		if (sd == INCREASING) { // sorting in increasing (non_decreasing) order
			index_min = i;
			key = t_array[i].getKey(); // 키 반환
			minKey = (K)key;
			for (int j = i + 1; j < num_elements; j++) {
				key = t_array[j].getKey();
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
			key = t_array[i].getKey();
			maxKey = (K)key;
			for (int j = i + 1; j < num_elements; j++) {
				key = t_array[j].getKey();
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
template<typename K, typename V>
int TA_Entry<K, V>::partition(SortingDirection sd, int left, int right, int pivotIndex)
{
	K Key, tKey; // pivot value
	int i, newPI; // new pivot index
	T_Entry<K, V> temp;

	Key = t_array[pivotIndex].getKey();
	temp = t_array[pivotIndex];
	t_array[pivotIndex] = t_array[right];
	t_array[right] = temp; // Move pivot to end

	newPI = left;
	for (i = left; i <= (right - 1); i++) {
		tKey = t_array[i].getKey();
		if (sd == INCREASING) {
			if (tKey <= Key) {
				temp = t_array[i];
				t_array[i] = t_array[newPI];
				t_array[newPI] = temp;
				newPI = newPI + 1;
			}
		}
		else {
			if (tKey > Key) {
				temp = t_array[i];
				t_array[i] = t_array[newPI];
				t_array[newPI] = temp;
				newPI = newPI + 1;
			}
		}
	}
	// swap array[newPI] and array[right]; Move pivot to its final place
	temp = t_array[newPI];
	t_array[newPI] = t_array[right];
	t_array[right] = temp;

	return newPI;
}
template<typename K, typename V>
void TA_Entry<K, V>::_quick_sort(SortingDirection sd, int left, int right)
{
	int pI, newPI; // pivot index
	if (left >= right) {
		return;
	}
	else if (left < right) { // subarray of 0 or 1 elements already sorted
	//select a pI (pivotIndex) in the range left ≤ pI ≤ right
		pI = (left + right) / 2;
	}
	newPI = partition(sd, left, right, pI);
	// element at newPivotIndex (newPI) is now at its final position
	if (left < (newPI - 1)) {
		_quick_sort(sd, left, newPI - 1);
		// recursively sort elements on the left of pivotNewIndex
	}
	if ((newPI + 1) < right) {
		_quick_sort(sd, newPI + 1, right);
		// recursively sort elements on the right of pivotNewIndex
	}
}
template<typename K, typename V>
void TA_Entry<K, V>::quick_sort(SortingDirection sd) {
	_quick_sort(sd, 0, num_elements - 1);
}
template<typename K, typename V>
void TA_Entry<K, V>::_merge_sort(SortingDirection sd, T_Entry<K, V>* tmp_array, int left, int right) {
	// printf("... invoke MergeSort(left=%d, right=%d):\n", left, right);
	if (left >= right)
		return;
	int i, j, k, mid = (left + right) / 2;
	K key1, key2;

	_merge_sort(sd, tmp_array, left, mid);
	_merge_sort(sd, tmp_array, mid + 1, right);
	if (sd == INCREASING) {
		/* merge step 1 : copy 2nd half to tmp_array[] */
		for (i = mid; i >= left; i--)
			tmp_array[i] = t_array[i];
		for (j = 1; j <= right - mid; j++)
			tmp_array[right - j + 1] = t_array[j + mid];
		/* merge step 2 : merge sub-arrays back to array[] */
		for (i = left, j = right, k = left; k <= right; k++) {
			key1 = tmp_array[i].getKey();
			key2 = tmp_array[j].getKey();
			if (key1 <= key2)
				t_array[k] = tmp_array[i++];
			else
				t_array[k] = tmp_array[j--];
		}
		/* for debugging of merge_sort() */
#ifdef DEBUG_MERGESORT
		printf("After merging (left=%d, mid=%d, right=%d):\n", left, mid, right);
		printf("tempA: ");
		for (int i = left; i <= right; i++)
			printf("%5d", tmp_array[i]);
		printf("\n");
		printf(" A: ");
		for (int i = left; i <= right; i++)
			printf("%5d", t_array[i]);
		printf("\n");
#endif
	}
	else {
		/* merge step 1 : copy 2nd half to tmp_array[] */
		for (i = mid; i >= left; i--)
			tmp_array[i] = t_array[i];
		for (j = 1; j <= right - mid; j++)
			tmp_array[right - j + 1] = t_array[j + mid];
		/* merge step 2 : merge sub-arrays back to array[] */
		for (i = left, j = right, k = left; k <= right; k++)
		{
			key1 = tmp_array[i].getKey();
			key2 = tmp_array[j].getKey();
			if (key1 > key2)
				t_array[k] = tmp_array[i++];
			else
				t_array[k] = tmp_array[j--];
		}
		/* for debugging of merge_sort() */
#ifdef DEBUG_MERGESORT
		printf("After merging (left=%d, mid=%d, right=%d):\n", left, mid, right);
		printf("tempA: ");
		for (int i = left; i <= right; i++)
			printf("%5d", tmp_array[i]);
		printf("\n");
		printf(" A: ");
		for (int i = left; i <= right; i++)
			printf("%5d", t_array[i]);
		printf("\n");
#endif
	}

}
template<typename K, typename V>
void TA_Entry<K, V>::merge_sort(SortingDirection sd) {
	T_Entry<K, V>* tmp_array = new T_Entry<K, V>[num_elements];
	if (tmp_array == NULL)
	{
		printf("Error in creation of tmp_array (size = %d) in mergeSort() !!!\n");
		exit;
	}
	_merge_sort(sd, tmp_array, 0, num_elements - 1);
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
