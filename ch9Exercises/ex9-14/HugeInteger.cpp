#include "HugeInteger.h"
#include <sstream>

HugeInteger::HugeInteger()
{
	// Initialize a HugeInteger to zero, with size 1
	digits.at(0) = "0";
	size = 1;
	negative = false;
}

HugeInteger::HugeInteger(std::string IH)
{
	input(IH);
}



HugeInteger::~HugeInteger()
{
}

bool HugeInteger::isEqualTo(HugeInteger IH)
{
	//If sizes are not the same, they are not equal
	if (size != IH.size) return false;
	//If sign is not the same, they are not equal
	if (negative != IH.negative) return false;
	//If sizes are the same, compare digit-by-digit
	for (int i = 0; i < size; i++)
	{
		if (digits.at(i) != IH.digits.at(i)) {
			return false;
		}
	}
	return true;
}

bool HugeInteger::isNotEqualTo(HugeInteger HI)
{
	if (this->isEqualTo(HI)) {
		return false;
	}
	else return true;
}

bool HugeInteger::isGreaterThan(HugeInteger HI)
{
	bool bothArePositive{ false };
	bool bothAreNegative{ false };

	// if this is positive and HI is negative, this is greater than HI
	if (!negative && HI.negative) return true;

	// if HI is positive and this is negative, this is not greater than HI
	if (negative && !HI.negative) return false;

	// if both have positive sign, and this size is larger, it is greater than HI
	if (!negative && !HI.negative) {
		bothArePositive = true;
		if (size > HI.size) return true;
	}

	// if both are negative and this size is larger, it is not greater than HI
	if (negative && HI.negative) {
		bothAreNegative = true;
		if (size > HI.size) return false;
	}

	// if the sizes are the same and the signs are the same, compare digit by digit
	for (int i = 0; i < size; i++) {
		if (digits.at(i) > HI.digits.at(i)) {
			if (bothArePositive) return true;
			if (bothAreNegative) return false;
		}
		else if (digits.at(i) < HI.digits.at(i)) {
			if (bothArePositive) return false;
			if (bothAreNegative) return true;
		}
		else continue;
	}
	
	return false; // they must be equal
}

bool HugeInteger::isLessThan(HugeInteger IH)
{
	if (!this->isGreaterThan(IH) &&
		!this->isEqualTo(IH)) return true;
	return false;
}

bool HugeInteger::isZero()
{
	// The value is zero if the size is 1 and the value is "0"
	if ((1 == size) && (digits.at(0) == "0")) {
		return true;
	}
	else return false;

}

void HugeInteger::input(std::string x)
{
	int i{ 0 };
	bool negativeInput{ false };

	// Check for a negative value and grab the sign in the incoming string
	if (x.at(0) == '-') {
		negativeInput = true;
		x.erase(0,1);
	}
	else if (x.at(0) == '+') {  // just in case someone passed in "+123..."
		x.erase(0,1);
		negativeInput = false;
		}

	// Get the digits of this object into a string of the proper length
	if (INTEGERSIZE < x.length()) return; // could return an exception here

	// empty the digits array by setting the size property to zero.  We can't do this via a member function because the array
	// doesn't know its size. We have to manage it.
	size = 0;

	// load the new digits in reverse order so least-significant digit in in data(0).
	int j = x.length() - 1;
	for (i = 0; i < static_cast<int>(x.length()); i++) {
		digits.at(j) = x[i];
		j--;
	}
	size = i;
	negative = negativeInput;
}

void HugeInteger::output()
{
	//Display the HugeInteger. 
	if (negative) {
		std::cout << "-";
	}
	for (int i = (size - 1); i >= 0; i--) {
		std::cout << digits.at(i);
	}
	std::cout << std::endl;
}

