#include "Person.h"

inline static void _get_line(std::istream& is, std::string& str)
{
	is >> std::ws;
	std::getline(is, str);
}

void Person::inputInforPerson(std::istream& is)
{
	std::cout << "Nhap ten: ";				_get_line(is, name);
	std::cout << "=> Ngay sinh: ";			dob.inputDate(is);
	std::cout << "Nhap dia chi: ";			_get_line(is, address);
	std::cout << "Nhap so dien thoai: ";	_get_line(is, phoneNumber);
}

void Person::setDefaultInforPerson()
{
	name = "N/A";
	dob.setDefaultDate();
	address = "N/A";
	phoneNumber = "N/A";
}

void Person::outputInforPerson(std::ostream& os)
{
	os  << name << std::endl
		<< dob.display() << std::endl
		<< address << std::endl
		<< phoneNumber << std::endl;
}