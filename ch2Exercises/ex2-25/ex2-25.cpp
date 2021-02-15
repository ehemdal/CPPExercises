// ex2-25.cpp : Is X a multiple of Y?
//

#include <iostream>
using namespace std;

int main()
{
    int x, y;

    cout << "Enter two integers: ";
    cin >> x >> y;

    cout << x;
    if ((x % y) == 0) {
        cout << " is ";
    }
    else {
        cout << " is not ";
    }
    cout << "a multiple of " << y << endl;

    return (1);
}

