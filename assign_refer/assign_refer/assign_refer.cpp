// assign_refer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
#include "Person.h"
#include <sstream>

void getUserInputDate(Date& date) {
    while (true) {
        std::cout << "Enter date (dd/mm/yyyy): ";
        std::string input;
        std::getline(std::cin, input);

        std::istringstream iss(input);

        try {
            date.inputDate(iss);
            break;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "ERROR: Invalid format date, please try again." << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "ERROR: " << e.what() << " Please try again." << std::endl;
        }
    }
}

#include "Vehicle.h"
#include "BMW.h"

int main()
{
    Vehicle* pb = new BMW;

    pb->saleCar();

    Person person = pb->getOwner();

    person.outputInforPerson(std::cout);

    return 0;
}