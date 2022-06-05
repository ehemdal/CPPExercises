// C++ program to demonstrate iterators
// Adapted from https://www.geeksforgeeks.org/difference-between-iterators-and-pointers-in-c-c-with-examples/
// for RSEG-0103 discussion

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// Declaring a vector
	vector<int> v = { 1, 2, 3 };

	// Declaring an iterator
	vector<int>::iterator i;

	int j;

	cout << "Without iterators = ";

	// Accessing the elements without using iterators
	// Notice the loop bound of 3
	for (j = 0; j < 3; ++j) {
		cout << v[j] << " ";
	}

	cout << "\nWith iterators = ";

	// Accessing the elements using iterators
	for (i = v.begin(); i != v.end(); ++i) {
		cout << *i << " ";
	}

	// Accessing the elements without using iterators -- 
	// You need to know the length of the vector for this to work.
	// Uncommenting this code will cause an error.
	/*
	for (j = 0; j < 4; ++j) {
		cout << v[j] << " ";
	}
	*/

	// Adding one more element to vector
	v.push_back(4);

	cout << "\nWithout iterators = ";

	// Accessing the elements without using iterators
	// Notice that the loop bound has been changed from what is in line 23
	for (j = 0; j < 4; ++j) {
		cout << v[j] << " ";
	}

	cout << "\nWith iterators = ";

	// Accessing the elements using iterators
	for (i = v.begin(); i != v.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	// Using some member functions
	// Erase all even numbers, show an inline declaration too
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ) {
		if (*it % 2 == 0) {
			it = v.erase(it);
		}
		else {
			++it;
		}
	}

	// Accessing the elements using iterators
	for (i = v.begin(); i != v.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "Vector v has size " << v.size() << endl;
	cout << "and maximum size " << v.max_size() << endl;
	cout << "Capacity: " << v.capacity() << endl;

	return 0;
}
