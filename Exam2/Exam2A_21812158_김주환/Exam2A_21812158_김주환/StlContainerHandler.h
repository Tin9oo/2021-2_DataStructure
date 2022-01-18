/* StlContainerHandler.h */
#ifndef STLCH_H
#define STLCH_H
#include <vector>
#include <algorithm>

template<typename T>
void printVector(vector<T>& v, string name, int per_line)
{
	string typeName = typeid(T).name();
	cout << name << " (size : " << v.size() << ") :" << endl;
	typename vector<T>::iterator p;
	for (p = v.begin(); p != v.end(); p++) {
		cout << *p << " ";
		if ((typeName == "class Date") || (typeName == "class Time"))
			continue;
		else
			cout << endl;
	}
	cout << endl << endl;
}
#endif // !STLCH_H