// ex7-33.cpp : Traverse a maze
//

#include <iostream>
#include <array>
#include <string>

using namespace std;

const size_t columns{ 6 };
const size_t rows{ 6 };
void printArray(const array<array<string, columns>, rows>&);

int main()
{

 
array<array<string, columns>, rows> maze = {  "X", "X", "X", "X", "X", "X",
                                            "X", "X", "X", "X", "X", "X",
                                            "X", "X", "X", "X", "X", "X", 
                                            "X", "X", "X", "X", "X", "X",
                                            "X", "X", "X", "X", "X", "X",
                                            "X", "X", "X", "X", "X", "X", };
printArray(maze);

}
void printArray(const array<std::array<string, columns>, rows>& a) {

    for (auto const& row : a) {
        for (auto const& element : row) {
            std::cout << element;
        }
        std::cout << endl;
    }
}