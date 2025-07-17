#ifndef _SPIDER_HEADER_INCLUDED_
#define _SPIDER_HEADER_INCLUDED_



#include <cstring>

#include <exception>
#include <stdexcept>

#include <iostream>



class Spider {
public:
    Spider(                         );
    Spider(const char*, unsigned int);
    Spider(const Spider&            );

    ~Spider();


public:
    Spider& operator=(const Spider&);



public:
    inline  const char*     getName ()  const   { return this->name ;   }
    inline  unsigned int    getAge  ()  const   { return this->age  ;   }



public:
    void print() const;



private:
    inline bool validateName    (const char*    name)   const   { return name != nullptr && name[0] != '\0' ;   }
    inline bool validateAge     (unsigned int   age )   const   { return age > 0                            ;   }



private:
    char*     buildString(const char*   )   const   ;
    void    destroyString(      char*&  )           ;



private:
    char*           name;
    unsigned int    age ;
};



#endif
