// filestreams.cpp: Sample using file streams.
// Run the program and compare readFrom.txt and writeTo.txt
#include <iostream>
#include <fstream>
using namespace std;
/*
    Update lines 11 and 17 to match your filesystem's requirements
*/
int main()
{
    ifstream readFrom("readFrom.txt", ios::in);

    if (!readFrom.is_open()) {
        cout << "cannot open file for reading! Exiting!" << endl;
        return -1;
    }
    ofstream writeTo("writeTo.txt", ios::out);

    if (!writeTo.is_open()) {
        cout << "cannot open file for writing! Exiting!" << endl;
        return 1;
    }

    int number;
    while (readFrom >> number) {
        writeTo << ++number << endl;
    }

    readFrom.close();
    writeTo.close();
    cout << "Completed to write file" << endl;

    return 0;
}
