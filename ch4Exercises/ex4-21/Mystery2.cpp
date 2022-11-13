// ex4-21.cpp (10th edition): Mystery2 -- what does this program do?

#include <iostream>
using namespace std;

int main()
{
    unsigned int count{ 1 };

    while (count <= 10) {
        cout << (count % 2 == 1 ? "****" : "++++++++") << endl;
        ++count;
    }
}