#pragma once
//Opcodes for Simpletron

// No-operation
const int nop{ 0 };

// I/O operations
const int read{ 10 }; // read from keyboard to memory location
const int write{ 11 }; //write a word from a memory location to the screen
const int writenl{ 12 }; //write a word from a memory location to the screen including a newline

// Load and store operations
const int load{ 20 }; // load the contents of a memory location to the accumulator
const int store{ 21 }; // store the contents of the accumulator to a memory location

//Arithmetic
const int add{ 30 }; // accumulator = accumulator + contents of memory location.
const int subtract{ 31 }; //accumulator = accumulator - contents of memory location
const int divide{ 32 }; // accumulator = accumulator / contents of memory location
const int multiply{ 33 }; // accumulator = accumulator * contents of memory location
const int modulo{ 34 }; // accumulator = accumulator % contents of memory location

//Transfer-of-control
const int branch{ 40 }; // Branch to memory location
const int branchneg{ 41 }; // Branch to memory location if accumulator is negative
const int branchzero{ 42 }; // Branch to memory location if accumulator is zero
const int halt{ 43 }; // Halt

