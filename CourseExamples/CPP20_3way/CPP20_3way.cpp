// CPP203way.cpp : Test the new 3-way "spaceship" operator.  This program was corrected and adapted from 
// https://www.geeksforgeeks.org/features-of-c-20/ and see here
// https://en.cppreference.com/w/cpp/language/default_comparisons
//

#include <compare>
#include <iostream>
#include <vector>
using namespace std;

// Driver Code
int main()
{
	int a = 91, b = 110;
	auto ans1 = a <=> b;

	cout << "ans1 value: " << ans1._Value << endl;

	if (ans1 < 0) {
		cout << "a < b because ans1 < 0" << endl;
	}
	else if (ans1 == 0) {
		cout << "a == b because ans1 == 0" << endl;
	}
	else if (ans1 > 0) {
		cout << "a > b, ans1 > 0" << endl;
	}

	vector<int> v1{ 3, 6, 9 };
	vector<int> v2{ 3, 6, 9 };
	auto ans2 = v1 <=> v2;

	if (ans2 < 0) {
		cout << "v1 < v2\n";
	}
	else if (ans2 == 0) {

		cout << "v1 == v2\n";
	}
	else if (ans2 > 0) {

		cout << "v1 > v2\n";
	}

	cout << endl;
}
