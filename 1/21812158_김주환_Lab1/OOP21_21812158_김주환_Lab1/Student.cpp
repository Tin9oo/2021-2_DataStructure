/* Student.cpp */

#include <iostream>
#include <iomanip>
using namespace std;

typedef struct s_Student {
	int st_id;
	char name[16];
	char dept[16];
	int grade;
	double gpa;
} Student;

void initStudents(Student students[], int st_ids[], int num_students) {
	int name_len;
	int j, grade;
	double br;

	srand(time(0));
	for (int i = 0; i < num_students; i++) {
		students[i].st_id = st_ids[i];

		name_len = rand() % 26 + 'A';

		students[i].name[0] = rand() % 26 + 'A';
		for (j = 1; j < name_len - 1; j++)
			students[i].name[j] = rand() % 26 + 'a';
		students[i].name[name_len - 1] = '\0';

		name_len = rand() % 4 + 2;
		for (j = 0; j < name_len - 1; j++)
			students[i].dept[j] = rand() % 26 + 'A';
		students[i].dept[name_len - 1] = '\0';

		students[i].grade = rand() % 8 + 1;

		students[i].gpa = (rand() % 10000) / 100.0;
	}
}
void fprintStudent(ostream& fout, Student* pSt) {
	int count = 0;
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(2);

	fout << "Student(ID : " << setw(4) << pSt->st_id;
	fout << ", Name : " << setw(16) << pSt->name;
	fout << ", Dept : " << setw(6) << pSt->dept;
	fout << ", Grade : " << pSt->gpa;
}
void fprintStudent_IDs(ostream& fout, Student students[], int num_students) {

}
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last) {
	Student* pSt;
	int count = 0;
	if (num_students <= num_first_last * 2) {
		for (int i = 0; i < num_students; i++) {
			pSt = &students[i];

			fout << setw(6) << pSt->st_id;
			count++;
			if ((count % 20) == 0) fout << endl;
		}
		return;
	}

	for (int i = 0; i < num_first_last; i++) {
		pSt = &students[i];

		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0) fout << endl;
	}

	fout << "....." << endl << endl;
	
	for (int i = num_students - num_first_last; i < num_students; i++) {
		pSt = &students[i];
		
		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0) fout << endl;
	}
}

// increasing order
void sortStudentsByID(Student students[], int num_students) {
	int i, j, mx;
	char minName[16] = { 0 };
	Student tmp;
	int min_st, min_ID;

	for (i = 0; i < num_students - 1; i++) {
		min_st = i;
		min_ID = students[min_st].st_id;
		for (j = i + 1; j < num_students; j++) {
			if (students[j].st_id < min_ID) {
				min_st = j;
				min_ID = students[j].st_id;
			}
		}

		if (min_st != i) {
			tmp = students[i];
			students[i] = students[min_st];
			students[min_st] = tmp;
		}
	}
}

// decreasing order in gpa, increasing order in ID
void sortStudentsByGPA_ID(Student students[], int num_students) {
	Student tmp;
	int max_gpa_index;
	double max_gpa;

	for (int i = 0; i < num_students - 1; i++) {
		max_gpa = students[i].gpa;

		for (int j = i + 1; j < num_students; j++) {
			if (students[j].gpa > max_gpa) { // gpa 내림차순 정렬
				max_gpa = students[j].gpa;

				tmp = students[i];
				students[i] = students[j];
				students[j] = tmp;
			}
			else if (students[j].gpa == max_gpa) { // gpa 같은 경우 ID 오름차순 정렬
				if (students[i].st_id > students[j].st_id) {
					tmp = students[i];
					students[i] = students[j];
					students[j] = tmp;
				}
			}
		}
	}
}
void fprintBigArrayOfStudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last) {
	Student* pSt;
	int count = 0;
	if (num_students <= num_first_last * 2) {
		for (int i = 0; i < num_students; i++) {
			pSt = &students[i];

			fout << "(";
			fout.setf(ios::fixed);
			fout.setf(ios::showpoint);
			fout.precision(2);
			fout << pSt->gpa << ",";
			fout << setw(5) << pSt->st_id << ") ";
			count++;
			if ((count % 10) == 0) fout << endl;
		}
		return;
	}

	for (int i = 0; i < num_first_last; i++) {
		pSt = &students[i];

		fout << "(";
		fout.setf(ios::fixed);
		fout.setf(ios::showpoint);
		fout.precision(2);
		fout << pSt->gpa << ",";
		fout << setw(5) << pSt->st_id << ") ";
		count++;
		if ((count % 10) == 0) fout << endl;
	}

	fout << "....." << endl << endl;

	for (int i = num_students - num_first_last; i < num_students; i++) {
		pSt = &students[i];

		fout << "(";
		if (pSt->gpa < 10) fout << " ";
		fout.setf(ios::fixed);
		fout.setf(ios::showpoint);
		fout.precision(2);
		fout << pSt->gpa << ",";
		fout << setw(5) << pSt->st_id << ") ";
		count++;
		if ((count % 10) == 0) fout << endl;
	}
}
Student* searchStudentByID(Student students[], int num_studnets, int st_ID) {
	int low, high, mid;
	int round = 0;

	low = 0;
	high = num_studnets - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (st_ID == students[mid].st_id) return &students[mid];
		else if (st_ID < students[mid].st_id) high = mid - 1;
		else low = mid + 1;
	}
	return NULL;
}