/* main.cpp */
/* Description
* trie 자료구조 구현 및 기능 검사
* Programmed by J. H. Kim
* Last updated : 2021-12-01 */
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "MyVoca.h"
#include "MyVocaList.h"
#include "Trie.h"
#include "TrieNode.h"
using namespace std;

#define MAX_WORD_LENGTH 100 
#define NUM_TEST_VOCAS 7
//#define TEST_SIMPLE_TRIE
void test_simple_trie(ostream& fout);
void test_trie_myVoca(ostream& fout);

void main()
{
	ofstream fout;
	fout.open("output.txt");
	if (fout.fail())
	{
		printf("Error in opening output file !\n");
		exit;
	}
	Trie<MyVoca*> trie_myVoca("Trie_MyVoca");
	TrieNode<MyVoca*>* pTN;
	MyVoca* pVoca;
	int word_count;
	string keyStr;
	char keyWord[MAX_WORD_LENGTH];
	List_pVoca predictVocas;
	List_pVoca_Iter itr;
	/* Testing Basic Operation in trie */
	MyVoca testVocas[NUM_TEST_VOCAS] =
	{
	MyVoca("xyz", NOUN, { "" }, { "" }),
	MyVoca("ABCD", NOUN, { "" }, { "" }),
	MyVoca("ABC", NOUN, { "" }, { "" }),
	MyVoca("AB", NOUN, { "" }, { "" }),
	MyVoca("A", NOUN, { "" }, { "" }),
	MyVoca("xy", NOUN, { "" }, { "" }),
	MyVoca("x", NOUN, { "" }, { "" }),
	};
	fout << "Testing basic operations of trie inserting ..... " << endl;
	for (int i = 0; i < NUM_TEST_VOCAS; i++)
	{
		trie_myVoca.insert(testVocas[i].getKeyWord(), &testVocas[i]);
	}
	trie_myVoca.fprintTrie(fout);
	/*Destroy the trie*/
	fout << "\nTesting TrieDestroy...\n";
	trie_myVoca.eraseTrie();
	trie_myVoca.fprintTrie(fout);
	/* inserting keyWords into trie */
	fout << "Inserting My Vocabularies to myVocaDict . . . " << endl;
	word_count = 0;
	pVoca = &myToeicVocaList[0];
	while (pVoca->getKeyWord() != "-1")
	{
		keyStr = pVoca->getKeyWord();
		trie_myVoca.insert(keyStr, pVoca);
		pVoca++;
	}
	fout << "Total " << trie_myVoca.size() << " words in trie_myVoca .." << endl;
	trie_myVoca.fprintTrie(fout);
	/* testing keyWord search in trie */
	while (1)
	{
		cout << "\nInput any prefix to search in trie (. to finish) : ";
		cin >> keyStr;
		if (keyStr == string("."))
			break;
		predictVocas.clear();
		trie_myVoca.findPrefixMatch(keyStr, predictVocas);
		cout << "list of predictive words with prefix (" << keyStr << ") :" << endl;
		itr = predictVocas.begin();
		for (int i = 0; i < predictVocas.size(); i++)
		{
			pVoca = *itr;
			cout << *pVoca << endl;
			++itr;
		}
	}
	cout << endl;

	/* Testing TrieDeleteKey() */
	printf("\nTesting trie_delete_key for %d keywords from trie data structure.\n", NUM_MY_TOEIC_VOCA);
	for (int i = 0; i < NUM_MY_TOEIC_VOCA / 2; i++) {
		pVoca = &myToeicVocaList[i];
		if ((pVoca == NULL) || (*pVoca->getKeyWord().c_str() == '\0'))
			continue;
		fout << "Trie-Deleting (key : " << pVoca->getKeyWord() << ") ...\n";
		trie_myVoca.deleteKeyStr(pVoca->getKeyWord());
		//trieStr.fprintTrie(fout);
	}
	//trieStr.fprintTrie(fout);

	cout << "\nErasing trie_myVoca ...." << endl;
	fout << "\nErasing trie_myVoca ...." << endl;
	trie_myVoca.eraseTrie();
	fout.close();
}