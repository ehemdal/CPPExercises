// ex5-19.cpp (10th edition): Calculating PI
//
//#define BIG_RUN 
#include <iostream>
#include <iomanip>
using namespace std;

long double mypi{ 4.0 };
long double thisTerm{ 0 };
long double denominator{ 3 };
const long double numerator{ 4 }; 
#ifndef BIG_RUN
unsigned int limit{ 200000 };
#else
unsigned int limit{ 100000000 };
#endif

int main()
{
    // first term is four
    cout.precision(17);
    for (int index = 2; index <= limit; index++) {
        // calculate the next term in the series
        thisTerm = numerator / denominator;

        // subtract it if this is an even-numbered term (2, 4, 6, ...)
        // add it if this is an odd-numbered term (3, 5, 7, ...)
        (0 == (index % 2)) ? mypi -= thisTerm : mypi += thisTerm;

        // print this entry in the table
#ifdef BIG_RUN
        if (index % 10000 == 0)
#endif
            cout << "Term # " << index << "   " << "Estimate: " << mypi << endl;

        // Set up for the next iteration
        denominator += 2;
    }

}
