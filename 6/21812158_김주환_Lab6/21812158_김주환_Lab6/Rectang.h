/* Rectang.h */
#ifndef Rectang_H
#define Rectang_H
#include <string>
#include "Shape.h"
using namespace std;

class Rectang : public Shape { // �Ļ� Ŭ����
	//friend ostream& operator<<(ostream &, Rectangle &);
public:
	// ������
	Rectang();
	Rectang(string name);
	Rectang(int px, int py, int w, int l, double ang,
		COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);
	
	~Rectang(); // �Ҹ���
	double getArea(); // ǥ���� ��ȯ

	// �����Լ� ����
	virtual void draw(ConsolePixelFrame cp_frame);

	void fprint(ostream&); // ���
	int getWidth() { return width; } // ���� ��ȯ
	int getLength() { return length; } // ���� ��ȯ
	Rectang& operator=(Rectang& rec); // ���Կ�����
protected:
	int width;
	int length;
};
#endif