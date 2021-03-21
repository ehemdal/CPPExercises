#pragma once
#include<array>
#include<iostream>

class Maze {
public:
    //Public members
    static const int rows{ 6 };
    static const int cols{ 6 };
    enum Direction { UP, DOWN, LEFT, RIGHT };

    // Constructor
    Maze(std::array<std::array<char, rows>, cols>& mazeArray) : MyMaze(mazeArray)
    {
        std::cout << "calling Maze constructor" << std::endl;
    }



    void printMaze() {
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                std::cout << MyMaze[i][j];
            }
            std::cout << std::endl;
        }
    };

private:
    std::array<std::array<char, 6>, 6> MyMaze; // 2D array
    //position variables
    int c{ 0 }; //column position
    int r{ 0 }; //row position
};