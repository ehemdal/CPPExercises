// ListExample.cpp 

#include <iostream>
#include <list>


int main()
{
    std::cout << "List Example"  << std::endl;
    std::list<char> letters{};
    std::list<char> more_letters{ 'J','K','n','m','Q','3' };
    letters.push_front('C');
    letters.push_back('B');
    letters.push_front('Z');
    letters.push_back('A');

    std::ostream_iterator<char> output(std::cout, " ");
    std::ranges::copy(letters, output);
    std::cout << std::endl;
    letters.sort();
    more_letters.sort();
    std::ranges::copy(letters, output);
    std::cout << std::endl;
    std::ranges::copy(more_letters, output); //We know it's not empty
    letters.merge(more_letters);
    std::cout << "\nNow letters contains: ";
    std::ranges::copy(letters, output);
    std::cout << "\nAnd more_letters contains: ";
    std::ranges::copy(more_letters, output);
}
