#pragma once
#include "Faculty.h"
using namespace std;

class Teacher : virtual public Faculty
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
	Teacher(const string& className)
		: className(className)
	{
	}
	~Teacher()
	{
		cout << "Teacher destructor called" << endl;
	}

	string className;


};