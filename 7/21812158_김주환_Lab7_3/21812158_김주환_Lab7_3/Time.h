/* Time.h */
#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time {
	friend ostream& operator<<(ostream&, const Time&); // ���
public:
	// ������
	Time() { hour = 0; min = 0; sec = 0; } // default constructor
	Time(int h, int m, int s);

	int elasedSec() const; // Time ������ �ʷ� ȯ�� �� ��ȯ
	Time getTime() const { return Time(hour, min, sec); } // Time ���� ��ȯ

	// �񱳿�����
	bool operator<(const Time&) const;
	bool operator<=(const Time&) const;
	bool operator>(const Time&) const;
	bool operator>=(const Time&) const;
	bool operator==(const Time&) const;
private:
	bool isValidTime(int, int, int); // ��ȿ�� Time �������� �Ǵ�
	int hour;
	int min;
	int sec;
};
#endif