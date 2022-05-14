#include "Widget.h"
#include <iostream>

Widget::Widget(int nbr) {
	cout << "\nCalling the Widget constructor" << endl;
	this->WhatIAm = "I am a Widget";
	this->getID(idPtr, DEVICE_SERIAL_LENGTH);
	this->widgetSize = 6;
	this->widgetNumber = nbr;
}

//destructor
Widget::~Widget() {
	cout << "Calling the Widget destructor on Widget " <<this->widgetNumber << endl;
}


//From   https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
void Widget::getID(char* s, const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	char hiddenString[] = "You can't see me";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = NULL;
}

int Widget::getSize() {
	return this->widgetSize;
}