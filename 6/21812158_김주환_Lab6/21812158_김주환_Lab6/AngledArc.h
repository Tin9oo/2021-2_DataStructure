/* AngledArc.h */
#ifndef ANGLE_ARC_H
#define ANGLE_ARC_H
#include <string>
#include "Shape.h"
using namespace std;

class AngledArc : public Shape { // �Ļ� Ŭ����
	friend ostream& operator<<(ostream&, const AngledArc&); // ���
public:
	// ������
	AngledArc();
	AngledArc(string name);
	AngledArc(int px, int py, int r, int ang, int start_ang, int sweep_ang,
		COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);

	//AngledArc(AngledArc &angarc);
	~AngledArc();// �Ҹ���
	
	// �����Լ�
	virtual void draw(ConsolePixelFrame cp_frame);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // ���
	int getRadius() const { return radius; } // Radius ��ȯ
	void setRadius(int r) { radius = r; } // Radius ����
	AngledArc& operator=(const AngledArc& right); // ���Կ�����
protected:
	int radius;
	int start_angle;
	int sweep_angle;
};
#endif