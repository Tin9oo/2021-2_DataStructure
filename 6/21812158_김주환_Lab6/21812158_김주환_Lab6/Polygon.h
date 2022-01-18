/* Polygon.h */
#ifndef PolyGon_H
#define PolyGon_H
#include <string>
#include "Shape.h"
using namespace std;

class PolyGon : public Shape { // �Ļ� Ŭ����
	//friend ostream& operator<<(ostream &, PolyGonle &);
public:
	// ������
	PolyGon();
	PolyGon(string name);
	PolyGon(int px, int py, int radius, int num_poly, double ang, COLORREF ln_clr, COLORREF br_clr,
		int pen_thick, string name);

	~PolyGon(); // �Ҹ���

	// �����Լ� ����
	virtual void draw(ConsolePixelFrame cp_frame);

	void fprint(ostream&); // ���
	int getRadius() { return radius; } // ������ ��ȯ
	int getNumPoly() { return num_poly; } // ������ ��ȯ
	PolyGon& operator=(PolyGon& pg); // ���Կ�����
protected:
	int radius;
	int num_poly;
};
#endif