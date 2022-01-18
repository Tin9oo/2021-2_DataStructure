/* Shape.h */
#ifndef S
#define S
#include <string>
#include "Color.h"
using namespace std;
class Shape
{
	friend ostream& operator<<(ostream&, Shape&);
public:
	Shape(); // default constructor
	Shape(string name); // ������
	Shape(int px, int py, double angle, COLORREF color, string name); // constructor
	~Shape(); // �Ҹ���
	void draw(); // ���� �׸� �� ���Ǵ� ���� ���
	void rotate(double rt_ang) { angle += rt_ang; } // ȸ��
	void move(int dx, int dy) { pos_x += dx; pos_y += dy; } // ��ǥ �̵�
	void print(ostream&);
	int get_pos_x() const { return pos_x; }
	int get_pos_y() const { return pos_y; }
	void set_pos_x(int x) { pos_x = x; }
	void set_pos_y(int y) { pos_y = y; }
	void setName(string n) { name = n; }
	string getName() { return name; }
	Shape& operator=(const Shape& s); // ���Կ�����
protected:
	int pos_x; // position x
	int pos_y; // position y
	double angle; // in radian
	string name;
	COLORREF color; // COLORREF is defined in <Windows.h>
};
#endif // !S
