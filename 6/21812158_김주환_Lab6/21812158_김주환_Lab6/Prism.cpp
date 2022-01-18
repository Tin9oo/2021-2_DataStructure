/* Prism.cpp */
#include <iostream>
#include <math.h>
#include "Prism.h"
#include <iomanip>
using namespace std;

Prism::Prism() // default constructor
	: Shape("no_name"), base(0), tri_height(0), height(0) {
	//cout << "Cylinder::Default AngleArc constructor (" << name << ").₩n";
}
Prism::Prism(string name)
	: Shape(name), base(0), tri_height(0), height(0) {
	//cout << "AngleArc::Constructor (" << name << ").₩n";
}
Prism::Prism(int px, int py, int b, int th, double ang, int ht,
	COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)
	: Shape(px, py, ang, ln_clr, br_clr, pen_thick, name) {
	//cout << "AngleArc::Constructor (" << name << ").₩n";
	base = b;
	tri_height = th;
	height = ht;
}
Prism::~Prism() {
	//cout << "Cylinder::Destructor (" << name << ").₩n";
}
double Prism::getArea() {
	return base * tri_height + base * height +
		2 * sqrt(base * base / 4.0 + tri_height * tri_height) * height;
}
void Prism::draw() {
	cout << "draw() of Cylinder";
	fprint(cout);
}
void Prism::draw(ConsolePixelFrame cp_frame){
	HPEN new_pen, old_pen; HBRUSH new_brush, old_brush; HDC hdc;

	int center_px, center_py; int start_px, start_py; double start_ang_rad;

	center_px = cp_frame.get_pos_org_x() + get_pos_x();
	center_py = cp_frame.get_pos_org_y() + get_pos_y();

	POINT p[3];
	p[0].x = center_px - base / 2;
	p[0].y = center_py - height / 2;
	p[1].x = p[0].x + base;
	p[1].y = p[0].y;
	p[2].x = p[0].x + base / 2.0;
	p[2].y = p[0].y - (base / 2.0) * tan(angle);

	hdc = cp_frame.getConsole_DC();
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);

	Polygon(hdc, p, 3);
	MoveToEx(hdc, p[0].x, p[0].y, (LPPOINT)NULL);
	LineTo(hdc, p[0].x, p[0].y + height);
	MoveToEx(hdc, p[1].x, p[1].y, (LPPOINT)NULL);
	LineTo(hdc, p[1].x, p[1].y + height);
	
	MoveToEx(hdc, center_px - base / 2, center_py + height / 2, (LPPOINT)NULL);
	LineTo(hdc, center_px + base / 2, center_py + height / 2);

	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}
ostream& operator<<(ostream& fout, const Prism& prm) {
	fout << prm.name << ": pos(" << prm.get_pos_x() << ", " << prm.get_pos_y() << ")";
	fout << ", angle(" << prm.angle << ")";
	fout << ", pen_thickness(" << prm.pen_thickness << ")";
	fout << ", line_color(";
	fprintRGB(fout, prm.line_color);
	fout << "), brush_color(";
	fprintRGB(fout, prm.brush_color);
	fout << ")";
	fout << ", base(" << prm.base << ")";
	fout << ", tri_height(" << prm.tri_height << ")";
	fout << ", height (" << prm.height << ")";
	fout << endl;

	return fout;
}
Prism& Prism::operator=(const Prism& right) {
	Shape::operator=(right);
	base = right.base;
	tri_height = right.tri_height;
	height = right.height;

	return *this;
}
void Prism::fprint(ostream& fout) {
	Shape::fprint(fout);
	fout << ", base (" << base << "), tri_height (" << tri_height << ")";
	fout << ", height(" << height << ")";
	fout << endl;
}