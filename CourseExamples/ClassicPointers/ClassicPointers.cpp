// ClassicPointers.cpp : Fundamentals of pointers

#include <iostream>

int main(void)
{
    int x = 5;
    // nullptr here tells the compiler that you know the pointer is uninitialized, to 
    // avoid a compile warning.
    int * xp = nullptr;
    // Setting uninitialized pointers to zero is also common, but nullptr is clearer.
    int* p = 0;

    std::cout << "Pointer Examples" << std::endl;
    std::cout << "Uninitialized xp: " << xp << std::endl;
    std::cout << "p = " << p << std::endl;

    xp = &x;
    std::cout << "x = " << x << std::endl;
    std::cout << "&x = " << &x << std::endl;
    std::cout << "xp = " << xp << std::endl;
    std::cout << "*xp = " << *xp << std::endl;

    *xp = 10;
    std::cout << "Change the value of x through the pointer: x = " << x << std::endl;

    return (0);

}

