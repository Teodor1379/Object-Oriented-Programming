#include "Vector.hpp"



Vector::Vector() {
    this->size  =   0                       ;
    this->cpct  =   2                       ;
    this->data  =   this->allocateData(4)   ;
}

Vector::Vector(unsigned int size) {
    if (size == 0) {
        this->size  =   0                               ;
        this->cpct  =   2                               ;
        this->data  =   this->allocateData(2)           ;
    } else {
        this->size  =   size                            ;
        this->cpct  =   this->findPowerTwo(this->size)  ;
        this->data  =   this->allocateData(this->cpct)  ;
    }
}

Vector::Vector(unsigned int size, int number) {
    if (size == 0) {
        this->size  =   0                               ;
        this->cpct  =   2                               ;
        this->data  =   this->allocateData(2)           ;
    } else {
        this->size  =   size                            ;
        this->cpct  =   this->findPowerTwo(this->size)  ;
        this->data  =   this->allocateData(this->cpct)  ;
    }

    for (unsigned int i = 0; i < this->size; ++i) {
        this->data[i] = number;
    }
}

Vector::Vector(const Vector& instance) {
    this->size  =   instance.size                   ;
    this->cpct  =   instance.cpct                   ;
    this->data  =   this->allocateData(instance)    ;
}

Vector::~Vector() {
    this->deallocateData();
}



Vector& Vector::operator=(const Vector& instance) {
    if (this != &instance) {
        int* buffer = this->allocateData(instance);

        this->deallocateData();

        this->size  =   instance.size   ;
        this->cpct  =   instance.cpct   ;
        this->data  =   buffer          ;
    }

    return *this;
}



void Vector::pushBack(int element) {
    if (this->size == this->cpct) {
        this->resize();
    }

    this->data[this->size] = element;

    this->size = this->size + 1;
}

void Vector::popBack() {
    if (this->size == 0) {
        throw std::logic_error("Invalid Vector Operation!");
    }

    this->size = this->size - 1;
}



void Vector::resize() {
    int* temporary = new int[this->cpct * 2]();

    for (unsigned int i = 0; i < this->size; ++i) {
        temporary[i] = this->data[i];
    }

    this->deallocateData();

    this->data  =   temporary       ;
    this->cpct  =   this->cpct * 2  ;
}



int* Vector::allocateData(unsigned int size) const {
    int* result = new int[size]();

    return result;
}

int* Vector::allocateData(const Vector& instance) const {
    int* result = new int[instance.size]();

    for (unsigned int i = 0; i < instance.size; ++i) {
        result[i] = instance.data[i];
    }

    return result;
}

void Vector::deallocateData() {
    delete[] this->data;

    this->data = nullptr;
}



unsigned int Vector::findPowerTwo(unsigned int number) const {
    unsigned int result = 1;

    while (result < number) {
        result = result << 1;
    }

    return result;
}



void print(const Vector& vector) {
    std::cout << "The elements of the vector are: ";

    for (unsigned int i = 0; i < vector.getSize(); ++i) {
        std::cout << vector.at(i) << ' ';
    }

    std::cout << std::endl;
}
