// ex5-13.cpp : Factorials example
// What's wrong with using data type long as the textbook suggests?
// Hint:  see https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-160

#include <iostream>
using namespace std;
long long fact{ 1 };  // compare with type long

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