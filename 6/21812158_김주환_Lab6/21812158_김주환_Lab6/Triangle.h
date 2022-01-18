/* Triangle.h */
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>
#include "Shape.h"
using namespace std;

class Triangle : public Shape { // �Ļ� Ŭ����
	//friend ostream& operator<<(ostream &, Triangle &);
public:
	// ������
	Triangle();
	Triangle(string name);
	Triangle(int px, int py, int b, int h, double ang, COLORREF ln_clr, COLORREF br_clr,
		int pen_thick, string name);

	~Triangle(); // �Ҹ���
	double getArea(); // ǥ���� ��ȯ

	// �����Լ� ����
	virtual void draw(ConsolePixelFrame cp_frame);

	void fprint(ostream&); // ���
	int getBase() { return base; } // �غ� ��ȯ
	int getHeight() { return tri_height; } // ���� ��ȯ
	Triangle& operator=(const Triangle& tri); // ���Կ�����
protected:
	int base;
	int tri_height;
};
#endif