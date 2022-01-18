/* Rect.h */
#ifndef R_H
#define R_H
#include "Shape.h"

class Rect : public Shape { // �Ļ� Ŭ����
	friend ostream& operator<<(ostream &, Rect &);
public:
	// ������
	Rect();
	Rect(string name);
	Rect(Position pos, int w, int l, double ang, COLORREF color, string name);

	~Rect(); // �Ҹ���
	double getArea(); // ǥ���� ��ȯ

	// �����Լ� ����
	virtual void draw(ostream&);

	void fprint(ostream&); // ���
	int getWidth() { return width; } // ���� ��ȯ
	int getLength() { return length; } // ���� ��ȯ
	Rect& operator=(Rect& rec); // ���Կ�����
protected:
	int width;
	int length;
};
#endif // !R_H

