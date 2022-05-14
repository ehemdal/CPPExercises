// StringsAndPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Widget.h"
using namespace std;

int main()
{
    std::cout << "Widget Example\n";
    Widget Widget1(1);
    cout << "Widget1 is declared by name" << endl;
    cout << "Here's the name via a String object: " << Widget1.WhatIAm << endl;
    cout << "Here's the serial via pointer: " << Widget1.idPtr << endl;
    cout << "Widget1 has size " << Widget1.getSize() << endl;
    // Uncomment below to cause a compile-time error
    //cout << "Widget1 has size " << Widget1.widgetSize << endl;

    cout << "Widget2 is declared via new" << endl;
    Widget* Widget2;
    Widget2 = new Widget(2);
    cout << "Here's the name via a String object: " << Widget2->WhatIAm << endl;
    cout << "Here's the serial via pointer: " << Widget2->idPtr << endl;
    cout << "Widget2 has size " << Widget2->getSize() << endl;
    // Comment out the delete to cause a memory leak
    delete(Widget2);
    // Uncomment this to cause a BOOM!
    //cout << Widget2->WhatIAm << endl;
    Widget2 = nullptr;
    return(0);
}
