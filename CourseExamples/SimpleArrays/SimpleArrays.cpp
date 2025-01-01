// SimpleArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main() {

    cout << "Simple Arrays.cpp\n";
    // Initialize with a list
    long odds[] = { 1, 3, 5, 7, 9 };
    for (int i = 0; i < 5; i++) {
        cout << i << " odds[" << i << "]= " << odds[i] << " Address= " << &odds[i] << endl;
    }
    cout << "Long variables are " << sizeof(long) << " bytes long.";
    return (0);
}

