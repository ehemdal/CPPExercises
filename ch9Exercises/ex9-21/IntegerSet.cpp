#include "IntegerSet.h"
#include <iostream>

IntegerSet::IntegerSet() {
	for (int i = 0; i < SET_SIZE; i++) {
		MySet.push_back(false);
	}
}

IntegerSet::IntegerSet(int *a, size_t asize) {
	for (int i = 0; i < SET_SIZE; i++) {
		MySet.push_back(false);
	}
	for (int i=0; i < (asize); i++) {
		MySet.at(a[i]) = true;
	}
}

IntegerSet IntegerSet::unionOfSets(IntegerSet is)
{
	IntegerSet result;
	for (size_t i = 0; i < MySet.size(); i++ ) {
		result.MySet.at(i) = (MySet.at(i) || is.MySet.at(i));
		}
	
	return result;
}
