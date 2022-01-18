/* Student.h */
#ifndef S
#define S
#include "Person.h"
class StudentArray;
class Student : public Person {
	friend class StudentArray;
	friend ostream& operator<<(ostream&, const Student&);
public:
	Student(); // ������
	Student(int id); // ������
	Student(int id, string n, Date dob, string dept_n, double gpa); // ������
	int getST_id() const { return st_id; } // �й� ��ȯ
	string getDept_name() const { return dept_name; } // �а� �̸� ��ȯ
	double getGPA() const { return gpa; } // ���� ��ȯ
	Date getBirthDate() const { return birthDate; } // ���� ��ȯ
	void setST_id(int id) { st_id = id; } // �й� ����
	void setDept_name(string dp_n) { dept_name = dp_n; } // �а� �̸� ����
	void setGPA(double g) { gpa = g; } // ���� ����
	const Student& operator=(const Student& right); // ���Կ�����
	bool operator>(const Student& right); // �񱳿�����
	bool operator==(const Student& right); // �񱳿�����
private:
	int st_id;
	string dept_name;
	double gpa;
};
Student genRandStudent(int id); // �л� ���� ����
void genST_ids(int num_students, int* st_ids); // �й� ���� ����
#endif // !S