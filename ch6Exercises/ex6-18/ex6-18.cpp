// ex6-18.cpp (10th edition): Exponentiation
//

#include <iostream>

int integerPower(int, int);

int main()
{
    std::cout << integerPower(3, 4);
}
/*
    exponent is a positive non-zero integer
    base is an integer
    return base raised to the power of exponent without using math library functions.
    Recursion seems the simplest way to write this.
*/
int integerPower(int base, int exponent) {
    
    if (1 == exponent) {
        return base;
    }
    else {
        return base * integerPower(base, (exponent - 1));
    }

}
