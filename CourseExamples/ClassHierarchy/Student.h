#pragma once
#include <string>
#include <iostream>
#include "CommunityMember.h"
using namespace std;

class Student : public CommunityMember
{
private:
    int classYear;
    string dormAddress;
public:
    Student(string name_in, string homeAddress, int year = 0, string address_in = "Default Dorm")
        :   classYear(year), dormAddress(address_in)
    {
        cout << "Student constructor called\n";
        this->setName(name_in);
        this->setAddress(homeAddress);
    }
    ~Student()
    {
        cout << "Student destructor called\n";
    }

    int getYear() const { return classYear; }
    string getDormAddress() const { return dormAddress; }

};