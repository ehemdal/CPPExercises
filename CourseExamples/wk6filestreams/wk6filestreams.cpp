#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream readFrom("Q:\\readFrom.txt", ios::in);

    if (!readFrom.is_open()) {
        cout << "cannot open file for reading! Exiting!" << endl;
        return -1;
    }
    ofstream writeTo("Q:\\writeTo.txt", ios::out);

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
