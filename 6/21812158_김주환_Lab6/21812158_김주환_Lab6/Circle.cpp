/* Circle.cpp */
#include "Circle.h"

ostream& operator<<(ostream& fout, Circle& c) {
	fout << c.name << ": pos(" << c.get_pos_x() << ", " << c.get_pos_y() << ")";
	fout << ", angle(" << c.angle << ")";
	fout << ", pen_thickness(" << c.pen_thickness << ")";
	fout << ", line_color(";
	fprintRGB(fout, c.line_color);
	fout << "), brush_color(";
	fprintRGB(fout, c.brush_color);
	fout << ")";

	return fout;
}
Circle::Circle()
	: Shape() {
	radius = 0;
}
Circle::Circle(string name)
	: Shape(name) {
	radius = 0;
}
Circle::Circle(int px, int py, int r, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick,
	string name)
	:Shape(px, py, ang, ln_clr, br_clr, pen_thick, name) {
	radius = r;
}
//Circle(Circle &tr);
Circle::~Circle() {
	//cout << "Circle::Destructor (" << name << ").₩n";
}
double Circle::getArea() {
	return PI * radius * radius;
}
void Circle::draw(ConsolePixelFrame cp_frame) {
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;
	HDC hdc;

	int pos_center_x, pos_center_y;

	pos_center_x = cp_frame.get_pos_org_x() + get_pos_x();
	pos_center_y = cp_frame.get_pos_org_y() + get_pos_y();
	hdc = cp_frame.getConsole_DC();
	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(hdc, new_brush);

	Ellipse(hdc, pos_center_x - radius, pos_center_y - radius, pos_center_x + radius,
		pos_center_y + radius);

	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}
void Circle::fprint(ostream& fout) {
	Shape::fprint(fout);
	fout << ", radius(" << radius << ")";
}
Circle& Circle::operator=(const Circle& right) {
	Shape::operator=(right);
	radius = right.radius;

	return *this;
}