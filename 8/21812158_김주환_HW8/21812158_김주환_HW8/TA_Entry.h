/* TA_Entry.h */
#ifndef TA_E_H
#define TA_E_H
#include <iostream>
using namespace std;

enum SortingDirection { INCREASING, DECREASING };

template<typename K>
class TA_Entry {
public:
	TA_Entry(int n, string nm);
	~TA_Entry();
	int size() { return num_elements; }
	bool empty() { return num_elements == 0; }
	string getName() { return name; }
	void reserve(int new_capacity);
	void insert(int i, K element);
	void remove(int i);
	K& at(int i);
	void set(int i, K element);
	K getMin(int begin, int end);
	K getMax(int begin, int end);
	void shuffle();
	int sequential_search(K search_key);
	int binary_search(K search_key);
	void selection_sort(SortingDirection sd);
	void quick_sort(SortingDirection sd);
	void fprint(ofstream& fout, int elements_per_line);
	void fprintSample(ofstream& fout, int elements_per_line, int num_sample_lines);
	bool isValidIndex(int i);
	K& operator[](int index) { return t_GA[index]; }
protected:
	K* t_GA;
	int num_elements;
	int capacity;
	string name;
};

template<typename K>
TA_Entry<K>::TA_Entry(int n, string nm) {
	t_GA = (K*) new K[n];
	if (t_GA == NULL) {
		cout << "Error in creation of dynamic array of size (" << n << ") !!" << endl;
		exit;
	}
	capacity = n;
	num_elements = 0;
	name = nm;
}
template<typename K>
TA_Entry<K>::~TA_Entry() {
	if (t_GA != NULL) delete[] t_GA;
}
template<typename K>
void TA_Entry<K>::reserve(int new_capacity) {
	if (capacity >= new_capacity)
		return; // already big enough
	K* t_newGA = (K*) new K[new_capacity];
	if (t_newGA == NULL)
	{
		cout << "Error in creation of dynamic array of size (" << new_capacity << ") !!" << endl;
		exit;
	}
	cout << this->getName() << " expands capacity to " << setw(3)
		<< new_capacity << endl;
	for (int i = 0; i < num_elements; i++)
		t_newGA[i] = t_GA[i];
	delete[] t_GA;
	t_GA = t_newGA;
	capacity = new_capacity;
}
template<typename K>
void TA_Entry<K>::insert(int i, K element) {
	if (isValidIndex(i)) {
		for (int j = num_elements - 1; j >= i; j--)
			t_GA[j + 1] = t_GA[j]; //shift up elements in one position
		t_GA[i] = element;
		num_elements++;
	}
}
template<typename K>
void TA_Entry<K>::remove(int i) {
	if (isValidIndex(i))
	{
		for (int j = i + 1; j < num_elements; j++)
			t_GA[j - 1] = t_GA[j]; //shift down elements in one position
		num_elements--;
	}
	if (num_elements < (capacity / 2))
	{
		int new_capacity = capacity / 2;
		K* t_newGA = (K*) new K[new_capacity];
		if (t_newGA == NULL)
		{
			return; // new memory allocation failed.
			// Just return without modification.
		}
		cout << this->getName()
			<< " reduces capacity to " << setw(3)
			<< new_capacity << endl;
		for (int i = 0; i < num_elements; i++)
			t_newGA[i] = t_GA[i];
		delete[] t_GA;
		t_GA = t_newGA;
		capacity = new_capacity;
	}
}
template<typename K>
K& TA_Entry<K>::at(int i) {
	if (isValidIndex(i))
	{
		return t_GA[i];
	}
}
template<typename K>
void TA_Entry<K>::set(int i, K element) {
	if (isValidIndex(i))
	{
		t_GA[i] = element;
	}
}
template<typename K>
K TA_Entry<K>::getMin(int begin, int end) {
	K minValue;
	int index_min;
	minValue = t_GA[begin];
	index_min = begin;
	for (int i = begin + 1; i <= end; i++)
	{
		if (t_GA[i] < minValue) // T must provide operator<() overloading !!
		{
			minValue = t_GA[i];
			index_min = i;
		}
	}
	return t_GA[index_min];
}
template<typename K>
K TA_Entry<K>::getMax(int begin, int end) {
	K maxValue;
	int index_max;
	maxValue = t_GA[begin]; index_max = begin; for (int i = begin + 1; i <= end; i++)
	{
		if (t_GA[i] > maxValue) // T must provide operator>() overloading !!
		{
			maxValue = t_GA[i];
			index_max = i;
		}
	}
	return t_GA[index_max];
}
template<typename K>
void TA_Entry<K>::shuffle() {
	srand(time(0));
	int index1, index2;
	int rand_1, rand_2;
	K temp;
	for (int i = 0; i < num_elements; i++)
	{
		rand_1 = rand();
		rand_2 = rand();
		index1 = ((rand_1 << 15) | rand_2) % num_elements;
		rand_1 = rand();
		rand_2 = rand();
		index2 = ((rand_1 << 15) | rand_2) % num_elements;
		temp = t_GA[index1];
		t_GA[index1] = t_GA[index2];
		t_GA[index2] = temp;
	}
}
template<typename K>
int TA_Entry<K>::sequential_search(K search_key) {
	int index;
	K key;
	if (search_key == "ST_ID") { // student_ID
		for (int index = 0; index < num_elements; index++) {
			t_GA[index].getKey(search_key, &key);
			if (key == search_key)
				return index;
		}
	}
	return -1;
}
template<typename K>
int TA_Entry<K>::binary_search(K search_key) {
	K key;
	int low, mid, high; int loop = 1;
	low = 0; high = num_elements - 1;
	while (low <= high) {
		cout << setw(2) << loop << "-th loop: current search range [" << setw(3) << low << ", " << setw(3) << high << "]" << endl;
		mid = (low + high) / 2;
		t_GA[mid].getKey(search_key, &key);
		if (key == search_key)
			return mid;
		else if (key > search_key)
			high = mid - 1;
		else
			low = mid + 1; loop++;
	}
}
template<typename K>
void TA_Entry<K>::selection_sort(SortingDirection sd) {
	int index_min, index_max; // index of the element with minimum value
	K tempElement;
	K minKey, maxKey, key;

	for (int i = 0; i < num_elements - 1; i++) {
		if (sd == INCREASING) { // sorting in increasing (non_decreasing) order
			index_min = i;
			key = t_GA[i].getKey(); // Å° ¹ÝÈ¯
			minKey = (K)key;
			for (int j = i + 1; j < num_elements; j++) {
				key = t_GA[j].getKey();
				if ((K)key < minKey) {
					index_min = j;
					minKey = (K)key;
				}
			}
			if (index_min != i) { // if a smaller element is found, then swap
				tempElement = t_GA[index_min];
				t_GA[index_min] = t_GA[i];
				t_GA[i] = tempElement;
			}
		}
		else { // sorting in decreasing (non_increasing) order
			index_max = i;
			key = t_GA[i].getKey();
			maxKey = (K)key;
			for (int j = i + 1; j < num_elements; j++) {
				key = t_GA[j].getKey();
				if ((K)key > maxKey) {
					index_max = j;
					maxKey = (K)key;
				}
			}
			if (index_max != i) { // if a smaller element is found, then swap  
				tempElement = t_GA[index_max];
				t_GA[index_max] = t_GA[i];
				t_GA[i] = tempElement;
			}
		}
	} // end for
}
template<typename T>
void _quick_sort(T* array, int size, int left, int right,
	SortingDirection sd = INCREASING) {
	int pI, newPI; // pivot index
	if (left >= right)
	{
		return;
	}
	else
	{//select a pI (pivotIndex) in the range left ¡Â pI ¡Â right
		pI = (left + right) / 2;
	}
	newPI = _partition(array, size, left, right, pI, sd);
	if (left < (newPI - 1)) {
		_quick_sort(array, size, left, newPI - 1, sd);
		// recursively sort elements on the left of pivotNewIndex
	}
	if ((newPI + 1) < right) {
		_quick_sort(array, size, newPI + 1, right, sd);
		// recursively sort elements on the right of pivotNewIndex
	}
}
template<typename K>
void TA_Entry<K>::quick_sort(SortingDirection sd) {
	_quick_sort(t_GA, size, 0, num_elements - 1, sd);
}
template<typename K>
void TA_Entry<K>::fprint(ofstream& fout, int elements_per_line) {
	int count = 0;
	while (count < num_elements)
	{
		for (int i = 0; i < elements_per_line; i++)
		{
			fout << t_GA[count] << " ";
			count++;
			if (count % elements_per_line == 0)
				fout << endl;
		}
	}
	cout << endl;
}
template<typename K>
void TA_Entry<K>::fprintSample(ofstream& fout, int elements_per_line, int num_sample_lines) {
	string T_type;
	int last_block_start;
	int count = 0;
	T_type = typeid(K).name();
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < elements_per_line; j++)
		{
			if (count >= num_elements)
			{
				fout << endl;
				return;
			}
			if ((T_type == string("int")) || (T_type == string("double")) ||
				(T_type == string("class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > ")))
				fout << setw(10) << t_GA[count];
			else
				fout << t_GA[count] << " ";
			count++;
		} fout << endl;
	}
	if (count < (num_elements - elements_per_line * num_sample_lines))
		count = num_elements - elements_per_line * num_sample_lines;
	fout << " . . . . . " << endl;
	for (int i = 0; i < num_sample_lines; i++)
	{
		for (int j = 0; j < elements_per_line; j++)
		{
			if (count >= num_elements)
			{
				fout << endl;
				return;
			}
			if ((T_type == string("int")) || (T_type == string("double")) ||
				(T_type == string("class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> > ")))
				fout << setw(10) << t_GA[count];
			else
				fout << t_GA[count] << " ";
			count++;
		} fout << endl;
	} fout << endl;
}
template<typename K>
bool TA_Entry<K>::isValidIndex(int i) {
	if ((i < 0) || (i > num_elements))
		return false;
	else
		return true;
}
#endif // !TA_E_H