/* main.cpp */
/* Description
* Hash Dictionary 설계 및 구현
* Programmed by J. H. Kim
* Last updated : 2021-11-24 */
#include <iostream>
#include <fstream>
#include <string>
#include "HashMap.h"
#include "CyclicShiftHashCode.h"
#include "Entry.h"
#include "HashDictionary.h"
#include "MyVoca.h"
#include "MyVocaList.h"
void main()
{
	ofstream fout;
	MyVoca* pVoca, voca;
	List_Str thesaurus;
	List_Str usages;
	int word_count;
	MyVoca mv;
	string keyWord;
	HashDict<string, MyVoca*> myVocaDict;
	HashDict<string, MyVoca*>::Iterator itr;
	HashDict<string, MyVoca*>::Range range;
	Entry<string, MyVoca*> vocaEntry;
	CyclicShiftHashCode hash;
	unsigned int h = 0;

	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Fail to open output.txt !!" << endl;
		exit;
	}
	fout << "Inserting My Vocabularies to myVocaDict . . . " << endl;
	word_count = 0;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		pVoca = &myToeicVocaList[i];
		keyWord = myToeicVocaList[i].getKeyWord();
		myVocaDict.insert(keyWord, pVoca);
	}
	//cout << endl;
	fout << "Total " << myVocaDict.size() << " words in my Voca_Dictionary .." << endl;
	// check all vocabularies in the hash_dictionary
	for (itr = myVocaDict.begin(); itr != myVocaDict.end(); ++itr)
	{
		pVoca = itr.operator*().getValue();
		h = hash(pVoca->getKeyWord());
		fout << "[ Key Word : " << setw(15) << pVoca->getKeyWord();
		fout << ", Hash Code : " << setw(10) << h;
		fout << ", Hash Value : " << setw(5) << h % DEFAULT_HASH_TABLE_SIZE << "]" << endl;
	}
	fout << endl;
	fout << "Status of each Bucket" << endl;
	myVocaDict.fprintBucketSizes(fout, myVocaDict.begin());
	fout << endl;

	fout << "Total " << myVocaDict.size() << " words in my Voca_Dictionary .." << endl;
	// check all vocabularies in the hash_dictionary
	for (itr = myVocaDict.begin(); itr != myVocaDict.end(); ++itr)
	{
		pVoca = itr.operator*().getValue();
		fout << *pVoca << endl;
	}
	fout << endl;

	fout << endl;
	fout.close();
}