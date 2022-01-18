/* Triangle.h */
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape { // �Ļ� Ŭ����
	friend ostream& operator<<(ostream &, Triangle &);
public:
	// ������
	Triangle();
	Triangle(string name);
	Triangle(Position pos, int b, int h, double ang, COLORREF color, string name);

	~Triangle(); // �Ҹ���
	double getArea(); // ǥ���� ��ȯ

	// �����Լ� ����
	virtual void draw(ostream& fout);

	void fprint(ostream&); // ���
	int getBase() { return base; } // �غ� ��ȯ
	int getHeight() { return tri_height; } // ���� ��ȯ
	Triangle& operator=(const Triangle& tri); // ���Կ�����
protected:
	int base;
	int tri_height;
};
#endif