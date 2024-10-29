#include "BMW.h"
#include <iostream>


void BMW::input()
{
	std::cout << "======= NHAP THONG TIN XE BMW =======" << std::endl;
	Vehicle::input();
	std::cout << "NHAP MODEL XE: "; std::cin >> model;
}

void BMW::display()
{
	Vehicle::display();
	std::cout << "Model: " << this->model;
}