#pragma once
#include<string>

class HugeInteger {

public:
	HugeInteger();
	
	~HugeInteger();

	bool isEqualTo(HugeInteger);
	bool isNotEqualTo(HugeInteger);
	bool isGreaterThan(HugeInteger);
	bool isLessThan(HugeInteger);
	bool isZero();

private:
	std::string digits[40]{ "0" };

};