/* Prism.h */
#ifndef PSM_H
#define PSM_H
#include <string>
#include "Shape.h"
using namespace std;

class Prism : public Shape { // �Ļ� Ŭ����
	friend ostream& operator<<(ostream&, const Prism&); // ���
public:
	// ������
	Prism();
	Prism(string name);
	Prism(int px, int py, int b, int th, double ang, int ht, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);
	
	//Cylinder(Cylinder &cyl);
	~Prism(); // �Ҹ���
	double getArea(); // ǥ���� ��ȯ

	// �����Լ� ����
	virtual void draw(ConsolePixelFrame cp_frame);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // ���
	int getBase() const { return base; } // �غ� ��ȯ
	int getTriHeight() { return tri_height; } // �ظ� ���� ��ȯ
	Prism& operator=(const Prism& right); // ���Կ�����
protected:
	int base;
	int tri_height;
	int height;
};
#endif // !PSM_H
