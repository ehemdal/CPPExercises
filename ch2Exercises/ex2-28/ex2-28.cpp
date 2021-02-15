// ex2-28.cpp : Print the digits in a five-digit integer with three spaces between each one.
//

#include <iostream>
using namespace std;

int main()
{
    int theNumber{ 0 };
    int divisor{ 10000 };

    std::cout << "Enter a five-digit integer\n";
    cin >> theNumber;
/*
    //Parse out the number, first try.
    d10k = (int)theNumber / 10000;
    theNumber = theNumber % 10000;
    d1k = (int)theNumber / 1000;
    theNumber = theNumber % 1000;
    d100 = (int)theNumber / 100;
    theNumber = theNumber % 100;
    d10 = (int)theNumber / 10;
    theNumber = theNumber % 10;
    d = theNumber;
*/
    // shorter implementation with a loop.
    for (int i = 0; i < 5; i++) {
        cout << (int)theNumber / divisor << "   ";
        theNumber = theNumber % divisor;
        divisor = divisor / 10;
    }
    cout << endl;

    return (1);

}

