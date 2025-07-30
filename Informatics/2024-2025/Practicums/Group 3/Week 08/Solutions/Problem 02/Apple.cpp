#include "Apple.hpp"



Apple::Apple(const char* name) {
    if (name == nullptr || name[0] == '\0') {
        throw std::invalid_argument("Invalid Constructor Arguments!");
    }

    this->name  =   this->buildString(name) ;
    this->size  =   strlen(this->name)      ;
}

Apple::Apple(const Apple& instance) {
    this->name  =   this->buildString(instance.name);
    this->size  =   instance.size                   ;
}

Apple::~Apple() {
    this->destroyString(this->name);
}



Apple& Apple::operator=(const Apple& instance) {
    if (this != &instance) {
        char* temporary = this->buildString(instance.name);

        this->destroyString(this->name);

        this->name  =   temporary       ;
        this->size  =   instance.size   ;
    }

    return *this;
}



void Apple::setName(const char* name) {
    if (name == nullptr || name[0] == '\0') {
        throw std::invalid_argument("Invalid Name Argument!");
    }

    char* buffer = this->buildString(name);

    this->destroyString(this->name);

    this->name  =   buffer          ;
    this->size  =   strlen(buffer)  ;
}



void Apple::addPrefix(const char* string) {
    if (string == nullptr) {
        throw std::invalid_argument("Invalid Prefix Argument!");
    }

    if (string[0] == '\0') {
        return;
    }

    char* temporary = new char[this->size + strlen(string) + 1]();

    strcpy(temporary, string    );
    strcat(temporary, this->name);

    this->destroyString(this->name);

    this->name  =   temporary           ;
    this->size  =   strlen(temporary)   ;
}

void Apple::addSuffix(const char* string) {
    if (string == nullptr) {
        throw std::invalid_argument("Invalid Suffix Argument!");
    }

    if (string[0] == '\0') {
        return;
    }

    char* temporary = new char[strlen(string) + this->size + 1]();

    strcpy(temporary, this->name);
    strcat(temporary, string    );

    this->destroyString(this->name);

    this->name  =   temporary           ;
    this->size  =   strlen(temporary)   ;
}



void Apple::print(std::ostream& stream) const noexcept {
    stream << "Apple: ";

    stream << "[ ";

    stream << "Name: "  << this->name   << ", " ;
    stream << "Size: "  << this->size           ;

    stream << " ]";

    stream << '\n';
}




char* Apple::buildString(const char* string) const {
    char* result = new char[strlen(string) + 1]();

    strcpy(result, string);

    return result;
}

void Apple::destroyString(char*& string) {
    delete[] string;

    string = nullptr;
}
