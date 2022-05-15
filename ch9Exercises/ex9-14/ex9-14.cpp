// ex9-14.cpp : Textbook example with extensions to do the same comparison functions using operator overloading
//

#include <iostream>
#include "HugeInteger.h"

int main()
{
    std::cout << "HugeInteger example\n";
    HugeInteger MyHugeInteger1;
    HugeInteger MyHugeInteger2;
    MyHugeInteger1.input("-1234567890123456789012345678901234567890");
    MyHugeInteger1.output();
    std::cout << "MyHugeInteger1 " << (MyHugeInteger1.isZero() == true ? "is" : "is not"); std::cout << " zero" << std::endl;
    std::cout << "MyHugeInteger2 " << (MyHugeInteger2.isZero() == true ? "is" : "is not"); std::cout << " zero" << std::endl;

    HugeInteger I3("-5");
    HugeInteger I4("5");
    if (I3.isEqualTo(I4)) {
        std::cout << "I3 and I4 are the same" << std::endl;
    }
    else std::cout << "I3 and I4 are not the same" << std::endl;

    if (I3 == I4) {
        std::cout << "I3 and I4 are the same" << std::endl;
    }
    if (I3 != I4) {
        std::cout << "I3 and I4 are not equal" << std::endl;
    }
    if (I3.isGreaterThan(I4)) std::cout << "I3 is greater than I4" << std::endl;
    if (I3 > I4) std::cout << "I3 is greater than I4" << std::endl;
    if (I3.isLessThan(I4)) std::cout << "I3 is less than I4" << std::endl;
    if (I3 < I4) std::cout << "I3 is less than I4" << std::endl;
    if (I4.isGreaterThan(I3)) std::cout << "I4 is greater than I3" << std::endl;
    if (I4 > I3) std::cout << "I4 is greater than I3" << std::endl;
}
