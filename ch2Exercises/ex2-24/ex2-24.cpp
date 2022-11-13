// ex2-24.cpp : Accept an integer from the keyboard and print whether it is odd or even.
// (10th edition)

#include <iostream>
using namespace std;

int main(void)
{
    int value;

    std::cout << "Enter an integer: ";
    cin >> value;
    cout << value;
    if ((value % 2) == 0) {
        cout << " is even.";
    }
    else {
        cout << " is odd";
    }
    cout << endl;

    return (1);
}
