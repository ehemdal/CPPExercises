#ifndef INTEGERSET_H
#define INTEGERSET_H
#include <vector>
#include <array>
#include <string>

constexpr auto HIGHEST_INT = 100;
constexpr auto SET_SIZE = 101;

class IntegerSet {

public:
	//construct an empty set
	explicit IntegerSet();

	// Construct a set from an array of integers
	explicit IntegerSet(int *, size_t);

	//Destructor
	~IntegerSet();

	//Member functions
	IntegerSet unionOfSets(IntegerSet);
	IntegerSet intersectionOfSets(IntegerSet);
	void insertElement(int);
	void deleteElement(int);
	std::string toString();
	bool isEqualTo(IntegerSet);

private:
	std::vector<bool> MySet;
};
#endif
