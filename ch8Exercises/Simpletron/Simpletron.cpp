// Simpletron.cpp : Simple CPU simulator
//

#include <iostream>
#include "Machine.h"

int main()
{
    Welcome();
    loadProgram(memory);
    std::cout << "*** Program execution begins ***" << std::endl;

    while (halt != operationCode && instructionCounter < MEMORY_SIZE) {

        //Fetch the next instruction
        instructionRegister = memory[instructionCounter];
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;
        instructionCounter++;

        // Decode the instruction
        switch (operationCode) 
        {
        case read:
            std::cin >> memory[operand];
            break;

        case write:
            std::cout << memory[operand];
            break;

        case load:
            accumulator = memory[operand];
            break;

        case store:
            memory[operand] = accumulator;
            break;
        
        case add:
            accumulator += memory[operand];
            break;
        
        case subtract:
            accumulator -= memory[operand];
            break;
        
        case divide:
            accumulator /= memory[operand];
            break;
        
        case multiply:
            accumulator *= memory[operand];
            break;
        
        case branch:
            instructionCounter = operand;
            break;
        
        case branchneg:
            if (0 == accumulator) instructionCounter = operand;
            break;
        
        case branchzero:
            if (accumulator < 0) instructionCounter = operand;
            break;
        
        case halt:
            std::cout << "*** Simpletron execution terminated ***" << std::endl;
        
        default:
            dumpMemory(memory);
        }
    }
}