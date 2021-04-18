#pragma once
#include<string>
#include <iostream>
#include <array>
#include <string>

class HugeInteger {

public:
	HugeInteger();
	HugeInteger(std::string);
	~HugeInteger();

	bool isEqualTo(HugeInteger);
	bool isNotEqualTo(HugeInteger);
	bool isGreaterThan(HugeInteger);
	bool isLessThan(HugeInteger);
	bool isZero();
	void input(std::string);
	void output();

private:
	std::array <std::string, 40> digits;
	int size{ 0 };
	bool negative{ false };

};