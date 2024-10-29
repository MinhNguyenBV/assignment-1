#include "Vehicle.h"
#include <iostream>
#include <tuple>

void Vehicle::input()
{
	std::cout << "-> NHAP THONG TIN XE: " << std::endl;
	std::cout << "NHAP SO SERIES (9 SO): "; std::cin >> series;
	std::cout << "NAM SAN XUAT: "; std::cin >> year;
	std::cout << "MAU SON: "; std::cin >> color;
}

void Vehicle::display()
{
	std::cout << "SERIES (9 SO): " << series << std::endl;
	std::cout << "NAM SAN XUAT: "  << year << std::endl;
	std::cout << "MAU SON: " << color << std::endl;
}

std::string Vehicle::getSeries()
{
	return this->series;
}

bool Vehicle::getStatus()
{
	return this->status;
}

void Vehicle::inputPersonInfor()
{
	info.inputInforPerson(std::cin);
}

static inline std::tuple<int, int, int> enter_date()
{
	int day{}, month{}, year{};

	std::cout << "NHAP NGAY: ";  std::cin >> day;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "NHAP THANG: "; std::cin >> month;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "NHAP NAM: ";   std::cin >> year;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return std::make_tuple(day, month, year);
}

void Vehicle::saleCar()
{
	std::cout << "======= NHAP THONG TIN BAN XE =======" << std::endl;
	std::cout << "NHAP SO SERIES (9 SO): "; std::cin >> series;

	std::cout << "-> NHAP THONG TIN CHU XE: " << std::endl;
	info.inputInforPerson(std::cin);

	std::cout << "-> NHAP THONG TIN XE: " << std::endl;
	std::cout << "-> NHAP NGAY MUA: " << std::endl;
	sale_date.setDate(enter_date());

	std::cout << "-> HAN BAO HANH: " << std::endl;
	warranty_period.setDate(enter_date());
}

void Vehicle::updateInfor()
{
	std::cout << "======= CAP NHAP THONG TIN XE =======" << std::endl;
	std::cout << "NHAP SO SERIES (9 SO): "; std::cin >> series;
	std::cout << "-> NHAP THONG TIN CHU XE: " << std::endl;

	info.inputInforPerson(std::cin);

	/* ======= Move to CarShop class ======= */
	std::cout << "DA CAP NHAT THONG TIN !" << std::endl;
	std::cout << "PRESS ANY KEY TO CONTINUE ...." << std::endl;
	std::cout << "BAN CO MUON TIEP TUC KHONG? (y/n)" << std::endl;
}

Person Vehicle::getOwner() const
{
	return info;
}