/* HashDictionary.h */
#ifndef HASH_DICTIONARY_H
#define HASH_DICTIONARY_H
#include "HashMap.h"
#define HASH_TABLE_SIZE 101
template <typename K, typename V>
class HashDict : public HashMap<K, V>
{
public: // public functions
	typedef typename HashMap<K, V>::Iterator Iterator;
	typedef typename HashMap<K, V>::Entry Entry;
	// Range class declaration
	class Range { // an iterator range
	private:
		Iterator _begin; // front of range
		Iterator _end; // end of range
	public:
		Range() {} // default constructor
		Range(const Iterator& b, const Iterator& e) // constructor
			: _begin(b), _end(e) { }
		Iterator& begin() { return _begin; } // get beginning
		Iterator& end() { return _end; } // get end
	}; // end class Range
public: // public functions
	HashDict(int capacity = HASH_TABLE_SIZE); // constructor
	Range findAll(const K& k); // find all entries with k
	Iterator insert(const K& k, const V& v); // insert pair (k,v)
}; // end class HashDict

template <typename K, typename V> // constructor
HashDict<K, V>::HashDict(int capacity) : HashMap<K, V>(capacity) { }
template <typename K, typename V> // insert pair (k,v)
typename HashDict<K, V>::Iterator
HashDict<K, V>::insert(const K& k, const V& v) {
	Iterator p = this->_find(k); // find key
	Iterator q = this->_insert(p, Entry(k, v)); // insert it here
	return q; // return its position
}
template <typename K, typename V> // find all entries with k
typename HashDict<K, V>::Range
HashDict<K, V>::findAll(const K& k)
{
	Iterator b = this->_find(k); // look up k
	Iterator p = b;
	while (p != this->end() && (*p).getKey() == k)
	{ // find next entry with different key or end of bucket array
		++p;
	}
	return Range(b, p); // return range of positions
}
#endif