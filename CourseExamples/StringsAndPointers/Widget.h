#pragma once
#include <string>
using namespace std;

constexpr auto DEVICE_SERIAL_LENGTH = 10;
class Widget
{

public:
		//constructor
		explicit Widget(int nbr);

		~Widget();
		
		void getID(char* s, const int len);
		
		std::string WhatIAm; 
		char* idPtr = new char[DEVICE_SERIAL_LENGTH];  //This needs to be initialized by the constructor
		int getSize();

private:
		int widgetSize;
		int widgetNumber;
};

