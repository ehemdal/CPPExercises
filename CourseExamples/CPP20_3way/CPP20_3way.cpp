// CPP203way.cpp : Test the new 3-way "spaceship" operator.  This program was corrected and adapted from 
// https://www.geeksforgeeks.org/features-of-c-20/ and see here
// https://en.cppreference.com/w/cpp/language/default_comparisons
// https://devblogs.microsoft.com/cppblog/simplify-your-code-with-rocket-science-c20s-spaceship-operator/#:~:text=The%20spaceship%20operator%20is%20a%20welcomed%20addition%20to,right%20now%20in%20Visual%20Studio%202019%20under%20%2Fstd%3Ac%2B%2Blatest%21
// 
//

#include <compare>
#include <iostream>
#include <vector>
#include <typeinfo>
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
