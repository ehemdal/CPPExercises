// ex9-21.cpp : IntegerSet exercise

#include <iostream>
#include "IntegerSet.h"
using namespace std;

int main()
{
    cout << "IntegerSet\n";
    IntegerSet IS1;
    int odds[] ={ 10, 1, 3, 5, 7, 9 };
    int evens[] = { 2, 4, 6, 8, 10, 12 };

    IntegerSet Odds(odds, sizeof(odds)/sizeof(int));
    IntegerSet Evens(evens, 6);
    IntegerSet ResultSet = Evens.unionOfSets(Odds);

}

