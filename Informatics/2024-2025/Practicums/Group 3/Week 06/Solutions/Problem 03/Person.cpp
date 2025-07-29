#include "Person.hpp"



Person::Person() {
    try {
        this->firstName = this->buildString("Unknown Name 1");
        this->thirdName = this->buildString("Unknown Name 3");
    } catch (std::bad_alloc& exception) {
        this->destroyString(this->firstName);

        throw exception;
    }

    this->age   =   -1      ;
    this->sex   =   false   ;
}

Person::Person(const char* firstName, const char* thirdName, unsigned int age, bool sex) {
    if (
        this->validateFirstName (firstName  )   ==  false   ||
        this->validateThirdName (thirdName  )   ==  false   ||
        this->validateAge       (age        )   ==  false
    ) {
        throw std::invalid_argument("Invalid Constructor Arguments!");
    }

    try {
        this->firstName = this->buildString(firstName);
        this->thirdName = this->buildString(thirdName);
    } catch (std::bad_alloc& exception) {
        this->destroyString(this->firstName);

        throw exception;
    }

    this->age   =   age ;
    this->sex   =   sex ;
}

Person::Person(const Person& instance) {
    try {
        this->firstName = this->buildString(instance.firstName);
        this->thirdName = this->buildString(instance.thirdName);
    } catch (std::bad_alloc& exception) {
        this->destroyString(this->firstName);

        throw exception;
    }

    this->age   =   instance.age ;
    this->sex   =   instance.sex ;
}

Person::~Person() {
    this->destroyString(this->firstName );
    this->destroyString(this->thirdName );
}



Person& Person::operator=(const Person& instance) {
    if (this != &instance) {
        char* firstNameTemp = nullptr;
        char* thirdNameTemp = nullptr;

        try {
            firstNameTemp = this->buildString(instance.firstName  );
            thirdNameTemp = this->buildString(instance.thirdName  );
        } catch (std::bad_alloc& exception) {
            this->destroyString(firstNameTemp);

            throw exception;
        }

        this->destroyString(this->firstName);
        this->destroyString(this->thirdName);

        this->firstName =   firstNameTemp   ;
        this->thirdName =   thirdNameTemp   ;
        this->age       =   instance.age    ;
        this->sex       =   instance.sex    ;
    }

    return *this;
}



void Person::setFirstName(const char* firstName) {
    if (this->validateFirstName(firstName) == false) {
        throw std::invalid_argument("Invalid FirstName Argument!");
    }

    char* temporary = this->buildString(firstName);

    this->destroyString(this->firstName);

    this->firstName = temporary;
}

void Person::setThirdName(const char* thirdName) {
    if (this->validateThirdName(thirdName) == false) {
        throw std::invalid_argument("Invalid Third Name Argument!");
    }

    char* temporary = this->buildString(thirdName);

    this->destroyString(this->thirdName);

    this->thirdName = temporary;
}

void Person::setAge(unsigned int age) {
    if (this->validateAge(age) == false) {
        throw std::invalid_argument("Invalid Age Argument!");
    }

    this->age = age;
}

void Person::setSex(bool sex) {
    this->sex = sex;
}



void Person::print() const {
    std::cout << "Person: ";

    std::cout << "[ ";

    std::cout << "First Name: " << this->firstName  << ", " ;
    std::cout << "Third Name: " << this->thirdName  << ", " ;
    std::cout << "Age       : " << this->age        << ", " ;
    std::cout << "Sex       : " << this->sex                ;

    std::cout << " ]";

    std::cout << std::endl;
}



char* Person::buildString(const char* string) const {
    char* result = new char[strlen(string) + 1]();

    strcpy(result, string);
    
    return result;
}

void Person::destroyString(char*& string) {
    delete[] string;

    string = nullptr;
}



Person findYoungest(const Person& p1, const Person& p2, const Person& p3) {
    if (p1.getAge() < p2.getAge()) {
        return p1.getAge() < p3.getAge() ? p1 : p3;
    } else {
        return p2.getAge() < p3.getAge() ? p2 : p3;
    }
}

Person findOldest(const Person& p1, const Person& p2, const Person& p3) {
    if (p1.getAge() > p2.getAge()) {
        return p1.getAge() > p3.getAge() ? p1 : p3;
    } else {
        return p2.getAge() > p3.getAge() ? p2 : p3;
    }
}
