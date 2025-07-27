#include "Person.hpp"



Person::Person() {
    strcpy(this->firstName, "NULL"  );
    strcpy(this->thirdName, "NULL"  );

    this->age   =   18      ;
    this->age   =   false   ;
}

Person::Person(const char* firstName, const char* thirdName, unsigned int age, bool sex) {
    if (
        !validateName(firstName) ||
        !validateName(thirdName) ||
        age         ==  0
    ) {
        std::cout << "Building Person... ERROR!" << std::endl;

        return;
    }

    strcpy(this->firstName, firstName);
    strcpy(this->thirdName, thirdName);

    this->age   =   age;
    this->sex   =   sex;
}



void Person::printInformation() const {
    std::cout << "Person Information: ";

    std::cout << "First Name: " << this->firstName  << std::endl;
    std::cout << "Third Name: " << this->thirdName  << std::endl;
    std::cout << "Age       : " << this->age        << std::endl;
    std::cout << "Sex       : " << this->sex        << std::endl;

    std::cout << std::endl;
}



bool Person::equals(const Person& instance) const {
    return
        strcmp(this->firstName, instance.firstName) &&
        strcmp(this->thirdName, instance.thirdName);
}



bool Person::validateName(const char* name) const {
    if (name ==  nullptr) {
        return false;
    }

    if (name[0] == '\0') {
        return false;
    }

    if (name[0] < 'A' || name[0] > 'Z') {
        return false;
    }

    for (unsigned int i = 1; name[i] != '\0'; ++i) {
        if (name[i] < 'a' || name[i] > 'z') {
            return false;
        }
    }

    return true;
}
