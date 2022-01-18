/* Date.h */
#ifndef D
#define D
#include <fstream>
using namespace std;
class Date {
	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, const Date&);
public:
	Date(); // ������
	Date(int y, int m, int d); // ������
	void setDate(int newYear, int newMonth, int newDay); // Date ����
	int getYear() { return year; } // ���� ��ȯ
	int getYearDay(); // �̹��⵵ ���� �� �� ��ȯ
	int getWeekDay(); // ���� ��ȯ
	int getElapsedDays(); // ���ʺ��� ���� �� �� ��ȯ
	const Date operator=(const Date rightSide); // ���Կ�����
	bool operator>(Date rightSide); // �񱳿�����
	bool operator<(Date rightSide); // �񱳿�����
	bool operator==(Date rightSide); // �񱳿�����
	bool operator!=(Date rightSide); // �񱳿�����
	bool isLeapYear(int y); // ���� Ȯ��
private:
	bool isLeapYear(); // ���� Ȯ��
	bool isValidDate(int y, int m, int d); // ��ȿ�� Date ���� Ȯ��
	int year;
	int month;
	int day;
};

bool isLeapYear(int y); // ���� Ȯ��
Date genRandDate(); // Date ���� ����
#endif // !D
