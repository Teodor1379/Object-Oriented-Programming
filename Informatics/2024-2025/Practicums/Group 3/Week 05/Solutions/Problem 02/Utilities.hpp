#ifndef UTILITIES_HEADER_INCLUDED
#define UTILITIES_HEADER_INCLUDED



#include "Person.hpp"



#define CAPACITY 64



bool compareLessThan(const Person&, const Person&);
bool compareBigrThan(const Person&, const Person&);



void sortPersonsNamesLessThan(Person persons[CAPACITY], unsigned int size);
void sortPersonsNamesBigrThan(Person persons[CAPACITY], unsigned int size);

void sortPersonsAgesLessThan(Person persons[CAPACITY], unsigned int size);
void sortPersonsAgesBigrThan(Person persons[CAPACITY], unsigned int size);



void removeDuplicates(Person persons[CAPACITY], unsigned int size, Person result[CAPACITY], unsigned int& anotherSize);



#endif
