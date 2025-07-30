#ifndef _DATE_HEADER_INCLUDED_
#define _DATE_HEADER_INCLUDED_



#include <cstdint>

#include <exception>
#include <stdexcept>

#include <fstream>
#include <iostream>



std::uint32_t squeeze(std::uint8_t, std::uint8_t, std::uint16_t);



class Date {
public:
    Date(                                           )   =   delete  ;
    Date(std::uint8_t, std::uint8_t, std::uint16_t  )               ;



public:
    inline std::uint8_t     getDay  ()  const   noexcept    { return this->day  ;   }
    inline std::uint8_t     getMonth()  const   noexcept    { return this->month;   }
    inline std::uint16_t    getYear ()  const   noexcept    { return this->year ;   }



public:
    void print(std::ostream& = std::cout)   const   noexcept;



private:
    bool validateDate(std::uint32_t) const noexcept;



private:
    inline bool isLeap(std::uint16_t year)  const noexcept  { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; };



private:
    const static std::uint16_t MIN_YEAR = 1970;

    const static std::uint8_t MDAY  =    1  ;
    const static std::uint8_t MDA1  =   28  ;
    const static std::uint8_t MDA2  =   30  ;
    const static std::uint8_t MDA3  =   31  ;

    const static std::uint8_t JAN   =    1  ;
    const static std::uint8_t FEB   =    2  ;
    const static std::uint8_t MAR   =    3  ;
    const static std::uint8_t APR   =    4  ;
    const static std::uint8_t MAY   =    5  ;
    const static std::uint8_t JUN   =    6  ;
    const static std::uint8_t JUL   =    7  ;
    const static std::uint8_t AUG   =    8  ;
    const static std::uint8_t SEP   =    9  ;
    const static std::uint8_t OCT   =   10  ;
    const static std::uint8_t NOV   =   11  ;
    const static std::uint8_t DEC   =   12  ;



private:
    std::uint8_t    day     ;
    std::uint8_t    month   ;
    std::uint16_t   year    ;
};



bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);



#endif
