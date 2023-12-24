#pragma once
#include <vector>
#include <memory>
class SingleClass {
	// Pointer to my singleton "Manager" object
	static SingleClass* instance;
	int SampleData;
	SingleClass();

public:
	static SingleClass* getInstance();
	int getSampleData();
	void setSampleData(int);
	std::vector<std::unique_ptr<int>> integers;
};

