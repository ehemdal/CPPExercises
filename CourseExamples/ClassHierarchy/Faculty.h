#pragma once
#include "Employee.h"
using namespace std;

class Faculty : public Employee
{
public:
	Faculty() : office("Default Office"), hasTenure(true)
	{
		cout << "Default Faculty constructor called" << endl;
	}
	Faculty(string name, string officeAddress, bool tenured) 
		: office(officeAddress), hasTenure(tenured)
	{
		cout << "Faculty constructor called" << endl;
		this->setName(name);

	}

	~Faculty()
	{
		cout << "Faculty destructor called" << endl;
	}

	string office;
	bool hasTenure;
};