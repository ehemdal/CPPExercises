#include <iostream>
#include "Complex.h"
using namespace std;


Complex::Complex(double a, double b) : realPart{ a }, imaginaryPart{ b }
{
	cout << "Two-argument Complex constructor called." << endl;
}

Complex::~Complex()
{
	cout << "Complex destructor called." << endl;
}

void Complex::add(const Complex a, const Complex b)
{
	
	realPart = a.realPart + b.realPart;
	imaginaryPart = a.imaginaryPart + b.imaginaryPart;
	return;
}

void Complex::subtract(const Complex a, const Complex b)
{
	realPart = a.realPart - b.realPart;
	imaginaryPart = a.imaginaryPart - b.imaginaryPart;
	return;
}

const std::string Complex::toString()
{
	string result = to_string(realPart) +
		(imaginaryPart >= 0 ? "+" : "") + to_string(imaginaryPart) + "j";
	return result;
}


