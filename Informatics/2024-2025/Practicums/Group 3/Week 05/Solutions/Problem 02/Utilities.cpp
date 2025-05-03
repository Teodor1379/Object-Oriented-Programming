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

bool compareBiggThan(const Person& person1, const Person& person2) {
    int firstNameCompare = strcmp(person1.getFirstName(), person2.getFirstName());

    if (firstNameCompare < 0) {
        return false;
    } else if (firstNameCompare > 0) {
        return true;
    } else {
        return strcmp(person1.getThirdName(), person2.getThirdName()) > 0;
    }
}
