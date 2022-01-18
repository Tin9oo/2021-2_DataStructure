/* Trie.h (1) */
#ifndef Trie_H
#define Trie_H
#include <iostream>
#include <string>
#include "TrieNode.h"
#define MAX_STR_LEN 50
//#define DEBUG
using namespace std;
typedef list<string*> List_pStr;
typedef list<string*>::iterator List_pStr_Iter;
enum SearchMode { FULL_MATCH, PREFIX_MATCH };
template <typename E>
class Trie
{
public:
	Trie(string name); // constructor
	int size() { return num_keys; }
	string getName() { return trie_name; }
	void insert(string keyStr, E value);
	void insertExternalTN(TrieNode<E>* pTN, string keyStr, E value);
	TrieNode<E>* find(string keyStr);
	void findPrefixMatch(string prefix, List_pStr& predictWords);
	// void deleteKeyStr(string keyStr);
	// void eraseTrie();
	void fprintTrie(ostream& fout);
protected:
	TrieNode<E>* _find(string keyStr, SearchMode sm);
	void _traverse(TrieNode<E>* pTN, List_pStr& list_keywords);
private:
	TrieNode<E>* _root; // _root trie node
	int num_keys;
	string trie_name;
};
template<typename E>
Trie<E>::Trie(string name)
{
	trie_name = name;
	_root = new TrieNode<E>('₩0', NULL);
	_root->setKeyChar('₩0');
	_root->setPrev(NULL);
	_root->setNext(NULL);
	_root->setParent(NULL);
	_root->setChild(NULL);
	num_keys = 0;
}
template<typename E>
void Trie<E>::insertExternalTN(TrieNode<E>* pTN, string keyStr, E value)
{
	TrieNode<E>* pTN_New = NULL;
	pTN_New = new TrieNode<E>('₩0', value);
	pTN->setChild(pTN_New);
	(pTN->getChild())->setParent(pTN);
	pTN_New->setValue(value);
	//cout << "key (" << keyStr << ") is inserted ₩n";
}
template<typename E>
void Trie<E>::insert(string keyStr, E value)
{
	TrieNode<E>* pTN = NULL, * pTN_New = NULL;
	char* keyPtr = (char*)keyStr.c_str();
	if (keyPtr == NULL)
		return;
	/* Firstly, check any possible duplicated key insertion */
	if (_find(keyStr, FULL_MATCH) != NULL)
	{
		cout << "The given key string (" << keyStr << ") is already existing; just return !!" << endl;
		return;
	}
	pTN = this->_root;
	while ((pTN != NULL) && (*keyPtr != '\0'))
	{
		if ((pTN->getKeyChar() < *keyPtr) && (pTN->getNext() == NULL) && (*keyPtr != '\0'))
			break;
		while ((pTN->getKeyChar() < *keyPtr) && (pTN->getNext() != NULL))
			pTN = pTN->getNext();
		while ((pTN != NULL) && (pTN->getKeyChar() == *keyPtr) && (*keyPtr != '\0'))
		{
			pTN = pTN->getChild();
			keyPtr++;
		}
		if ((pTN->getKeyChar() > *keyPtr) && (*keyPtr != '\0'))
			break;
	} // end while for positioning
	/* Secondly, the given key string is a sub-string of an existing key */
	/* e.g.) trying to insert "abc" while "abcde" is already exisiting. */
	if ((pTN->getKeyChar() != '\0') && (*keyPtr == '\0'))
	{
		/* there was a longer key string already !! */
		/* break the longer key string, and connected to the separated key strings */
		pTN_New = new TrieNode<E>('\0', value);
		pTN_New->setParent(pTN->getParent());
		(pTN->getParent())->setChild(pTN_New);
		pTN_New->setNext(pTN);
		pTN->setPrev(pTN_New);
		//cout << "key (" << keyWord << ") is inserted" << endl;
		this->num_keys++;
		return;
	}
	else if ((pTN->getKeyChar() < *keyPtr) && (pTN->getNext() == NULL) && (*keyPtr != '\0'))
	{
		/* at this level, a new substring is inserted as the last nodes */
		pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);
		pTN_New->setParent(pTN->getParent());
		pTN_New->setPrev(pTN);
		pTN->setNext(pTN_New);
		pTN = pTN_New;
		keyPtr++;
		while (*keyPtr != '\0')
		{
			pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);
			pTN->setChild(pTN_New);
			(pTN->getChild())->setParent(pTN);
			pTN = pTN->getChild();
			keyPtr++;
		}
		if (*keyPtr == '\0')
		{
			insertExternalTN(pTN, keyStr, value);
			this->num_keys++;
			return;
		}
	}
	else if ((pTN->getKeyChar() > *keyPtr) && (*keyPtr != '\0'))
	{
		/* insert between two existing trie nodes */
		pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);
		pTN_New->setNext(pTN);
		pTN_New->setParent(pTN->getParent());
		if (pTN->getPrev() == NULL)
		{ /* this pTN_new becomes the new first in this level */
			if (pTN->getParent() != NULL)
				(pTN->getParent())->setChild(pTN_New);
		}
		else {
			(pTN->getPrev())->setNext(pTN_New);
		}
		pTN_New->setPrev(pTN->getPrev());
		pTN->setPrev(pTN_New);
		pTN = pTN_New;
		keyPtr++;
		while (*keyPtr != '\0')
		{
			pTN_New = new TrieNode<E>(*keyPtr, VALUE_INTERNAL_NODE);
			pTN->setChild(pTN_New);
			(pTN->getChild())->setParent(pTN);
			pTN = pTN->getChild();
			keyPtr++;
		}
		if (*keyPtr == '\0')
		{
			insertExternalTN(pTN, keyStr, value);
			this->num_keys++;
			return;
		}
	}
}
template<typename E>
TrieNode<E>* Trie<E>::find(string keyStr)
{
	TrieNode<E>* pTN = NULL;
	pTN = _find(keyStr, FULL_MATCH);
	return pTN;
}
template<typename E>
TrieNode<E>* Trie<E>::_find(string keyStr, SearchMode sm)
{
	char* keyPtr;
	TrieNode<E>* pTN = NULL;
	TrieNode<E>* found = NULL;
	if (&keyStr == NULL)
		return NULL;
	keyPtr = (char*)keyStr.c_str();
	pTN = this->_root;
	while ((pTN != NULL) && (*keyPtr != '\0'))
	{
		while ((pTN != NULL) && (pTN->getKeyChar() < *keyPtr))
		{ // 없다면 next로 이동하지 못한다.
			if (pTN->getNext() == NULL)
				return NULL;
			pTN = pTN->getNext();
		}
		if ((pTN != NULL) && (pTN->getKeyChar() > *keyPtr))
		{
			// key not found
			return NULL;
		}
		else if ((pTN == NULL) && (*keyPtr != '\0'))
		{
			// key not found
			return NULL;
		}
		else if ((pTN->getKeyChar() == *keyPtr) && (*keyPtr != '\0'))
		{
			pTN = pTN->getChild();
			keyPtr++;
			if (*keyPtr == '\0')
			{
				/* key or prefix found */
				if (sm == FULL_MATCH)
				{
					if (pTN->getKeyChar() == '\0')
					{
						/* found the key string as a full-match */
						return pTN;
					}
					else // (pTN->getKey() != '\0')
					{
						/* found the key string as a substring of a longer existing string */
						return NULL;
					}
				}
				else if (sm == PREFIX_MATCH)
				{
					/* found the key string as a full-match or as a substring of a longer existing
					string */
					return pTN;
				}
			}
			else if ((pTN->getKeyChar() == '\0') && (*keyPtr != '\0'))
			{
				if (pTN->getNext() != NULL)
				{
					pTN = pTN->getNext();
					continue;
				}
				else
					return NULL;
			}
			else
			{
				continue;
			}
		}
	} // end while
}
template<typename E>
void Trie<E>::_traverse(TrieNode<E>* pTN, List_pStr& list_keywords)
{
	if (pTN == NULL)
		return;
	if (pTN->getChild() == NULL)
	{
		list_keywords.push_back(pTN->getValue());
	}
	else
	{
		_traverse(pTN->getChild(), list_keywords);
	}
	if (pTN->getNext() != NULL)
	{
		_traverse(pTN->getNext(), list_keywords);
	}
}
template<typename E>
void Trie<E>::findPrefixMatch(string keyStr, List_pStr& predictWords)
{
	TrieNode<E>* pPtr = NULL;
	const char* keyPtr;
	TrieNode<E>* pTN = NULL;
	TrieNode<E>* found = NULL;
	keyPtr = (char*)keyStr.c_str();
	if (keyPtr == NULL)
		return;
	pTN = this->_root;
	pTN = _find(keyStr, PREFIX_MATCH);
	_traverse(pTN, predictWords);
	//printf("Error in TrieSearch (key: %s) !!\n", keyWord);
}
template<typename E>
void Trie<E>::fprintTrie(ostream& fout)
{
	TrieNode<E>* pTN;
	int line = 1, indent = 0;
	fout << "trie ( " << this->trie_name << ") with "
		<< this->num_keys << " trie_nodes" << endl;
	if (this->num_keys == 0)
	{
		fout << "Empty trie !" << endl;
		return;
	}
	pTN = this->_root;
	pTN->_fprint(fout, pTN, indent);
}
#endif