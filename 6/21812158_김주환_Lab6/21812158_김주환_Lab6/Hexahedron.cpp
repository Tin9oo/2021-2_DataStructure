/* Hexahedron.cpp */
#include <iostream>
#include <math.h>
#include "Hexahedron.h"
#include <iomanip>
using namespace std;

Hexahedron::Hexahedron() // default constructor
	: Shape("no_name"), width(0), length(0), height(0) {
	//cout << "Cylinder::Default AngleArc constructor (" << name << ").₩n";
}
Hexahedron::Hexahedron(string name)
	: Shape(name), width(0), length(0), height(0) {
	//cout << "AngleArc::Constructor (" << name << ").₩n";
}
Hexahedron::Hexahedron(int px, int py, int w, int l, double ang, int ht,
	COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)
	: Shape(px, py, ang, ln_clr, br_clr, pen_thick, name) {
	//cout << "AngleArc::Constructor (" << name << ").₩n";
	width = w;
	length = l;
	height = ht;
}
Hexahedron::~Hexahedron() {
	//cout << "Cylinder::Destructor (" << name << ").₩n";
}
double Hexahedron::getArea() {
	return 2 * (width * length + width * height + length * height);
}
void Hexahedron::draw() {
	cout << "draw() of Cylinder";
	fprint(cout);
}
void Hexahedron::draw(ConsolePixelFrame cp_frame) {
	HPEN new_pen, old_pen; HBRUSH new_brush, old_brush; HDC hdc;

	int center_px, center_py; int start_px, start_py; double start_ang_rad;

	double slp = length * cos(angle);

	center_px = cp_frame.get_pos_org_x() + get_pos_x();
	center_py = cp_frame.get_pos_org_y() + get_pos_y();

	POINT p[4];
	p[2].x = center_px + width / 2;
	p[2].y = center_py - height / 2;
	p[3].x = center_px - width / 2;
	p[3].y = center_py - height / 2;
	p[0].x = p[3].x + slp * cos(angle);
	p[0].y = p[3].y - slp * sin(angle);
	p[1].x = p[2].x + slp * cos(angle);
	p[1].y = p[2].y - slp * sin(angle);

	hdc = cp_frame.getConsole_DC();
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);

	MoveToEx(hdc, p[3].x, p[3].y, (LPPOINT)NULL);
	LineTo(hdc, p[3].x, p[3].y + height);
	MoveToEx(hdc, p[2].x, p[2].y, (LPPOINT)NULL);
	LineTo(hdc, p[2].x, p[2].y + height);
	MoveToEx(hdc, p[1].x, p[1].y, (LPPOINT)NULL);
	LineTo(hdc, p[1].x, p[1].y + height);
	MoveToEx(hdc, p[3].x, p[3].y + height, (LPPOINT)NULL);
	LineTo(hdc, p[2].x, p[2].y + height);
	MoveToEx(hdc, p[2].x, p[2].y + height, (LPPOINT)NULL);
	LineTo(hdc, p[2].x + slp * cos(angle), p[2].y - slp * sin(angle) + height);
	Polygon(hdc, p, 4); // 윗면

	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}
ostream& operator<<(ostream& fout, const Hexahedron& hxhd) {
	fout << hxhd.name << ": pos(" << hxhd.get_pos_x() << ", " << hxhd.get_pos_y() << ")";
	fout << ", angle(" << hxhd.angle << ")";
	fout << ", pen_thickness(" << hxhd.pen_thickness << ")";
	fout << ", line_color(";
	fprintRGB(fout, hxhd.line_color);
	fout << "), brush_color(";
	fprintRGB(fout, hxhd.brush_color);
	fout << ")";
	fout << ", width(" << hxhd.width << ")";
	fout << ", length(" << hxhd.length << ")";
	fout << ", height (" << hxhd.height << ")";
	fout << endl;

	return fout;
}
Hexahedron& Hexahedron::operator=(const Hexahedron& right) {
	Shape::operator=(right);
	width = right.width;
	length = right.length;
	height = right.height;

	return *this;
}
void Hexahedron::fprint(ostream& fout) {
	Shape::fprint(fout);
	fout << ", width (" << width << "), length (" << length << ")";
	fout << ", height(" << height << ")";
	fout << endl;
}