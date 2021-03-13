// ex7-13.cpp : Read in 20 numbers between 10 and 100 inclusive. As each number is read, validate it
// and store it in the array only if it isn't a duplicate of a number already read. After reading, display only
// the unique values that were entered. Use the smallest possible array, but provide for the worst case
// when all 20 numbers are different.
//

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()

{
    std::array<float, 20> numberArray = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    float valueIn{ 0 };

    /*
        Add new values at element zero.  They will be sorted to the high end of the array because the initial
        values are all zero so this will push zeros to the start of the array.  Since duplicates are not accepted, this
        can result in fewer than 20 numbers being displayed.
    */
    std::cout << "Unique numbers: enter 20 numbers from 10 - 100 inclusive.\n";
    for (int i = 0; i < 20; i++) { 
        cout << "Enter value " << i << endl;
        cin >> valueIn;
        while (valueIn < 10 || valueIn > 100) { 
            cout << "Try value " << i << " again" << endl;
            cin >> valueIn; 
        } 
       std::sort(numberArray.begin(), numberArray.end()); // TODO: Find out why this sort is wiping out data
       if (false == (binary_search(numberArray.begin(), numberArray.end(), valueIn))) 
        {
            numberArray[0] = valueIn;
        }
    }

    //Display the values from 0 to idx in numberArray
    //Do one final sort to put them in order
    std::sort(numberArray.begin(), numberArray.end());
    cout << "Here is the final list:" << endl;
    for (int i = 0; i < numberArray.size(); i++) {
        //Only display non-duplicate numbers
        if (0 != numberArray[i]) {
            cout << numberArray[i] << endl;
        }
    }
}


