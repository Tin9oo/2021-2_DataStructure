/* MyString.cpp */
#include <string>
#include "MyString.h"
using namespace std;

string genRandName() {
	char str[8];
	int name_len, i = 0;
	name_len = rand() % (7 - 4) + 4;
	str[0] = rand() % 26 + 'A';
	for (i = 1; i < name_len; i++)
		str[i] = rand() % 26 + 'a';
	str[i] = '\0';
	return string(str);
}
string genRandDeptName() {
	char str[5];
	int name_len, i = 0;
	name_len = rand() % (4 - 3) + 3;
	str[0] = rand() % 26 + 'A';
	for (i = 1; i < name_len; i++)
		str[i] = rand() % 26 + 'a';
	str[i] = '\0';
	return string(str);
}