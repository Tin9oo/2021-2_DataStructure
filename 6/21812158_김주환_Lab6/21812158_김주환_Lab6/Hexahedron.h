/* Hexahedron.h */
#ifndef HXHD_H
#define HXHD_H
#include <string>
#include "Shape.h"
using namespace std;

class Hexahedron : public Shape { // �Ļ� Ŭ����
	friend ostream& operator<<(ostream&, const Hexahedron&); // ���
public:
	// ������
	Hexahedron();
	Hexahedron(string name);
	Hexahedron(int px, int py, int w, int l, double ang, int ht, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);
	
	//Cylinder(Cylinder &cyl);
	~Hexahedron(); // �Ҹ���
	double getArea(); // ǥ����

	// �����Լ� ����
	virtual void draw(ConsolePixelFrame cp_frame);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // ���
	int getWidth() const { return width; } // ���� ��ȯ
	int getLength() { return length; } // ���� ��ȯ
	Hexahedron& operator=(const Hexahedron& right); // ���Կ�����
protected:
	int width;
	int length;
	int height;
};
#endif // !HXHD_H