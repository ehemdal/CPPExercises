// ex5-12.cpp : Display the product of the first 15 odd integers
//

#include <iostream>
using namespace std;

/* Calculate the product of the odd integers from 1 to 15 */
int main()
{
    int product{ 1 };
    for (int i{ 1 }; i <= 15; i += 2) {
        product *= i;
    }
    cout << "The product of the odd integers from 1 to 15 is " << product << endl;
}
