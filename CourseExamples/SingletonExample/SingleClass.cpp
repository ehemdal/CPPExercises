#include "SingleClass.h"
SingleClass::SingleClass() {
	SampleData = 0;
};

SingleClass* SingleClass::getInstance()
{
	if (!instance) {
		instance = new SingleClass();
		return instance;
	}
	else return nullptr;
}

int SingleClass::getSampleData()
{
	return this->SampleData;
}

void SingleClass::setSampleData(int data)
{
	this->SampleData = data;
}




