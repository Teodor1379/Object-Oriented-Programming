#ifndef DATE_HEADER_INCLUDED
#define DATE_HEADER_INCLUDED



#include <cstdint>


class Date {
public:
    Date() = default;
    Date(std::uint8_t, std::uint8_t, std::uint8_t);


public:
    inline std::uint8_t getDay  ()  const   { return this->day  ;   }
    inline std::uint8_t getMonth()  const   { return this->month;   }
    inline std::uint8_t getYear ()  const   { return this->year ;   }


private:
    std::uint8_t    day     ;
    std::uint8_t    month   ;
    std::uint8_t    year    ;
};



bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);


#endif