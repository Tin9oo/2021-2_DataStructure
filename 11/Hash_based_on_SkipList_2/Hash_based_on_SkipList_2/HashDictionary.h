/* HashDictionary.h */
#ifndef HASH_DICTIONARY_H
#define HASH_DICTIONARY_H
#include "HashMap.h"
template <typename K, typename V>
class HashDict : public HashMap<K, V>
{
public: // public functions
	typedef typename HashMap<K, V>::Iterator Iterator;
	typedef typename SkipList<int, V>::Position SLPos;
	// Range class declaration
	class Range { // an iterator range
	private:
		SLPos _begin; // front of range
		SLPos _end; // end of range
	public:
		Range() {} // default constructor
		Range(const SLPos& b, const SLPos& e) // constructor
			: _begin(b), _end(e) { }
		SLPos& begin() { return _begin; } // get beginning
		SLPos& end() { return _end; } // get end
	}; // end class Range
public: // public functions
	HashDict(int capacity = DEFAULT_HASH_TABLE_SIZE); // constructor
	Range findAll(const K& k); // find all entries with k
	Iterator insert(const K& k, const V& v); // insert pair (k,v)
}; // end class HashDict

template <typename K, typename V> // constructor
HashDict<K, V>::HashDict(int capacity) : HashMap<K, V>(capacity) { }
template <typename K, typename V> // insert pair (k,v)
typename HashDict<K, V>::Iterator
HashDict<K, V>::insert(const K& k, const V& v) {
	Iterator p = this->_find(k); // find key
	Iterator q = this->_insert(p, k, v); // insert it here
	return q; // return its position
}
template <typename K, typename V> // find all entries with k
typename HashDict<K, V>::Range HashDict<K, V>::findAll(const K& k)
{
	Iterator b = this->_find(k); // look up k

	CyclicShiftHashCode hash;
	int h = hash(k);
	SLPos pe = b.operator*().SkipListSearch(h);
	SLPos pb = pe;
	while (pb != SLPos(NULL)  && pb.key() == h) // list의 iterator와 다르게 연속적이지 않아서 오류가 발생한다.
	{ // find next entry with different key or end of bucket array
		--pb;
	}
	return Range(++pb, pe); // return range of positions
}
#endif