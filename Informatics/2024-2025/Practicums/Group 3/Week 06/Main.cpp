#include <stdexcept>
#include <exception>

#include <iostream>

class Base1 {
public:
    Base1() {
        std::cout << "Create Base 1" << std::endl;
    }

    Base1(const Base1&) = delete;

    ~Base1() = default;

    /* ~Base1() {
        std::cout << "Destroy Base 1" << std::endl;
    } */
};

class Base2 {
public:
    Base2() {
        std::cout << "Create Base 2" << std::endl;
    }

    ~Base2() {
        std::cout << "Destroy Base 2" << std::endl;
    }
};

class BiggerClass {
public:
    BiggerClass() {
        std::cout << "Create Bigger Class!" << std::endl;
    }

    ~BiggerClass() {
        std::cout << "Destroy Bigger Class!" << std::endl;
    }

public:
    int     number;
    Base1 internal1;
    Base2 internal2;
};

int main() {
    BiggerClass instance;

    return 0;
}
