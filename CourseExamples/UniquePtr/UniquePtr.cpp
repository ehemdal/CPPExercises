// UniquePtr.cpp : Adapted from RSEG-0103 week 1 notes
//
// Step through this program to observe
//	How a smart pointer gets created
//  What happens to valuePtr after it gets moved to valuePtrNow (uncomment line 17, recompile, and try to run :-) )

#include <iostream>
#include <memory>
#include <utility>
#include <string>

int main()
{
	std::unique_ptr<int> valuePtr(new int(15));
	std::unique_ptr<int> valuePtrNow(std::move(valuePtr));
	std::cout << "valuePtrNow = " << *valuePtrNow << '\n';
	//std::cout << "valuePtr = " << *valuePtr << '\n';
	std::cout << "Has valuePtr an associated object? "
		<< std::boolalpha
		<< static_cast<bool>(valuePtr) << '\n';

	// RAII - initialize when you acquire. . .
	std::unique_ptr<std::string> string1Ptr(new std::string("ABCD"));
	std::cout << "String1Ptr is " << string1Ptr << std::endl;
	std::cout << "String1Ptr points to " << *string1Ptr << std::endl;

	// . . .or not
	std::unique_ptr<std::string> string2Ptr(new std::string);
	std::string myString{ "This is my string" };
	string2Ptr->assign(myString);
	std::cout << "String2Ptr at " << string2Ptr << " contains :" << std::endl;
	std::cout << *string2Ptr << std::endl;

}