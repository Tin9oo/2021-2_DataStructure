/* StudentArray.h */
#ifndef SA
#define SA
#include <iostream>
#include "Student.h"
using namespace std;
class StudentArray {
	friend ostream& operator<<(ostream&, const StudentArray&);
public:
	StudentArray(int size); // ������
	StudentArray(const StudentArray& obj); // ���� ������
	~StudentArray(); // �Ҹ���
	int size() const { return num_students; }
	Student& operator[] (int index) const;
	void sortByBirthDate(); // ���� ����
	void sortByName(); // �̸� ����
	void sortByST_ID(); // �й� ����
	void sortByGPA(); // ���� ����
private:
	Student* students;
	int num_students;
	bool isValidIndex(int index) const; // ��ȿ���� Ȯ��
};
#endif // !SA
