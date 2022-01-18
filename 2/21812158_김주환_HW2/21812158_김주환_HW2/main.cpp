/* main.cpp */
/* Description
* Date ��ü�� �����Ѵ�.
* ���ϴ� ��¥�� �Է��ϰ� ũ������������ �󸶳� ���Ҵ��� Ȯ���Ѵ�.
* Programmed by J. H. Kim
* Last updated : 2021-09-15 */
#include <iostream>
#include "Date.h"
using namespace std;
int main() {
	Date AD010101(1, 1, 1), newYearDay(2021, 1, 1), today, christmas(2021, 12, 25); // ��ü ����
	int year;
	int daysToChristmas;
	cout << "AD Jan. 1, 1 is ";
	AD010101.print(); // ���� 1�� 1�� 1�� ���� ���
	cout << endl;
	cout << "New year's day of 2020 is ";
	newYearDay.print(); // �ݳ� 1�� 1�� ���� ���
	cout << endl;
	cout << "Christmas of this year is ";
	christmas.print(); // ũ�������� ���� ���
	cout << endl;
	today.input(); // ���� ���� �Է�
	cout << "Today is ";
	today.print(); // ���� ���� ���
	cout << endl;
	if (today.getMonth() == christmas.getMonth() && // �Է¹��� Date�� ũ������������ Ȯ��
		today.getDay() == christmas.getDay()) {
		cout << "Happy Christmas !!\n";
	}
	else { // �ƴҰ��
		cout << "Sorry, today is not Christmas!";
		daysToChristmas = christmas.getElapsedDays() - today.getElapsedDays(); // ũ������������ �󸶳� ���Ҵ��� ���
		cout << " You must wait " << daysToChristmas << " day(s) to Christmas !" << endl;
	}
	return 0;
}