/* main.cpp */
/* Description
* Hash Dictionary 설계 및 구현
* Programmed by J. H. Kim
* Last updated : 2021-11-24 */
#include <iostream>
#include <fstream>
#include <string>
#include "GenericSkipList.h"
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
	SkipList<string, MyVoca*> myVocaSL;
	typedef SkipList<string, MyVoca*>::Position Pos_planet;
	unsigned int h = 0;
	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "output.txt file opening failed !!\n";
		exit(1);
	}
	//testTaskSkipList();
	fout << "\n=================" << endl;
	fout << "Testing SkipList<int, Planet> ..." << endl;
	Pos_planet pPlanet;
	string id;

	fout << " Inserting myVocas to";
	fout << "myVoca SkipList ..." << endl;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		fout << "Inserting [";
		fout << i << "]: " << myToeicVocaList[i] << endl;
		id = myToeicVocaList[i].getKeyWord();
		myVocaSL.SkipListInsert(fout, id, &myToeicVocaList[i]);
		myVocaSL.PrintSkipList(fout);
		fout << endl;
	}
	fout << "\n********************* " << endl;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		fout << "Search planetSkipList and delete";
		fout << " the planet(";
		fout << myToeicVocaList[i] << ") : ";
		pPlanet = myVocaSL.SkipListSearch(myToeicVocaList[i].getKeyWord());
		if (pPlanet != Pos_planet(NULL))
		{
			fout << *pPlanet << endl;
			myVocaSL.SkipListRemove(fout, myToeicVocaList[i].getKeyWord());
		}
		myVocaSL.PrintSkipList(fout);
		fout << endl;
	}
}