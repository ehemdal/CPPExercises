// ReferenceExample.cpp 
#include <iostream>
using namespace std;
int main()
{
    cout << "Reference Example" << endl;
    int var = 5;
    int& ref = var;
    cout << "Value of var: " << var << endl;
    cout << "Address of var: " << &var << endl;
    cout << "Value of ref: " << ref << endl;
    cout << "Address of ref: " << &ref << endl;
}
