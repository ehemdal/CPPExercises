// VectorExample.cpp 

#include <iostream>
#include <vector>
#include <format>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    cout << "Vector Example" << endl;

    vector<int> data{ 1, 2, 3, 4, 5, 6 };
    vector<int> result{ data.cbegin(), data.cend() };
    ostream_iterator <int> output{ cout, " -- " };

    cout << format("Front: {} Back: {}\n", result.front(), result.back());

    cout << "The result contains: ";
    copy(result.begin(), result.end(), output);

    cout << "\nElement 1: " << result.at(1) << endl;
    result[2] = 267;

    result.insert(result.begin() + 4, 15);

    cout << "The result now contains: ";
    copy(result.begin(), result.end(), output);

}

