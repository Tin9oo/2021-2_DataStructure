/* Person.h */
#ifndef P
#define P
#include <string>
#include "Date.h"
using namespace std;

class Person {
	friend ostream& operator<<(ostream&, const Person&);
public:
	Person() { birthDate = Date(0, 0, 0); name = ""; } // ������
	Person(string nm, Date bd) { birthDate = bd; name = nm; } // ������
	void setName(string n) { name = n; } // �̸� ����
	void setBirthDate(Date bd) { birthDate = bd; } // ���� ����
	string getName() const { return name; } // �̸� ��ȯ
	Date getBirthDate() const { return birthDate; } // ���� ��ȯ
	const Person& operator=(const Person&); // ���Կ�����
protected:
	Date birthDate;
	string name;
};
#endif // !P
