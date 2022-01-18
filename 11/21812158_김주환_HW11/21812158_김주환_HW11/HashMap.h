/* HashMap.h */
#ifndef HASHMAP_H
#define HASHMAP_H
#include <list>
#include <vector>
#include "Entry.h"
#include "Exceptions.h"
#include "CyclicShiftHashCode.h"
#include "MyVoca.h"
#define DEFAULT_HASH_TABLE_SIZE 64
template <typename K, typename V> // key, value, hash
class HashMap {
public: // public types
	typedef Entry<const K, V> Entry; // a (key, value) pair
	// typedef Entry<const K, V> Entry;// a (key,value) pair
	typedef std::list<Entry> Bucket;// a bucket of entries
	typedef std::vector<Bucket> BktArray;// a bucket array
	typedef typename BktArray::iterator BItor;// bucket iterator
	typedef typename Bucket::iterator EItor;// entry iterator
	class Iterator;
public:
	HashMap(int capacity = DEFAULT_HASH_TABLE_SIZE); // constructor
	int size() const { return num_entry; } // number of entries
	bool empty() const { return (num_entry == 0); } // is the map empty?
	Iterator find(const K& k); // find entry with key k
	Iterator insert(const K& k, const V& v); // insert/replace (k,v)
	void erase(const K& k); // remove entry with key k
	void erase(const Iterator& p); // erase entry at p
	Iterator begin(); // iterator to first entry of HashMap
	Iterator end(); // iterator to end entry of HashMap
	void fprintBucketSizes(ostream& fout, Iterator itr); // printout bucket sizes
	void fprintBucket(ostream& fout, BItor bkt);
protected: // protected types
// HashMap utilities here
	Iterator _find(const K& k); // find utility
	Iterator _insert(const Iterator& p, const Entry& e); // insert utility
	void _erase(const Iterator& p); // remove utility
	static bool _endOfBkt(const Iterator& p) // end of bucket?
	{
		return p.ent == p.bkt->end();
	}
private:
	int num_entry; // number of entries
	BktArray B; // bucket array (Hash Table)
public: // public types
	// Iterator class declaration
	class Iterator { // an HashMap::Iterator (& position)
	private:
		const BktArray* ba; // which bucket array in the hash table
		BItor bkt; // iterator of bucket in the bucket array (hash table)
		EItor ent; // iterator of the bucket (iterator of list)
	public:
		Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())
			: ba(&a), bkt(b), ent(q) { }
		Iterator() {} // default constructor
		Entry& operator*() const; // get entry
		bool operator==(const Iterator& p) const; // are iterators equal?
		bool operator!=(const Iterator& p) const; // are iterators different ?
		Iterator& operator++(); // advance to next entry
		friend class HashMap; // give HashMap access
	}; // end class Iterator
}; // end of class HashMap
template <typename K, typename V> // constructor
HashMap<K, V>::HashMap(int capacity) : num_entry(0), B(capacity) { }
template <typename K, typename V> // iterator to front
typename HashMap<K, V>::Iterator HashMap<K, V>::begin()
{
	if (empty()) return end(); // emtpty - return end
	BItor bkt = B.begin(); // else search for an entry
	while (bkt->empty()) ++bkt; // find nonempty bucket
	return Iterator(B, bkt, bkt->begin()); // return first of bucket
}
template <typename K, typename V> // iterator to end
typename HashMap<K, V>::Iterator HashMap<K, V>::end()
{
	return Iterator(B, B.end());
}
template <typename K, typename V> // get entry
typename HashMap<K, V>::Entry& HashMap<K, V>::Iterator::operator*() const
{
	return *ent;
}
template <typename K, typename V> // are iterators equal?
bool HashMap<K, V>::Iterator::operator==(const Iterator& p) const
{
	if (ba != p.ba || bkt != p.bkt) return false; // ba or bkt differ?
	else if (bkt == ba->end()) return true; // both at the end?
	else return (ent == p.ent); // else use entry to decide
}
template <typename K, typename V> // are iterators equal?
bool HashMap<K, V>::Iterator::operator!=(const Iterator& p) const
{
	if (ba != p.ba || bkt != p.bkt) return true; // ba or bkt differ?
	else if (bkt == ba->end()) return false; // both at the end?
	else return (ent != p.ent); // else use entry to decide
}
template <typename K, typename V> // advance to next entry
typename HashMap<K, V>::Iterator& HashMap<K, V>::Iterator::operator++()
{
	++ent; // next entry in bucket
	if (_endOfBkt(*this)) { // at end of bucket?
		++bkt; // go to next bucket
		while (bkt != ba->end() && bkt->empty()) // find nonempty bucket
			++bkt;
		if (bkt == ba->end()) return *this; // end of bucket array?
		ent = bkt->begin(); // first nonempty entry
	}
	return *this; // return self
}
template <typename K, typename V> // find utility
typename HashMap<K, V>::Iterator HashMap<K, V>::_find(const K& k)
{
	CyclicShiftHashCode hash;
	unsigned int i = hash(k) % B.size(); // calculate hash value i, using CyclicShiftHashCode()
	BItor bkt = B.begin() + i; // the i-th bucket
	Iterator p(B, bkt, bkt->begin()); // start of i-th bucket
	while (!_endOfBkt(p) && (*p).getKey() != k) // linear search for k in the bucket
		++p.ent;
	return p; // return final position
}
template <typename K, typename V> // find key
typename HashMap<K, V>::Iterator HashMap<K, V>::find(const K& k)
{
	Iterator p = _find(k); // look for k
	if (_endOfBkt(p)) // if could not find the given key?
		return end(); // return end iterator
	else
		return p; // return its position
}
template <typename K, typename V> // insert utility
typename HashMap<K, V>::Iterator
HashMap<K, V>::_insert(const Iterator& p, const Entry& e) {
	EItor ins = p.bkt->insert(p.ent, e); // insert before p using insert() of list<Entry>
	num_entry++; // one more entry
	return Iterator(B, p.bkt, ins); // return this position
}
template <typename K, typename V> // insert/replace (v,k)
typename HashMap<K, V>::Iterator
HashMap<K, V>::insert(const K& k, const V& v) {
	Iterator p = _find(k); // search for k
	if (_endOfBkt(p)) { // k not found?
		return _insert(p, Entry(k, v)); // insert at end of bucket
	}
	else
	{ // found it?
		p.ent->setValue(v); // replace value with v
		return p; // return this position
	}
}
template <typename K, typename V> // remove utility
void HashMap<K, V>::_erase(const Iterator& p) {
	p.bkt->erase(p.ent); // remove entry from bucket
	num_entry--; // one fewer entry
}
template <typename K, typename V> // remove entry at p
void HashMap<K, V>::erase(const Iterator& p)
{
	_erase(p);
}
template <typename K, typename V> // remove entry with key k
void HashMap<K, V>::erase(const K& k) {
	Iterator p = _find(k); // find k
	if (_endOfBkt(p)) // not found?
		throw NonexistentElement("Erase of nonexistent"); // ...error
	_erase(p); // remove it
}
template <typename K, typename V>
void HashMap<K, V>::fprintBucket(ostream& fout, BItor bkt)
{
	CyclicShiftHashCode hash;
	Iterator p(this->B, bkt, bkt->begin());
	MyVoca* pVoca;
	unsigned int h = 0;

	while (p.ent != bkt->end())
	{
		pVoca = p.operator*().getValue();
		h = hash(pVoca->getKeyWord());
		fout << "["<< setw(15) << pVoca->getKeyWord();
		fout << ", " << setw(5) << h % DEFAULT_HASH_TABLE_SIZE << "], ";
		++p.ent;
	}
}
template <typename K, typename V>
void HashMap<K, V>::fprintBucketSizes(ostream& fout, Iterator itr)
{
	BItor ptor = itr.bkt;
	int bkt_size;
	int max_ent, min_ent, total;
	int num_bkts, max_bkt = 0;
	double avg = 0.0;
	max_ent = min_ent = B[0].size();
	total = 0;
	num_bkts = B.size();
	for (int bkt = 0; bkt < num_bkts; bkt++)
	{
		bkt_size = B[bkt].size();
		fout << "Bucket[" << setw(3) << bkt << "] : ";
		fprintBucket(fout, ptor++);
		if (bkt_size > max_ent)
		{
			max_ent = bkt_size;
			max_bkt = bkt;
		}
		if (bkt_size < min_ent)
			min_ent = bkt_size;
		total += bkt_size;
		fout << endl;
	}

}
#endif