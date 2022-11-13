// ex2-19.cpp : Program takes three integers and prints sum, average, product, smallest, and largest of these numbers.
// (10th edition)

#include <iostream>
using namespace std;

int main()
{
    int first{ 0 };
    int second{ 0 };
    int third{ 0 };
    int largest;
    int smallest;
    int sum;

    std::cout << "Input three different integers: ";
    std::cin >> first >> second >> third;

    // Find the largest
    (second > first) ? largest = second : largest = first;
    (third > largest) ? largest = third : largest = largest;

    // Find the smallest
    (second < first) ? smallest = second : smallest = first;
    (third < smallest) ? smallest = third : smallest = smallest;

    // Print the results
    sum = first + second + third;
    cout << "Sum is " << sum << endl;
    cout << "Average is " << (sum / 3) << endl;
    cout << "Product is " << (first * second * third) << endl;
    cout << "Smallest is " << smallest << endl;
    cout << "Largest is " << largest << endl;
    return (1);

}
