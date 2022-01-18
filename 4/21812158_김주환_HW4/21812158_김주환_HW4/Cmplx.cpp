/** Cmplx.cpp */
#include <iostream>
#include "Cmplx.h"
using namespace std;
Cmplx::Cmplx(double r, double i) :real(r), imag(i) { }
ostream& operator<<(ostream& output, const Cmplx& c) {
	output << c.real << " ";
	if (c.imag >= 0.0) output << "+ " << c.imag << "j" << endl;
	else output << "- " << -1 * c.imag << "j" << endl;
	return output;
}
istream& operator>>(istream& input, Cmplx& c) {
	input >> c.real;
	input >> c.imag;
	return input;
}
const Cmplx Cmplx::operator+(const Cmplx& c) {
	Cmplx result;
	result.real = real + c.real; result.imag = imag + c.imag;
	return result;
}
const Cmplx Cmplx::operator-(const Cmplx& c) {
	Cmplx result;
	result.real = real - c.real; result.imag = imag - c.imag;
	return result;
}
const Cmplx Cmplx::operator*(const Cmplx& c) {
	Cmplx result;
	result.real = real * c.real - imag * c.imag; result.imag = real * c.imag + c.real * imag;
	return result;
}
const Cmplx Cmplx::operator/(const Cmplx& c) {
	Cmplx result;
	double temp;
	temp = c.real * c.real + c.imag * c.imag;

	result.real = (real * c.real + imag * c.imag) / temp; result.imag = (imag * c.real - real * c.imag) / temp;
	return result;
}
const Cmplx Cmplx::operator~() {
	Cmplx result;
	result.real = real; result.imag = -imag;
	return result;
}
bool Cmplx::operator==(const Cmplx& c) {
	if ((real == c.real) && (imag == c.imag))
		return true;
	else
		return false;
}
bool Cmplx::operator!=(const Cmplx& c) {
	if ((real == c.real) && (imag == c.imag))
		return false;
	else
		return true;
}
bool Cmplx::operator<(const Cmplx& c) {
	double mag1, mag2;
	
	mag1 = sqrt(real * real + imag * imag);
	mag2 = sqrt(c.real * c.real + c.imag * c.imag);

	if (mag1 < mag2)
		return true;
	else
		return false;
}
bool Cmplx::operator>(const Cmplx& c) {
	double mag1, mag2;

	mag1 = sqrt(real * real + imag * imag);
	mag2 = sqrt(c.real * c.real + c.imag * c.imag);

	if (mag1 < mag2)
		return false;
	else
		return true;
}
const Cmplx Cmplx::operator=(const Cmplx& c) {
	this->real = c.real; this->imag = c.imag;
	return *this;
}