/* Time.h */
#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time {
	friend ostream& operator<<(ostream&, const Time&);
public:
	Time(); // default constructor
	Time(int h, int m, int s); // ������
	Time& operator+(int s); // ������ �����ε�
	int elasedSec(); // ���� �� ���
	Time getTime(); // Time ���� ��ȯ
	
	// �񱳿�����
	bool operator<(Time&);
	bool operator<=(Time&);
	bool operator>(Time&);
	bool operator>=(Time&);
	bool operator==(Time&);
private:
	bool isValidTime(int, int, int); // ��ȿ�� Time �������� �Ǵ�
	int hour;
	int min;
	int sec;
}; 
#endif