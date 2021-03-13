// ex7.14.cpp : Exercise 7.13 reimplemented with a vector#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()

{
    std::vector<float> numberVector;
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
        
        if (false == (binary_search(numberVector.begin(), numberVector.end(), valueIn)))
        {
            numberVector.push_back(valueIn);
        }
    }

    //Display the values from 0 to idx in numberArray
    //Do one sort to put them in order
    std::sort(numberVector.begin(), numberVector.end());
    cout << "Here is the final list:" << endl;
    for (float item : numberVector) {
        cout << item << endl;
        }
    
}