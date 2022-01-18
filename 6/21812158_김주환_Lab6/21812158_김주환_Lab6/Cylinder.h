/* Cylinder.h */
#ifndef CYLINDER_H
#define CYLINDER_H
#include <string>
#include "Shape.h"
using namespace std;

class Cylinder : public Shape { // �Ļ� Ŭ����
	friend ostream& operator<<(ostream&, const Cylinder&); // ���
public:
	// ������
	Cylinder();
	Cylinder(string name);
	Cylinder(int px, int py, int r, int ang, int height,
		COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);
	
	//Cylinder(Cylinder &cyl);
	~Cylinder(); // �Ҹ���
	double getArea(); // ����

	// �����Լ� ����
	virtual void draw(ConsolePixelFrame cp_frame);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // ���
	int getRadius() const { return radius; } // ������ ��ȯ
	void setRadius(int r) { radius = r; } // ������ ����
	Cylinder& operator=(const Cylinder& right); // ���Կ�����
protected:
	int radius;
	int height;
};
#endif