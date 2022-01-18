/* ElpsCylinder.h */
#ifndef EC
#define ED
#include <string>
#include "Elps.h"
#include "Color.h"
using namespace std;
class ElpsCylinder : public Elps // Ÿ�� ���
{
	friend ostream& operator<<(ostream&, const ElpsCylinder&);
public:
	ElpsCylinder(); // default constructor
	ElpsCylinder(string n); // ������
	ElpsCylinder(int px, int py, double r1, double r2, double h, double ang, COLORREF clr, string n); // ������
	virtual ~ElpsCylinder(); // �Ҹ���
	double getArea() const; // Ÿ����� ǥ����
	double getVolume() const; // Ÿ����� ü��
	void draw();
	void print(ostream&);
	ElpsCylinder& operator=(const ElpsCylinder& right); // ���Կ�����
protected:
	double height; // Cylinder height
};
#endif // !EC
