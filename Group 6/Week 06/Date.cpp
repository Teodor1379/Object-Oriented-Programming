#include "Date.h"

#include <cassert>

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    assert(this->validateDate(day, month, year));

    this->day   = day;
    this->month = month;
    this->year  = year;
}

unsigned Date::getDaysByMonth() const {
    unsigned leapYear = (((this->year % 4 == 0) && (this->year % 100 != 0)) || (this->year % 400 == 0));

    switch (this->month) {
        case 1: case 3:
        case 5: case 7:
        case 8: case 10:
        case 12:
            return 31;
        case 4: case 6:
        case 9: case 11:
            return 30;
        default:
            return 28 + leapYear;
    }
}

unsigned Date::getDaysByYear() const {
    return 365 + (((this->year % 4 == 0) && (this->year % 100 != 0)) || (this->year % 400 == 0));
}

bool Date::operator==(const Date& rhs) const {
    return  this->day == rhs.getDay()       &&
            this->month == rhs.getMonth()   &&
            this->year == rhs.getYear();
}

bool Date::operator<(const Date& rhs) const {
    return  this->day + this->getDaysByMonth() + this->getDaysByYear() <
            rhs.getDay() + rhs.getDaysByMonth() + rhs.getDaysByYear();
}

bool Date::validateDate(unsigned int day, unsigned int month, unsigned int year) {
    unsigned leapYear = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));

    switch (month) {
        case 1: case 3:
        case 5: case 7:
        case 8: case 10:
        case 12:
            return day > 0 && day < 32;
        case 2:
            return day > 0 && day < 29 + leapYear;
        case 4: case 6:
        case 9: case 11:
            return day > 0 && day < 31;
        default:
            return false;
    }
}
