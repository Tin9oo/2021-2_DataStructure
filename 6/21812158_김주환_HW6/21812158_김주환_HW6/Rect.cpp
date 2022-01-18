/* Rect.cpp */
#include "Rect.h"

ostream& operator<<(ostream& fout, Rect& r) {
	r.fprint(fout);

	return fout;
}
Rect::Rect()
	: Shape(), width(0), length(0) {

}
Rect::Rect(string name)
	: Shape(name), width(0), length(0) {

}
Rect::Rect(Position pos, int w, int l, double ang, COLORREF color, string name)
	: Shape(pos, ang, color, name), width(w), length(l) {

}
Rect::~Rect() {

}
double Rect::getArea() {
	return width * length;
}

// 가상함수 구현
void Rect::draw(ostream& fout) {
	fout << "Rect::draw()        =>     ";
	fprint(fout);
}

void Rect::fprint(ostream& fout) {
	Shape::fprint(fout);
	fout << "width(" << width << "), length(" << length << "), ";
	int red, green, blue;
	red = (color & 0x000000FF);
	green = (color & 0x0000FF00) >> 8;
	blue = (color & 0x00FF0000) >> 16;
	fout << hex << "RGB(" << setw(3) << red << ", " << setw(3) << green << ", "
		<< setw(3) << blue << "), " << dec;
	fout << endl << "                           ";
	fout << "rectangle area(" << getArea() << ")]";
	fout << endl << endl;
}
Rect& Rect::operator=(Rect& rec) {
	Shape::operator=(rec);
	width = rec.width;
	length = rec.length;

	return *this;
}