// ex9-21.cpp (10th edition): IntegerSet exercise

#include <iostream>
#include "IntegerSet.h"
using namespace std;

int main()
{
    cout << "IntegerSet\n";
    IntegerSet IS1;
    int odds[] = { 10, 1, 3, 5, 7, 9 };
    int evens[] = { 2, 4, 6, 8, 10, 12 };

    IntegerSet Odds(odds, sizeof(odds) / sizeof(int));
    IntegerSet Evens(evens, 6);
    IntegerSet UnionSet = Evens.unionOfSets(Odds);
    IntegerSet IntersectionSet = Odds.intersectionOfSets(Evens);
    string TestString = UnionSet.toString();
    cout << TestString << endl;
    Odds.insertElement(11);
    Odds.deleteElement(10);
    cout << "Odds after insert/delete: " << Odds.toString() << endl;
    cout << "New union after adds and deletes: " << endl;
    cout << Odds.unionOfSets(Evens).toString() << endl;
    cout << "Test equality of Odds and Evens:";
    cout << (Odds.isEqualTo(Evens) ? "Yes" : "No") << endl;
}

