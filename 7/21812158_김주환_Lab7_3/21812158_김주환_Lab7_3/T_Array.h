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
	int sequential_search(K search_key); // search and return the index; -1 if not found
	int binary_search(K search_key); // search and return the index; -1 if not found
	void selection_sort(string keyName, SortingOrder sortOrder);

	// Quick sorting
	int partition(string keyName, SortingOrder sortOrder, int left, int right, int pivotIndex);
	void _quick_sort(string keyName, SortingOrder sortOrder, int left, int right);
	void quick_sort(string keyName, SortingOrder sortOrder);

	// Merge sorting
	void _merge_sort(string keyName, SortingOrder sortOrder, T* tmp_array, int left, int right);
	void merge_sort(string keyName, SortingOrder sortOrder);

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
int T_Array<T, K>::sequential_search(K search_key) {
	int index; string keytype;
	keytype = typeid(K).name();
	if (keytype == "int") { // student_ID
		for (int index = 0; index < num_elements; index++) {
			if (t_array[index].getIntKey() == search_key)
				return index;
		}
	}
		return -1;
}
template<typename T, typename K>
int T_Array<T, K>::binary_search(K search_key) {
	int low, mid, high; int loop = 1;
	low = 0; high = num_elements - 1;
	while (low <= high) {
		cout << setw(2) << loop << "-th loop: current search range [" << setw(3) << low << ", " << setw(3) << high << "]" << endl;
		mid = (low + high) / 2;
		if (t_array[mid] == search_key)
			return mid;
		else if (t_array[mid] > search_key)
			high = mid - 1;
		else
			low = mid + 1; loop++;
	}
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
int T_Array<T, K>::partition(string keyName, SortingOrder sortOrder, int left, int right, int pivotIndex)
{
	K Key, tKey; // pivot value
	int i, newPI; // new pivot index
	T temp;

	t_array[pivotIndex].getKey(keyName, &Key);
	temp = t_array[pivotIndex];
	t_array[pivotIndex] = t_array[right];
	t_array[right] = temp; // Move pivot to end

	newPI = left;
	for (i = left; i <= (right - 1); i++) {
		t_array[i].getKey(keyName, &tKey);
		if (sortOrder == INCREASING) {
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
template<typename T, typename K>
void T_Array<T, K>::_quick_sort(string keyName, SortingOrder sortOrder, int left, int right)
{
	int pI, newPI; // pivot index
	if (left >= right) {
		return;
	}
	else if (left < right) { // subarray of 0 or 1 elements already sorted
	//select a pI (pivotIndex) in the range left ≤ pI ≤ right
		pI = (left + right) / 2;
	}
	newPI = partition(keyName, sortOrder, left, right, pI);
	// element at newPivotIndex (newPI) is now at its final position
	if (left < (newPI - 1)) {
		_quick_sort(keyName, sortOrder, left, newPI - 1);
		// recursively sort elements on the left of pivotNewIndex
	}
	if ((newPI + 1) < right) {
		_quick_sort(keyName, sortOrder, newPI + 1, right);
		// recursively sort elements on the right of pivotNewIndex
	}
}
template<typename T, typename K>
void T_Array<T, K>::quick_sort(string keyName, SortingOrder sortOrder) {
	_quick_sort(keyName, sortOrder, 0, num_elements - 1);
}
template<typename T, typename K>
void T_Array<T, K>::_merge_sort(string keyName, SortingOrder sortOrder, T* tmp_array, int left, int right) {
	// printf("... invoke MergeSort(left=%d, right=%d):\n", left, right);
	if (left >= right)
		return;
	int i, j, k, mid = (left + right) / 2;
	K key1, key2;

	_merge_sort(keyName, sortOrder, tmp_array, left, mid);
	_merge_sort(keyName, sortOrder, tmp_array, mid + 1, right);
	if (sortOrder == INCREASING) {
		/* merge step 1 : copy 2nd half to tmp_array[] */
		for (i = mid; i >= left; i--)
			tmp_array[i] = t_array[i];
		for (j = 1; j <= right - mid; j++)
			tmp_array[right - j + 1] = t_array[j + mid];
		/* merge step 2 : merge sub-arrays back to array[] */
		for (i = left, j = right, k = left; k <= right; k++) {
			tmp_array[i].getKey(keyName, &key1);
			tmp_array[j].getKey(keyName, &key2);
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
			tmp_array[i].getKey(keyName, &key1);
			tmp_array[j].getKey(keyName, &key2);
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
template<typename T, typename K>
void T_Array<T, K>::merge_sort(string keyName, SortingOrder sortOrder) {
	T* tmp_array = new T[num_elements];
	if (tmp_array == NULL)
	{
		printf("Error in creation of tmp_array (size = %d) in mergeSort() !!!\n");
		exit;
	}
	_merge_sort(keyName, sortOrder, tmp_array, 0, num_elements - 1);
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