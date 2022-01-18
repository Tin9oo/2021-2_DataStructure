/* Polygon.cpp */
#include "Polygon.h"

PolyGon::PolyGon()
	: Shape() {
	radius = 0;
	num_poly = 0;
}
PolyGon::PolyGon(string name)
	: Shape(name) {
	radius = 0;
	num_poly = 0;
}
PolyGon::PolyGon(int px, int py, int radius, int num_poly, double ang,
	COLORREF ln_clr, COLORREF br_clr, int pen_thick, string name)
	:Shape(px, py, ang, ln_clr, br_clr, pen_thick, name) {
	this->radius = radius;
	this->num_poly = num_poly;
}
PolyGon::~PolyGon() {
	//cout << "PolyGon::Destructor (" << name << ").₩n";
}
void PolyGon::draw(ConsolePixelFrame cp_frame) {
	POINT* points = (POINT*)calloc(num_poly, sizeof(POINT));

	double rad_angle, delta_angle; // angle in radian
	int pos_center_x, pos_center_y;

	pos_center_x = cp_frame.get_pos_org_x() + get_pos_x();
	pos_center_y = cp_frame.get_pos_org_y() + get_pos_y();

	int x, y;
	
	HDC hdc;
	HPEN new_pen, old_pen;
	HBRUSH new_brush, old_brush;

	hdc = cp_frame.getConsole_DC();
	delta_angle = 2.0 * PI / num_poly;
	rad_angle = PI / 2.0;
	for (int i = 0; i < num_poly; i++, rad_angle += delta_angle) {
		x = pos_center_x + radius * cos(rad_angle);
		y = pos_center_y - radius * sin(rad_angle);
		points[i].x = x;
		points[i].y = y;
	}

	new_pen = CreatePen(PS_SOLID, pen_thickness, line_color);
	old_pen = (HPEN)SelectObject(hdc, new_pen);
	new_brush = CreateSolidBrush(brush_color);
	old_brush = (HBRUSH)SelectObject(cp_frame.getConsole_DC(), new_brush);

	Polygon(hdc, points, num_poly);
	
	SelectObject(hdc, old_pen);
	DeleteObject(new_pen);
	SelectObject(hdc, old_brush);
	DeleteObject(new_brush);
}
void PolyGon::fprint(ostream& fout) {
	Shape::fprint(fout);
	fout << ", radius(" << radius << ")";
	fout << ", num_poly(" << num_poly << ")";
}
PolyGon& PolyGon::operator=(PolyGon& pg) {
	Shape::operator=(pg);
	radius = pg.radius;
	num_poly = pg.num_poly;

	return *this;
}