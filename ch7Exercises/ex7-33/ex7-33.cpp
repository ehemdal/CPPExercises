// ex7-33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Maze.h"
#include<array>

void mazeTraverse(Maze, int, int);
void printMaze();
int main()
{
    std::array<std::array<char, 12>, 12> mazeArray
    {  '#', '#','#','#', '#', '#', '#', '#','#','#', '#', '#',
       '#', '.', '.', '.','#','.', '.', '.', '.', '.','.','#',
       '.','.', '#', '.','#','.', '#','#', '#', '#','.','#',
       '#', '#', '#', '.', '#', '.', '.','.','.','#','.','#',
        '#', '.','.','.', '.', '#', '#', '#','.','#','.','.',
       '#', '#','#','#', '.', '#', '.', '#','.','#', '.', '#',
       '#', '.','.','#', '.', '#', '.', '#','.','#', '.', '#',
       '#', '#','.','#', '.', '#', '.', '#','.','#', '.', '#',
       '#', '.','.','.', '.', '.', '.', '.','.','#', '.', '#',
       '#', '#','#','#', '#', '#', '.', '#','#','#', '.', '#',
       '#', '.','.','.', '.', '.', '.', '#','.','.', '.', '#',
       '#', '#','#','#', '#', '#', '#', '#','#','#', '#', '#' };
      
    int startcol{ 0 };
    int startrow{ 1 };

 
    std::cout << "Hello World!\n";
    Maze MySampleMaze(mazeArray);
   MySampleMaze.mazeTraverse(startrow, startcol);
}



