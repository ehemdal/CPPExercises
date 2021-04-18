#include "IntegerSet.h"
#include <iostream>
#include <string>

IntegerSet::IntegerSet() {
	for (int i = 0; i < SET_SIZE; i++) {
		MySet.push_back(false);
	}
}

IntegerSet::IntegerSet(int *a, size_t asize) {
	for (int i = 0; i < SET_SIZE; i++) {
		MySet.push_back(false);
	}
	for (size_t i=0; i < (asize); i++) {
		MySet.at(a[i]) = true;
	}
}

IntegerSet::~IntegerSet() {}

IntegerSet IntegerSet::unionOfSets(IntegerSet is)
{
	IntegerSet result;
	for (size_t i = 0; i < MySet.size(); i++ ) {
		result.MySet.at(i) = (MySet.at(i) || is.MySet.at(i));
		}
	
	return result;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet is)
{
	IntegerSet result;
	for (size_t i = 0; i < MySet.size(); i++) {
		result.MySet.at(i) = (MySet.at(i) && is.MySet.at(i));
	}

	return result;
}

void IntegerSet::insertElement(int i)
{
	MySet.at(i) = true;
}

void IntegerSet::deleteElement(int i)
{
	MySet.at(i) = false;
}

std::string IntegerSet::toString() 
{
	std::string result;

	for (size_t i = 0; i < MySet.size(); i++) {
		if (MySet.at(i)) result.append(std::to_string(i) + " ");
	}
	return result;
}

bool IntegerSet::isEqualTo(IntegerSet is)
{
	for (size_t i = 0; i < MySet.size(); i++) {
		if (MySet.at(i) != is.MySet.at(i)) return false;
	}
	return true;
}
