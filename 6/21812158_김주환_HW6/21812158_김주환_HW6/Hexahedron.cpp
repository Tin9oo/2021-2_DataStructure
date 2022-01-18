/* Hexahedron.cpp */
#include <math.h>
#include "Hexahedron.h"

ostream& operator<<(ostream& fout, const Hexahedron& hxhd) {


	return fout;
}
Hexahedron::Hexahedron() // default constructor
	: Rect("no_name"), height(0) {
	//cout << "Cylinder::Default AngleArc constructor (" << name << ").₩n";
}
Hexahedron::Hexahedron(string name)
	: Rect(name), height(0) {
	//cout << "AngleArc::Constructor (" << name << ").₩n";
}
Hexahedron::Hexahedron(Position pos, int w, int l, int ht, double ang, COLORREF color, string name)
	: Rect(pos, w, l, ang, color, name), height(ht) {
	//cout << "AngleArc::Constructor (" << name << ").₩n";
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
void Hexahedron::draw(ostream& fout) {
	fout << "Hexahedron::draw()  =>     ";
	fprint(fout);
}
void Hexahedron::fprint(ostream& fout) {
	Shape::fprint(fout);
	fout << "width(" << width << "), length(" << length << "), ";
	fout << "height(" << height << "), ";
	int red, green, blue;
	red = (color & 0x000000FF);
	green = (color & 0x0000FF00) >> 8;
	blue = (color & 0x00FF0000) >> 16;
	fout << hex << "RGB(" << setw(3) << red << ", " << setw(3) << green << ", "
		<< setw(3) << blue << "), " << dec;
	fout << endl << "                           ";
	fout << "hexahedron surface area(" << getArea() << "), ";
	fout << dec << "hexahedron volume(" << width * length * height << ")]";
	fout << endl << endl;
}
Hexahedron& Hexahedron::operator=(const Hexahedron& right) {
	Shape::operator=(right);
	width = right.width;
	length = right.length;
	height = right.height;

	return *this;
}