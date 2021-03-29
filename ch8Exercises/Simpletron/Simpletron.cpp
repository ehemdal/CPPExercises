// Simpletron.cpp : Simple CPU simulator
//

#include <iostream>
#include "Machine.h"

int main()
{
    Welcome();
    loadProgram(memory);
    dumpMemory(memory);
}