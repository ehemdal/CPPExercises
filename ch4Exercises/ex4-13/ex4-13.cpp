// ex4-13.cpp (10th edition): MPG calculator
/*
    Develop a program that uses a while loop to iput the miles driver and gallons used for each trip.
    Program should calculate and display the MG obtained for each trip and the combined MPG  for all tankfuls up to this point.
    Enter -1 to quit.
*/
#include <iostream>
using namespace std;

void main()
{
    float currentMiles{ 0 };
    float currentGallons{ 0 };
    float totalMiles{ 0 };
    float totalGallons{ 0 };

    // prompt for miles driven
    cout << "Enter miles driven (-1 to quit): ";
    cin >> currentMiles;
    if (currentMiles < 0) return;

    // prompt for gallons used
    while (currentGallons <= 0) {
        cout << "Enter gallons used: ";
        cin >> currentGallons; 
    }

    // while miles driven is a positive value, continue.  Take any negative value as the sentinel.
    while (currentMiles > 0) {

        //Calculate and display MPG for this trip
        cout << "MPG this trip: " << (currentMiles / currentGallons) << endl;

        //Add miles and gallons to totals
        totalMiles += currentMiles;
        totalGallons += currentGallons;

        //Calculate and display total MPG
        cout << "Total MPG: " << (totalMiles / totalGallons) << endl << endl;

        //Prompt for the next miles driven
        cout << "Enter miles driven (-1 to quit): ";
        cin >> currentMiles;

        //Exit if miles driven is -1, 
        if (currentMiles < 0) return;
        //else prompt for gallons used.  Clear currentGallons so the new input can be checked.
        currentGallons = 0;
        while (currentGallons <= 0) {
            cout << "Enter gallons used: ";
            cin >> currentGallons;
        }
    }
    return;
}

