// ex7-33.cpp : Traverse a maze
//

#include <iostream>
#include <array>
#include <string>

using namespace std;

const size_t columns{ 6 };
const size_t rows{ 6 };
void printArray(const array<array<char, columns>, rows>&);

int main()
{

 
array<array<char, columns>, rows> maze = {  '#', '#', '#', '#', '#', '#',
                                              '#', '.', '.', '.', '#', '#',
                                              '.', '.', '#', '.', '#', '#', 
                                              '#', '#', '#', '.', '#', '#',
                                              '#', '#', '#', '.', '.', '.',
                                              '#', '#', '#', '#', '#', '#' };
printArray(maze);

}
void printArray(const array<std::array<char, columns>, rows>& a) {
    // rows and columns start at the upper left
    // RC0 C1 C2 ...
    // R1
    // R2
    // ...
    for (auto const& row : a) {
        for (auto const& element : row) {
            std::cout << element << ' ';
        }
        std::cout << endl;
    }
}