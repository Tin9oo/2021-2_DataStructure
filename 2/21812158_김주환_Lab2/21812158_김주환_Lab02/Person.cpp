/* Person.cpp */
#include "Person.h"

void Person::setRandPersonAttributes() {
	char str[MAX_NAME_LEN + 1];
	int name_len, i = 0;
	birthDate.setRandDateAttributes();
	name_len = rand() % (MAX_NAME_LEN - MIN_NAME_LEN) + MIN_NAME_LEN;
	str[0] = rand() % 26 + 'A';
	for (i = 1; i < name_len; i++)
		str[i] = rand() % 26 + 'a';
	str[i] = '\0';
	name = string(str);
}
void Person::fprintPerson(ostream& fout) {
	fout << " Person [name: ";
	fout.setf(ios::left);
	fout << setw(16) << name;
	fout << ", birth date: ";
	fout.unsetf(ios::left);
	birthDate.fprintDate(fout);
	fout << "]";
}
void Person::sortByName(Person persons[], int num_person) {
	int i, j, mx;
	Person tmp;
	int min_p;
	string min_N;

	for (i = 0; i < num_person - 1; i++) {
		min_p = i;
		min_N = persons[min_p].name;
		for (j = i + 1; j < num_person; j++) {
			if (persons[j].name.compare(min_N) < 0) {
				min_p = j;
				min_N = persons[j].name;
			}
		}

		if (min_p != i) {
			tmp = persons[i];
			persons[i] = persons[min_p];
			persons[min_p] = tmp;
		}
	}
}
void Person::sortByBirthDay(Person persons[], int num_person) {
	int i, j, mx;
	Person tmp;
	int min_p;
	Date min_BD;

	for (i = 0; i < num_person - 1; i++) {
		min_p = i;
		min_BD = persons[min_p].birthDate;
		for (j = i + 1; j < num_person; j++) {
			if (persons[j].birthDate.getElapsedDaysFromAD010101() < min_BD.getElapsedDaysFromAD010101()) {
				min_p = j;
				min_BD = persons[j].birthDate;
			}
		}

		if (min_p != i) {
			tmp = persons[i];
			persons[i] = persons[min_p];
			persons[min_p] = tmp;
		}
	}
}