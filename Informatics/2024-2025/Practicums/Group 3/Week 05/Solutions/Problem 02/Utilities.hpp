#ifndef UTILITIES_HEADER_INCLUDED
#define UTILITIES_HEADER_INCLUDED



#include "Person.hpp"



#define CAPACITY 64



bool compareLessThan(const Person&, const Person&);
bool compareBiggThan(const Person&, const Person&);



void sortPersonsNamesLessThan(Person persons[CAPACITY], unsigned int size);
void sortPersonsNamesBiggThan(Person persons[CAPACITY], unsigned int size);

void sortPersonsAgesLessThan(Person persons[CAPACITY], unsigned int size);
void sortPersonsAgesBiggThan(Person persons[CAPACITY], unsigned int size);



void removeDuplicates(Person persons[CAPACITY], unsigned int& size, Person result[CAPACITY]);



#endif
