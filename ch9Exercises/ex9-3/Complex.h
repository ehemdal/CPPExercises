#pragma once
#include <string>

class Complex {

public:
	// Constructor
	explicit Complex(double = 0, double = 0);
	// Destructor
	~Complex();

	// Member functions
	void add(Complex a, Complex b);
	void subtract(Complex a, Complex b);
	const std::string toString();

private:
	double realPart{ 0 };
	double imaginaryPart{ 0 };
};