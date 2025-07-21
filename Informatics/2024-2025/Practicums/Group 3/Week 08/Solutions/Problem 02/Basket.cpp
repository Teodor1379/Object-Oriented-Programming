#include "Basket.hpp"



Basket::Basket() {
    this->data  =   new Apple*[Basket::ALLOC_B]()   ;
    this->size  =   0                               ;
    this->cpct  =   Basket::ALLOC_B                 ;
}

Basket::Basket(const Basket& instance) {
    this->data  =   this->allocateData(instance)    ;
    this->size  =   instance.size                   ;
    this->cpct  =   instance.cpct                   ;
}

Basket::~Basket() {
    this->deallocateData(this->data, this->cpct);
}



Basket& Basket::operator=(const Basket& instance) {
    if (this != &instance) {
        Apple** temporary   =   this->allocateData(instance);

        this->deallocateData(this->data, this->cpct);

        this->data  =   temporary       ;
        this->size  =   instance.size   ;
        this->cpct  =   instance.cpct   ;
    }

    return *this;
}



void Basket::add(const char* name) {
    if (name == nullptr) {
        throw std::invalid_argument("Invalid Add Argument!");
    }

    for (unsigned int i = 0; i < this->size; ++i) {
        if (*this->data[i] == name) {
            throw std::logic_error("Apple Name Error!");
        }
    }

    if (this->size == this->cpct) {
        this->reallocateData();
    }

    this->data[this->size] = new Apple(name);

    this->size = this->size + 1;
}

void Basket::rem(const char* name) {
    if (name == nullptr) {
        throw std::invalid_argument("Invalid Rem Argument!");
    }

    bool found = false;

    for (unsigned int i = 0; i < this->size; ++i) {
        if (found) {
            this->data[i - 1] = this->data[i];
        } else {
            if (*this->data[i] == name) {
                delete this->data[i];

                this->data[i] = nullptr;

                found = true;
            }
        }
    }

    if (found) {
        this->data[this->size - 1] = nullptr;

        this->size = this->size - 1;
    } else {
        throw std::logic_error("Apple Name Error!");
    }
}



void Basket::print(std::ostream& stream) const noexcept {
    stream << "The apples in the basket are: " << '\n';

    for (unsigned int i = 0; i < this->size; ++i) {
        this->data[i]->print(stream);
    }
}



const Apple* const& Basket::operator[](unsigned int index) const {
    if (index >= this->size) {
        throw std::out_of_range("Invalid Index Argument!");
    }

    return this->data[index];
}

const Apple* const& Basket::operator[](const char* name) const {
    for (unsigned int i = 0; i < this->size; ++i) {
        if (*this->data[i] == name) {
            return this->data[i];
        }
    }

    throw std::out_of_range("Invalid Name Argument!");
}



Basket& Basket::operator+=(const Basket& basket) {
    Basket result;

    for (unsigned int i = 0; i < this->size; ++i) {
        result.add(this->data[i]->getName());
    }

    for (unsigned int i = 0; i < basket.getSize(); ++i) {
        result.add(basket[i]->getName());
    }

    *this = result;

    return *this;
}

Basket& Basket::operator+=(const char* string) {
    Basket result;

    for (unsigned int i = 0; i < this->size; ++i) {
        result.add(this->data[i]->getName());
        
        result.data[i]->addSuffix(string);
    }

    *this = result;

    return *this;
}



Apple** Basket::allocateData(const Basket& instance) {
    Apple** temporary   =   new Apple*[instance.cpct]();

    try {
        for (unsigned int i = 0; i < instance.size; ++i) {
            temporary[i] = new Apple(instance.data[i]->getName());
        }
    } catch (std::exception& exception) {
        this->deallocateData(temporary, instance.cpct);

        throw exception;
    }

    return temporary;
}

void Basket::deallocateData(Apple**& data, unsigned int size) {
    for (unsigned int i = 0; i < size; ++i) {
        delete data[i];
    }

    delete[] data;

    data = nullptr;
}

void Basket::reallocateData() {
    Apple** temporary   =   new Apple*[this->cpct * Basket::ALLOC_S]();

    try {
        for (unsigned int i = 0; i < this->size; ++i) {
            temporary[i] = new Apple(this->data[i]->getName());
        }
    } catch (std::exception& exception) {
        this->deallocateData(temporary, this->cpct * Basket::ALLOC_S);

        throw exception;
    }

    this->deallocateData(this->data, this->cpct);

    this->data  =   temporary                   ;
    this->cpct  =   this->cpct * Basket::ALLOC_S;
}
