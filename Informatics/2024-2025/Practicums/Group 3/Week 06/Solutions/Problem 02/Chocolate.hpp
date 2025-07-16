#ifndef _CHOCOLATE_HEADER_INCLUDED_
#define _CHOCOLATE_HEADER_INCLUDED_



#include <cstring>

#include <cmath>

#include <exception>
#include <stdexcept>

#include <iostream>



#define EPSILON 1e-9



class Chocolate {
public:
    Chocolate();
    Chocolate(const char*, double, double);
    Chocolate(const Chocolate&);

    ~Chocolate();



public:
    Chocolate& operator=(const Chocolate&);



public:
    inline  const char* getBrand    ()  const   { return this->brand    ;   }
    inline  double      getPrice    ()  const   { return this->price    ;   }
    inline  double      getWeight   ()  const   { return this->weight   ;   }



public:
    void    setBrand    (const char*);
    void    setPrice    (double     );
    void    setWeight   (double     );



public:
    void    print() const;



private:
    inline  bool    validateBrand   (const char*    brand   )   const   { return brand != nullptr           && brand[0] != '\0'             ;   }

    inline  bool    validatePrice   (double         price   )   const   { return std::isfinite(price    )   && std::fabs(price  ) >= EPSILON;   }
    inline  bool    validateWeight  (double         weight  )   const   { return std::isfinite(weight   )   && std::fabs(weight ) >= EPSILON;   }



private:
    char* buildString(const char*);



private:
    char*   brand   ;
    double  price   ;
    double  weight  ;
};



#endif
