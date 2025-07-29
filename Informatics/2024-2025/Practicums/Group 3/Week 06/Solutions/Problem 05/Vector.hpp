#ifndef _VECTOR_HEADER_INCLUDED_
#define _VECTOR_HEADER_INCLUDED_



#include <exception>
#include <stdexcept>

#include <iostream>



class Vector {
public:
    Vector(                     )               ;
    Vector(unsigned int         )               ;
    Vector(unsigned int, int    )               ;
    Vector(const Vector&        )   noexcept    ;

    ~Vector();



public:
    Vector& operator=(const Vector&);



public:
    inline  unsigned int    getSize     ()  const   noexcept    { return this->size;    }
    inline  unsigned int    getCpct     ()  const   noexcept    { return this->cpct;    }



public:
    inline          int&    front   ()          noexcept    { return this->data[0]              ;   }   // No Throw Guarantee
    inline  const   int&    front   ()  const   noexcept    { return this->data[0]              ;   }   // No Throw Guarantee

    inline          int&    back    ()          noexcept    { return this->data[this->size - 1] ;   }   // No Throw Guarantee
    inline  const   int&    back    ()  const   noexcept    { return this->data[this->size - 1] ;   }   // No Throw Guarantee

    

public:
    inline          int&    at(unsigned int index)          { if (index >= this->size) { throw std::out_of_range("Invalid Index"); }    return this->data[index];   }
    inline const    int&    at(unsigned int index)  const   { if (index >= this->size) { throw std::out_of_range("Invalid Index"); }    return this->data[index];   }



public:
    void    pushBack(int);
    void     popBack(   );



public:
    inline  void    clear() noexcept    { this->size = 0; }



private:
    void resize();



private:
    int*      allocateData(unsigned int )   const   ;
    int*      allocateData(const Vector&)   const   ;
    void    deallocateData(             )           ;



private:
    unsigned int findPowerTwo(unsigned int) const noexcept;



private:
    unsigned int    size;
    unsigned int    cpct;
    int*            data;
};



void print(const Vector&);



#endif

