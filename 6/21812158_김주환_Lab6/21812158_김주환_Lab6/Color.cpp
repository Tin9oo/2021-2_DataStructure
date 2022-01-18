/* Color.cpp */
#include <iostream>
#include <iomanip>
#include "Color.h"

ostream& fprintRGB(ostream& ostr, COLORREF color) {
	int red, green, blue;
	red = (color & 0x000000FF);
	green = (color & 0x0000FF00) >> 8;
	blue = (color & 0x00FF0000) >> 16;
	ostr << "RGB(" << setw(3) << red << ", " << setw(3) << green << ", "
		<< setw(3) << blue << ")";

	return ostr;
}