#include "Utilities.hpp"



bool compareLessThan(const Person& person1, const Person& person2) {
    int firstNameCompare = strcmp(person1.getFirstName(), person2.getFirstName());

    if (firstNameCompare < 0) {
        return true;
    } else if (firstNameCompare > 0) {
        return false;
    } else {
        return strcmp(person1.getThirdName(), person2.getThirdName()) < 0;
    }
}

bool compareBigrThan(const Person& person1, const Person& person2) {
    int firstNameCompare = strcmp(person1.getFirstName(), person2.getFirstName());

    if (firstNameCompare < 0) {
        return false;
    } else if (firstNameCompare > 0) {
        return true;
    } else {
        return strcmp(person1.getThirdName(), person2.getThirdName()) > 0;
    }
}



void sortPersonsNamesLessThan(Person persons[CAPACITY], unsigned int size) {
    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            if (compareLessThan(persons[i], persons[j])) {
                std::swap(persons[i], persons[j]);
            }
        }
    }
}

void sortPersonsNamesBigrThan(Person persons[CAPACITY], unsigned int size) {
    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            if (compareBigrThan(persons[i], persons[j])) {
                std::swap(persons[i], persons[j]);
            }
        }
    }
}



void sortPersonsAgesLessThan(Person persons[CAPACITY], unsigned int size) {
    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            if (persons[i].getAge() < persons[j].getAge()) {
                std::swap(persons[i], persons[j]);
            }
        }
    }
}

void sortPersonsAgesBigrThan(Person persons[CAPACITY], unsigned int size) {
    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            if (persons[i].getAge() > persons[j].getAge()) {
                std::swap(persons[i], persons[j]);
            }
        }
    }
}



void removeDuplicates(Person persons[CAPACITY], unsigned int size, Person result[CAPACITY], unsigned int& anotherSize) {
    for (unsigned int i = 0; i < size; ++i) {
        bool found = false;

        for (unsigned int j = 0; j < anotherSize; ++j) {
            if (persons[i].equals(result[j])) {
                found = true; break;
            }
        }

        if (found == false) {
            result[anotherSize] = persons[i];

            anotherSize = anotherSize + 1;
        }
    }
}
