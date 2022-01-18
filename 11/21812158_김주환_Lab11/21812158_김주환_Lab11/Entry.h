/* Entry.h */
#ifndef E_H
#define E_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template<typename K, typename V>
class Entry
{
	friend ostream& operator<<(ostream& fout, Entry<K, V>& entry)
	{
		if (entry.getValue() != NULL)
			fout << "(" << setw(8) << entry.getKey() << ": " << *(entry.getValue()) << ")";
		return fout;
	}
public:
	Entry(K key, V value)
		: _key(key), _value(value) { }
	Entry()
		: _key(), _value() { } // default constructor
	~Entry() {}
	void setKey(const K& key) { _key = key; }
	void setValue(const V& value) { _value = value; }
	K getKey() const { return _key; }
	V getValue() const { return _value; }
	bool operator>(const Entry<K, V>& right) const { return (_key > right.getKey()); }
	bool operator>=(const Entry<K, V>& right) const { return (_key >= right.getKey()); }
	bool operator<(const Entry<K, V>& right) const { return (_key < right.getKey()); }
	bool operator<=(const Entry<K, V>& right) const { return (_key <= right.getKey()); }
	bool operator==(const Entry<K, V>&right) const {
		return ((_key == right.getKey()) && (_value == right.getValue()));
	}
	const Entry<K, V>& operator=(const Entry<K, V>& right); // 뭐야, 뭐가 문제야?
	void fprint(ostream fout); // 레퍼런스로 해야하나?
private:
	K _key;
	V _value;
};
template<typename K, typename V>
const Entry<K, V>& Entry<K, V>::operator=(const Entry<K, V>& right)
{
	this->_key = right.getKey();
	this->_value = right.getValue();
	return *this;
}
template<typename K, typename V>
void Entry<K, V>::fprint(ostream fout)
{
	fout << "[Key:" << setw(2) << this->getKey() << ", " << *(this->getValue()) << "]";
}
#endif // !E_H