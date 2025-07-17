#include "Chocolate.hpp"



Chocolate::Chocolate() {
    this->brand     =   this->buildString("Unknown")    ;
    this->price     =   EPSILON                         ;
    this->weight    =   EPSILON                         ;
}

Chocolate::Chocolate(const char* brand, double price, double weight) {
    if (
        this->validateBrand (brand  )   == false    ||
        this->validatePrice (price  )   == false    ||
        this->validateWeight(weight )   == false
    ) {
        throw std::invalid_argument("Invalid Constructor Arguments!");
    }

    this->brand     =   buildString(brand)  ;
    this->price     =   price               ;
    this->weight    =   weight              ;
}

Chocolate::Chocolate(const Chocolate& instance) {
    this->brand     =   buildString(instance.brand) ;
    this->price     =   instance.price              ;
    this->weight    =   instance.weight             ;
}

Chocolate::~Chocolate() {
    this->destroyString(this->brand);
}



Chocolate& Chocolate::operator=(const Chocolate& instance) {
    if (this != &instance) {
        char* temporary = buildString(instance.brand);

        this->destroyString(this->brand);

        this->brand     =   temporary       ;
        this->price     =   instance.price  ;
        this->weight    =   instance.weight ;
    }

    return *this;
}



void Chocolate::setBrand(const char* brand) {
    if (this->validateBrand(brand) == false) {
        throw std::invalid_argument("Invalid Brand Argument!");
    }

    char* temporary = buildString(brand);

    this->destroyString(this->brand);

    this->brand = temporary;
}

void Chocolate::setPrice(double price) {
    if (this->validatePrice(price) == false) {
        throw std::invalid_argument("Invalid Price Argument!");
    }

    this->price = price;
}

void Chocolate::setWeight(double weight) {
    if (this->validateWeight(weight) == false) {
        throw std::invalid_argument("Invalid Weight Argument!");
    }

    this->weight = weight;
}



void Chocolate::print() const {
    std::cout << "Chocolate ";

    std::cout << "[ ";

    std::cout << "Brand : " << this->brand  << ", " ;
    std::cout << "Price : " << this->price  << ", " ;
    std::cout << "Weight: " << this->weight         ;

    std::cout << " ]";

    std::cout << std::endl;
}



char* Chocolate::buildString(const char* string) const {
    char* temporary = new char[strlen(string) + 1]();

    strcpy(temporary, string);

    return temporary;
}

void Chocolate::destroyString(char*& string) {
    delete[] string;

    string = nullptr;
}
