// ClassHierarchy.cpp : Partial implementation of the hierarchy in course notes

#include <iostream>
#include "Student.h"
#include "Employee.h"
#include "Faculty.h"
#include "Administrator.h"
#include "Teacher.h"
#include "AdministratorTeacher.h"

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

    Faculty Professor = Faculty();
    std::cout << Professor.getName() << endl;
    std::cout << Professor.office << endl;
    std::cout << Professor.hasTenure << endl;

    Administrator Admin = Administrator();
    cout << Admin.getName() << " has department " << Admin.departmentName << endl;

    Teacher Instructor = Teacher();
    cout << "Instructor " << Instructor.getName() << " runs " << Instructor.className << endl;

    AdministratorTeacher DeptChair = AdministratorTeacher();
    cout << "Department Chair " << DeptChair.CommunityMember::getName() << endl;
    cout << "has department " << DeptChair.departmentName << endl;
    cout << "has Tax ID " << DeptChair.getTaxID() << endl;
    cout << "has salary " << DeptChair.getSalary() << endl;
    cout << "and teaches " << DeptChair.className << endl;
}

