// ex6-28.cpp (10th edition): isPerfect exercise
// Find the perfect numbers less than 100,000.
// For an answer to check, visit https://en.wikipedia.org/wiki/List_of_perfect_numbers

#include <iostream>
using namespace std;

bool isPerfect(int);

int main()

{   // Quick sanity check
    if (isPerfect(6)) cout << "6 is perfect" << endl;

    //Terrible, horrible loop to find perfect numbers and then find their divisors
    for (int i = 2; i < 100'000; i++) {
        if (isPerfect(i)) {
            cout << i << " has divisors ";
            for (int index = 2; index < i; index++) {
                if (0 == (i % index)) cout << index << "  ";
            }
            cout << endl;
        }
    }
}

/*
    A number is perfect if the sum of its divisors, including 1 but not the number itself, add up to the number itself
    Example: 6 is perfect because 1 + 2 + 3 = 6.
*/
bool isPerfect(int number) {

    int sum{ 1 };
    int limit{ number / 2 };

    for (int index = 2; index <= limit; index++) {
        if (0 == (number % index)) sum += index;
    }
    return ((sum == number) ? true : false);
}