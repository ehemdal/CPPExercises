#pragma once
#include "Administrator.h"
#include "Teacher.h"
using namespace std;

class AdministratorTeacher : public Administrator, public Teacher
{
public:
	AdministratorTeacher()
	{
		cout << "Default AdministratorTeacher constructor called" << endl;
	}

	~AdministratorTeacher()
	{
		cout << "AdministratorTeacher destructor called" << endl;
	}
};