// ClassHierarchy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
#include "Employee.h"
int main()
{
    Student NewStudent = Student("Joe Verdietz", "205 Elm St", 2025, "Henderson Hall");
    std::cout << NewStudent.getName() << endl;
    std::cout << NewStudent.getAddress() << endl;
    std::cout << NewStudent.getDormAddress() << endl;
    std::cout << NewStudent.getYear() << endl;

    Employee StaffMember = Employee("Tom Smith", "1 Main St.", "111-22-3333", 45000);
    std::cout << StaffMember.getName() << endl;
    std::cout << StaffMember.getAddress() << endl;
    std::cout << StaffMember.getTaxID() << endl;
    std::cout << StaffMember.getSalary() << endl;

}

