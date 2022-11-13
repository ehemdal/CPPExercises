// ex9-3.cpp (10th edition): Complex class example showing separation of interface and implementation.
// Why is the destructor called 10 times if the constructor is called six times?
//

#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    Complex A(5, 6);
    Complex B(5, -23.6);
    Complex Result1;

    Complex C(12);
    Complex D(0, 15);
    Complex Result2;

    Result1.add(A, B);
    cout << Result1.toString() << endl;

    Result2.subtract(C, D);
    cout << Result2.toString() << endl;
}
