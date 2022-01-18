/* Cylinder.h */
#ifndef CYLINDER_H
#define CYLINDER_H
#include "Circle.h"

class Cylinder : public Circle { // �Ļ� Ŭ����
	friend ostream& operator<<(ostream&, const Cylinder&); // ���
public:
	// ������
	Cylinder();
	Cylinder(string name);
	Cylinder(Position pos, int r, int height, int ang, COLORREF color, string name);

	//Cylinder(Cylinder &cyl);
	~Cylinder(); // �Ҹ���
	double getArea(); // ����

	// �����Լ� ����
	virtual void draw(ostream& fout);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // ���
	int getRadius() const { return radius; } // ������ ��ȯ
	void setRadius(int r) { radius = r; } // ������ ����
	Cylinder& operator=(const Cylinder& right); // ���Կ�����
protected:
	int height;
};
#endif