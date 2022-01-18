/* StudentArray.h */
#ifndef SA
#define SA
#include <iostream>
#include "Student.h"
using namespace std;
class StudentArray {
	friend ostream& operator<<(ostream&, const StudentArray&);
public:
	StudentArray(int size); // 생성자
	StudentArray(const StudentArray& obj); // 복제 생성자
	~StudentArray(); // 소멸자
	int size() const { return num_students; }
	Student& operator[] (int index) const;
	void sortByBirthDate(); // 생일 정렬
	void sortByName(); // 이름 정렬
	void sortByST_ID(); // 학번 정렬
	void sortByGPA(); // 학점 정렬
private:
	Student* students;
	int num_students;
	bool isValidIndex(int index) const; // 유효범위 확인
};
#endif // !SA
