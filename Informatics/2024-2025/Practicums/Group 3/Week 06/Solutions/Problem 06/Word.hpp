#ifndef _WORD_HEADER_INCLUDED_
#define _WORD_HEADER_INCLUDED_



#include <cassert>
#include <cstring>

#include <exception>
#include <stdexcept>

#include <fstream>
#include <iostream>



#define MAX 256
#define SIZ 100



class Word {
public:
    inline Word(                    )   : string(this->buildString("")              ), size(strlen(this->string))   {}
    inline Word(const char* string  )   : string(this->buildString(string)          ), size(strlen(this->string))   {}
    inline Word(const Word& instance)   : string(this->buildString(instance.string) ), size(strlen(this->string))   {}

    inline ~Word() noexcept { this->destroyString(this->string);    }



public:
    Word& operator=(const Word&);



public:
    inline  const char*     getString   ()  const   { return this->string   ;   }
    inline  unsigned int    getSize     ()  const   { return this->size     ;   }



public:
    inline          char&   front   ()          noexcept    { return this->string[0]                ;   }
    inline  const   char&   front   ()  const   noexcept    { return this->string[0]                ;   }

    inline          char&   back    ()          noexcept    { return this->string[this->size - 1]   ;   }
    inline  const   char&   back    ()  const   noexcept    { return this->string[this->size - 1]   ;   }



public:
    inline          char&   at  (unsigned int index)            noexcept    { if (index >= this->size)  { throw std::out_of_range("Invalid Index"); }   return this->string[index]; }
    inline  const   char&   at  (unsigned int index)    const   noexcept    { if (index >= this->size)  { throw std::out_of_range("Invalid Index"); }   return this->string[index]; }



public:
    std::istream&  readFrom(std::istream&)          ;
    std::ostream&  writeTo (std::ostream&) const    ;



public:
    Word concatenate(const Word&, const Word&) const;



public:
    inline bool empty() const noexcept  { return this->size == 0; }



private:
    char*     buildString(const char*   )   const   ;
    void    destroyString(      char*&  )           ;



private:
    char*           string  ;
    unsigned int    size    ;
};



Word concatenateWords(const Word[SIZ], unsigned int);



#endif
