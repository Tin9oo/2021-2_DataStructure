/* TA_Entry.h */
#ifndef TA_E_H
#define TA_E_H
#include "T_Entry.h"

enum SortingDirection { INCREASING, DECREASING };

template<typename K, typename V>
class TA_Entry {
public:
	TA_Entry(int n, string nm);
	~TA_Entry();

	int size() { return num_elements; }
	bool empty() { return num_elements == 0; }

	string getName() { return name; }

	void reserve(int new_capacity); // 용량 재설정
	void insert(int i, T_Entry<K, V> element); // 삽입
	void remove(int i); // 삭제
	T_Entry<K, V>& at(int i); // i번째 인덱스의 element 반환
	void set(int i, T_Entry<K, V> element); // i번째 인덱스를 element로 설정

	T_Entry<K, V> getMin(int begin, int end);
	T_Entry<K, V> getMax(int begin, int end);

	// 탐색 및 정렬
	void shuffle();
	int sequential_search(T_Entry<K, V> search_key);
	int binary_search(T_Entry<K, V> search_key);
	void selection_sort(SortingDirection sd);
	void quick_sort(SortingDirection sd);

	// 출력
	void fprint(ofstream& fout, int elements_per_line);
	void fprintSample(ofstream& fout, int elements_per_line, int num_sample_lines);

	bool isValidIndex(int i);
	T_Entry<K, V>& operator[](int index) { return t_array[index]; }
protected:
	T_Entry<K, V>* t_array; // element 배열
	int num_elements; // 현재 개수
	int capacity; // 배열의 크기(용량), 실제 사용에서는 크기를 한칸 늘려서 사용한다.
	string name;
};

template<typename K, typename V>
TA_Entry<K, V>::TA_Entry(int n, string nm) {
	t_array = new T_Entry<K, V>[n];
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
	if (t_array != NULL)
		delete[] t_array;
}
template<typename K, typename V>
void TA_Entry<K, V>::reserve(int new_capacity) {
	if (capacity >= new_capacity)
		return; // already big enough
	T_Entry<K, V>* t_newGA = new T_Entry<K, V>[new_capacity];
	if (t_newGA == NULL) {
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
void TA_Entry<K, V>::remove(int i) {
	if (isValidIndex(i)) {
		for (int j = i + 1; j < num_elements; j++)
			t_array[j - 1] = t_array[j]; //shift down elements in one position
		num_elements--;
	}
	if (num_elements < (capacity / 2)) {
		int new_capacity = capacity / 2;
		TA_Entry<K, V>* t_newGA = new TA_Entry<K, V>[new_capacity];
		if (t_newGA == NULL) {
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
template<typename K, typename V>
T_Entry<K, V>& TA_Entry<K, V>::at(int i) {
	if (isValidIndex(i)) {
		return t_array[i];
	}
}
template<typename K, typename V>
void TA_Entry<K, V>::set(int i, T_Entry<K, V> element) {
	if (isValidIndex(i)) {
		t_array[i] = element;
	}
}
template<typename K, typename V>
T_Entry<K, V> TA_Entry<K, V>::getMin(int begin, int end) {
	V minValue;
	int index_min;
	minValue = t_array[begin];
	index_min = begin;
	for (int i = begin + 1; i <= end; i++) {
		if (t_array[i] < minValue) { // T must provide operator<() overloading !!
			minValue = t_array[i];
			index_min = i;
		}
	}
	return t_array[index_min];
}
template<typename K, typename V>
T_Entry<K, V> TA_Entry<K, V>::getMax(int begin, int end) {
	V maxValue;
	int index_max;
	maxValue = t_array[begin];
	index_max = begin;
	for (int i = begin + 1; i <= end; i++) {
		if (t_array[i] > maxValue) { // T must provide operator>() overloading !!
			maxValue = t_array[i];
			index_max = i;
		}
	}
	return t_array[index_max];
}
template<typename K, typename V>
void TA_Entry<K, V>::shuffle() {
	srand(time(0));
	int index1, index2;
	int rand_1, rand_2;
	V temp;
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
template<typename K, typename V>
int TA_Entry<K, V>::sequential_search(T_Entry<K, V> search_key) {
	int index;
	K key;
	if (search_key == "ST_ID") { // student_ID
		for (int index = 0; index < num_elements; index++) {
			t_array[index].getKey(search_key, &key);
			if (key == search_key)
				return index;
		}
	}
	return -1;
}
template<typename K, typename V>
int TA_Entry<K, V>::binary_search(T_Entry<K, V> search_key) {
	K key;
	int low, mid, high; int loop = 1;
	low = 0; high = num_elements - 1;
	while (low <= high) {
		cout << setw(2) << loop << "-th loop: current search range [" << setw(3) << low << ", " << setw(3) << high << "]" << endl;
		mid = (low + high) / 2;
		t_array[mid].getKey(search_key, &key);
		if (key == search_key)
			return mid;
		else if (key > search_key)
			high = mid - 1;
		else
			low = mid + 1; loop++;
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
template<typename T>
void _quick_sort(T* array, int size, int left, int right,
	SortingDirection sd = INCREASING) {
	int pI, newPI; // pivot index
	if (left >= right) {
		return;
	}
	else { //select a pI (pivotIndex) in the range left ≤ pI ≤ right
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
template<typename K, typename V>
void TA_Entry<K, V>::quick_sort(SortingDirection sd) {
	_quick_sort(t_array, size, 0, num_elements - 1, sd);
}
template<typename K, typename V>
void TA_Entry<K, V>::fprint(ofstream& fout, int elements_per_line) {
	int count = 0;
	while (count < num_elements) {
		for (int i = 0; i < elements_per_line; i++) {
			fout << t_array[count] << " ";
			count++;
			if (count % elements_per_line == 0)
				fout << endl;
		}
	}
	cout << endl;
}
template<typename K, typename V>
void TA_Entry<K, V>::fprintSample(ofstream& fout, int elements_per_line, int num_sample_lines) {
	string T_type;
	int last_block_start;
	int count = 0;
	T_type = typeid(T_Entry<K, V>).name();
	for (int i = 0; i < num_sample_lines; i++) {
		for (int j = 0; j < elements_per_line; j++) {
			if (count >= num_elements) {
				fout << endl;
				return;
			}
			if ((T_type == string("int")) || (T_type == string("double")) ||
				(T_type == string("class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > ")))
				fout << setw(10) << t_array[count];
			else
				fout << t_array[count] << " ";
			count++;
		} fout << endl;
	}
	if (count < (num_elements - elements_per_line * num_sample_lines))
		count = num_elements - elements_per_line * num_sample_lines;
	fout << " . . . . . " << endl;
	for (int i = 0; i < num_sample_lines; i++) {
		for (int j = 0; j < elements_per_line; j++) {
			if (count >= num_elements) {
				fout << endl;
				return;
			}
			if ((T_type == string("int")) || (T_type == string("double")) ||
				(T_type == string("class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> > ")))
				fout << setw(10) << t_array[count];
			else
				fout << t_array[count] << " ";
			count++;
		} fout << endl;
	} fout << endl;
}
template<typename K, typename V>
bool TA_Entry<K, V>::isValidIndex(int i) {
	if ((i < 0) || (i > num_elements))
		return false;
	else
		return true;
}
#endif // !TA_E_H