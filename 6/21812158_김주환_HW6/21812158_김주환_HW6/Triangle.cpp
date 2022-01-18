/* Triangle.cpp */
#include "Triangle.h"

ostream& operator<<(ostream& fout, Triangle& t) {
	t.fprint(fout);
	
	return fout;
}
Triangle::Triangle()
	: Shape(), base(0), tri_height(0) {

}
Triangle::Triangle(string name)
	: Shape(name), base(0), tri_height(0) {
	
}
Triangle::Triangle(Position pos, int b, int h, double ang, COLORREF color, string name)
	: Shape(pos, ang, color, name), base(b), tri_height(h) {
	
}
Triangle::~Triangle() {
	//cout << "Triangle::Destructor (" << name << ").₩n";
}
double Triangle::getArea() {
	return (base / 2.0) * tri_height;
}
void Triangle::draw(ostream& fout) {
	fout << "Triangle::draw()    =>     ";
	fprint(fout);
}
void Triangle::fprint(ostream& fout) {
	Shape::fprint(fout);
	fout << "base(" << base << "), tri_height(" << tri_height << "), ";
	int red, green, blue;
	red = (color & 0x000000FF);
	green = (color & 0x0000FF00) >> 8;
	blue = (color & 0x00FF0000) >> 16;
	fout << hex << "RGB(" << setw(3) << red << ", " << setw(3) << green << ", "
		<< setw(3) << blue << "), " << dec;
	fout << endl << "                           ";
	fout << "triangle area(" << getArea() << ")]";
	fout << endl << endl;
}
Triangle& Triangle::operator=(const Triangle& tri) {
	Shape::operator=(tri);
	base = tri.base;
	tri_height = tri.tri_height;

	return *this;
}