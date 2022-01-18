
#include <iostream>
#include <fstream>
#include <string>
#include "HashMap.h"
#include "HashDictionary.h"
#include "CyclicShiftHashCode.h"
#include "MyVoca.h"
#include "MyVocaList.h"
using namespace std;

void main()
{
	MyVoca* pVoca, voca;
	List_Str thesaurus;
	List_Str usages;
	int word_count;
	MyVoca mv;
	string keyWord;
	HashDict<string, MyVoca*> myVocaDict;
	HashDict<string, MyVoca*>::Iterator itr;
	HashDict<string, MyVoca*>::Range range;
	HashDict<string, MyVoca*>::SLPos pos;

	cout << "Inserting My Vocabularies to myVocaDict . . . " << endl << endl;

	word_count = 0;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		pVoca = &myToeicVocaList[i];
		keyWord = myToeicVocaList[i].getKeyWord();
		myVocaDict.insert(keyWord, pVoca);
	}
	cout << endl;
	cout << "Total " << myVocaDict.size() << " words in my Voca_Dictionary .." << endl << endl;

	// check all vocabularies in the hash_dictionary
	for (itr = myVocaDict.begin(); itr != myVocaDict.end(); ++itr)
	{
		itr.operator*().PrintSkipList();
	}
	cout << endl;

	string testWord = "mean";
	// string testWord = "offer";
	cout << "Thesaurus of [" << testWord << "]: \n";

	
	range = myVocaDict.findAll(testWord);
	pos = range.begin();

	for (pos = range.begin(); pos != range.end().after(); ++pos)
	{
		pVoca = pos.element();
		cout << *pVoca << endl;
	}
	
	/*
	CyclicShiftHashCode hash;
	int h = hash(testWord);
	itr = myVocaDict.find(testWord);
	pVoca = itr.operator*().SkipListSearch(h).element();
	pos = itr.operator*().SkipListSearch(h);

	for (;pos.before().key() != h;)
	{
		pVoca = pos.element();
		cout << *pVoca << endl;
		pos = pos.before();
	}
	*/
	
	cout << endl;
}