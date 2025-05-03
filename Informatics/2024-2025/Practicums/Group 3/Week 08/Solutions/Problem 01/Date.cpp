#include "Date.hpp"



Date::Date(std::uint8_t day, std::uint8_t month, std::uint8_t year) {
    this->day   =   day     ;
    this->month =   month   ;
    this->year  =   year    ;
}



bool operator==(const Date& lhs, const Date& rhs) {
    return
        lhs.getDay  ()  ==  rhs.getDay  ()  &&
        lhs.getMonth()  ==  rhs.getMonth()  &&
        lhs.getYear ()  ==  rhs.getYear ();

    // return ! (lhs != rhs);
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return
        lhs.getDay  ()  !=  rhs.getDay  ()  ||
        lhs.getMonth()  !=  rhs.getMonth()  ||
        lhs.getYear ()  !=  rhs.getYear ();

    // return ! (lhs == rhs);
}