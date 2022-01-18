/* Elps.h */
#ifndef E
#define E
#include <string>
#include "Shape.h"
#include "Color.h"
class Elps : public Shape // Ellipse Ÿ��
{
	friend ostream& operator<<(ostream&, const Elps&);
public:
	Elps(); // ������
	Elps(string name); // ������
	Elps(int px, int py, double r1, double r2, double ang, COLORREF clr, string name); // ������
	~Elps(); // ������
	double getArea() const; // Ÿ�� ���� ���
	void draw(); // Ÿ�� �۵��� �ʿ��� �Ķ���� ���
	void print(ostream&); // Ÿ���� ���� ��±��
	double getRadius_1() const { return radius_1; }
	double getRadius_2() const { return radius_2; }
	void setRadius(double r1, double r2) { radius_1 = r1; radius_2 = r2; }
	Elps& operator=(const Elps& elp); // ���Կ�����
protected:
	double radius_1;
	double radius_2;
};
#endif // !E
