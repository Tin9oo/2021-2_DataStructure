/* Shape.h */
#ifndef S_H
#define S_H
#include <string>
#include <Windows.h>
#include <conio.h>
#include "ConsolePixelDrawing.h"
#include "Color.h"
using namespace std;

#define PI 3.141592

class ConsolePixelFrame;
class Shape { // ��� Ŭ����
	friend ostream& operator<<(ostream&, Shape&); // ���
public:
	// ������
	Shape(); // default constructor
	Shape(string name);
	Shape(int px, int py, double ang, COLORREF ln_clr, COLORREF br_clr,
		int pen_thick, string name);
	
	// �����Լ�
	virtual ~Shape();
	virtual void draw(ConsolePixelFrame cp_frame);

	void fprint(ostream&); // ���
	int get_pos_x() const { return pos_x; } // x ��ǥ ��ȯ
	int get_pos_y() const { return pos_y; } // y ��ǥ ��ȯ
	void set_pos_x(int x) { pos_x = x; } // x ��ǥ ����
	void set_pos_y(int y) { pos_y = y; } // y ��ǥ ����
	string getName() { return name; } // �̸� ��ȯ
	void setName(string n) { name = n; } // �̸� ����
	Shape& operator=(const Shape& s); // ���Կ�����
protected:
	int pos_x; // position x
	int pos_y; // position y
	double angle;
	string name;
	int pen_thickness;
	COLORREF line_color;
	COLORREF brush_color;
};
#endif