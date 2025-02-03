#ifndef CMEMBER_H
#define CMEMBER_H

#include <string>
#include <iostream>
using namespace std;

class CommunityMember
{
private:
    string m_name;
    string m_address;
public:
    CommunityMember(string name_in = "Default Name", string address_in = "Default Address")
        : m_name(name_in), m_address(address_in)
    {
        cout << m_name + " CommunityMember constructor called\n";
    }
    ~CommunityMember()
    {
        cout << m_name + " CommunityMember destructor called\n";
    }

    string getName() const { return m_name; }
    string getAddress() const { return m_address; }
    void setName(string name_in) { m_name = name_in; }
    void setAddress(string address_in) { m_address = address_in; }

};

#endif // CMEMBER_H