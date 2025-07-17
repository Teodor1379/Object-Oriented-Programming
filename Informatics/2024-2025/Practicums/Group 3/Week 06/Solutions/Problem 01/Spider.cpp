#include "Spider.hpp"



Spider::Spider() {
    this->name  = this->buildString("Unknown")  ;
    this->age   = -1                            ;
}

Spider::Spider(const char* name, unsigned int age) {
    if (
        this->validateName  (name) == false   ||
        this->validateAge   (age ) == false   
    ) {
        throw std::invalid_argument("Invalid Spider Arguments!");
    }

    this->name  =   this->buildString(name) ;
    this->age   =   age                     ;
}

Spider::Spider(const Spider& instance) {
    this->name  =   this->buildString(instance.name);
    this->age   =   instance.age                    ;
}


Spider::~Spider() {
    this->destroyString(this->name);
}



Spider& Spider::operator=(const Spider& instance) {
    if (this != &instance) {
        char* temporary = this->buildString(instance.name);

        this->destroyString(this->name);

        this->name  =   temporary   ;
        this->age   =   instance.age;
    }

    return *this;
}



void Spider::print() const { 
    std::cout << "Spider: ";

    std::cout << "[ ";

    std::cout << "Name  : " << this->name   << ", " ;
    std::cout << "Age   : " << this->age            ;

    std::cout << " ]";

    std::cout << std::endl;
}



char* Spider::buildString(const char* string) const {
    char* result = new char[strlen(string) + 1]();

    strcpy(result, string);

    return result;
}

void Spider::destroyString(char*& string) {
    delete[] string;

    string = nullptr;
}
