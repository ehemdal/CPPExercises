// Fig. 11.9: fig11_09.cpp now turned into Ex 11.3 by JEH
// BasePlusCommissionEmployee class test program.
#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h" 
using namespace std;

int main() {
   // instantiate BasePlusCommissionEmployee object             
   BasePlusCommissionEmployee employee{"Bob", "Lewis", "333-33-3333",
      5000, .04, 300};

   // get commission employee data
   cout << fixed << setprecision(2); // set floating-point formatting

   // Because of composition, I need to call member functions of the CommissionEmployee object "thisEmployee" which is 
   // a member of the BasePlusCommissionEmployee object "employee"  that I just created.
   // I want public methods of class BasePlusCommissionEmployee that give me
   // the ability to access the private member "thisEmployee" and call on its methods.  
   // 
   // I could make thisEmployee a public member of class BasePlusCommissionEmployee, because the members of CommissionEmployee are
   // private (so class CommissionEmployee would control their access).  But I might want to control how others will use
   // these members when they use BasePlusCommissionEmployee, so I want thisEmployee to be private.
   // 
   // In that case, I need to create public methods in BasePlusCommissionEmployee that give me access to the private member
   // "thisEmployee".  I'm reusing the names of the methods from class CommissionEmployee -- but these are different.
   // 
   // Instead of inheriting these methods from the base class in the subclass, we are including objects of the base class type
   // inside objects of the subclass and we are adding methods of the subclass type that let us control access to
   // the methods of the base class which have the same names but are different methods. 
   // 
   // Reusing CommissionEmployee via inheritance looks kind of like magic -- the methods are available without having to do 
   // much of anything.  Doing this via composition is more explicit, and more visible.
   
   cout << "Employee information obtained by get functions: \n"
      << "\nFirst name is " << employee.getFirstName()
      << "\nLast name is " << employee.getLastName()
      << "\nSocial security number is "
      << employee.getSocialSecurityNumber()
      << "\nGross sales is " << employee.getGrossSales()
      << "\nCommission rate is " << employee.getCommissionRate()
      << "\nBase salary is " << employee.getBaseSalary() << endl;
   employee.setBaseSalary(1000); // set base salary 
   cout << "\nUpdated employee information from function toString: \n\n"
      << employee.toString();

   // display the employee's earnings
   cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;
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
