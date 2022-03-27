#pragma once
#include "Opcodes.h"
#include <iostream>
#include <iomanip>

constexpr auto MEMORY_SIZE = 1000;
constexpr auto SENTINEL = -99999;

// Main memory array, uses default initialization to clear all memory to zeroes.
// Registers
int memory[MEMORY_SIZE]{ nop };
int accumulator{ 0 };
int instructionCounter{ 0 };
int instructionRegister{ 0 };
int operationCode{ 0 };
int operand{ 0 };


void Welcome() {
	std::cout << "***           Welcome to Simpletron            ***\n";
	std::cout << "*** Please enter your program one instruction  ***\n"; 
	std::cout << "*** (or data word) at a time. I will type the  ***\n";
	std::cout << "*** location number and a question mark (?).   ***\n";
	std::cout << "*** You then type the word for that location.  ***\n";
	std::cout << "*** Type the sentinel " << SENTINEL << " to stop entering  ***\n";
	std::cout << "*** your program.                              ***\n";
}

//TODO: troubleshoot the stream manipulators described in page 381 of the text.
char sign(int arg) {
	// return the sign of an instruction or data word
	if (arg >= 0) {
		return '+';
	}
	else return('\0');
}

void dumpMemory(int* m) {
	
	std::cout << "REGISTERS" << std::endl;
	std::cout << "Accumulator: " << sign(accumulator) << accumulator << std::endl;
	std::cout << "Instruction counter: " << instructionCounter << std::endl;
	std::cout << "Instruction register: " << sign(instructionRegister) << instructionRegister << std::endl;
	std::cout << "Operation code: " << operationCode << std::endl;
	std::cout << "Operand: " << operand << std::endl;
	std::cout << "MEMORY" << std::endl;


	for (int i = 0; i < MEMORY_SIZE; ++i) {
		//std::cout << std::setfill('0') << std::internal;
		std::cout << sign(m[i]) << m[i] << " ";
		if (0 == ((i+1) % 10)) std::cout << std::endl;
	}
}

void loadProgram(int* m) {
	int word{ 0 };
	unsigned int address{ 0 };
	while( address < MEMORY_SIZE) {
		std::cout << address << " ? ";
		std::cin >> word;
		
		// Test for the sentinel
		if (SENTINEL == word) {
			std::cout << "*** Program loading complete ***" << std::endl;
			return;  //We're done'
		}
		// Test word for valid range -9999 to 9999, emit error and try again if not
		if ((-9999 <= word) || (9999 >= word)) {
			m[address] = word;
			address++;
		} else {
			std::cout << "bad range, try again" << std::endl;
			continue;
		}
	}
}
