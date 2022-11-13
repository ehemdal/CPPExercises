// ex6-19.cpp (10th edition): Find the hypotenuse of a right triangle given the opposite two sides.
//

#include <iostream>
#include <math.h>

double hypotenuse(double, double);

int main()
{
    std::cout << "Triangle 1: " << hypotenuse(3.0, 4.0) << std::endl;
    std::cout << "Triangle 2: " << hypotenuse(5.0, 12.0) << std::endl;
    std::cout << "Triangle 3: " << hypotenuse(8.0, 15.0) << std::endl;
}

double hypotenuse(double a, double b) {
    // Use the Pythagorean theorem to find the hypotenuse

    return (sqrt((a * a) + (b * b)));
}