#pragma once

#include <tuple>
#include <string>
#include <iostream>

class Date {
public:
	Date();
	Date(const Date& src) = default;
	Date& operator= (const Date& rhs) = default;
	~Date() = default;

	void setDate(int day, int month, int year);
	void setDate(std::tuple<int, int, int> new_date);
	void setDateIsToday();
	void setDefaultDate();
	void inputDate(std::istream&);

	std::string display() const;
private:
	static std::tuple<int, int, int> getCurrentDate();
	static const std::tuple<int, int, int> defaultDate;
	void set_date(int new_day, int new_month, int new_year);
private:
	int m_day	= 0;
	int m_month	= 0;
	int m_year	= 0;
};