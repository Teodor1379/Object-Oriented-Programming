#ifndef PERSON_HEADER_INCLUDED
#define PERSON_HEADER_INCLUDED



#include <cstring>

#include <iostream>



#define MAX 256



class Person {
public:
    Person();

    Person(const char*, const char*, unsigned int, bool);


public:
    inline const char*  getFirstName()  const   { return firstName; }
    inline const char*  getThirdName()  const   { return thirdName; }
    inline unsigned int getAge      ()  const   { return age;       }
    inline bool         getSex      ()  const   { return sex;       }


public:
    inline bool isMature()  const { return this->age > 17;  }


public:
    void printInformation() const;


public:
    bool equals(const Person&)  const;


private:
    bool validateName(const char*)  const;


private:
    char            firstName[MAX]  ;
    char            thirdName[MAX]  ;
    unsigned int    age             ;
    bool            sex             ;
};



#endif
