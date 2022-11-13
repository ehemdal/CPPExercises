/* Exercise 2.17: Printing (10th edition)
   Print 1 2 3 4 on one line, four different ways.
 */

#include <iostream>
using namespace std;

int main(void) {

	// One statement with one stream insertion operator
	cout << "1 2 3 4\n";

	// One statement with four stream insertion operators
	cout << "1 " << "2 " << "3 " << "4\n";

	// Four statements
	cout << "1 ";
	cout << "2 ";
	cout << "3 ";
	cout << "4" << endl;

	return(1);
}