
#include <iostream>
#include <fstream>
#include <string>
#include "HashMap.h"
#include "CyclicShiftHashCode.h"
#include "HashDictionary.h"
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
	HashDict<string, MyVoca*>::SLPos pos;

	cout << "Inserting My Vocabularies to myVocaDict . . . " << endl;

	word_count = 0;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		pVoca = &myToeicVocaList[i];
		keyWord = myToeicVocaList[i].getKeyWord();
		myVocaDict.insert(keyWord, pVoca);
	}
	//cout << endl;
	cout << "Total " << myVocaDict.size() << " words in my Voca_Dictionary .." << endl;

	// check all vocabularies in the hash_dictionary
	for (itr = myVocaDict.begin(); itr != myVocaDict.end(); ++itr)
	{
		itr.operator*().PrintSkipList();
	}
	cout << endl;

	//string testWord = "mean";
	string testWord = "offer";
	pVoca = itr.operator*().SkipListSearch(testWord).value().getValue();
	pos = itr.operator*().SkipListSearch(testWord);

	cout << "Thesaurus of [" << testWord << "]: \n";
	for (int i = pos.size(); i > 0; --i)
	{
		cout << pVoca << endl;
		pos = pos.below();
	}
	cout << endl;
}