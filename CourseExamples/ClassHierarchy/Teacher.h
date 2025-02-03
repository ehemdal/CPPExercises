#pragma once
#include "Faculty.h"
using namespace std;

class Teacher : public Faculty
{
public:
	Teacher() : className("Intro Class")
	{
		cout << "Default Teacher constructor called" << endl;
	}
	Teacher(string course) : className(course)
	{
		cout << "Teacher constructor called" << endl;
	}

	~Teacher()
	{
		cout << "Teacher destructor called" << endl;
	}

	string className;
};