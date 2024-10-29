#pragma once

#include "Date.h"
#include "Person.h"
#include <string>

class Vehicle
{
public:
	virtual void input() = 0;
	virtual void display() = 0;
	void inputPersonInfor();
	void saleCar();
	void updateInfor();
	std::string getSeries();
	Person getOwner() const;
	bool getStatus();
protected:
	Person info;
	std::string branch;
	std::string series;
	Date sale_date;
	Date warranty_period;
	std::string color;
	bool status;
	int year;
};

