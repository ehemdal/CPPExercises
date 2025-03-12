// BadIterator.cpp : What can go wrong with raw iterators

#include <iostream>
#include <vector>

int main()
{
    std::cout << "Bad Iterator Example\n";
    std::vector<int> v1{ 0, 2, 4, 6, 8 };
    std::vector<int> v2{ 1, 3, 5, 7, 9 };
    std::vector<int> v3(5);

    std::ostream_iterator<int> output(std::cout, " ");
    std::cout << "Correct copy of v1 to v3:\n";
    std::copy(v1.begin(), v1.end(), v3.begin());
    std::copy(v3.begin(), v3.end(), output);
    std::cout << "\nBad iterator passed to copy:\n";
    std::copy(v1.begin(), v2.end(), v3.begin());
    
}
