#pragma once

#include "Vehicle.h"
#include <string>

class BMW : public Vehicle
{
public:
	void input() override;
	void display() override;
private:
	std::string model;
};

