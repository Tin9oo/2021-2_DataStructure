/* StlContainerHandler.h */
#ifndef STLCH_H
#define STLCH_H
#include <list>

template<typename T>
void printList(list<T>& L, string name, int per_line)
{
	string typeName = typeid(T).name();
	cout << name << " (size : " << L.size() << ") :" << endl;
	typename list<T>::iterator p;
	int cnt = 1;
	for (p = L.begin(); p != L.end(); p++) {
		cout << *p << " ";
		if ((typeName == "class Date") || (typeName == "class Time"))
			continue;
		else
			cout << endl;
	}
	cout << endl;
}
#endif // !STLCH_H