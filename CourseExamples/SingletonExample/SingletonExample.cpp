// SingletonExample.cpp : This shows a singleton class that contains a vector of unique_ptr to int's
// which is similar to what is needed for Assignment 3.  Notice that you can't just push_back a
// unique_ptr, it has to be moved from whatever created it to the vector if you're going to 
// store a number of pointers in a vector.  Failing to do this generates a "deleted function" error
// deep in generated code that may be mystifying at first.
//

#include <iostream>
#include "SingleClass.h"
using namespace std;

SingleClass* SingleClass::instance = nullptr;

int main()
{
    std::cout << "Singleton example, with a vector of unique_ptr to ints" << std::endl;
    std::cout << "Set a breakpoint at the return(), then examine the contents of s in your watch window." << std::endl;
    SingleClass* s = s->getInstance();
    int x = 5;
    std::unique_ptr<int> ptr2x(&x);
    s->integers.push_back(std::move(ptr2x));
    cout << "Starting getSampleData from the singleton: " << s->getSampleData() << endl;
    s->setSampleData(25);
    cout << "New getSampleData from the singleton: " << s->getSampleData() << endl;
    
    // Get the raw pointer for our unique_ptr; can't pass a unique_ptr by value
    int* myInt = s->integers.at(0).get();
    cout << "Our integer value: " << *myInt << endl;

    return 0;
}
