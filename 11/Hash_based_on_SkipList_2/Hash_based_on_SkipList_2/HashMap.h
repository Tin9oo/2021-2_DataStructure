/* HashMap.h */
#ifndef HASHMAP_H
#define HASHMAP_H
#include <vector>
#include <list>
#include "SkipList.h"
#include "CyclicShiftHashCode.h"
#include "MyVoca.h"
#define DEFAULT_HASH_TABLE_SIZE 101
template <typename K, typename V> // key, value, hash
class HashMap {
public: // public types
	typedef SkipList<int, V> Bucket;// a bucket of entries // Entry를 V로 바꾸는 것도 고려할것
	typedef std::vector<Bucket> BktArray;// a bucket array
	typedef typename BktArray::iterator BItor;// bucket iterator
	typedef typename Bucket::Position SLPos;
	class Iterator;
public:
	HashMap(int capacity = DEFAULT_HASH_TABLE_SIZE); // constructor
	int size() const { return num_entry; } // number of entries
	bool empty() const { return (num_entry == 0); } // is the map empty?
	Iterator find(const K& k); // find entry with key k
	Iterator insert(const K& k, const V& v); // insert/replace (k,v)
	void erase(const K& k); // remove entry with key k
	Iterator begin(); // iterator to first entry of HashMap
	Iterator end(); // iterator to end entry of HashMap
	void fprintBucketSizes(ostream& fout); // printout bucket sizes
	void fprintBucket(ostream& fout, BItor bkt);
protected: // protected types
// HashMap utilities here
	Iterator _find(const K& k); // find utility
	Iterator _insert(const Iterator& p, const K& k, const V& v); // insert utility
	void _erase(const Iterator& p, const K& k); // remove utility
private:
	int num_entry; // number of entries
	BktArray B; // bucket array (Hash Table)
public: // public types
	// Iterator class declaration
	class Iterator { // an HashMap::Iterator (& position)
	private:
		const BktArray* ba; // which bucket array in the hash table
		BItor bkt; // iterator of bucket in the bucket array (hash table)
		// SLPos sl;
	public:
		Iterator(const BktArray& a, const BItor& b)
			: ba(&a), bkt(b) { }
		Iterator() {} // default constructor
		Bucket& operator*() const; // get entry
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
	return Iterator(B, bkt); // return first of bucket
}
template <typename K, typename V> // iterator to end
typename HashMap<K, V>::Iterator HashMap<K, V>::end()
{
	return Iterator(B, B.end());
}
template <typename K, typename V> // get entry
typename HashMap<K, V>::Bucket& HashMap<K, V>::Iterator::operator*() const
{
	return this->bkt.operator*(); // ent를 가리킬지 skiplist를 가리킬지 결정해야한다.
}
template <typename K, typename V> // are iterators equal?
bool HashMap<K, V>::Iterator::operator==(const Iterator& p) const
{
	if (ba != p.ba || bkt != p.bkt) return false; // ba or bkt differ?
	else if (bkt == ba->end()) return true; // both at the end?
}
template <typename K, typename V> // are iterators equal?
bool HashMap<K, V>::Iterator::operator!=(const Iterator& p) const
{
	if (ba != p.ba || bkt != p.bkt) return true; // ba or bkt differ?
	else if (bkt == ba->end()) return false; // both at the end?
}
template <typename K, typename V> // advance to next entry
typename HashMap<K, V>::Iterator& HashMap<K, V>::Iterator::operator++()
{
	// ++sl; // next entry in bucket
	++bkt; // go to next bucket
	while (bkt != ba->end() && bkt.operator*().empty()) // find nonempty bucket
		++bkt;
	if (bkt == ba->end()) return *this; // end of bucket array?
	return *this; // return self
}
template <typename K, typename V> // find utility
typename HashMap<K, V>::Iterator HashMap<K, V>::_find(const K& k)
{
	CyclicShiftHashCode hash;
	SLPos pos;

	int i = hash(k) % B.size(); // calculate hash value i, using CyclicShiftHashCode()
	BItor bkt = B.begin() + i; // the i-th bucket
	Iterator p(B, bkt); // start of i-th bucket
	return p; // return final position
}
template <typename K, typename V> // find key
typename HashMap<K, V>::Iterator HashMap<K, V>::find(const K& k)
{
	Iterator p = _find(k); // look for k
	return p;
}
template <typename K, typename V> // insert utility
typename HashMap<K, V>::Iterator HashMap<K, V>::_insert(const Iterator& p, const K& k, const V& v) {
	CyclicShiftHashCode hash;
	int h = hash(k);
	p.bkt.operator*().SkipListInsert(h, v); // insert before p using insert() of list<Entry>
	num_entry++; // one more entry
	Iterator q(B, p.bkt); // return this position
	return q;
}
template <typename K, typename V> // insert/replace (v,k)
typename HashMap<K, V>::Iterator HashMap<K, V>::insert(const K& k, const V& v) {
	Iterator p = this->_find(k); // search for k
	Iterator q = this->_insert(p, k, v); // insert at end of bucket
	return q;
}
template <typename K, typename V> // remove utility
void HashMap<K, V>::_erase(const Iterator& p, const K& k) {
	CyclicShiftHashCode hash;
	int h = hash(k);
	p.bkt->SkipListRemove(h); // remove entry from bucket
	num_entry--; // one fewer entry
}
template <typename K, typename V> // remove entry with key k
void HashMap<K, V>::erase(const K& k) {
	Iterator p = _find(k); // find k
	_erase(p, k); // remove it
}
template <typename K, typename V>
void HashMap<K, V>::fprintBucket(ostream& fout, BItor bkt)
{
	Iterator p(B, bkt);
	int i = 0;
	while (i != p.ba->size())
	{
		p.operator*().PrintSkipList();
		++p;
		++i;
	}
}
template <typename K, typename V>
void HashMap<K, V>::fprintBucketSizes(ostream& fout)
{
	int bkt_size;
	int max_ent, min_ent, total;
	int num_bkts, max_bkt = 0;
	double avg = 0.0;
	max_ent = min_ent = B.at(0).size();
	total = 0;
	num_bkts = B.size();
	for (int bkt = 0; bkt < num_bkts; bkt++)
	{
		bkt_size = B.at(bkt).size();
		fout << "Bucket[" << setw(3) << bkt << "] : " << bkt_size << " entries"
			<< endl;
		if (bkt_size > max_ent)
		{
			max_ent = bkt_size;
			max_bkt = bkt;
		}
		if (bkt_size < min_ent)
			min_ent = bkt_size;
		total += bkt_size;
	}
	avg = total / num_bkts;
	fout.precision(2);
	fout << endl << "Max_ent(" << setw(2) << max_ent << "), min_ent(" << setw(2)
		<< min_ent << "), avg (" << setw(5) << avg << ")" << endl;
	fout << "Bucket with maximum (" << max_ent << ") entries : " << endl;
	BItor bkt = B.begin() + max_bkt;// the ith bucket
	fprintBucket(fout, bkt);
}
#endif