// Fig. 11.15: BasePlusCommissionEmployee.cpp
// Class BasePlusCommissionEmployee member-function definitions.
#include <stdexcept>
#include <sstream>
#include "BasePlusCommissionEmployee.h"
using namespace std;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
   const string& first, const string& last, const string& ssn,
   double sales, double rate, double salary) { 

    thisEmployee.setFirstName(first); 
    thisEmployee.setLastName(last);
    thisEmployee.setSocialSecurityNumber(ssn);
    thisEmployee.setGrossSales(sales);
    thisEmployee.setCommissionRate(rate);
    setBaseSalary(salary); // validate and store base salary
}

string BasePlusCommissionEmployee::getFirstName()
{
    return thisEmployee.getFirstName();
}

string BasePlusCommissionEmployee::getLastName() {
    return thisEmployee.getLastName();
}

string BasePlusCommissionEmployee::getSocialSecurityNumber() {
    return thisEmployee.getSocialSecurityNumber();
}

double BasePlusCommissionEmployee::getGrossSales() {
    return thisEmployee.getGrossSales();
}
double BasePlusCommissionEmployee::getCommissionRate()
{
    return thisEmployee.getCommissionRate();
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
   if (salary < 0.0) {
      throw invalid_argument("Salary must be >= 0.0");
   }

   baseSalary = salary;
}

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const {
   return baseSalary;
}

// calculate earnings
double BasePlusCommissionEmployee::earnings() const {
   return getBaseSalary() + thisEmployee.earnings();
}

// return string representation of BasePlusCommissionEmployee object
string BasePlusCommissionEmployee::toString() const {
   ostringstream output;
   output << "base-salaried " << thisEmployee.toString()
      << "\nbase salary: " << getBaseSalary();
   return output.str();
}


/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
