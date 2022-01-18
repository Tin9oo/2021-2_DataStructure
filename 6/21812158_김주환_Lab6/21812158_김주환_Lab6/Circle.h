/* Circle.h */
#ifndef Circle_H
#define Circle_H
#include <string>
#include "Shape.h"
using namespace std;

#define PI 3.141592

class Circle : public Shape { // �Ļ� Ŭ����
	friend ostream& operator<<(ostream&, Circle&); // ���
public:
	// ������
	Circle();
	Circle(string name);
	Circle(int px, int py, int r, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick,
		string name);

	//Circle(Circle &tr);
	~Circle(); // �Ҹ���
	double getArea(); // ���� ��ȯ

	// �Ļ� Ŭ������ �´� ���� �Լ� ����
	virtual void draw(ConsolePixelFrame cp_frame);
	
	void fprint(ostream&); // ���
	int getRadius() const { return radius; } // Radius ��ȯ
	void setRadius(int r) { radius = r; } // Radius ����
	Circle& operator=(const Circle& right); // ���Կ�����
protected:
	int radius;
};
#endif