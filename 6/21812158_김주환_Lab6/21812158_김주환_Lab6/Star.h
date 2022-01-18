/* Star.h */
#ifndef Star_H
#define Star_H
#include <string>
#include "Shape.h"
using namespace std;

class Star : public Shape { // �Ļ� Ŭ����
	//friend ostream& operator<<(ostream &, PolyGonle &);
public:
	// ������
	Star();
	Star(string name);
	Star(int px, int py, int radius, int num_vertices, double ang, COLORREF ln_clr,
		COLORREF br_clr, int pen_thick, string name);

	//PolyGonle(PolyGonle &pg);
	~Star(); // �Ҹ���
	//double getArea();

	// �����Լ� ����
	virtual void draw(ConsolePixelFrame cp_frame);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // ���
	int getRadius() { return radius; } // ������ ��ȯ
	int getNumPoly() { return num_vertices; } // ������ ��ȯ
	Star& operator=(Star& pg); // ���Կ�����
protected:
	int radius;
	int num_vertices;
};
#endif