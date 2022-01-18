/* Cylinder.cpp */
#include <iostream>
#include <math.h>
#include "Cylinder.h"
#include <iomanip>
using namespace std;

Cylinder::Cylinder() // default constructor
	: Shape("no_name"), radius(0), height(0) {
	//cout << "Cylinder::Default AngleArc constructor (" << name << ").₩n";
}
Cylinder::Cylinder(string name)
	: Shape(name), radius(0), height(0) {
	//cout << "AngleArc::Constructor (" << name << ").₩n";
}
Cylinder::Cylinder(int px, int py, int r, int ang, int ht, COLORREF ln_clr, COLORREF br_clr,
	int pen_thick, string name)
	: Shape(px, py, ang, ln_clr, br_clr, pen_thick, name) {
	//cout << "AngleArc::Constructor (" << name << ").₩n";
	radius = r;
	height = ht;
}
Cylinder::~Cylinder() {
	//cout << "Cylinder::Destructor (" << name << ").₩n";
}
double Cylinder::getArea() {
	return 2 * PI * radius * radius + 2 * PI * radius * height;
}
void Cylinder::draw() {
	cout << "draw() of Cylinder";
	fprint(cout);
}
void Cylinder::draw(ConsolePixelFrame cp_frame) {
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	HDC hdc;

	int center_px, center_py;
	int start_px, start_py;
	double start_ang_rad;
	
	center_px = cp_frame.get_pos_org_x() + get_pos_x();
	center_py = cp_frame.get_pos_org_y() + get_pos_y();
	
	hdc = cp_frame.getConsole_DC();
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);
	
	MoveToEx(hdc, center_px - radius, center_py - height / 2, (LPPOINT)NULL);
	LineTo(hdc, center_px - radius, center_py + height / 2); // 왼쪽 줄
	MoveToEx(hdc, center_px + radius, center_py - height / 2, (LPPOINT)NULL);
	LineTo(hdc, center_px + radius, center_py + height / 2); // 오른쪽 줄
	Ellipse(hdc, center_px - radius, center_py - height / 2 - 20, // 윗면
		center_px + radius, center_py - height / 2 + 20); 
	MoveToEx(hdc, center_px - radius, center_py + height / 2, (LPPOINT)NULL);
	ArcTo(hdc, center_px - radius, center_py + height / 2 - 20, center_px + radius, // 아랫면 곡선
		center_py + height / 2 + 20, center_px - radius, center_py + height / 2,
		center_px + radius, center_py + height / 2);
	
	SelectObject(hdc, old_pen); DeleteObject(new_pen);
	SelectObject(hdc, old_brush); DeleteObject(new_brush);
}
ostream& operator<<(ostream& fout, const Cylinder& cyl) {
	fout << cyl.name << ": pos(" << cyl.get_pos_x() << ", " << cyl.get_pos_y() << ")";
	fout << ", angle(" << cyl.angle << ")";
	fout << ", pen_thickness(" << cyl.pen_thickness << ")";
	fout << ", line_color(";
	fprintRGB(fout, cyl.line_color);
	fout << "), brush_color(";
	fprintRGB(fout, cyl.brush_color);
	fout << ")";
	fout << ", radius(" << cyl.radius << ")";
	fout << ", height (" << cyl.height << ")";
	fout << endl;

	return fout;
}
Cylinder& Cylinder::operator=(const Cylinder& right) {
	Shape::operator=(right);
	radius = right.radius;
	height = right.height;

	return *this;
}
void Cylinder::fprint(ostream& fout) {
	Shape::fprint(fout);
	fout << ", radius (" << radius << "), height (" << height << ")";
	fout << endl;
}