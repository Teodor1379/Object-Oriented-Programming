#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
public:
    Date() = delete;

    Date(unsigned int, unsigned int, unsigned int);

    unsigned int getDay()   const { return this->day; }
    unsigned int getMonth() const { return this->month; }
    unsigned int getYear()  const { return this->year; }

    unsigned getDaysByMonth()   const;
    unsigned getDaysByYear()    const;

    bool operator==(const Date&) const;
    bool operator<(const Date&) const;

private:
    bool validateDate(unsigned int, unsigned int, unsigned int);

    std::uint8_t    day;
    std::uint8_t    month;
    std::uint16_t   year;
};

#endif
