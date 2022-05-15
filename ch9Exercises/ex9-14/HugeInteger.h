#pragma once
#include<string>
#include <iostream>
#include <array>
#include <string>
constexpr auto INTEGERSIZE = 40;
class HugeInteger {

public:
	HugeInteger();
	HugeInteger(std::string);
	~HugeInteger();

	bool operator>(const HugeInteger& H);

	bool isEqualTo(HugeInteger);
	bool operator==(HugeInteger& HI);
	bool isNotEqualTo(HugeInteger);
	bool operator!=(HugeInteger& IH);
	bool isGreaterThan(HugeInteger);
	bool isLessThan(HugeInteger);
	bool isZero();
	void input(std::string);
	void output();

private:
	std::array <std::string, INTEGERSIZE> digits;
	int size{ 0 };
	bool negative{ false };

};