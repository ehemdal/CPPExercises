// ex5-13.cpp : Factorials example
// What's wrong with using data type long as the textbook suggests?  Define TEXT_VERSION to find out
// Hint:  see https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-160

//#define TEXT_VERSION

#include <iostream>
using namespace std;

#ifdef TEXT_VERSION
long fact{ 1 };
#else
long long fact{ 1 };  // compare with type long
#endif

/* Calculate and display 1! through 20! */
int main()
{
    for (int i = 1; i <= 20; i++) {
        // calculate i! 
        fact *= i;
        // display with a little trick of spacing
        cout << i << (i < 10 ? "    " :"   ") << fact << endl;
    }
}