/* HashMap.h */
#ifndef HASHMAP_H
#define HASHMAP_H
#include <list>
#include <vector>
#include "Entry.h"
#include "Exceptions.h"
#include "CyclicShiftHashCode.h"
#include "MyVoca.h"
#define DEFAULT_HASH_TABLE_SIZE 101
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
	void fprintBucketSizes(ostream& fout); // printout bucket sizes
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
#endif