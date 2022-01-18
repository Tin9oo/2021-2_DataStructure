/* Person.h */
#ifndef P
#define P
#include <string>
#include "Date.h"
using namespace std;

class Person {
	friend ostream& operator<<(ostream&, const Person&);
public:
	Person() { birthDate = Date(0, 0, 0); name = ""; } // 생성자
	Person(string nm, Date bd) { birthDate = bd; name = nm; } // 생성자
	void setName(string n) { name = n; } // 이름 설정
	void setBirthDate(Date bd) { birthDate = bd; } // 생일 설정
	string getName() const { return name; } // 이름 반환
	Date getBirthDate() const { return birthDate; } // 생일 반환
	const Person& operator=(const Person&); // 대입연산자
protected:
	Date birthDate;
	string name;
};
#endif // !P
