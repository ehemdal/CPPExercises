// ex2-18.cpp :Comparing integers (10th edition)
//

#include <iostream>
using namespace std;

int main()
{
    int x{ 0 };
    int y{ 0 };

    std::cout << "Enter two integers:" << endl;
    cin >> x >> y;
    if (x > y) {
        cout << x << " is larger." << endl;
    }
    else if (y > x) {
        cout << y << " is larger." << endl;
    }
    else {
        cout << "These numbers are equal." << endl;
    }
}
