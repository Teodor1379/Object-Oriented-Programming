#include <iostream>



#define NUMBER 1379



int main() {
    #if defined(NUMBER)
        std::cout << "NUMBER is     defined!"   << std::endl;
    #elif defined(OTHER)
        std::cout << "NUMBER is NOT defined!"   << std::endl;
    #else
        std::cout << "Nothing is    defined!"   << std::endl;
    #endif

    return 0;
}
