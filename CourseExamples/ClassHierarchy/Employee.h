#pragma once
#include <string.h>
#include "CommunityMember.h"
using namespace std;

class Employee : public CommunityMember
{
public:
		Employee()
		{
			cout << "Default Employee constructor called" << endl;
			this->taxID = "None";
			this->salary = 0;
		}
		Employee(string name, string homeAddress, string tax_id, float pay_amt) 
			: taxID(tax_id), salary(pay_amt)
		{
			cout << "Employee constructor called" << endl;
			this->setName(name);
			this->setAddress(homeAddress);
		};

		~Employee() 
		{
			cout << "Employee destructor called" << endl;
		};

		void setTaxID(string id) { taxID = id; }
		void setSalary(float pay) { salary = pay; }
		string getTaxID() const { return taxID; }
		float getSalary() const { return salary; }
private:
	string taxID;
	float salary;
};
