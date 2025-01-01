// BadPointer.cpp : Using a cast to do bad things with pointers.

#include <iostream>

int main()
{
    int p = 5;
    int* pp = &p;
    double pi = 3.14156;
    double* dp = &pi;

    /*
        You can't assign dp to pp because they point to different data types.
        So an assignment like

        dp = p;

        won't work, even though both are addresses.

        You can coerce dp by casting pp to point to type double, which will compile 
        but will not give useful results.
    */
    dp = (double *) pp;
    std::cout << "dp = " << dp << " pp = " << pp << std::endl;
    std::cout << "*dp = " << *dp << std::endl;
    std::cout << "but *pp = " << *pp << std::endl;
    
}
