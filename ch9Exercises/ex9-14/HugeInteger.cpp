#include "HugeInteger.h"

HugeInteger::HugeInteger()
{
	for (auto i : digits) {
		*digits[i] = "0";
	}
}



HugeInteger::~HugeInteger()
{
}

bool HugeInteger::isEqualTo(HugeInteger)
{
	return false;
}

bool HugeInteger::isNotEqualTo(HugeInteger)
{
	return false;
}

bool HugeInteger::isGreaterThan(HugeInteger)
{
	return false;
}

bool HugeInteger::isLessThan(HugeInteger)
{
	return false;
}

bool HugeInteger::isZero()
{
	return false;
}

bool HugeInteger::isEqualTo(HugeInteger, HugeInteger)
{
	return false;
}
