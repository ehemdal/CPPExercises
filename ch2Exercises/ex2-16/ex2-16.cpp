/* Exercise 2.16 (10th edition)
Prompt the user for two numbers, obtain the numbers from the user, and print the sum, product, difference, and quotient.
*/

#include <iostream>
using namespace std;

int main(void) {

	float x{ 0 }; // first value
	float y{ 0 }; // second value

	cout << "Exercise 2.16: Arithmetic.  Enter two numbers" << endl;
	cin >> x >> y;

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "sum = " << x + y << endl;
	cout << "product = " << x * y << endl;
	cout << "difference = " << x - y << endl;
	cout << "quotient = " << x / y << endl;

	return (1);
}