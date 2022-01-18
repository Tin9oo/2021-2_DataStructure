/* Hexahedron.h */
#ifndef HXHD_H
#define HXHD_H
#include "Rect.h"

class Hexahedron : public Rect { // �Ļ� Ŭ����
	friend ostream& operator<<(ostream&, const Hexahedron&); // ���
public:
	// ������
	Hexahedron();
	Hexahedron(string name);
	Hexahedron(Position pos, int w, int l, int ht, double ang, COLORREF color, string name);

	//Cylinder(Cylinder &cyl);
	~Hexahedron(); // �Ҹ���
	double getArea(); // ǥ����

	// �����Լ� ����
	virtual void draw(ostream& fout);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // ���
	int getWidth() const { return width; } // ���� ��ȯ
	int getLength() { return length; } // ���� ��ȯ
	Hexahedron& operator=(const Hexahedron& right); // ���Կ�����
protected:
	int height;
};
#endif // !HXHD_H