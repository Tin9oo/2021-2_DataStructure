/* main_trie.cpp */
/* Description
* Trie 구현 및 기능검사
* Programmed by J. H. Kim
* Last updated : 2021-12-15 */
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "Trie.h"
#include "TrieNode.h"
using namespace std;
#define NUM_SAMPLE_TEXTS 100
#define NUM_TEST_PREFIX 3
void main()
{
	Trie<string*> trie_PredictText("Trie_PredictiveText");
	TrieNode<string*>* pTN;
	int word_count;
	string keyStr, prefixStr;
	List_pStr predictTexts;
	List_pStr_Iter itr;
	/* Testing Basic Operation in trie */
	string sample_texts[] =
	{
	"abcd", "abc", "ab", "a", "WXYZ", "WXY", "WX", "W", "bcd", "bc", "binary", "bit",
	"-1"
	};
	cout << "Inserting keywords (texts) into " << trie_PredictText.getName() << " ..... " << endl;

	for (int i = 0; i < NUM_SAMPLE_TEXTS; i++)
	{
		keyStr = sample_texts[i];
		if (keyStr == "-1")
			break;
		trie_PredictText.insert(keyStr, &sample_texts[i]);
	}
	trie_PredictText.fprintTrie(cout);
	/* testing keyWord search in trie */
	string testPrefix[NUM_TEST_PREFIX] = { "W", "a", "b" };
	for (int i = 0; i < NUM_TEST_PREFIX; i++)
	{
		predictTexts.clear();
		prefixStr = testPrefix[i];
		trie_PredictText.findPrefixMatch(prefixStr, predictTexts);
		cout << "Predictive wors that starts with with (" << prefixStr << ") : ";
		itr = predictTexts.begin();
		for (int i = 0; i < predictTexts.size(); i++)
		{
			keyStr = *(*itr);
			cout << keyStr << ", ";
			++itr;
		}
		cout << endl;
	}
}