/* Circle.h */
#ifndef Circle_H
#define Circle_H
#include "Shape.h"

#define PI 3.141592

class Circle : public Shape { // �Ļ� Ŭ����
	friend ostream& operator<<(ostream&, Circle&); // ���
public:
	// ������
	Circle();
	Circle(string name);
	Circle(Position pos, int r, double ang, COLORREF color, string name);

	//Circle(Circle &tr);
	~Circle(); // �Ҹ���
	double getArea(); // ���� ��ȯ

	// �Ļ� Ŭ������ �´� ���� �Լ� ����
	virtual void draw(ostream&);

	void fprint(ostream&); // ���
	int getRadius() const { return radius; } // Radius ��ȯ
	void setRadius(int r) { radius = r; } // Radius ����
	Circle& operator=(const Circle& right); // ���Կ�����
protected:
	int radius;
};
#endif