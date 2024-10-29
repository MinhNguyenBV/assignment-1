#pragma once

#include "Date.h"
#include <string>
#include <iostream>

class Person
{
public:
	void inputInforPerson(std::istream&);
	void setDefaultInforPerson();
	void outputInforPerson(std::ostream&);
private:
	std::string name;
	Date dob;
	std::string address;
	std::string phoneNumber;
};

