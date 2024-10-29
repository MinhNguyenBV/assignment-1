#pragma once

#include "Vehicle.h"

class Porsche : public Vehicle
{
public:
	void input() override;
	void display() override;
private:
	int topSpeed;
};

