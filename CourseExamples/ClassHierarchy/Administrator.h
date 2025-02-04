#pragma once
#include "Faculty.h"
using namespace std;

class Administrator : virtual public Faculty
{
public:
	Administrator() : departmentName("Default Department")
	{
		cout << "Default Administrator constructor called" << endl;
	}

	Administrator(string dept) : departmentName(dept)
	{
		cout << "Administrator constructor called" << endl;
	}

	~Administrator()
	{
		cout << "Administrator destructor called" << endl;
	}

	string departmentName;
};