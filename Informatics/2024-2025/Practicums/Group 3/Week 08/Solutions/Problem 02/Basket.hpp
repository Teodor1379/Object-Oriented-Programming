#ifndef _BASKET_HEADER_INCLUDED_
#define _BASKET_HEADER_INCLUDED_



#include <exception>
#include <stdexcept>

#include <fstream>
#include <iostream>


#include "Apple.hpp"



class Basket {
public:
    Basket(             );
    Basket(const Basket&);

    ~Basket();



public:
    Basket& operator=(const Basket&);



public:
    inline  const Apple* const* getData()   const   noexcept    { return this->data;    }
    inline  unsigned int        getSize()   const   noexcept    { return this->size;    }
    inline  unsigned int        getCpct()   const   noexcept    { return this->cpct;    }



public:
    void add(const char*);
    void rem(const char*);



public:
    void print(std::ostream& = std::cout) const noexcept;



public:
    const Apple* const& operator[](unsigned int )   const;
    const Apple* const& operator[](const char*  )   const;



public:
    Basket& operator+=(const Basket&);
    Basket& operator+=(const char*  );

    Basket operator+(const Basket&  basket) const   { Basket result = *this; result += basket; return result;   }
    Basket operator+(const char*    string) const   { Basket result = *this; result += string; return result;   }



private:
    Apple**   allocateData(const    Basket&                 );
    void    deallocateData(         Apple**&, unsigned int  );
    void    reallocateData(                                 );



private:
    const static unsigned int ALLOC_B = 4;
    const static unsigned int ALLOC_S = 2;


private:
    Apple**         data;
    unsigned int    size;
    unsigned int    cpct;
};



#endif
