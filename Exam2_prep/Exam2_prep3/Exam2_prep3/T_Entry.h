/* T_Entry.h */
#ifndef T_ENTRY_H
#define T_ENTRY_H
#include <iostream>
using namespace std;

template<typename K, typename V>
class T_Entry
{
public:
	T_Entry(K key, V value) { _key = key; _value = value; }
	T_Entry() { } // default constructor
	~T_Entry() {}
	void setKey(const K& key) { _key = key; }
	void setValue(const V& value) { _value = value; }
	const K getKey() const { return _key; }
	const V getValue() const { return _value; }
	bool operator>(const T_Entry<K, V>& right) const { return (_key > right.getKey()); }
	bool operator>=(const T_Entry<K, V>& right) const { return (_key >= right.getKey()); }
	bool operator<(const T_Entry<K, V>& right) const { return (_key < right.getKey()); }
	bool operator<=(const T_Entry<K, V>& right) const { return (_key <= right.getKey()); }
	bool operator==(const T_Entry<K, V>& right) const
	{
		return ((_key == right.getKey()) && (_value == right.getValue()));
	}
	T_Entry<K, V>& operator=(const T_Entry<K, V>& right);
	void print();
private:
	K _key;
	V _value;
};
template<typename K, typename V>
T_Entry<K, V>& T_Entry<K, V>::operator=(const T_Entry<K, V>& right) {
	_key = right._key;
	_value = right._value;
	return *this;
}
template<typename K, typename V>
void T_Entry<K, V>::print() {
	cout << *_value << " ";
}
#endif // !T_ENTRY_H