// ex5-10.cpp (10th edition): What does this print?
#include <iostream>
using namespace std;

int main() {
    for (int i{ 1 }; i <= 10; i++) {
        for (int j{ 1 }; j <= 5; j++) {
            cout << '@';
        }

        cout << endl;
    }
}