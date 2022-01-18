/* Shape.cpp */
#include "Shape.h"

ostream& operator<<(ostream&fout, Shape& s) {
	s.fprint(fout);

	return fout;
}
Shape::Shape()
	: pos({ 0, 0 }), angle(0), name("noname"), color(RGB_BLACK) {

}
Shape::Shape(string name)
	: pos({ 0, 0 }), angle(0), name(name), color(RGB_BLACK) {

}
Shape::Shape(Position pos, double ang, COLORREF color, string name)
	: pos(pos), angle(ang), color(color), name(name) {
	// pos.Position(pos.x, pos.y);
}

Shape::~Shape() {

}
void Shape::draw(ostream& fout) {
	fout << "Shape::draw()       =>     ";
	fprint(fout);
	int red, green, blue;
	red = (color & 0x000000FF);
	green = (color & 0x0000FF00) >> 8;
	blue = (color & 0x00FF0000) >> 16;
	fout << hex << uppercase << "RGB(" << setw(3) << red << ", " << setw(3) << green << ", "
		<< setw(3) << blue << ")]" << dec;
	fout << endl << "                           ";
	fout << endl;
}

void Shape::fprint(ostream& fout) {
	fout << "[name(" << setw(20) << name << "), ";
	fout << "pos(" << pos.x << ", " << pos.y << "), ";
	// fout << "color(" << color << ")]";
}
Shape& Shape::operator=(const Shape& s) {
	pos = s.pos;
	angle = s.angle;
	name = s.name;
	color = s.color;

	return *this;
}
/*ostream& fprintRGB(ostream& ostr, COLORREF color) {
	int red, green, blue;
	red = (color & 0x000000FF);
	green = (color & 0x0000FF00) >> 8;
	blue = (color & 0x00FF0000) >> 16;
	ostr << "RGB(" << setw(3) << red << ", " << setw(3) << green << ", "
		<< setw(3) << blue << ")";

	return ostr;
}*/