/* Shape.cpp */
#include <iostream>
#include "Shape.h"
#include <iomanip>
using namespace std;

Shape::Shape() { // default constructor
	pos_x = pos_y = 0;
	angle = 0;
	line_color = brush_color = RGB_BLACK;
	name = "no_name";
	//cout << "Shape::Default constructor (" << name << ").₩n";
}
Shape::Shape(string name)
	:name(name) {
	pos_x = pos_y = 0;
	angle = 0;
	pen_thickness = 0;
	line_color = brush_color = RGB_BLACK;
	//cout << "Shape::Constructor (" << name << ").₩n";
}
Shape::~Shape() {
	//cout << "Shape::Destructor (" << name << ").₩n";
}
Shape::Shape(int px, int py, double ang, COLORREF ln_clr, COLORREF br_clr, int pen_thick, string nm) {
	pos_x = px;
	pos_y = py;
	angle = ang;
	pen_thickness = pen_thick;
	line_color = ln_clr;
	brush_color = br_clr;
	name = nm;
	//cout << "Shape::Constructor (" << name << ").₩n";
}
void Shape::fprint(ostream& fout) {
	fout << name << ": pos(" << get_pos_x() << ", " << get_pos_y() << ")";
	fout << ", angle(" << angle << ")";
	fout << ", pen_thickness(" << pen_thickness << ")";
	fout << ", line_color(";
	fprintRGB(fout, line_color);
	fout << "), brush_color(";
	fprintRGB(fout, brush_color);
	fout << ")";
}
void Shape::draw(ConsolePixelFrame cp_frame) {
	/* virtual function that will be late-binded to sub-class's draw() */
}
Shape& Shape::operator=(const Shape& s) {
	pos_x = s.pos_x;
	pos_y = s.pos_y;
	angle = s.angle;
	name = s.name;
	line_color = s.line_color;
	brush_color = s.brush_color;

	return *this;
}
ostream& operator<<(ostream& ostr, Shape& shp) {
	ostr << shp.name << ": pos(" << shp.get_pos_x() << ", " << shp.get_pos_y() << ")";
	ostr << ", angle(" << shp.angle << ")";
	ostr << ", pen_thickness(" << shp.pen_thickness << ")";
	ostr << ", line_color(";
	fprintRGB(ostr, shp.line_color);
	ostr << "), brush_color(";
	fprintRGB(ostr, shp.brush_color);
	ostr << ")";

	return ostr;
}