/* AngledArc.h */
#ifndef ANGLE_ARC_H
#define ANGLE_ARC_H
#include <string>
#include "Shape.h"
using namespace std;

class AngledArc : public Shape { // 파생 클래스
	friend ostream& operator<<(ostream&, const AngledArc&); // 출력
public:
	// 생성자
	AngledArc();
	AngledArc(string name);
	AngledArc(int px, int py, int r, int ang, int start_ang, int sweep_ang,
		COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name);

	//AngledArc(AngledArc &angarc);
	~AngledArc();// 소멸자
	
	// 가상함수
	virtual void draw(ConsolePixelFrame cp_frame);
	virtual void draw(); // // used for testing of late binding

	void fprint(ostream&); // 출력
	int getRadius() const { return radius; } // Radius 반환
	void setRadius(int r) { radius = r; } // Radius 설정
	AngledArc& operator=(const AngledArc& right); // 대입연산자
protected:
	int radius;
	int start_angle;
	int sweep_angle;
};
#endif