// ex4-12.cpp (10th edition): Mystery -- what does this program do?
// Try to work it out before you run the program.

#include <iostream>
using namespace std;

int main()
{
    unsigned int x{ 1 };
    unsigned int total{ 0 };
    while (x <= 10) {
        int y = x * x;
        cout << y << endl;
        total += y;
        ++x;
    }
    cout << "Total is: " << total << endl;
}

