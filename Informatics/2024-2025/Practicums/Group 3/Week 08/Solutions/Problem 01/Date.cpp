#include "Date.hpp"



std::uint32_t squeeze(std::uint8_t n1, std::uint8_t n2, std::uint16_t n3) {
    std::uint32_t result = 0;

    result = (result | (static_cast<std::uint32_t>(n1   ) << 24));
    result = (result | (static_cast<std::uint32_t>(n2   ) << 16));
    result = (result | (static_cast<std::uint32_t>(n3   ) <<  0));

    return result;
}



Date::Date(std::uint8_t day, std::uint8_t month, std::uint16_t year) {
    if (this->validateDate(squeeze(day, month, year)) == false) {
        throw std::invalid_argument("Invalid Constructor Arguments!");
    }

    this->day   =   day     ;
    this->month =   month   ;
    this->year  =   year    ;
}



void Date::print(std::ostream& stream) const noexcept {
    stream << static_cast<int>(this->day    )   << '.'  ;
    stream << static_cast<int>(this->month  )   << '.'  ;
    stream << static_cast<int>(this->year   )   << '\n' ;
}



bool Date::validateDate(std::uint32_t date) const noexcept {
    if (static_cast<std::uint16_t>(date) < Date::MIN_YEAR) {
        return false;
    }

    std::uint8_t d = static_cast<std::uint8_t>(date >> 24);
    std::uint8_t m = static_cast<std::uint8_t>(date >> 16);

    switch (m) {
        case Date::JAN: case Date::MAR: case Date::MAY: case Date::JUL:
        case Date::AUG: case Date::OCT: case Date::DEC:
            return d >= Date::MDAY && d <= Date::MDA3;

        case Date::FEB:
            return d >= Date::MDAY && d <= Date::MDA1 + this->isLeap(static_cast<std::uint16_t>(date));

        case Date::APR: case Date::JUN:
        case Date::SEP: case Date::NOV:
            return d >= Date::MDAY && d <= Date::MDA2;

        default:
            return false;
    }
}



bool operator==(const Date& lhs, const Date& rhs) {
    return
        lhs.getDay  ()  ==  rhs.getDay  ()  &&
        lhs.getMonth()  ==  rhs.getMonth()  &&
        lhs.getYear ()  ==  rhs.getYear ();

    // return ! (lhs != rhs); iff there is operator!=
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return
        lhs.getDay  ()  !=  rhs.getDay  ()  ||
        lhs.getMonth()  !=  rhs.getMonth()  ||
        lhs.getYear ()  !=  rhs.getYear ();

    // return ! (lhs == rhs); iff there is operator==
}
