#include "Porsche.h"
#include <iostream>


void Porsche::input()
{
	std::cout << "======= NHAP THONG TIN XE PORSCHE =======" << std::endl;
	Vehicle::input();
	std::cout << "NHAP TOC DO TOI DA: "; std::cin >> topSpeed;
}

void Porsche::display()
{
	std::cout << "Series: " << this->getSeries() << std::endl;
	std::cout << "TOP SPEED: " << this->topSpeed;
}