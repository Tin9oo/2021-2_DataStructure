/* Student.h */
#ifndef S
#define S
#include "Person.h"
class StudentArray;
class Student : public Person {
	friend class StudentArray;
	friend ostream& operator<<(ostream&, const Student&);
public:
	Student(); // 생성자
	Student(int id); // 생성자
	Student(int id, string n, Date dob, string dept_n, double gpa); // 생성자
	int getST_id() const { return st_id; } // 학번 반환
	string getDept_name() const { return dept_name; } // 학과 이름 반환
	double getGPA() const { return gpa; } // 학점 반환
	Date getBirthDate() const { return birthDate; } // 생일 반환
	void setST_id(int id) { st_id = id; } // 학번 설정
	void setDept_name(string dp_n) { dept_name = dp_n; } // 학과 이름 설정
	void setGPA(double g) { gpa = g; } // 학점 설정
	const Student& operator=(const Student& right); // 대입연산자
	bool operator>(const Student& right); // 비교연산자
	bool operator==(const Student& right); // 비교연산자
private:
	int st_id;
	string dept_name;
	double gpa;
};
Student genRandStudent(int id); // 학생 랜덤 생성
void genST_ids(int num_students, int* st_ids); // 학번 랜덤 생성
#endif // !S