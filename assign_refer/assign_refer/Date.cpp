#include "Date.h"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

const std::tuple<int, int, int> Date::defaultDate = std::make_tuple(1, 1, 2023);

Date::Date()
{
    setDefaultDate();
}

void Date::set_date(int new_day, int new_month, int new_year)
{
    if (new_day < 1 || new_day > 31) throw std::out_of_range("Day must be between 1 and 31");
    if (new_month < 1 || new_month > 12) throw std::out_of_range("Month must be between 1 and 12");
    if (new_year <= 0) throw std::invalid_argument("Year must be a positive integer");

    this->m_day     = new_day;
    this->m_month   = new_month;
    this->m_year    = new_year;
}

std::tuple<int, int, int> Date::getCurrentDate()
{
    auto now = std::chrono::system_clock::now();

    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm localTime;
    localtime_s(&localTime, &now_c);

    int day = localTime.tm_mday;
    int month = localTime.tm_mon + 1;
    int year = localTime.tm_year + 1900;

    return std::make_tuple(day, month, year);
}

void Date::setDate(int day, int month, int year)
{
    set_date(day, month, year);
}

void Date::setDate(std::tuple<int, int, int> new_date)
{
    set_date(std::get<0>(new_date), std::get<1>(new_date), std::get<2>(new_date));
}

void Date::setDateIsToday()
{
    setDate(getCurrentDate());
}

void Date::setDefaultDate()
{
    setDate(defaultDate);
}

void Date::inputDate(std::istream& is)
{
    std::string line;
    std::getline(is, line);

    std::vector<int> dateParts;
    std::istringstream iss(line);
    std::string token;

    while (std::getline(iss, token, ' ')) {
        std::stringstream tokenStream(token);
        std::string subToken;
        while (std::getline(tokenStream, subToken, '/'))
        {
            if (subToken.empty() || 
                !std::all_of(subToken.begin(), subToken.end(), isdigit))
            {
                throw std::invalid_argument("Invalid input format for date");
            }

            dateParts.push_back(std::stoi(subToken));
        }
    }

    if (dateParts.size() != 3)
    {
        throw std::invalid_argument("Invalid input format for date");
    }

    set_date(dateParts[0], dateParts[1], dateParts[2]);
}

std::string Date::display() const
{
    std::ostringstream oss;

    oss << std::setw(2) << std::setfill('0') << this->m_day << "/"
        << std::setw(2) << std::setfill('0') << this->m_month << "/"
        << this->m_year;

    return oss.str();
}