/* Student.h */

#include <iostream>
using namespace std;

typedef struct s_Student {
	int st_id;
	char name[16];
	char dept[16];
	int grade;
	double gpa;
} Student;

void initStudents(Student students[], int st_ids[], int num_students);
void fprintStudent(ostream& fout, Student* pSt);
void fprintStudent_IDs(ostream& fout, Student students[], int num_students);
void fprintBigArrayOfStudent_IDs(ostream& fout, Student studnets[], int num_students, int num_first_last);
void sortStudentsByID(Student students[], int num_students);
void sortStudentsByGPA_ID(Student students[], int num_students);
void fprintBigArrayOfStudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last);
Student* searchStudentByID(Student students[], int num_studnets, int st_ID);