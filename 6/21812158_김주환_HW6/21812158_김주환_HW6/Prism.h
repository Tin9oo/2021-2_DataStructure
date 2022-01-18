/* Prism.h */
#ifndef PSM_H
#define PSM_H
#include "Triangle.h"

class Prism : public Triangle { // �Ļ� Ŭ����
	friend ostream& operator<<(ostream&, const Prism&); // ���
public:
	// ������
	Prism();
	Prism(string name);
	Prism(Position pos, int b, int th, int ht, double ang, COLORREF color, string name);

	//Cylinder(Cylinder &cyl);
	~Prism(); // �Ҹ���
	double getArea(); // ǥ���� ��ȯ

	// �����Լ� ����
	virtual void draw(ostream& fout);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // ���
	int getBase() const { return base; } // �غ� ��ȯ
	int getTriHeight() { return tri_height; } // �ظ� ���� ��ȯ
	Prism& operator=(const Prism& right); // ���Կ�����
protected:
	int height;
};
#endif // !PSM_H
