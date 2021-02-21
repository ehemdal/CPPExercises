// ex4-22.cpp : Mystery3 -- What does this program do?
//

#include <iostream>
using namespace std;

int main()
{
	unsigned int row{ 10 };

	while (row >= 1) {
		unsigned int column{ 1 };

		while (column <= 10) {
			cout << (row % 2 == 1 ? "<" : ">");
			++column;
		}

		--row;
		cout << endl;
	}
}
