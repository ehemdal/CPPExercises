#pragma once
#include<array>
#include<iostream>

class Maze {
public:
    //Public members
    static const int rows{ 12 };
    static const int cols{ 12 };
    enum Direction { UP, DOWN, LEFT, RIGHT };

    // Constructor
    Maze(std::array<std::array<char, rows>, cols>& mazeArray) : MyMaze(mazeArray)
    {
        std::cout << "calling Maze constructor" << std::endl;
    }

    void mazeTraverse(int rowpos, int colpos) {

        //Mark the current position
        MyMaze[rowpos][colpos] = 'X';

        //display the maze
        printMaze();

        //Return if done
        if (colpos == (MyMaze[rowpos].size() - 1)) return;

        //where can we move?//
        if (MyMaze[rowpos][colpos + 1] == '.') { // go straight
            mazeTraverse(rowpos, (colpos + 1));
        }
        else if (MyMaze[rowpos + 1][colpos] == '.') {// can't go straight, so try turning right.
            mazeTraverse((rowpos + 1), colpos);
        }
        else if (MyMaze[rowpos - 1][colpos] == '.') { // can't go right, so try turning left
            mazeTraverse((rowpos - 1), colpos);
        }
        else { //dead end, so go back a step
            mazeTraverse(rowpos, (colpos - 1));
        }



    };

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
    std::array<std::array<char, 12>, 12> MyMaze; // 2D array
    //position variables
    int c{ 0 }; //column position
    int r{ 0 }; //row position
};