#ifndef _APPLE_HEADER_INCLUDED_
#define _APPLE_HEADER_INCLUDED_



#include <cstring>

#include <exception>
#include <stdexcept>

#include <fstream>
#include <iostream>



class Apple {
public:
                Apple(              )   =   delete  ;
    explicit    Apple(const char*   )               ;
                Apple(const Apple&  )               ;

                ~Apple()    noexcept                ;



public:
    Apple& operator=(const Apple&);



public:
    inline  const char*     getName()   const   noexcept    { return this->name ;   }
    inline  unsigned int    getSize()   const   noexcept    { return this->size ;   }



public:
    void    setName(const char*);



public:
    void    addPrefix(const char*);
    void    addSuffix(const char*);



public:
    void    print(std::ostream& = std::cout)   const   noexcept;



private:
    char*     buildString(const char*   )    const  ;
    void    destroyString(      char*&  )           ;



private:
    char*           name;
    unsigned int    size;
};




inline bool operator==(const Apple& apple1, const Apple& apple2)    { return strcmp(apple1.getName(), apple2.getName()) == 0;   }
inline bool operator!=(const Apple& apple1, const Apple& apple2)    { return strcmp(apple1.getName(), apple2.getName()) != 0;   }

inline bool operator==(const Apple& apple1, const char* apple2)     { return apple2 != nullptr && strcmp(apple1.getName(), apple2) == 0;    }
inline bool operator!=(const Apple& apple1, const char* apple2)     { return apple2 != nullptr && strcmp(apple1.getName(), apple2) != 0;    }

inline bool operator==(const char* apple1, const Apple& apple2)     { return apple1 != nullptr && strcmp(apple1, apple2.getName()) == 0;    }
inline bool operator!=(const char* apple1, const Apple& apple2)     { return apple1 != nullptr && strcmp(apple1, apple2.getName()) != 0;    }



#endif
