/** Cmplx.h */
#ifndef CMPLX_H
#define CMPLX_H
#include <iostream>
using namespace std;
class CmplxArray;
class Cmplx {
	friend ostream& operator<< (ostream&, const Cmplx&);
	friend istream& operator>> (istream&, Cmplx&);
	friend class CmplxArray;
public:
	Cmplx(double real = 0.0, double imag = 0.0); // constructor
	double mag() const; // return the magnitude 
	const Cmplx operator+(const Cmplx &);
	const Cmplx operator-(const Cmplx &);
	const Cmplx operator*(const Cmplx &);
	const Cmplx operator/(const Cmplx &);
	const Cmplx operator~(); // conjugate of this complex
	bool operator==(const Cmplx &);
	bool operator!=(const Cmplx &);
	bool operator<(const Cmplx &);
	bool operator>(const Cmplx &);
	const Cmplx operator=(const Cmplx &);
private:
	double real;
	double imag;
};
#endif