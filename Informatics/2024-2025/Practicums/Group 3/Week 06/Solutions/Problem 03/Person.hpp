#ifndef _PERSON_HEADER_INCLUDED_
#define _PERSON_HEADER_INCLUDED_



#include <cstring>

#include <exception>
#include <stdexcept>

#include <iostream>



class Person {
public:
    Person(                                             );
    Person(const char*, const char*, unsigned int, bool );
    Person(const Person&                                );

    ~Person();



public:
    Person& operator=(const Person&);



public:
    inline  const char*     getFirstName()  const   { return this->firstName;   }
    inline  const char*     getThirdName()  const   { return this->thirdName;   }
    inline  unsigned int    getAge      ()  const   { return this->age      ;   }
    inline  bool            getSex      ()  const   { return this->sex      ;   }



public:
    void    setFirstName(const char*    );
    void    setThirdName(const char*    );
    void    setAge      (unsigned int   );
    void    setSex      (bool           );



public:
    void print() const;



private:
    inline  bool    validateFirstName   (const char*    firstName   )   const   { return firstName != nullptr && firstName[0] != '\0';  }
    inline  bool    validateThirdName   (const char*    thirdName   )   const   { return thirdName != nullptr && thirdName[0] != '\0';  }

    inline  bool    validateAge         (unsigned int   age         )   const   { return age != 0;                                      }



private:
    char*     buildString(const char*   )   const   ;
    void    destroyString(      char*&  )           ;



private:
    char*           firstName   ;
    char*           thirdName   ;
    unsigned int    age         ;
    bool            sex         ;
};



Person findYoungest (const Person&, const Person&, const Person&);
Person findOldest   (const Person&, const Person&, const Person&);



#endif
